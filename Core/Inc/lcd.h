#ifndef _LCD_H
#define _LCD_H

#include "stm32h7xx_hal.h"

//液晶屏初始化配置宏
#define LCD_DIR_Mode	L2R_U2D		//刷新方向，具体参照以下宏选择
#define RGB_BGR_ORDER	BGR			//面板滤色选择，像素颜色排列方式
#define LVGL_ENABLE		1			//使用LVGL显示框架，只需保留批量填充即可

//液晶屏颜色选择开关控制宏
#define BGR		0x08
#define RGB		0x00
//显示方向宏
#define L2R_U2D  0x00	//从左到右,从上到下,正屏
#define L2R_D2U  0x80	//从左到右,从下到上
#define R2L_U2D  0x40	//从右到左,从上到下
#define R2L_D2U  0xC0	//从右到左,从下到上
//行列交换，相当于翻转90°
#define U2D_L2R  0x20	//从上到下,从左到右
#define U2D_R2L  0x60	//从上到下,从右到左,翻转屏
#define D2U_L2R  0xA0	//从下到上,从左到右
#define D2U_R2L  0xE0	//从下到上,从右到左

//自定义命令宏
#define REGFLAG_DELAY			0xFC	//延时命令
#define REGFLAG_END_OF_TABLE	0xFD	//结束命令

//液晶控制口置1操作语句宏
#define	LCD_CS_SET	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)	//PB12置1	LCD_CS：PB12 //片选	
#define LCD_DC_SET	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET)	//PB14置1	LCD_DC：PB14 //数据输出/复位

//液晶控制口置0操作语句宏
#define	LCD_CS_CLR	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)	//PB12置0	LCD_CS：PB12 //片选
#define LCD_DC_CLR	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET)	//PB14置0	LCD_DC：PB14 //数据输出/复位

//刷新方向条件编译宏
#if LCD_DIR_Mode == L2R_U2D
#define LCD_MADCTL ( L2R_U2D | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == L2R_D2U
#define LCD_MADCTL ( L2R_D2U | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == R2L_U2D
#define LCD_MADCTL ( R2L_U2D | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == R2L_D2U
#define LCD_MADCTL ( R2L_D2U | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == U2D_L2R
#define LCD_MADCTL ( U2D_L2R | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == U2D_R2L
#define LCD_MADCTL ( U2D_R2L | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == D2U_L2R
#define LCD_MADCTL ( D2U_L2R | RGB_BGR_ORDER )
#elif LCD_DIR_Mode == D2U_R2L
#define LCD_MADCTL ( D2U_R2L | RGB_BGR_ORDER )
#endif

//LCD重要参数集
typedef struct  
{
	uint16_t	width;		//LCD 宽度
	uint16_t	height;		//LCD 高度
	uint16_t	id;			//LCD ID
	uint8_t		dir;		//横屏还是竖屏控制：竖屏和横屏。
	uint16_t	wramcmd;	//开始写gram指令
	uint16_t	setxcmd;	//设置x坐标指令
	uint16_t	setycmd;	//设置y坐标指令 
}_lcd_dev;

//LCD命令、数据表原型
typedef struct{
	uint8_t cmd;
	uint32_t count;
	uint8_t para_list[32];
}LCD_Setting_Table;

//函数原型声明
static void LCD_Write_CMD_DATA(const LCD_Setting_Table * ILI9341);
void LCD_Color_Fill(uint16_t X_Start, uint16_t Y_Start, uint16_t X_End, uint16_t Y_End, const uint16_t *Color);
void LCD_Init(void);

#endif
