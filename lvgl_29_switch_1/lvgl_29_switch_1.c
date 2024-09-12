// lvgl第29讲开关基础知识代码
#include "my_gui.h"
#include "lvgl.h"


static void event_cb(lv_event_t* e);
static lv_obj_t* switch1;

void my_gui(void)
{
    // 创建一个开关
    switch1 = lv_switch_create(lv_scr_act());
    lv_obj_align(switch1, LV_ALIGN_CENTER, 0, 0);
    // 指示器不生效的原因；开关的状态。
    // 开关的状态默认是关闭的，此时主体已经完全覆盖掉指示器了
    // 因此指示器设置了背景颜色是看不出来的。
    // 当我们去切换这开关的状态时，它就不是默认状态了
    // 此时背景颜色就不会生效了。
    // 因为它只会在默认的状态下生效即开关处于关闭的状态下才会生效
//    lv_obj_set_style_bg_color(switch1,
//                              lv_color_hex(0xff0000),
//                              LV_PART_INDICATOR);
    // 开关默认处于关闭状态
    lv_obj_set_style_bg_color(switch1,
                              lv_color_hex(0xff0000),
                              LV_STATE_CHECKED | LV_PART_INDICATOR);
    // 软件级开启开关，不需要手动开启。
    // 此时开关处于打开状态
//    lv_obj_add_state(switch1, LV_STATE_CHECKED | LV_STATE_DISABLED);

//    // 软件级关闭按钮，此时开关处于关闭状态
    lv_obj_clear_state(switch1,
                       LV_STATE_CHECKED | LV_STATE_DISABLED);
    // 获取开关的状态
    lv_obj_add_event_cb(switch1,
                        event_cb,
                        LV_EVENT_VALUE_CHANGED,
                        NULL);

}

static void event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (LV_EVENT_VALUE_CHANGED == code)
    {
        if (lv_obj_has_state(switch1,
                             LV_STATE_CHECKED))
        {
            puts("LED ON");
        }
        else
        {
            puts("LED OFF");
        }
    }
}
