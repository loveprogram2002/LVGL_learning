// lvgl第35讲前半部分 LED基础知识的代码
#include "lvgl.h"
#include <stdio.h>

void my_gui(void)
{
    // 创建出来的led部件默认是打开状态，亮度为255
    lv_obj_t* led = lv_led_create(lv_scr_act());
    lv_obj_set_size(led, 100, 100);
    lv_obj_center(led);

    lv_led_set_color(led, lv_color_hex(0x00ff00));
    // 设置led部件的亮度：值越大，led亮度越大
    //  lv_led_set_brightness(led, 25);
    // 设置led状态
    lv_led_off(led); // 关闭led
    lv_led_on(led);// 打开led
    // 翻转led的状态
    lv_led_toggle(led);
}
