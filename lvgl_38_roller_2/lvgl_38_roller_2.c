// lvgl第38讲后半部分：滚轮部件例程代码

#include "lvgl.h"
#include "my_gui.h"


/* 模式选项 */
static const char *mode_options = "Auto\n"
                                    "Heat\n"
                                    "Cool\n"
                                    "Fan";
/* 温度选项 */
static const char *temp_options = "23\n"
                                    "24\n"
                                    "25\n"
                                    "26\n"
                                    "27\n"
                                    "28\n"
                                    "29";
/* 湿度选项 */
static const char *hum_options  = "30\n"
                                    "40\n"
                                    "50\n"
                                    "60\n"
                                    "70\n"
                                    "80\n"
                                    "90";
 /* 定义字体 */
static const lv_font_t *font;
 /* 温度滚轮 */
static lv_obj_t *temp_roller;
 /* 湿度滚轮 */
static lv_obj_t *hum_roller;


static void example_roller_mode(void);
static void example_roller_tem(void);
static void example_roller_hum(void);

static void event_cb(lv_event_t* e);


void my_gui(void)
{
    example_roller_mode();
    example_roller_tem();
    example_roller_hum();
}

static void example_roller_mode(void)
{
    // 灵活设置字体
    if (lv_obj_get_width(lv_scr_act()) <= 320)
    {
        font = &lv_font_montserrat_14;
    }
    else
    {
        font = &lv_font_montserrat_18;
    }
    lv_obj_t* roller_mode = lv_roller_create(lv_scr_act());
    lv_obj_set_width(roller_mode, lv_obj_get_width(lv_scr_act()) / 6);
    lv_obj_align(roller_mode, LV_ALIGN_CENTER,
                 -lv_obj_get_width(lv_scr_act()) / 4, 0);
    lv_roller_set_options(roller_mode,
                          mode_options,
                          LV_ROLLER_MODE_NORMAL);
    // 设置模式滚轮的当前选项
    lv_roller_set_selected(roller_mode, 1, LV_ANIM_ON);
    lv_obj_add_event_cb(roller_mode,
                        event_cb,
                        LV_EVENT_VALUE_CHANGED,
                        NULL);
    // 设置标签
    lv_obj_t* label_mode = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(label_mode, font,
                               LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_mode,
                                lv_color_hex(0x00ffcc),
                                LV_STATE_DEFAULT);
    lv_obj_align_to(label_mode, roller_mode,
                    LV_ALIGN_OUT_TOP_MID, -10, -10);
    lv_label_set_text(label_mode, "Mode");
}


static void example_roller_tem(void)
{
    // 温度滚轮
    temp_roller = lv_roller_create(lv_scr_act());
    lv_obj_set_width(temp_roller, lv_obj_get_width(lv_scr_act()) / 6);
    lv_obj_align(temp_roller, LV_ALIGN_CENTER,0, 0);
    lv_roller_set_options(temp_roller,
                          temp_options,
                          LV_ROLLER_MODE_NORMAL);
    // 温度标签
    lv_obj_t* temp_label = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(temp_label, font,
                               LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(temp_label,
                                lv_color_hex(0xff00cc),
                                LV_STATE_DEFAULT);
    lv_obj_align_to(temp_label, temp_roller,
                    LV_ALIGN_OUT_TOP_MID, -10, -10);
    lv_label_set_text(temp_label, "Temp");

}

static void example_roller_hum(void)
{
    // 湿度滚轮
    hum_roller = lv_roller_create(lv_scr_act());
    lv_obj_set_width(hum_roller, lv_obj_get_width(lv_scr_act()) / 6);
    lv_obj_align(hum_roller, LV_ALIGN_CENTER,
                 lv_obj_get_width(lv_scr_act()) / 4, 0);
    lv_roller_set_options(hum_roller,
                          hum_options,
                          LV_ROLLER_MODE_NORMAL);
    // 湿度标签
    lv_obj_t* hum_label = lv_label_create(lv_scr_act());
    lv_obj_align_to(hum_label, hum_roller, LV_ALIGN_OUT_TOP_MID, -10, -10);
    lv_obj_set_style_text_font(hum_label, font,
                               LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(hum_label,
                                lv_color_hex(0xcc00ff),
                                LV_STATE_DEFAULT);
    lv_label_set_text(hum_label, "Hum");
}

static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);

    // 自动模式下不需要设置温度和湿度
    if ((uint16_t)0 == lv_roller_get_selected(target))
    {
        lv_obj_add_state(temp_roller, LV_STATE_DISABLED);
        lv_obj_add_state(hum_roller, LV_STATE_DISABLED);
    }
    else // 非自动模式则可以手动设置温度和湿度
    {
        lv_obj_clear_state(temp_roller, LV_STATE_DISABLED);
        lv_obj_clear_state(hum_roller, LV_STATE_DISABLED);
    }
}


