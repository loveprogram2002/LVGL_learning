// lvgl基础对象的设置大小
#include "my_gui.h"
#include "lvgl.h"


void my_gui(void)
{
    // 设置部件的大小
    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
    // 仅设置宽度
    lv_obj_set_width(obj1, 200); 
    // 仅设置高度
    lv_obj_set_height(obj1, 300); 
    // 这个函数本质就是上述这两个函数的共同调用
    // 同时设置高度和宽度
    lv_obj_set_size(obj1, 200, 380); 
}
