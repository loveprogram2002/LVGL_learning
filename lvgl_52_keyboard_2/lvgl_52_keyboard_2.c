// lvgl第52讲 键盘部件后半部分 例程代码
// 将当前的键盘模式切换为数字模式
#include "lvgl.h"
#include "my_gui.h"

#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))


void event_cb(lv_event_t* e);
void example_keyboard(void);

void my_gui(void)
{
    example_keyboard();
}


void example_keyboard(void)
{
    lv_obj_t* kb = lv_keyboard_create(lv_scr_act());

    lv_obj_t* ta = lv_textarea_create(lv_scr_act());
    lv_obj_align(ta, LV_ALIGN_CENTER,
                 0, -scr_act_height() / 5);
    lv_keyboard_set_textarea(kb, ta);
    lv_obj_set_style_text_font(ta,
                               &lv_font_montserrat_30,
                               LV_STATE_DEFAULT);
    lv_obj_add_event_cb(kb, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}


void event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    uint16_t id = 0;

    if (LV_EVENT_VALUE_CHANGED == code)
    {
        // 获取id
        id = lv_btnmatrix_get_selected_btn(target);
        // 获取文本
        const char* txt = lv_btnmatrix_get_btn_text(target, id);
        if (0 == strcmp(txt, LV_SYMBOL_KEYBOARD))
        {
            if (LV_KEYBOARD_MODE_NUMBER == lv_keyboard_get_mode(target))
            {
                // 如果当前模式为数字模式则切换为小写字母模式
                lv_keyboard_set_mode(target,
                                     LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            else
            {
                lv_keyboard_set_mode(target,
                                     LV_KEYBOARD_MODE_NUMBER);
            }
        }
    }
}

