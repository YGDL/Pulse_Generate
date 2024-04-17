
#include "lcd.h"
#include "main.h"
#include "spi.h"
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"

_lcd_dev lcd_dev;

static HAL_StatusTypeDef SPI_DMA_State = HAL_OK;

//ILI9341初始化命令、数据表
const static LCD_Setting_Table ILI9341_Setting[] = {
	{0x01, 0, {0x00}},				//软复位指令
	{REGFLAG_DELAY, REGFLAG_DELAY, {50}},
	{0xCF, 3, {0x00, 0xD9, 0x30}},	//功耗控制B
	{0xED, 4, {0x64, 0x03, 0x12, 0x81}},		//电源序列控制
	{0xE8, 3, {0x85, 0x10, 0x78}},	//驱动时序控制A
	{0xCB, 5, {0x39, 0x2C, 0x00, 0x34, 0x02}},	//功耗控制A
	{0xF7, 1, {0x20}},				//泵比控制
	{0xEA, 2, {0x00, 0x00}},		//驱动时序控制B
	{0xC0, 1, {0x21}},				//功耗控制1
	{0xC1, 1, {0x12}},				//功耗控制2
	{0xC5, 2, {0x32, 0x3C}},		//VCOM控制1
	{0xC7, 1, {0xC1}},				//VCOM控制2
	{0x36, 1, {0x08}},				//内存器访问控制
	{0x3A, 1, {0x55}},				//像素格式控制
	{0xB1, 2, {0x00, 0x18}},		//帧速率控制
	{0xB6, 2, {0x0A, 0xA2}},		//显示功能控制
	{0xF2, 1, {0x00}},				//使能3伽马控制
	{0x26, 1, {0x01}},				//伽马设置
	{0xE0, 15, {0x0F, 0x20, 0x1E, 0x09, 0x12, 0x0B, 0x50, 0xBA, 0x44, 0x09, 0x14, 0x05, 0x23, 0x21, 0x00}},
	{0xE1, 15, {0x00, 0x19, 0x19, 0x00, 0x12, 0x07, 0x2D, 0x28, 0x3F, 0x02, 0x0A, 0x08, 0x25, 0x2D, 0x0F}},
	{0x11, 0, {0x00}},				//退出睡眠
	{REGFLAG_DELAY, REGFLAG_DELAY, {120}},
	{0x29, 0, {0x00}},				//开启显示
	{0x36, 1, {LCD_MADCTL}},		//内存访问控制，刷新的方向与RGB\BGR
	{REGFLAG_DELAY, REGFLAG_DELAY, {50}},
	{REGFLAG_END_OF_TABLE, REGFLAG_END_OF_TABLE, {0x00}}
};

//LCD写指令与数据
//传入命令、数据表
static void LCD_Write_CMD_DATA(const LCD_Setting_Table * ILI9341)	//修改为指针形式，限定的指针形式，无法修改源数据
{
    int8_t data_count = 0;
	uint16_t cmd_count = 0U, cmd_num = 0U;
	while((ILI9341 + cmd_num)->cmd != REGFLAG_END_OF_TABLE)
		cmd_num ++;	//获取指令个数，即除了结束指令的个数
	while(cmd_count != cmd_num)
	{
		if((ILI9341 + cmd_count)->cmd == REGFLAG_DELAY)		//查到延时命令
			osDelay((ILI9341 + cmd_count)->para_list[0]);	//启用延时
		else
		{
			LCD_CS_CLR;
			LCD_DC_CLR;
			HAL_SPI_Transmit(&hspi2, (uint8_t *)&((ILI9341 + cmd_count)->cmd), 1, 10);	//写第一个指令
			LCD_DC_SET;
			while((data_count != (ILI9341 + cmd_count)->count) && ((ILI9341 + cmd_count)->count != 0))	//没有数据直接跳过
			{
				HAL_SPI_Transmit(&hspi2, (uint8_t *)&((ILI9341 + cmd_count)->para_list[data_count]), 1, 10);	//指令携带数据
				data_count ++;
			}	//能够连发数据，例如16bit、24bit、32bit……
			LCD_CS_SET;
			data_count = 0;
		}
		cmd_count ++;
	}
}

