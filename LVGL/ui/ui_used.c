#include "tim.h"
#include "gpio.h"
#include "ui.h"
#include "lv_port_indev.h"

lv_group_t * Group_1;

void Use_Switch1_Callback(lv_event_t * e);
void Use_Slider1_Callback(lv_event_t * e);
void Use_Slider2_Callback(lv_event_t * e);
void Use_IO_Switch_Callback(lv_event_t * e);

void Focuse_Group_Init(void)
{
    // 创建组1
    Group_1 = lv_group_create();

    lv_group_add_obj(Group_1, ui_Button1);
    lv_group_add_obj(Group_1, ui_Button2);
    lv_group_add_obj(Group_1, ui_Button3);
    lv_group_add_obj(Group_1, ui_Button4);
    lv_group_add_obj(Group_1, ui_Switch1);
    lv_group_add_obj(Group_1, ui_IO1_Switch);
    lv_group_add_obj(Group_1, ui_IO2_Switch);
    lv_group_add_obj(Group_1, ui_IO3_Switch);
    lv_group_add_obj(Group_1, ui_IO4_Switch);

    lv_indev_set_group(indev_keypad, Group_1);
}

/* 创建事件组 */
void Use_Event_Init(void)
{
    lv_obj_add_event_cb(ui_Switch1, Use_Switch1_Callback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Slider1, Use_Slider1_Callback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Slider2, Use_Slider2_Callback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_IO1_Switch, Use_IO_Switch_Callback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_IO2_Switch, Use_IO_Switch_Callback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_IO3_Switch, Use_IO_Switch_Callback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_IO4_Switch, Use_IO_Switch_Callback, LV_EVENT_ALL, NULL);
}

void Use_Switch1_Callback(lv_event_t * e)
{
    static uint16_t Count = 1U;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target,LV_STATE_CHECKED))
    {
        if(Count != 1U)
        {
            // 开关打开，此时应该开始产生脉冲
            __HAL_TIM_CLEAR_IT(&htim5, TIM_IT_UPDATE);
            htim5.Instance->ARR = Period_Count;
            htim5.Instance->CCR1 = Width_Count;
            htim5.Instance->CR1 = htim5.Instance->CR1 | 0x1;
        }
        else
        {
            __HAL_TIM_CLEAR_IT(&htim5, TIM_IT_UPDATE);
            __HAL_TIM_ENABLE_IT(&htim5, TIM_IT_UPDATE);
            htim5.Instance->ARR = Period_Count;
            htim5.Instance->CCR1 = Width_Count;
            HAL_TIM_OnePulse_Start(&htim5, TIM_CHANNEL_1);
            Count = 2U;
        }
    }
}

void Use_Slider1_Callback(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_VALUE_CHANGED)
    {
        Pulse_Number = (uint32_t)lv_slider_get_value(ui_Slider1);
        Width_Count = (uint32_t)(Pulse_Width/(dt*Pulse_Number));
        Period_Count = Width_Count*2;
    }
}

void Use_Slider2_Callback(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_VALUE_CHANGED)
    {
        Pulse_Width = lv_slider_get_value(ui_Slider2);
        Width_Count = (uint32_t)(Pulse_Width/(dt*Pulse_Number));
        Period_Count = Width_Count*2;
    }
}

void Use_IO_Switch_Callback(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_VALUE_CHANGED)
    {
        if(ui_IO1_Switch == target)
        {
            // if(lv_obj_has_state(target, LV_STATE_CHECKED))
            //     HAL_GPIO_WritePin(GPIOB, IO1_Pin, GPIO_PIN_SET);
            // else
            //     HAL_GPIO_WritePin(GPIOB, IO1_Pin, GPIO_PIN_RESET);
        }

        if(ui_IO2_Switch == target)
        {
            if(lv_obj_has_state(target, LV_STATE_CHECKED))
                HAL_GPIO_WritePin(GPIOB, IO2_Pin, GPIO_PIN_SET);
            else
                HAL_GPIO_WritePin(GPIOB, IO2_Pin, GPIO_PIN_RESET);
        }

        if(ui_IO3_Switch == target)
        {
            if(lv_obj_has_state(target, LV_STATE_CHECKED))
                HAL_GPIO_WritePin(GPIOB, IO3_Pin, GPIO_PIN_SET);
            else
                HAL_GPIO_WritePin(GPIOB, IO3_Pin, GPIO_PIN_RESET);
        }

        if(ui_IO4_Switch == target)
        {
            if(lv_obj_has_state(target, LV_STATE_CHECKED))
                HAL_GPIO_WritePin(GPIOB, IO4_Pin, GPIO_PIN_SET);
            else
                HAL_GPIO_WritePin(GPIOB, IO4_Pin, GPIO_PIN_RESET);
        }
    }
}