// lvgl第51讲 文本区域 例程代码
#include "lvgl.h"
#include "my_gui.h"

// 宏
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))
#define HAREATEXT_LENGTH 3
lv_font_t* font;

lv_obj_t* keyboard;
lv_obj_t* account_label;
lv_obj_t* password_label;


static void password_event_cb(lv_event_t* e);
static void account_event_cb(lv_event_t* e);
static void example_textarea(void);

void my_gui(void)
{
    example_textarea();
}

static void example_textarea(void)
{
    if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_20;
    }
    else
    {
        font = &lv_font_montserrat_30;
    }
    // 创建一个键盘
    keyboard = lv_keyboard_create(lv_scr_act());
    // 创建账号文本区域部件
    lv_obj_t* account_textarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(account_textarea,
                    scr_act_width() / 2, 0);
    lv_obj_align(account_textarea,
                 LV_ALIGN_CENTER, 0,
                 -scr_act_height() / 3);
    lv_obj_set_style_text_font(account_textarea, font, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(account_textarea,
                                LV_TEXT_ALIGN_CENTER,
                                LV_STATE_DEFAULT);
    lv_textarea_set_one_line(account_textarea, true);// 设置单行
    lv_textarea_set_max_length(account_textarea, HAREATEXT_LENGTH);// 限制账号的长度
    lv_textarea_set_placeholder_text(account_textarea, "account");
    lv_obj_set_style_text_font(account_textarea,
                               font,
                               LV_STATE_DEFAULT);
    lv_obj_add_event_cb(account_textarea,
                        account_event_cb,
                        LV_EVENT_ALL, NULL);

    // 用户名输入正误提示标签
    account_label = lv_label_create(lv_scr_act());
    lv_label_set_text(account_label, "");
    lv_obj_align_to(account_label, account_textarea,
                     LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_set_style_text_font(account_label,
                               font,
                               LV_STATE_DEFAULT);
    // 创建密码文本区域部件
    lv_obj_t* password_textarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(password_textarea,
                    scr_act_width() / 2, 0);
    lv_obj_align_to(password_textarea, account_textarea,
                 LV_ALIGN_OUT_BOTTOM_MID, 0, 15);
    lv_obj_set_style_text_font(password_textarea,
                               font,
                               LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(password_textarea,// 文本居中对齐
                                LV_TEXT_ALIGN_CENTER,
                                LV_STATE_DEFAULT);
    lv_textarea_set_one_line(password_textarea, true);// 设置单行
    lv_textarea_set_password_mode(password_textarea, true);// 密码模式
    lv_textarea_set_password_show_time(password_textarea, 500);// 设置密码显示时间
    lv_textarea_set_max_length(password_textarea, HAREATEXT_LENGTH);// 限制密码的长度
    lv_textarea_set_placeholder_text(password_textarea, "password");
    lv_obj_set_style_text_font(password_textarea,
                               font,
                               LV_STATE_DEFAULT);
    lv_obj_add_event_cb(password_textarea,
                        password_event_cb,
                        LV_EVENT_ALL,
                        NULL);
    // 密码输入正误提示标签
    password_label = lv_label_create(lv_scr_act());
    lv_label_set_text(password_label, "");
    lv_obj_align_to(password_label, password_textarea,
                     LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_add_event_cb(password_label,
                        password_event_cb,
                        LV_EVENT_ALL, NULL);
    lv_obj_set_style_text_font(password_label,
                           font,
                           LV_STATE_DEFAULT);
}


static void password_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);

    if (LV_EVENT_FOCUSED == code)// 
    {
        lv_keyboard_set_textarea(keyboard, target);
    }
    else if (LV_EVENT_VALUE_CHANGED == code)
    {
        const char* password_input = lv_textarea_get_text(target);
        if (0 == strncmp(password_input, "123", strlen("123")))
        {
            puts("password right");
            lv_label_set_text(password_label, LV_SYMBOL_OK);
        }
        else
        {
             lv_label_set_text(password_label, LV_SYMBOL_CLOSE);
        }
    }
}

static void account_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);

    if (LV_EVENT_FOCUSED == code)
    {
        lv_keyboard_set_textarea(keyboard, target);
    }
    else if (LV_EVENT_VALUE_CHANGED == code)
    {
        const char* account_input = lv_textarea_get_text(target);
        if (0 == strncmp(account_input, "123", strlen("123")))
        {
            puts("account pass");
            lv_label_set_text(account_label, LV_SYMBOL_OK);
        }
        else
        {
             lv_label_set_text(account_label, LV_SYMBOL_CLOSE);
        }
    }
}

