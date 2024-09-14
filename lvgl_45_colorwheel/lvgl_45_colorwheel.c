// lvgl第45讲 色环部件
#include "lvgl.h"
#include "my_gui.h"

lv_obj_t* obj;
static void event_cb(lv_event_t* e);

void my_gui(void)
{
    obj = lv_obj_create(lv_scr_act());
    lv_obj_center(obj);
    lv_obj_set_style_radius(obj, 300, LV_PART_MAIN);

    lv_obj_t* cw = lv_colorwheel_create(lv_scr_act(), true);
    lv_obj_center(cw);
    lv_obj_set_style_arc_width(cw, 20, LV_PART_MAIN);

    // 设置当前选中颜色
    lv_colorwheel_set_rgb(cw, lv_color_hex(0xff00000));
    lv_obj_set_style_bg_color(obj,
                              lv_colorwheel_get_rgb(cw),
                              LV_PART_MAIN);

    lv_obj_add_event_cb(cw, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    // 饱和度越低越接近白色
    // 明度越低越接近黑色
    // 当长按旋钮时，有概率会导致模式发生切换
    lv_colorwheel_set_mode(cw, LV_COLORWHEEL_MODE_VALUE);
    lv_colorwheel_set_mode_fixed(cw, true);// 规定色环模式



}


static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    lv_obj_set_style_bg_color(obj,
                              lv_colorwheel_get_rgb(target),
                              LV_PART_MAIN);


}
