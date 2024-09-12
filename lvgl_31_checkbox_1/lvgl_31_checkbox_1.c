// lvgl第31讲 复选框部件基础知识的代码
#include "lvgl.h"
#include "my_gui.h"


static void event_cb(lv_event_t* e);
lv_obj_t* checkbox;

void my_gui(void)
{
    // 定义一个复选框
    checkbox = lv_checkbox_create(lv_scr_act());
    lv_obj_center(checkbox);
    // 文本设置
    lv_checkbox_set_text(checkbox, "remember the password");
    lv_obj_set_style_pad_column(checkbox, 25, LV_STATE_DEFAULT);
    // 添加和清除复选框的状态
    // 勾选复选框的状态且不可修改
    lv_obj_add_state(checkbox, LV_STATE_CHECKED | LV_STATE_DISABLED);

    lv_obj_clear_state(checkbox, LV_STATE_CHECKED | LV_STATE_DISABLED);
    lv_obj_add_event_cb(checkbox,
                        event_cb,
                        LV_EVENT_VALUE_CHANGED,
                        NULL);
}

static void event_cb(lv_event_t* e)
{
    // 获取事件类型
    lv_event_code_t code = lv_event_get_code(e);
    // 判断事件类型
    if (LV_EVENT_VALUE_CHANGED == code)
    {
        if (lv_obj_has_state(checkbox, LV_STATE_CHECKED))
        {
            puts("ON");
        }
        else
        {
            puts("OFF");
        }
    }
}
