// lvgl第39讲后半部分 滑块部件的例程代码

#include "lvgl.h"
#include "my_gui.h"


lv_font_t* font;
lv_obj_t* percent_label;
void example_slider(void);
void event_cb(lv_event_t* e);

void my_gui(void)
{
   example_slider();
}


void example_slider(void)
{
    if (lv_obj_get_width(lv_scr_act()))
    {
        font = &lv_font_montserrat_18;
    }
    else
    {
        font = &lv_font_montserrat_20;
    }
    // 创建滑块
    lv_obj_t* slider = lv_slider_create(lv_scr_act());
    lv_obj_center(slider);
    lv_obj_set_size(slider, 300, 15);
    lv_obj_add_event_cb(slider, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    // 创建音量标签
    lv_obj_t* music_label = lv_label_create(lv_scr_act());
    lv_obj_align_to(music_label, slider, LV_ALIGN_OUT_LEFT_MID, -10, 0);
    lv_label_set_text(music_label, LV_SYMBOL_VOLUME_MAX);

    // 创建百分比标签
    percent_label = lv_label_create(lv_scr_act());
    lv_obj_align_to(percent_label, slider, LV_ALIGN_OUT_RIGHT_MID, +10, 0);
    lv_label_set_text(percent_label, "0 %");
}

void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if (LV_EVENT_VALUE_CHANGED == code)
    {
        lv_label_set_text_fmt(percent_label, "%d %%",
                              lv_slider_get_value(target));
    }
}
