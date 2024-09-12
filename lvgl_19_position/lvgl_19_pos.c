#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
    // 注意设置部件位置时，坐标原点在父对象的左上角
    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_x(obj1, 100);
    lv_obj_set_y(obj1, 300);
    // 同时设置x轴和y轴坐标前面设置的被覆盖了
    lv_obj_set_pos(obj1, 350, 150);
}

