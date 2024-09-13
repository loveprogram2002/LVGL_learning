// lvgl第37讲后半部分：下拉列表例程代码

#include "lvgl.h"
#include "my_gui.h"

#define BUF 512


lv_font_t* font;
static lv_obj_t* label;
static char buf[BUF] = { 0 };

static void example_dropdown_list(void);

static void event_cb(lv_event_t* e);



void my_gui(void)
{
    example_dropdown_list();
}

static void example_dropdown_list(void)
{
    if (lv_obj_get_width(lv_scr_act()) <= 320)
    {
        font = &lv_font_montserrat_20;
    }
    else
    {
        font = &lv_font_montserrat_24;
    }
    // 显示当前下拉列表选项的文本内容的标签
    label = lv_label_create(lv_scr_act());

    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, lv_color_hex(0x0000ff),
                                LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT,
                 lv_obj_get_width(lv_scr_act()) * 0.1,
                 lv_obj_get_height(lv_scr_act()) * 0.1);
    // 下拉列表
    lv_obj_t* dropdown_list = lv_dropdown_create(lv_scr_act());
    lv_obj_align_to(dropdown_list, label,
                    LV_ALIGN_OUT_BOTTOM_MID, 9,
                    lv_obj_get_height(lv_scr_act()) * 0.1);
    // 设置选项内容
    lv_dropdown_set_options(dropdown_list, "Game\nMath\nEnglish\nProgram");
    lv_dropdown_get_selected_str(dropdown_list, buf, sizeof(buf));
    lv_label_set_text(label, buf);
    lv_obj_add_event_cb(dropdown_list,
                        event_cb,
                        LV_EVENT_VALUE_CHANGED,// 对象的值已更改则触发
                        NULL);
}

static void event_cb(lv_event_t* e)
{
    // 获取触发回调函数的部件
    lv_obj_t* target = lv_event_get_target(e);
    // 获取列表按钮的文本内容
    lv_dropdown_get_selected_str(target, buf, sizeof(buf));
    lv_label_set_text(label, buf);
}

