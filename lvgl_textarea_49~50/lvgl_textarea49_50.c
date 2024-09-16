// lvgl第49与50讲 文本区域部件
#include "lvgl.h"
#include "my_gui.h"

static void event_cb(lv_event_t* e);

void my_gui(void)
{
    lv_obj_t* ta = lv_textarea_create(lv_scr_act());
//    lv_obj_center(ta);
//    // 添加一个字符
//    lv_textarea_add_char(ta, 'A');
//    // 添加一个字符串
//    lv_textarea_add_text(ta, "BCDEFdsafasfasdfasdfasdfasdfasdfas");
    // 设置键盘输入
    lv_obj_t *keyboard = lv_keyboard_create(lv_scr_act());/* 创建键盘部件 */
    lv_keyboard_set_textarea(keyboard, ta);			/* 关联键盘和文本区域部件 */
    // 设置光标位置
    // 文本的最左侧
//    lv_textarea_set_cursor_pos(ta, 0);
    // 文本的最右侧
//    lv_textarea_set_cursor_pos(ta, LV_TEXTAREA_CURSOR_LAST);
//    lv_textarea_set_cursor_pos(ta, 2);
//    lv_textarea_del_char(ta);
//    lv_textarea_del_char_forward(ta);
////    // 设置单行模式。注意点击enter键不换行
//    lv_textarea_set_one_line(ta, true);
//    // 设置密码模式
//    lv_textarea_set_password_mode(ta, true);
//    // 设置密码显示
//    // 默认情况下是1.5秒的
//    lv_textarea_set_password_show_time(ta, 100);
//    // 限制接受的字符
//    lv_textarea_set_accepted_chars(ta, "0123456789");
//    // 限制字符长度
//    lv_textarea_set_max_length(ta, 6);
    // 设置占位符
    lv_textarea_set_placeholder_text(ta, "password");
    
    lv_obj_add_event_cb(ta, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    // 获取文本内容
    const char* txt = lv_textarea_get_text(target);
    if (0 == strcmp(txt, "123456"))
    {
        printf("pass\n", txt);
    }
}

