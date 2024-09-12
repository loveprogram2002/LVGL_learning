#include "my_gui.h"
#include "lvgl.h"


static lv_coord_t scr_act_width;// 活动屏幕的宽度
static lv_coord_t scr_act_height; // 活动屏幕的高度
static lv_obj_t* parent_obj;
static lv_obj_t* child_obj;


static void obj_event_cb(lv_event_t* e);

// 测试样式的各种属性
void my_gui(void)
{
    // 动态获取屏幕大小
    scr_act_width = lv_obj_get_width(lv_scr_act());
    scr_act_height = lv_obj_get_height(lv_scr_act());

    // 创建父对象
    parent_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(parent_obj,
                    scr_act_width / 3 * 2,
                    scr_act_height / 3 * 2);
    lv_obj_set_style_bg_color(parent_obj,
                              lv_color_hex(0x99CCFF),
                              LV_STATE_DEFAULT);
    lv_obj_align(parent_obj, LV_ALIGN_TOP_MID, 0, 0);
    // 添加事件类型
    lv_obj_add_event_cb(parent_obj,
                        obj_event_cb,
                        LV_EVENT_LONG_PRESSED,
                        NULL);
    // 创建子对象
    child_obj = lv_obj_create(parent_obj);
    lv_obj_set_size(child_obj,
                    scr_act_width / 3,
                    scr_act_height / 3);
    lv_obj_center(child_obj);
    lv_obj_set_style_bg_color(child_obj,
                              lv_color_hex(0x003366),
                              LV_STATE_DEFAULT);
    lv_obj_add_event_cb(child_obj,
                    obj_event_cb,
                    LV_EVENT_CLICKED,
                    NULL);
}

static void obj_event_cb(lv_event_t* e)
{
    // 获取事件触发源即触发事件的具体部件
    lv_obj_t* target = lv_event_get_target(e);

    if (target == parent_obj)
    {
        // 重新设置父对象的位置：居中对齐
        lv_obj_center(parent_obj);
    }
    else if (child_obj == target)
    {
        // 重新设置子对象的位置
        lv_obj_align(child_obj, LV_ALIGN_RIGHT_MID, 100, 0);
    }
}







