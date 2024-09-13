// 圆弧基础知识的后半部分代码
#include "lvgl.h"
#include "my_gui.h"


static void event_cb(lv_event_t* e);

void my_gui(void)
{
    lv_obj_t* arc = lv_arc_create(lv_scr_act());
    lv_obj_center(arc);
    lv_arc_set_value(arc, 80);
    // 设置旋转角度
//    lv_arc_set_rotation(arc, 180);
    lv_obj_add_event_cb(arc, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    // 前景弧的起始角度被固定在中间位置
    lv_arc_set_mode(arc, LV_ARC_MODE_SYMMETRICAL);
    lv_arc_set_change_rate(arc, 90);
    
}


static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);

    printf("%d \n", lv_arc_get_value(target));

}
