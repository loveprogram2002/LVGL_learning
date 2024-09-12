// lvgl第35讲后半部分 LED部件例程代码
#include "lvgl.h"
#include <stdio.h>

// 宏定义
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))

static lv_font_t* font;
static lv_obj_t* led1;
static lv_obj_t* led2;
static lv_obj_t* led3;

static void example_label(void);
static void example_led1(void);
static void event_cb(lv_event_t* e);

void my_gui(void)
{
   example_label();
   example_led1();

}

static void example_label(void)
{
    if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_24;
    }
    else
    {
        font = &lv_font_montserrat_32;
    }
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -scr_act_height() / 5);
    lv_label_set_text(label, "Loading...");
}

static void example_led1(void)
{
    led1 = lv_led_create(lv_scr_act());
    lv_obj_center(led1);
    lv_obj_set_size(led1, 60, 60);
    lv_led_set_brightness(led1, 200);
    lv_led_off(led1);
    lv_obj_add_event_cb(led1, event_cb,
                        LV_EVENT_CLICKED,
                        NULL);
    led2 = lv_led_create(lv_scr_act());
    lv_led_set_color(led2, lv_color_hex(0xff0000));
    lv_obj_align(led2, LV_ALIGN_CENTER,
                 -(scr_act_width() / 5), 0);
    lv_obj_set_size(led2, 60, 60);
    lv_led_set_brightness(led2, 200);
    lv_led_off(led2);
    lv_obj_add_event_cb(led2, event_cb,
                        LV_EVENT_CLICKED,
                        NULL);

    led3 = lv_led_create(lv_scr_act());
    lv_led_set_color(led3, lv_color_hex(0x00ff00));
    lv_obj_align(led3, LV_ALIGN_CENTER,
                 +(scr_act_width() / 5), 0);
    lv_obj_set_size(led3, 60, 60);
    lv_led_set_brightness(led3, 200);
    lv_led_off(led3);
    lv_obj_add_event_cb(led3, event_cb,
                        LV_EVENT_CLICKED,
                        NULL);
}

void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    lv_led_toggle(target);
}


//#include "lvgl.h"
//#include <stdio.h>
//
//
///* 获取当前活动屏幕的宽高 */
//#define scr_act_width() lv_obj_get_width(lv_scr_act())
//#define scr_act_height() lv_obj_get_height(lv_scr_act())
//
//static const lv_font_t *font;                   /* 定义字体 */
//static lv_obj_t *obj;                           /* 基础对象 */
//
///**
// * @brief  LED事件回调
// * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
// * @return 无
// */
//static void led_event_cb(lv_event_t* e)
//{
//    lv_obj_t* led = lv_event_get_target(e);     /* 获取触发源 */
//    lv_led_toggle(led);                         /* 翻转LED状态 */
//}
//
///**
// * @brief  LED1
// * @param  无
// * @return 无
// */
//static void lv_example_led_1(void)
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
//    /* 创建基础对象作为背景 */
//    obj = lv_obj_create(lv_scr_act());
//    lv_obj_set_size(obj, scr_act_width() * 5 /6 , scr_act_height() * 3 /5);
//    lv_obj_align(obj, LV_ALIGN_CENTER, 0 , 0);
//    lv_obj_set_style_bg_color(obj, lv_color_hex(0xefefef), LV_STATE_DEFAULT);
//
//    lv_obj_t* led = lv_led_create(obj);                                                     /* 创建LED */
//    lv_obj_set_size(led, scr_act_height() /5 , scr_act_height() /5);                        /* 设置LED大小 */
//    lv_obj_align(led, LV_ALIGN_CENTER, -scr_act_width() * 4/ 15, -scr_act_height() /15);    /* 设置LED位置 */
//    lv_led_off(led);                                                                        /* 关闭LED */
//    lv_obj_add_event_cb(led, led_event_cb, LV_EVENT_CLICKED, NULL);                         /* 设置LED事件回调 */
//
//    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* 创建LED功能标签 */
//    lv_label_set_text(label, "ROOM 1");                                                     /* 设置文本 */
//    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* 设置字体 */
//    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* 设置位置 */
//}
//
///**
// * @brief  LED2
// * @param  无
// * @return 无
// */
//static void lv_example_led_2(void)
//{
//    lv_obj_t* led = lv_led_create(obj);                                                     /* 创建LED */
//    lv_obj_set_size(led, scr_act_height() /5 , scr_act_height() /5);                        /* 设置LED大小 */
//    lv_obj_align(led, LV_ALIGN_CENTER, 0, -scr_act_height() /15);                           /* 设置LED位置 */
//    lv_led_set_color(led, lv_color_hex(0xff0000));                                          /* 设置LED颜色 */
//    lv_led_on(led);                                                                         /* 打开LED */
//    lv_obj_add_event_cb(led, led_event_cb, LV_EVENT_CLICKED, NULL);                         /* 设置LED事件回调 */
//
//    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* 创建LED功能标签 */
//    lv_label_set_text(label, "ROOM 2");                                                     /* 设置文本 */
//    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* 设置字体 */
//    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* 设置位置 */
//}
//
///**
// * @brief  LED3
// * @param  无
// * @return 无
// */
//static void lv_example_led_3(void)
//{
//    lv_obj_t* led = lv_led_create(obj);                                                     /* 创建LED */
//    lv_obj_set_size(led, scr_act_height() /5 , scr_act_height() /5);                        /* 设置LED大小 */
//    lv_obj_align(led, LV_ALIGN_CENTER, scr_act_width() * 4/ 15, -scr_act_height() /15);     /* 设置LED位置 */
//    lv_led_set_color(led, lv_color_hex(0x2fc827));                                          /* 设置LED颜色 */
//    lv_led_off(led);                                                                        /* 关闭LED */
//    lv_obj_add_event_cb(led, led_event_cb, LV_EVENT_CLICKED, NULL);                         /* 设置LED事件回调 */
//
//    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* 创建LED功能标签 */
//    lv_label_set_text(label, "ROOM 3");                                                     /* 设置文本 */
//    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* 设置字体 */
//    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* 设置位置 */
//}
//
///**
// * @brief  LVGL演示
// * @param  无
// * @return 无
// */
//void my_gui(void)
//{
//    lv_example_led_1();         /* LED1 */
//    lv_example_led_2();         /* LED2 */
//    lv_example_led_3();         /* LED3 */
//}
