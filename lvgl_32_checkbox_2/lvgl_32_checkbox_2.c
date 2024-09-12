// lvgl第32讲 复选框部件的例程
#include "lvgl.h"
#include "my_gui.h"

// 宏定义
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))


static lv_font_t* font; // 字体大小
static lv_obj_t* checkbox_chicken;
static lv_obj_t* checkbox_duck;
static lv_obj_t* checkbox_fish;
static lv_obj_t* checkbox_lamb;
static lv_obj_t* label_cost_val; // 计价标签部件
static int cost_val = 0;

// 函数原型
static void lv_example_label(void);
static void lv_example_checkbox(void);
static void event_cb(lv_event_t* e);

void my_gui(void)
{
    lv_example_label();
    lv_example_checkbox();
}


static void lv_example_label(void)
{
    // 设置字体大小
    if (scr_act_width() <= 320)
    {
        font = &lv_font_montserrat_10;
    }
    else if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_14;
    }
    else
    {
        font = &lv_font_montserrat_20;
    }
    // 菜单标签（在上面）
    lv_obj_t* label_menu = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(label_menu,
                               font, LV_PART_MAIN);
    lv_obj_set_style_text_color(label_menu,
                                lv_color_hex(0xff0000),
                                LV_STATE_DEFAULT);
    lv_label_set_text(label_menu, "Menu");
    lv_obj_align(label_menu, LV_ALIGN_TOP_MID, 0, 30);
    // 计价标签（在下面）
    label_cost_val = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(label_cost_val,
                               font, LV_PART_MAIN);
    lv_obj_align(label_cost_val, LV_ALIGN_BOTTOM_MID, 0, -30);
    lv_label_set_text(label_cost_val, "Aggregate: $0");
}


static void lv_example_checkbox(void)
{
    // 创建一个矩形框
    lv_obj_t* parent_rect = lv_obj_create(lv_scr_act());
    lv_obj_set_size(parent_rect,
                    scr_act_width() / 3 * 2,
                    scr_act_height() / 3 * 2);
    lv_obj_center(parent_rect);

    // 创建4个复选框
    // 烤鸡复选框
    checkbox_chicken = lv_checkbox_create(parent_rect);
    lv_checkbox_set_text(checkbox_chicken,
                         "Roast chicken   $19");
    lv_obj_set_style_y(checkbox_chicken, 30, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(checkbox_chicken,
                                20,
                                LV_STATE_DEFAULT);
    lv_obj_add_event_cb(checkbox_chicken,
                     event_cb,
                     LV_EVENT_VALUE_CHANGED,
                     NULL);
    // 烤鸭复选框
    checkbox_duck = lv_checkbox_create(parent_rect);
    lv_checkbox_set_text(checkbox_duck,
                     "Roast duck  $29");
    lv_obj_align_to(checkbox_duck,
                 checkbox_chicken,
                 LV_ALIGN_OUT_BOTTOM_LEFT,
                 0, 50);
    lv_obj_set_style_pad_column(checkbox_duck,
                            20,
                            LV_STATE_DEFAULT);
    lv_obj_add_event_cb(checkbox_duck,
                     event_cb,
                     LV_EVENT_VALUE_CHANGED,
                     NULL);
    // 接下来的两个复选框不可被选中
    // 烤鱼复选框
    checkbox_fish = lv_checkbox_create(parent_rect);
    lv_checkbox_set_text(checkbox_fish,
                     "Roast fish  $39");
    lv_obj_align_to(checkbox_fish,
                 checkbox_duck,
                 LV_ALIGN_OUT_BOTTOM_LEFT,
                 0, 50);
    lv_obj_set_style_pad_column(checkbox_fish,
                            20,
                            LV_STATE_DEFAULT);
    lv_obj_add_state(checkbox_fish, // 禁用复选框
                       LV_STATE_DISABLED );

     // 烤羊复选框
    checkbox_lamb = lv_checkbox_create(parent_rect);
    lv_checkbox_set_text(checkbox_lamb,
                     "Roast lamb  $39");
    lv_obj_align_to(checkbox_lamb,
                 checkbox_fish,
                 LV_ALIGN_OUT_BOTTOM_LEFT,
                 0, 50);
    lv_obj_set_style_pad_column(checkbox_lamb,
                            20,
                            LV_STATE_DEFAULT);
    lv_obj_add_state(checkbox_lamb, // 禁用复选框
                       LV_STATE_DISABLED );
}

static void event_cb(lv_event_t* e)
{
    // 获取事件来自哪个部件
    lv_obj_t* target = lv_event_get_target(e);
    // 判断是哪个部件
    if (checkbox_chicken == target)
    {
       (lv_obj_has_state(checkbox_chicken, LV_STATE_CHECKED)) ? (cost_val += 19) : (cost_val -= 19);
    }
    else if (checkbox_duck == target)
    {
        (lv_obj_has_state(checkbox_duck, LV_STATE_CHECKED)) ? (cost_val += 29) : (cost_val -= 29);
    }

    lv_label_set_text_fmt(label_cost_val,
                          "Aggregate: $%d", cost_val);
}
