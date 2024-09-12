// lvgl第27讲 开关部件基础知识讲解
#include "my_gui.h"
#include "lvgl.h"

// 按钮部件
static void  event_cb(lv_event_t* e);

void my_gui(void)
{
    lv_obj_t* btn = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn, 100, 50);
    lv_obj_set_align(btn, LV_ALIGN_CENTER);
//    lv_obj_set_style_bg_color(btn,
//                              lv_color_hex(0xde4d3e),
//                              LV_STATE_PRESSED);
    /* 开启状态切换 */
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    // LV_EVENT_VALUE_CHANGED含义：当部件的值发生变化时，才会触发
    // 对于按钮而言，如果需要检测按钮这个部件的值是否发生变化
    // 那么就需要开启这个状态的切换
    /* 添加事件 */
    lv_obj_add_event_cb( btn, event_cb,
                        LV_EVENT_VALUE_CHANGED,
                        NULL);
}

static void event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    // 点击按钮则打印
    if (LV_EVENT_VALUE_CHANGED == code)
    {
        puts("LV_EVENT_VALUE_CHANGED");
    }
}
