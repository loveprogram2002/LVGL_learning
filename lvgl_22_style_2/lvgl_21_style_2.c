// 如何单独设置部件中某个部分的样式
#include "my_gui.h"
#include "lvgl.h"


void my_gui(void)
{
//    // 第22讲
//    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
//    lv_obj_set_align(obj1, LV_ALIGN_CENTER);
//    // 设置样式的边框颜色
//    lv_obj_set_style_border_color(obj1,
//                                  lv_color_hex(0x56c94c),
//                                  LV_STATE_DEFAULT);
//    // 设置边框的宽度
//    lv_obj_set_style_border_width(obj1, 10, LV_STATE_DEFAULT);
//    lv_obj_set_style_border_opa(obj1, 150, LV_STATE_DEFAULT);
//    // 设置轮廓
//    // 设置样式的轮廓颜色
//    lv_obj_set_style_outline_color(obj1,
//                                  lv_color_hex(0x0000a0),
//                                  LV_STATE_DEFAULT);
//    // 设置轮廓的宽度
//    lv_obj_set_style_outline_width(obj1, 10, LV_STATE_DEFAULT);
//    // 设置轮廓的透明度：透明值3越大越不透明
//    lv_obj_set_style_outline_opa(obj1, 150, LV_STATE_DEFAULT);

    // 如何单独设置部件中某个部分的样式
    // 创建一个滑块
    lv_obj_t* slider = lv_slider_create(lv_scr_act());
    lv_obj_set_align(slider, LV_ALIGN_CENTER); // 居中对齐
    // 设置样式
    // 若没有指定修改哪一部分，就默认修改主体部分
//    // 修改指示器
//    lv_obj_set_style_bg_color(slider,
//                              lv_color_hex(0xff0000),
//                              LV_PART_INDICATOR);
//    //
//    lv_obj_set_style_bg_color(slider,
//                              lv_color_hex(0x00ff00),
//                              LV_PART_KNOB);
//    // 修改主体的颜色
//    lv_obj_set_style_bg_color(slider,
//                              lv_color_hex(0x0000ff),
//                              LV_PART_MAIN);
    // 指示器
    lv_obj_set_style_bg_color(slider,
                              lv_color_hex(0x49bc40),
                              LV_STATE_DEFAULT | LV_PART_INDICATOR);
    // 手柄
    lv_obj_set_style_bg_color(slider,
                              lv_color_hex(0XFF0000),
                              LV_STATE_DEFAULT | LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider,
                              lv_color_hex(0XFF00FF),
                              LV_STATE_DEFAULT | LV_PART_MAIN);

}
