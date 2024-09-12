// lvgl第34讲 加载器基础知识的代码
#include "lvgl.h"
#include <stdio.h>

void my_gui(void)
{
    // 第二个参数表示指示器旋转一周所需要的时间
    lv_obj_t* spinner = lv_spinner_create(lv_scr_act(), 1000, 60);
    lv_obj_center(spinner);
    // 设置加载器的颜色
    lv_obj_set_style_arc_color(spinner,
                               lv_color_hex(0x00ff00),
                               LV_PART_MAIN ); 	   /* 设置主体圆弧颜色 */
    lv_obj_set_style_arc_color(spinner,
                               lv_color_hex(0xff0000),
                               LV_PART_INDICATOR );   /* 设置指示器圆弧颜色 */
    // 设置加载器的宽度
    lv_obj_set_style_arc_width( spinner, 10, LV_PART_MAIN );					    /* 设置主体圆弧宽度 */
    lv_obj_set_style_arc_width( spinner, 10, LV_PART_INDICATOR );				    /* 设置指示器圆弧宽度 */
}
