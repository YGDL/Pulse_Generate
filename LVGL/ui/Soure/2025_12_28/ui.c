// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Signal_Modulation_System_Measurement

#include "ui.h"
#include "ui_helpers.h"
#include "task_start.h"

const char *type_str[] = {"No", "CW", "AM", "FM"};
const char *SHOW_points[] = {"10.0", "10.5", "11.0", "11.5", "12.0", "12.5", "13.0", "13.5", "14.0", "14.5",
                             "15.0", "15.5", "16.0", "16.5", "17.0", "17.5", "18.0", "18.5", "19.0", "19.5",
                             "20.0", "20.5", "21.0", "21.5", "22.0", "22.5", "23.0", "23.5", "24.0", "24.5",
                             "25.0", "25.5", "26.0", "26.5", "27.0", "27.5", "28.0", "28.5", "29.0", "29.5",
                             "30.0"};

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_StartScreen;
lv_obj_t * ui_StartText;
lv_obj_t * ui_Logo;
lv_obj_t * ui_WaitScreen;
lv_obj_t * ui_WaitSpinner;
lv_obj_t * ui_MeasureLabel;
lv_obj_t * ui_Logo1;
lv_obj_t * ui_ResultScreen;
lv_obj_t * ui_Logo2;
lv_obj_t * ui_BasicIinformation;
lv_obj_t * ui_ModulationType;
lv_obj_t * ui_ModulationFrequency;
lv_obj_t * ui_AmplitudeModulationFactor;
lv_obj_t * ui_FrequencyModulationFactor;
lv_obj_t * ui_FrequencyDeviation;
lv_obj_t * ui_ReferenceInformation;
lv_obj_t * ui_CarrierFrequency;
lv_obj_t * ui_LocalFrequency;
lv_obj_t * ui_ModulationType1;
lv_obj_t * ui_ModulationFrequency1;
lv_obj_t * ui_ModulationFrequency2;
lv_obj_t * ui_AmplitudeModulationFactor1;
lv_obj_t * ui_FrequencyModulationFactor1;
lv_obj_t * ui_FrequencyDeviation1;
lv_obj_t * ui_FrequencyDeviation2;
lv_obj_t * ui_CarrierFrequency1;
lv_obj_t * ui_CarrierFrequency2;
lv_obj_t * ui_LocalFrequency1;
lv_obj_t * ui_LocalFrequency2;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "#error LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_StartScreen_screen_init(void)
{

    // ui_StartScreen

    ui_StartScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_StartScreen, LV_OBJ_FLAG_SCROLLABLE);

    // ui_StartText

    ui_StartText = lv_textarea_create(ui_StartScreen);

    lv_obj_set_width(ui_StartText, 130);
    lv_obj_set_height(ui_StartText, 70);

    lv_obj_set_x(ui_StartText, 0);
    lv_obj_set_y(ui_StartText, 0);

    lv_obj_set_align(ui_StartText, LV_ALIGN_CENTER);

    if("" == "") lv_textarea_set_accepted_chars(ui_StartText, NULL);
    else lv_textarea_set_accepted_chars(ui_StartText, "");

    lv_textarea_set_text(ui_StartText, "Start");
    lv_textarea_set_placeholder_text(ui_StartText, "Placeholder...");

    lv_obj_set_style_text_font(ui_StartText, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Logo

    ui_Logo = lv_label_create(ui_StartScreen);

    lv_obj_set_width(ui_Logo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Logo, -4);
    lv_obj_set_y(ui_Logo, 4);

    lv_obj_set_align(ui_Logo, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Logo, "Sunshine Circuit");

    lv_obj_set_style_text_font(ui_Logo, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_WaitScreen_screen_init(void)
{

    // ui_WaitScreen

    ui_WaitScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_WaitScreen, LV_OBJ_FLAG_SCROLLABLE);

    // ui_WaitSpinner

    ui_WaitSpinner = lv_spinner_create(ui_WaitScreen, 1000, 90);

    lv_obj_set_width(ui_WaitSpinner, 50);
    lv_obj_set_height(ui_WaitSpinner, 50);

    lv_obj_set_x(ui_WaitSpinner, 0);
    lv_obj_set_y(ui_WaitSpinner, 0);

    lv_obj_set_align(ui_WaitSpinner, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_WaitSpinner, LV_OBJ_FLAG_CLICKABLE);

    // ui_MeasureLabel

    ui_MeasureLabel = lv_label_create(ui_WaitScreen);

    lv_obj_set_width(ui_MeasureLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_MeasureLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_MeasureLabel, 0);
    lv_obj_set_y(ui_MeasureLabel, 60);

    lv_obj_set_align(ui_MeasureLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_MeasureLabel, "Measure");

    lv_obj_set_style_text_font(ui_MeasureLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Logo1

    ui_Logo1 = lv_label_create(ui_WaitScreen);

    lv_obj_set_width(ui_Logo1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Logo1, -4);
    lv_obj_set_y(ui_Logo1, 4);

    lv_obj_set_align(ui_Logo1, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Logo1, "Sunshine Circuit");

    lv_obj_set_style_text_font(ui_Logo1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ResultScreen_screen_init(void)
{

    // ui_ResultScreen

    ui_ResultScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ResultScreen, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Logo2

    ui_Logo2 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_Logo2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Logo2, -4);
    lv_obj_set_y(ui_Logo2, 4);

    lv_obj_set_align(ui_Logo2, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Logo2, "Sunshine Circuit");

    lv_obj_set_style_text_font(ui_Logo2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_BasicIinformation

    ui_BasicIinformation = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_BasicIinformation, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BasicIinformation, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BasicIinformation, 10);
    lv_obj_set_y(ui_BasicIinformation, 40);

    lv_label_set_text(ui_BasicIinformation, "Basic Iinformation");

    lv_obj_set_style_text_font(ui_BasicIinformation, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModulationType

    ui_ModulationType = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_ModulationType, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ModulationType, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ModulationType, 10);
    lv_obj_set_y(ui_ModulationType, 55);

    lv_label_set_text(ui_ModulationType, "Type:");

    lv_obj_set_style_text_font(ui_ModulationType, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModulationFrequency

    ui_ModulationFrequency = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_ModulationFrequency, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ModulationFrequency, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ModulationFrequency, 10);
    lv_obj_set_y(ui_ModulationFrequency, 70);

    lv_label_set_text(ui_ModulationFrequency, "MFreq:");

    lv_obj_set_style_text_font(ui_ModulationFrequency, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_AmplitudeModulationFactor

    ui_AmplitudeModulationFactor = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_AmplitudeModulationFactor, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AmplitudeModulationFactor, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_AmplitudeModulationFactor, 10);
    lv_obj_set_y(ui_AmplitudeModulationFactor, 85);

    lv_label_set_text(ui_AmplitudeModulationFactor, "AM Depth(ma):");

    lv_obj_set_style_text_font(ui_AmplitudeModulationFactor, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FrequencyModulationFactor

    ui_FrequencyModulationFactor = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_FrequencyModulationFactor, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FrequencyModulationFactor, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FrequencyModulationFactor, 10);
    lv_obj_set_y(ui_FrequencyModulationFactor, 100);

    lv_label_set_text(ui_FrequencyModulationFactor, "FM Factor(mf):");

    lv_obj_set_style_text_font(ui_FrequencyModulationFactor, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FrequencyDeviation

    ui_FrequencyDeviation = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_FrequencyDeviation, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FrequencyDeviation, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FrequencyDeviation, 10);
    lv_obj_set_y(ui_FrequencyDeviation, 115);

    lv_label_set_text(ui_FrequencyDeviation, "FMDev:");

    lv_obj_set_style_text_font(ui_FrequencyDeviation, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ReferenceInformation

    ui_ReferenceInformation = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_ReferenceInformation, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ReferenceInformation, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ReferenceInformation, 10);
    lv_obj_set_y(ui_ReferenceInformation, 140);

    lv_label_set_text(ui_ReferenceInformation, "Reference Information");

    lv_obj_set_style_text_font(ui_ReferenceInformation, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_CarrierFrequency

    ui_CarrierFrequency = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_CarrierFrequency, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CarrierFrequency, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_CarrierFrequency, 10);
    lv_obj_set_y(ui_CarrierFrequency, 155);

    lv_label_set_text(ui_CarrierFrequency, "CFre:");

    lv_obj_set_style_text_font(ui_CarrierFrequency, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LocalFrequency

    ui_LocalFrequency = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_LocalFrequency, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LocalFrequency, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LocalFrequency, 10);
    lv_obj_set_y(ui_LocalFrequency, 170);

    lv_label_set_text(ui_LocalFrequency, "LFreq:");

    lv_obj_set_style_text_font(ui_LocalFrequency, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModulationType1

    ui_ModulationType1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_ModulationType1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ModulationType1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ModulationType1, 190);
    lv_obj_set_y(ui_ModulationType1, 55);

    lv_label_set_text(ui_ModulationType1, "CW");

    lv_obj_set_style_text_font(ui_ModulationType1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModulationFrequency1

    ui_ModulationFrequency1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_ModulationFrequency1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ModulationFrequency1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ModulationFrequency1, 190);
    lv_obj_set_y(ui_ModulationFrequency1, 70);

    lv_label_set_text(ui_ModulationFrequency1, "*.***");

    lv_obj_set_style_text_font(ui_ModulationFrequency1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModulationFrequency2

    ui_ModulationFrequency2 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_ModulationFrequency2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ModulationFrequency2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ModulationFrequency2, 270);
    lv_obj_set_y(ui_ModulationFrequency2, 70);

    lv_label_set_text(ui_ModulationFrequency2, "kHz");

    lv_obj_set_style_text_font(ui_ModulationFrequency2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_AmplitudeModulationFactor1

    ui_AmplitudeModulationFactor1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_AmplitudeModulationFactor1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AmplitudeModulationFactor1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_AmplitudeModulationFactor1, 190);
    lv_obj_set_y(ui_AmplitudeModulationFactor1, 85);

    lv_label_set_text(ui_AmplitudeModulationFactor1, "*.***");

    lv_obj_set_style_text_font(ui_AmplitudeModulationFactor1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FrequencyModulationFactor1

    ui_FrequencyModulationFactor1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_FrequencyModulationFactor1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FrequencyModulationFactor1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FrequencyModulationFactor1, 190);
    lv_obj_set_y(ui_FrequencyModulationFactor1, 100);

    lv_label_set_text(ui_FrequencyModulationFactor1, "*.***");

    lv_obj_set_style_text_font(ui_FrequencyModulationFactor1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FrequencyDeviation1

    ui_FrequencyDeviation1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_FrequencyDeviation1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FrequencyDeviation1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FrequencyDeviation1, 190);
    lv_obj_set_y(ui_FrequencyDeviation1, 115);

    lv_label_set_text(ui_FrequencyDeviation1, "*.***");

    lv_obj_set_style_text_font(ui_FrequencyDeviation1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FrequencyDeviation2

    ui_FrequencyDeviation2 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_FrequencyDeviation2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FrequencyDeviation2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FrequencyDeviation2, 270);
    lv_obj_set_y(ui_FrequencyDeviation2, 115);

    lv_label_set_text(ui_FrequencyDeviation2, "kHz");

    lv_obj_set_style_text_font(ui_FrequencyDeviation2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_CarrierFrequency1

    ui_CarrierFrequency1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_CarrierFrequency1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CarrierFrequency1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_CarrierFrequency1, 190);
    lv_obj_set_y(ui_CarrierFrequency1, 155);

    lv_label_set_text(ui_CarrierFrequency1, "*.***");

    lv_obj_set_style_text_font(ui_CarrierFrequency1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_CarrierFrequency2

    ui_CarrierFrequency2 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_CarrierFrequency2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CarrierFrequency2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_CarrierFrequency2, 270);
    lv_obj_set_y(ui_CarrierFrequency2, 155);

    lv_label_set_text(ui_CarrierFrequency2, "kHz");

    lv_obj_set_style_text_font(ui_CarrierFrequency2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LocalFrequency1

    ui_LocalFrequency1 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_LocalFrequency1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LocalFrequency1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LocalFrequency1, 190);
    lv_obj_set_y(ui_LocalFrequency1, 170);

    lv_label_set_text(ui_LocalFrequency1, "*.***");

    lv_obj_set_style_text_font(ui_LocalFrequency1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LocalFrequency2

    ui_LocalFrequency2 = lv_label_create(ui_ResultScreen);

    lv_obj_set_width(ui_LocalFrequency2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LocalFrequency2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LocalFrequency2, 270);
    lv_obj_set_y(ui_LocalFrequency2, 170);

    lv_label_set_text(ui_LocalFrequency2, "kHz");

    lv_obj_set_style_text_font(ui_LocalFrequency2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_StartScreen_screen_init();
    ui_WaitScreen_screen_init();
    ui_ResultScreen_screen_init();
    lv_disp_load_scr(ui_ResultScreen);
}

void show_all(void)
{
    if (have)
    {
        lv_label_set_text(ui_ModulationType1, type_str[type]);
        if (type > 1)
        {
            lv_label_set_text_fmt(ui_ModulationFrequency1, "%.3f", bf);
            if (type == 3)  //调频
            {
                lv_label_set_text(ui_AmplitudeModulationFactor1, "*.***");
                lv_label_set_text_fmt(ui_FrequencyModulationFactor1, "%.3f", mf);
                lv_label_set_text_fmt(ui_FrequencyDeviation1, "%.3f", of);
                lv_label_set_text_fmt(ui_CarrierFrequency1, "%.3f", points);
            }
            else    //调幅
            {
                lv_label_set_text_fmt(ui_AmplitudeModulationFactor1, "%.3f", ma/100);
                lv_label_set_text(ui_FrequencyModulationFactor1, "*.***");
                lv_label_set_text(ui_FrequencyDeviation1, "*.***");
                lv_label_set_text_fmt(ui_CarrierFrequency1, "%.3f", points);
            }
        }
        else        //CW
        {
            lv_label_set_text(ui_ModulationFrequency1, "*.***");
            lv_label_set_text(ui_AmplitudeModulationFactor1, "*.***");
            lv_label_set_text(ui_FrequencyModulationFactor1, "*.***");
            lv_label_set_text(ui_FrequencyDeviation1, "*.***");
            lv_label_set_text_fmt(ui_CarrierFrequency1, "%.3f", points);
        }
    }
    else
    {
        lv_label_set_text(ui_ModulationType1, type_str[0]);
        lv_label_set_text(ui_ModulationFrequency1, "*.***");
        lv_label_set_text(ui_AmplitudeModulationFactor1, "*.***");
        lv_label_set_text(ui_FrequencyModulationFactor1, "*.***");
        lv_label_set_text(ui_FrequencyDeviation1, "*.***");
        lv_label_set_text(ui_CarrierFrequency1, "*.***");
    }
}
