// 第16讲 基础对象 简介1
// 介绍基本的API
#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
   // 以活动屏幕为父对象创建一个开关
   lv_obj_t* switch1 = lv_switch_create(lv_scr_act());
   // 设置开关的宽度和高度
   lv_obj_set_size(switch1, 200, 100);
   // 以第一个开关为父对象创建第二个开关
   lv_obj_t* switch2 = lv_switch_create(switch1);
}