// 正定原子官方例程代码
//
//#include "lvgl.h"
//#include <stdio.h>
//
//
///* 获取当前活动屏幕的宽高 */
//#define scr_act_width() lv_obj_get_width(lv_scr_act())
//#define scr_act_height() lv_obj_get_height(lv_scr_act())
//
///* 模式选项 */
//static const char *mode_options = "Auto\n"
//                                    "Heat\n"
//                                    "Cool\n"
//                                    "Fan";
///* 温度选项 */
//static const char *temp_options = "23\n"
//                                    "24\n"
//                                    "25\n"
//                                    "26\n"
//                                    "27\n"
//                                    "28\n"
//                                    "29";
///* 湿度选项 */
//static const char *hum_options  = "30\n"
//                                    "40\n"
//                                    "50\n"
//                                    "60\n"
//                                    "70\n"
//                                    "80\n"
//                                    "90";
//
//static const lv_font_t *font;                   /* 定义字体 */
//static lv_obj_t *temp_roller;                   /* 温度滚轮 */
//static lv_obj_t *hum_roller;                    /* 湿度滚轮 */
//
//
///**
// * @brief  滚轮事件回调
// * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
// * @return 无
// */
//static void roller_event_cb(lv_event_t* e)
//{
//    lv_obj_t *target = lv_event_get_target(e);                  /* 获取触发源 */
//
//    if(lv_roller_get_selected(target) == 0)                     /* 获取索引，判断是否为Auto选项 */
//    {
//        lv_obj_add_state(temp_roller, LV_STATE_DISABLED);       /* 设置温度滚轮为不可选状态 */
//        lv_obj_add_state(hum_roller, LV_STATE_DISABLED);        /* 设置湿度滚轮为不可选状态 */
//    }
//    else
//    {
//        lv_obj_clear_state(temp_roller, LV_STATE_DISABLED);     /* 解除温度滚轮不可选状态 */
//        lv_obj_clear_state(hum_roller, LV_STATE_DISABLED);      /* 解除湿度滚轮不可选状态 */
//    }
//}
//
///**
// * @brief  模式设置
// * @param  无
// * @return 无
// */
//static void lv_example_roller1(void)
//{
//    /* 根据活动屏幕宽度选择字体 */
//    if (scr_act_width() <= 480)
//    {
//        font = &lv_font_montserrat_14;
//    }
//    else
//    {
//        font = &lv_font_montserrat_20;
//    }
//
//    lv_obj_t *mode_roller = lv_roller_create(lv_scr_act());                                     /* 创建模式设置滚轮 */
//    lv_roller_set_options(mode_roller, mode_options, LV_ROLLER_MODE_NORMAL);                    /* 滚轮添加选项、设置正常模式 */
//    lv_obj_align(mode_roller, LV_ALIGN_CENTER, -scr_act_width() / 4, 0);                        /* 设置滚轮位置 */
//    lv_obj_set_width(mode_roller, scr_act_width() / 6);                                         /* 设置滚轮宽度 */
//    lv_obj_set_style_text_font(mode_roller, font, LV_STATE_DEFAULT);                            /* 设置滚轮字体 */
//    lv_roller_set_visible_row_count(mode_roller, 3);                                            /* 设置滚轮可见选项个数 */
//    lv_roller_set_selected(mode_roller, 2, LV_ANIM_OFF);                                        /* 设置滚轮当前所选项 */
//    lv_obj_add_event_cb(mode_roller, roller_event_cb, LV_EVENT_VALUE_CHANGED, NULL);            /* 添加事件回调 */
//
//    lv_obj_t *label = lv_label_create(lv_scr_act());                                            /* 创建标签 */
//    lv_label_set_text(label, "MODE");                                                           /* 设置文本内容 */
//    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                                  /* 设置字体 */
//    lv_obj_align_to(label, mode_roller, LV_ALIGN_OUT_TOP_MID, 0, -15 );                         /* 设置位置 */
//}
//
///**
// * @brief  温度设置
// * @param  无
// * @return 无
// */
//static void lv_example_roller2(void)
//{
//    temp_roller = lv_roller_create(lv_scr_act());                                               /* 创建温度设置滚轮 */
//    lv_roller_set_options(temp_roller, temp_options, LV_ROLLER_MODE_NORMAL);                    /* 滚轮添加选项、设置正常模式 */
//    lv_obj_align(temp_roller, LV_ALIGN_CENTER, 0, 0);                                           /* 设置滚轮位置 */
//    lv_obj_set_width(temp_roller, scr_act_width() / 6);                                         /* 设置滚轮宽度 */
//    lv_obj_set_style_text_font(temp_roller, font, LV_STATE_DEFAULT);                            /* 设置滚轮字体 */
//    lv_roller_set_visible_row_count(temp_roller, 3);                                            /* 设置滚轮可见选项个数 */
//    lv_roller_set_selected(temp_roller, 2, LV_ANIM_OFF);                                        /* 设置滚轮当前所选项 */
//
//    lv_obj_t *label = lv_label_create(lv_scr_act());                                            /* 创建标签 */
//    lv_label_set_text(label, "TEMP");                                                           /* 设置文本内容 */
//    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                                  /* 设置字体 */
//    lv_obj_align_to(label, temp_roller, LV_ALIGN_OUT_TOP_MID, 0, -15 );                         /* 设置位置 */
//}
//
///**
// * @brief  湿度设置
// * @param  无
// * @return 无
// */
//static void lv_example_roller3(void)
//{
//    hum_roller = lv_roller_create(lv_scr_act());                                                /* 创建湿度设置滚轮 */
//    lv_roller_set_options(hum_roller, hum_options, LV_ROLLER_MODE_NORMAL);                      /* 滚轮添加选项、设置正常模式 */
//    lv_obj_align(hum_roller, LV_ALIGN_CENTER, scr_act_width() / 4, 0);                          /* 设置滚轮位置 */
//    lv_obj_set_width(hum_roller, scr_act_width() / 6);                                          /* 设置滚轮宽度 */
//    lv_obj_set_style_text_font(hum_roller, font, LV_STATE_DEFAULT);                             /* 设置滚轮字体 */
//    lv_roller_set_visible_row_count(hum_roller, 3);                                             /* 设置滚轮可见选项个数 */
//    lv_roller_set_selected(hum_roller, 2, LV_ANIM_OFF);                                         /* 设置滚轮当前所选项 */
//
//    lv_obj_t *label = lv_label_create(lv_scr_act());                                            /* 创建标签 */
//    lv_label_set_text(label, "HUM");                                                            /* 设置文本内容 */
//    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                                  /* 设置字体 */
//    lv_obj_align_to(label, hum_roller, LV_ALIGN_OUT_TOP_MID, 0, -15 );                          /* 设置位置 */
//}
//
//
///**
// * @brief  LVGL演示
// * @param  无
// * @return 无
// */
//void my_gui(void)
//{
//    lv_example_roller1();               /* 模式设置滚轮 */
//    lv_example_roller2();               /* 温度设置滚轮 */
//    lv_example_roller3();               /* 湿度设置滚轮 */
//}
