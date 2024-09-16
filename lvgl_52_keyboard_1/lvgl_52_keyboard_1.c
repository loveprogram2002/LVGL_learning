// lvgl第52讲 键盘部件 基础知识
#include "lvgl.h"
#include "my_gui.h"


void my_gui(void)
{
    lv_obj_t* kb = lv_keyboard_create(lv_scr_act());
    // 创建文本框
    lv_obj_t* ta = lv_textarea_create(lv_scr_act());
    lv_keyboard_set_textarea(kb, ta);
    // 设置按键的弹窗
    lv_keyboard_set_popovers(kb, true);
    // 设置键盘的模式
    lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);

}
