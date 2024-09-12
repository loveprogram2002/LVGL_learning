// lvgl第33讲前半部分 进度条基础知识讲解
#include "lvgl.h"
#include "my_gui.h"


void my_gui(void)
{
    lv_obj_t* bar = lv_bar_create(lv_scr_act());

    lv_obj_center(bar);// 位置居中
    lv_obj_set_size(bar, 400, 20); // 横向显示
    // 设置进度条的范围：最低为-100，最高为100
    lv_bar_set_range(bar, -100, 100);
    // 设置动画时间必须在设置进度条的值前面
    // 第二个参数表示从当前值过渡到-50需要的时间
    lv_obj_set_style_anim_time(bar, 1000, LV_STATE_DEFAULT);
    // 设置进度条的值表示的是进度条从默认初始值走向最终显示的值
    lv_bar_set_value(bar, -50, LV_ANIM_ON);
    // 拓展知识
    /* 设置模式 */
    lv_bar_set_mode(bar, LV_BAR_MODE_RANGE );
    /* 设置起始值 */
    lv_bar_set_start_value(bar, -50, LV_ANIM_ON);
}
