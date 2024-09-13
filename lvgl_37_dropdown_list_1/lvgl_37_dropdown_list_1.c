// lvgl第37讲前半部分：下拉列表基础知识代码讲解

#include "lvgl.h"
#include "my_gui.h"


static void event_cb(lv_event_t* e);

void my_gui(void)
{
    // 基础知识
    lv_obj_t* dd = lv_dropdown_create(lv_scr_act());
    lv_obj_center(dd);
    // 设置选项内容
    lv_dropdown_set_options(dd, "a\nb\nc\nd");
//    lv_dropdown_set_options_static(dd, "a\nb\nc\nd");
    lv_dropdown_add_option(dd, "e", 4);
    // 设置当前选项即下拉列表默认显示哪个选项
    lv_dropdown_set_selected(dd, 2);
    // 通过回调函数测试：获取选项内容
    lv_obj_add_event_cb(dd, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    // 设置方向和图标
    lv_dropdown_set_dir(dd, LV_DIR_TOP);				/* 设置列表展开方向 */
    lv_dropdown_set_symbol(dd, LV_SYMBOL_UP);			/* 设置图标 */

}

static void event_cb(lv_event_t* e)
{
    // 获取触发回调函数的部件
    lv_obj_t* target = lv_event_get_target(e);
    // 获取选项的索引
    printf("%d ", lv_dropdown_get_selected(target));
    char buf[10] = { 0 };
    // 获取选项文本
    lv_dropdown_get_selected_str(target, buf, sizeof(buf));
    printf("%s\n", buf);
}

