// 标签部件的代码例程
#include "my_gui.h"
#include "lvgl.h"

// 宏定义
// 动态获取活动屏幕的宽度和高度
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))

static const lv_font_t* font;// 字体大小

// 函数原型
static void lv_example_label_left(void);
static void lv_example_label_2(void);
// 设置文本的阴影
static void lv_example_label_3(void);


void my_gui(void)
{
    lv_example_label_left();
    lv_example_label_2();
    lv_example_label_3();
}

static void lv_example_label_left(void)
{
    // 通过确定屏幕的宽度来使用何种字体
    if (scr_act_width() <= 320)
    {
        font = &lv_font_montserrat_10;// 10号字体
    }
    else if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_14;
    }
    else
    {
        font = &lv_font_montserrat_20;
    }
    // 在活动屏幕上创建一个标签部件
    lv_obj_t* label = lv_label_create(lv_scr_act());
    // 设置标签的透明度
    lv_obj_set_style_bg_opa(label, 100, LV_STATE_DEFAULT);
    // 设置标签的背景颜色
    lv_obj_set_style_bg_color(label,
                              lv_color_hex(0xccff99),
                              LV_STATE_DEFAULT);
    // 开启重新着色
    lv_label_set_recolor(label, true);
    // 设置标签的文本内容
    lv_label_set_text(label, "#0000ff Re-color# #ff00ff words# #ff0000 of a# "
                             "label, align the lines to the center"
                             "and  wrap long text automatically.");
     // 设置字体大小
    lv_obj_set_style_text_font(label,
                               font,
                               LV_PART_MAIN);
    // 设置标签部件的宽度为活动屏幕的三分之一
    lv_obj_set_width(label, scr_act_width() / 3);
    // 设置标签部件在活动屏幕中的位置
    lv_obj_align(label, LV_ALIGN_CENTER, -(scr_act_width() / 3), 0);
    // 设置标签部件内的文本对齐方式
    lv_obj_set_style_text_align(label,
                                LV_TEXT_ALIGN_CENTER,// 居中对齐
                                LV_STATE_DEFAULT);
}

static void lv_example_label_2(void)
{
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "It is a circularly scrolling text. ");
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);
    // 长文本模式：循环滚动显示文本
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_width(label, scr_act_width() / 3);
    /* 居中对齐 */
    lv_obj_center(label);
//    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

static void lv_example_label_3(void)
{
    // 主体
    // 创建一个标签部件
    lv_obj_t* label = lv_label_create(lv_scr_act());
    // 设置标签部件的宽度
    lv_obj_set_width(label, scr_act_width() / 3);
    // 设置标签部件在活动屏幕中的位置
    lv_obj_align(label, LV_ALIGN_CENTER, scr_act_width() / 3, 0);
    // 设置标签文本的内容中字体的大小
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);
    // 设置标签的文本内容
    lv_label_set_text_fmt(label,
                          "Label can set text like %s",
                          "printf");
    // 设置文本居中对齐
    lv_obj_set_style_text_align(label,
                                LV_TEXT_ALIGN_CENTER,
                                LV_PART_MAIN);
    // 设置文本的阴影
    // 阴影部件
    lv_obj_t* shadow = lv_label_create(lv_scr_act());
    // 设置阴影部件的宽度
    lv_obj_set_width(shadow, scr_act_width() / 3);
    // 设置字体大小
    lv_obj_set_style_text_font(shadow, font, LV_PART_MAIN);
    // 设置阴影的文本内容
    lv_label_set_text(shadow, lv_label_get_text(label));
    // 设置文本的透明度
    // 第二个参数的值越大则越不透明
    lv_obj_set_style_text_opa(shadow, LV_OPA_50, LV_PART_MAIN);
    // 设置字体的颜色
    lv_obj_set_style_text_color(shadow,
                              lv_color_black(),
                              LV_PART_MAIN);
    // 设置阴影的文本内容居中
    lv_obj_set_style_text_align(shadow,
                                LV_TEXT_ALIGN_CENTER,
                                LV_PART_MAIN);
    // 设置阴影部件与实体部件的偏移位置
    lv_obj_align_to(shadow, label, LV_ALIGN_CENTER, 2, 2);
}
