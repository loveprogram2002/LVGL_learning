// lvgl第39讲前半部分 滑块基础知识的代码
#include "lvgl.h"
#include "my_gui.h"



static void event_cb(lv_event_t* e);

void my_gui(void)
{
    lv_obj_t* slider = lv_slider_create(lv_scr_act());
    lv_obj_center(slider);
//    lv_obj_set_size(slider, 20, 200);// 纵向显示
    // 默认创建出来的滑块的范围值是0~100
    lv_slider_set_range(slider, -100, 100);
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);
    // 滑块发生变化则调用回调函数
    lv_obj_add_event_cb(slider, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    // 模式设置
    // 总是从零开始绘制
//    lv_slider_set_mode(slider, LV_SLIDER_MODE_SYMMETRICAL);
    // 可以设置左值的模式，两个旋钮
    lv_slider_set_mode(slider, LV_SLIDER_MODE_RANGE);
    lv_slider_set_left_value(slider, -50, LV_ANIM_OFF);




}


static void event_cb(lv_event_t* e)
{
    lv_obj_t* slider = lv_event_get_target(e);

    printf("%d ~ %d\n", lv_slider_get_left_value(slider),
           lv_slider_get_value(slider));

}
