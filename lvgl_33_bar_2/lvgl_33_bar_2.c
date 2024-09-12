// lvgl 第33讲后半部分 进度条例程讲解
#include "lvgl.h"
#include <stdio.h>

// 宏
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))

static lv_font_t* font;
static int32_t val = 0; // 进度值

static lv_obj_t* bar;
static lv_obj_t* label_bar;// 显示当前进度条的百分比

// 显示加载标签
static void lv_example_label(void);
// 显示当前打印进度值
static void lv_example_bar(void);
// 定时器回调函数
static void timer_cb(lv_timer_t* timer);

void my_gui(void)
{
    lv_example_label();
    lv_example_bar();
}

static void lv_example_label(void)
{
    if (scr_act_width() <= 320)
    {
        font = &lv_font_montserrat_18;
    }
    else if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_26;
    }
    else
    {
        font = &lv_font_montserrat_30;
    }
    // 加载标签
    lv_obj_t* label_load = lv_label_create(lv_scr_act());
    lv_obj_align(label_load, LV_ALIGN_CENTER,
                 0, -(scr_act_height() / 5));
    lv_obj_set_style_text_font(label_load,
                               font, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_load,
                                lv_color_hex(0xff0000),
                                LV_PART_MAIN);
    lv_label_set_text(label_load, "Loading......");

    // 显示当前进度条的标签
    label_bar = lv_label_create(lv_scr_act());
    lv_obj_align(label_bar, LV_ALIGN_CENTER,
                 0, +(scr_act_height() / 5));
    lv_obj_set_style_text_font(label_bar,
                               font,
                               LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_bar,
                                lv_color_hex(0x00ff00),
                                LV_PART_MAIN);
    lv_label_set_text(label_bar, "0 %");
}

static void lv_example_bar(void)
{
    // 进度条
    bar = lv_bar_create(lv_scr_act());
    lv_obj_center(bar);
    lv_obj_set_size(bar, 400, 20);
    lv_obj_set_style_anim_time(bar, 500, LV_ANIM_ON);
    // 创建一个定时器：每隔100毫秒触发回调函数
    lv_timer_create(timer_cb, 100, NULL);
}

static void timer_cb(lv_timer_t* timer)
{
    if (val < 100)
    {
        lv_bar_set_value(bar, val, LV_ANIM_ON);
        lv_label_set_text_fmt(label_bar, "%d %%",
                              lv_bar_get_value(bar));
//        printf("%d\n", lv_bar_get_value(bar));
        val++;
    }
    else
    {
        lv_label_set_text(label_bar, "finished!");
    }
}
