// lvgl第40讲 圆弧基础知识的代码
#include "lvgl.h"
#include "my_gui.h"

void my_gui(void)
{
    lv_obj_t* arc =  lv_arc_create(lv_scr_act());
    lv_obj_center(arc);

    // 设置范围值
    lv_arc_set_range(arc, 0, 200);
//    lv_arc_set_value(arc, 80);

    // 出现问题：背景弧的起始角度是135，因此超出了前景弧的起始角度
    // 当修改当前值时，lvgl就会强制把前景弧这个起始角度修改为和背景弧起始角度
    // 一致的
    lv_arc_set_bg_angles(arc, 90, 45);// 设置背景弧角度
    lv_arc_set_angles(arc, 90, 360);// 设置前景弧角度
    // 注意：背景弧角度设置必须放在前景弧角度之前
    // 前景弧角度设置的范围必须包含在背景弧角度设置的范围内
}

