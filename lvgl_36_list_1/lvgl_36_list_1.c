// lvgl第36讲前半部分 列表基础知识的代码
#include "lvgl.h"
#include <stdio.h>


static lv_obj_t* list;
static void event_cb(lv_event_t* e);

void my_gui(void)
{
    // 创建列表
    list = lv_list_create(lv_scr_act());
    lv_obj_set_size(list, 200, 400);
    lv_obj_center(list);
    // 添加列表文本
    lv_list_add_text(list, "Settings");
    // 添加列表按钮
    lv_obj_t* btn1 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WLAN");
    lv_obj_t* btn2 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WLAN");
    lv_obj_t* btn3 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WLAN");
    lv_obj_t* btn4 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WLAN");
    lv_obj_t* btn5 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WLAN");

    lv_obj_add_event_cb(btn1, event_cb, LV_EVENT_CLICKED, NULL);

}

static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    // 获取列表的按钮文本
    printf("%s\n", lv_list_get_btn_text(list, target));
}



