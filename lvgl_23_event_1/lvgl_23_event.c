// lvgl 23讲 事件
#include "my_gui.h"
#include "lvgl.h"

lv_obj_t* obj1;
lv_obj_t* obj2;

static void my_event_cb(lv_event_t* e);

void my_gui(void)
{
    // 对象1
    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(obj1,
                              lv_color_hex(0xff0000),
                              LV_STATE_DEFAULT);
    lv_obj_center(obj1); // 部件居于活动屏幕的中央
    lv_obj_add_event_cb(obj1,
                        my_event_cb,
                        LV_EVENT_CLICKED,
                        NULL);
    // 对象2
    obj2 = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(obj2,
                              lv_color_hex(0x00ff00),
                              LV_STATE_DEFAULT // 部件处于何种状态下背景颜色生效
                              );
    lv_obj_add_event_cb(obj2,
                    my_event_cb,
                    LV_EVENT_LONG_PRESSED, // 长按部件触发回调函数
                    NULL);
}

// 事件的回调函数
static void my_event_cb(lv_event_t* e)
{
//    // 第一步获取事件类型
//    lv_event_code_t code = lv_event_get_code(e);
//    // 第二步判断事件类型
//    if (LV_EVENT_CLICKED == code)
//    {
//        printf("event clicked\n");
//    }
//    else if (LV_EVENT_LONG_PRESSED == code)
//    {
//        printf("long pressed\n");
//    }
    // 获取触发事件的部件（关键点）
    lv_obj_t* target = lv_event_get_target(e);
    // 判断触发事件的部件
    if (obj1 == target)
    {
        puts("obj1");
    }
    else if (obj2 == target)
    {
        puts("obj2");
    }
}

