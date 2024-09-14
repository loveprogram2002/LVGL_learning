// lvgl第41讲前半部分 线条部件 基础知识
#include "lvgl.h"
#include "my_gui.h"

void event_cb(lv_event_t* e);

static lv_point_t line_points[] = {
    {150, 50}, {250, 200}, {50, 200}, {150, 50}
};


void my_gui(void)
{
    // 默认什么都没有
    lv_obj_t* line = lv_line_create(lv_scr_act());
    // 设置线条坐标点
    lv_line_set_points(line, line_points, 4);
    // 设置线条宽度
    lv_obj_set_style_line_width(line, 7, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(line, true, LV_PART_MAIN);
    // 设置y轴翻转
    lv_line_set_y_invert(line, true);
}

