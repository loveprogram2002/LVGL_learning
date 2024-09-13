// lvgl第38讲前半部分：滚轮部件基础知识

#include "lvgl.h"
#include "my_gui.h"

#define BUF 512


static char buf[BUF] = { 0 };

static void event_cb(lv_event_t* e);


void my_gui(void)
{
    lv_obj_t* roller = lv_roller_create(lv_scr_act());
    lv_obj_center(roller);
    // 设置选线间隔
    lv_obj_set_style_text_line_space(roller, 10, LV_STATE_DEFAULT);
    // 设置选项内容和模式
    // 正常模式
    lv_roller_set_options(roller, "a\nb\nc\nd", LV_ROLLER_MODE_NORMAL);
    // 无限循环模式：占用内存较大
//    lv_roller_set_options(roller, "a\nb\nc\nd", LV_ROLLER_MODE_INFINITE);
    // 设置当前所选项
    lv_roller_set_selected(roller, 2, LV_ANIM_ON);
    // 设置可见行数
//    // 注意：在lvgl中，默认的可见行数是不确定的，它依赖于滚轮的字体、样式等
//    lv_roller_set_visible_row_count(roller, 2);
    // 获取选项内容
    lv_obj_add_event_cb(roller, event_cb, LV_EVENT_VALUE_CHANGED, NULL);

}


static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    // 获取选项的文本内容
    char buf[BUF] = { 0 };
    lv_roller_get_selected_str(target, buf, sizeof(buf));
    // 打印选项和对应的文本内容
    printf("%d %s\n", lv_roller_get_selected(target), buf);
}