const static uint16_t LCD_Test_Array[10][10] = {
	{0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E},
	{0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E},
	{0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E},
	{0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E},
	{0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E, 0xE00E},
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
	{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}
};

//批量填充，使用DMA+SPI实现
void LCD_Color_Fill(uint16_t X_Start, uint16_t Y_Start, uint16_t X_End, uint16_t Y_End, const uint16_t *Color)
{
	uint8_t RAMWR = 0x2C;	//RAMWR指令
	LCD_Setting_Table ILI9341_XY[] = {
		{0x2A, 4, {X_Start >> 8, X_Start & 0xFF, X_End >> 8, X_End & 0xFF}},
		{0x2B, 4, {Y_Start >> 8, Y_Start & 0xFF, Y_End >> 8, Y_End & 0xFF}},
		{REGFLAG_END_OF_TABLE, REGFLAG_END_OF_TABLE, {0x00}}
	};
	LCD_Write_CMD_DATA(ILI9341_XY);

	LCD_CS_CLR;
	LCD_DC_CLR;
	HAL_SPI_Transmit(&hspi2, &RAMWR, 1, 1);		//写RAMWR命令
	LCD_DC_SET;

	HAL_SPI_Transmit_DMA(&hspi2, (uint8_t *)Color, (X_End - X_Start + 1)*(Y_End - Y_Start + 1)*2);
	SPI_DMA_State = HAL_BUSY;
	while(SPI_DMA_State != HAL_OK)
		osDelay(1);
	LCD_CS_SET;
}

//发送完成回调，改写DMA状态标志
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	SPI_DMA_State = HAL_OK;
}

#if LVGL_ENABLE == 0
//设置LCD显示方向，全屏
//dir:     0,竖屏  正
//         1,竖屏  反
//         2,横屏  左
//         3,横屏  右
void LCD_Display_Dir(uint8_t dir)
{
	
	uint8_t SCAN_DIR;
		
	switch(dir)
	{
		case 0:
			lcd_dev.dir = 0;		//竖屏
			lcd_dev.width = 240;
			lcd_dev.height = 320;
			SCAN_DIR = L2R_U2D;		//选择扫描方向
			break;

		case 1:
			lcd_dev.dir = 0;		//竖屏
			lcd_dev.width = 240;
			lcd_dev.height = 320;
			SCAN_DIR = R2L_D2U;		//选择扫描方向
			break;

		case 2:
			lcd_dev.dir = 1;		//横屏
			lcd_dev.width = 320;
			lcd_dev.height = 240;
			SCAN_DIR = U2D_R2L;		//选择扫描方向
			break;

		case 3:
			lcd_dev.dir = 1;		//横屏
			lcd_dev.width = 320;
			lcd_dev.height = 240;
			SCAN_DIR = D2U_L2R;		//选择扫描方向
			break;
		
		default:
			lcd_dev.dir = 0;		//竖屏
			lcd_dev.width = 240;
			lcd_dev.height = 320;
			SCAN_DIR = L2R_U2D;		//选择扫描方向
			break;
	}
	lcd_dev.wramcmd = 0x2C;
	lcd_dev.setxcmd = 0x2A;
	lcd_dev.setycmd = 0x2B;

	//以下设置，为窗口参数设置，设置了全屏的显示范围
	LCD_WR_REG(lcd_dev.setxcmd);

	LCD_WR_DATA16(0);
	LCD_WR_DATA16(lcd_dev.width-1);

	LCD_WR_REG(lcd_dev.setycmd);
	LCD_WR_DATA16(0);
	LCD_WR_DATA16(lcd_dev.height-1);

 	//设置屏幕显示--扫描方向
	LCD_Scan_Dir(SCAN_DIR);	//设置屏幕显示--扫描方向
}
#endif

//LCD屏初始化
void LCD_Init(void)
{
	LCD_Write_CMD_DATA(ILI9341_Setting);
	LCD_Color_Fill(0, 0, 9, 9, (uint16_t *)LCD_Test_Array);
}
