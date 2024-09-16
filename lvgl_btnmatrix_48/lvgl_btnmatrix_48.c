// lvgl第48讲 按钮矩阵 例程代码
#include "lvgl.h"
#include "my_gui.h"

// 宏定义
#define scr_act_width() ( lv_obj_get_width(lv_scr_act()) )
#define scr_act_height() ( lv_obj_get_height(lv_scr_act()) )


LV_IMG_DECLARE(img_user);
lv_font_t* font;
lv_obj_t* my_img_user;
lv_obj_t* label_input;
static int zoom_value;

static void example_img_user(void);
static void event_cb(lv_event_t* e);

/* 按钮矩阵数组 */
static const char *num_map[] = { "1", "2", "3", "\n",
                                 "4", "5", "6", "\n",
                                 "7", "8", "9", "\n",
                                 "#", "0", "%", "" };

void my_gui(void)
{
    example_img_user();
}


static void example_img_user(void)
{
    if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_18;
        zoom_value = 128; // 缩小为原来的一半
    }
    else
    {
        font = &lv_font_montserrat_24;
        zoom_value = 256; // 大小保持不变
    }
    // 创建图像
    my_img_user = lv_img_create(lv_scr_act());
    lv_img_set_zoom(my_img_user, zoom_value);// 缩放图片
    lv_img_set_src(my_img_user, &img_user);	/* 设置图片源 */
    lv_obj_align(my_img_user, LV_ALIGN_CENTER,
                 -scr_act_width() / 4,
                 -scr_act_height() / 5);
    lv_obj_set_style_opa(my_img_user, 100, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(my_img_user,
                              lv_color_hex(0xf2f2f2),
                              LV_STATE_DEFAULT);
    // 用户标签
    lv_obj_t* label_user = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_user, my_img_user,
                    LV_ALIGN_OUT_BOTTOM_LEFT, 5, 10);
    lv_label_set_text(label_user, "USER");
    lv_obj_set_style_text_font(label_user, font, LV_STATE_DEFAULT);
    // 输入框背景
    lv_obj_t* obj_input = lv_obj_create(lv_scr_act());
    lv_obj_align_to(obj_input, label_user,
                    LV_ALIGN_OUT_BOTTOM_MID,
                    -scr_act_width() / 22,
                    scr_act_height() / 48);
    lv_obj_set_size(obj_input, scr_act_width() / 4,
                    scr_act_width() / 18);
    lv_obj_set_style_border_width(obj_input, 0 , 0);// 去除边框背景
    lv_obj_set_style_radius(obj_input, 20, LV_STATE_DEFAULT);// 设置圆角半径
    lv_obj_remove_style(obj_input, NULL, LV_PART_SCROLLBAR);// 移除滚动条
    // 输入标签
    label_input = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_input, obj_input,
                    LV_ALIGN_CENTER, 0, -6);
    lv_obj_set_style_text_font(label_input, font, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(label_input,
                                LV_TEXT_ALIGN_CENTER,
                                LV_STATE_DEFAULT);
    lv_label_set_text(label_input, " ");
    // 设置分割线
    lv_obj_t* line = lv_line_create(lv_scr_act());
    static lv_point_t line_points[] = { {400, 300}, {400, 100} };
    lv_line_set_points(line, line_points, 2);
    // 设置矩阵按钮
    lv_obj_t* btnm = lv_btnmatrix_create(lv_scr_act());
    lv_obj_set_size(btnm, scr_act_width() / 5 * 2,
                    scr_act_height() / 5 * 3);
    lv_btnmatrix_set_map(btnm, num_map);
    lv_obj_align_to(btnm, line,
                        LV_ALIGN_OUT_RIGHT_MID, 50, 30);
    // 设置按钮矩阵内部的文本字体大小
    lv_obj_set_style_text_font(btnm, font, LV_STATE_DEFAULT);
    // 优化矩阵按钮
    // 按钮互斥
    lv_btnmatrix_set_btn_ctrl_all(btnm, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_one_checked(btnm, true);
    // 去除边框背景
    lv_obj_set_style_border_width(btnm, 0, LV_STATE_DEFAULT);
    // 去除透明度
    lv_obj_set_style_bg_opa(btnm, 0, LV_PART_MAIN);                                             /* 设置主体背景透明度 */
    lv_obj_set_style_bg_opa(btnm, 0, LV_PART_ITEMS);
    // 去除按钮影印的效果
    lv_obj_set_style_shadow_width(btnm, 0, LV_PART_ITEMS);
    lv_obj_add_event_cb(btnm, event_cb,
                    LV_EVENT_VALUE_CHANGED, NULL);
}


static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        int text_id = lv_btnmatrix_get_selected_btn(target);
        const char* input_text = lv_btnmatrix_get_btn_text(target, text_id);
        lv_label_set_text(label_input, input_text);
    }
}



//#include "lvgl.h"
//#include <stdio.h>
//
//
///* 获取当前活动屏幕的宽高 */
//#define scr_act_width()  lv_obj_get_width(lv_scr_act())
//#define scr_act_height() lv_obj_get_height(lv_scr_act())
//
///* 按钮矩阵数组 */
//static const char *num_map[] = { "1", "2", "3", "\n",
//                                 "4", "5", "6", "\n",
//                                 "7", "8", "9", "\n",
//                                 "#", "0", "%", "" };
//
//static uint16_t zoom_val;                           /* 图片缩放系数 */
//static lv_point_t points[] = {{0,0},{0,200}};       /* 线条坐标点数组 */
//
//static const lv_font_t *font;                       /* 定义字体 */
//static lv_obj_t *label_input;                       /* 输入框标签 */
//static lv_obj_t *obj_input;                         /* 输入框背景 */
//
//LV_IMG_DECLARE(img_user);                           /* 声明图片 */
//
///**
// * @brief  按钮矩阵事件回调
// * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
// * @return 无
// */
//static void btnm_event_cb(lv_event_t* e)
//{
//    uint8_t id;
//
//    lv_event_code_t code = lv_event_get_code(e);                                /* 获取事件类型 */
//    lv_obj_t *target = lv_event_get_target(e);                                  /* 获取触发源 */
//
//    if (code == LV_EVENT_VALUE_CHANGED)
//    {
//        id = lv_btnmatrix_get_selected_btn(target);                             /* 获取按键索引 */
//        lv_label_set_text(label_input, lv_btnmatrix_get_btn_text(target, id));  /* 更新输入框标签文本 */
//        lv_obj_align_to(label_input, obj_input, LV_ALIGN_CENTER, 0, 0);         /* 设置标签位置 */
//    }
//}
//
///**
// * @brief  密码输入界面
// * @param  无
// * @return 无
// */
//static void lv_example_btnmatrix(void)
//{
//
//    /* 根据屏幕宽度选择字体和图片缩放系数 */
//    if (scr_act_width() <= 480)
//    {
//        font = &lv_font_montserrat_14;
//        zoom_val = 128;
//    }
//    else
//    {
//        font = &lv_font_montserrat_30;
//        zoom_val = 256;
//    }
//
//    /* 图片显示 */
//    lv_obj_t *img = lv_img_create(lv_scr_act());                                                /* 创建图片部件 */
//    lv_img_set_src(img, &img_user);                                                             /* 设置图片源 */
//    lv_img_set_zoom(img, zoom_val);                                                             /* 设置图片缩放 */
//    lv_obj_align(img, LV_ALIGN_CENTER, -scr_act_width()/4, -scr_act_height()/7);                /* 设置位置 */
//    lv_obj_set_style_img_recolor(img, lv_color_hex(0xf2f2f2),0);                                /* 设置重新着色 */
//    lv_obj_set_style_img_recolor_opa(img,100,0);                                                /* 设置着色透明度 */
//
//    /* 用户标签 */
//    lv_obj_t *label_user = lv_label_create(lv_scr_act());                                       /* 创建标签 */
//    lv_label_set_text(label_user, "USER");                                                      /* 设置文本 */
//    lv_obj_set_style_text_font(label_user, font, LV_PART_MAIN);                                 /* 设置字体 */
//    lv_obj_set_style_text_align(label_user, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);                /* 设置文本居中 */
//    lv_obj_align_to(label_user, img, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);                           /* 设置位置 */
//
//    /* 输入框背景 */
//    obj_input = lv_obj_create(lv_scr_act());                                                    /* 创建基础对象 */
//    lv_obj_set_size(obj_input, scr_act_width()/4, scr_act_height()/12);                         /* 设置大小 */
//    lv_obj_align_to(obj_input, label_user, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height()/20);    /* 设置位置 */
//    lv_obj_set_style_bg_color(obj_input, lv_color_hex(0xcccccc),0);                             /* 设置背景颜色 */
//    lv_obj_set_style_bg_opa(obj_input, 150,0);                                                  /* 设置透明度 */
//    lv_obj_set_style_border_width(obj_input, 0 , 0);                                            /* 去除边框 */
//    lv_obj_set_style_radius(obj_input, 20, 0);                                                  /* 设置圆角 */
//    lv_obj_remove_style(obj_input, NULL, LV_PART_SCROLLBAR);                                    /* 移除滚动条 */
//
//    /* 输入框文本标签 */
//    label_input = lv_label_create(lv_scr_act());                                                /* 创建标签 */
//    lv_label_set_text(label_input, "");                                                         /* 设置文本 */
//    lv_obj_set_style_text_font(label_input, font, LV_PART_MAIN);                                /* 设置字体 */
//    lv_obj_set_style_text_align(label_input, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);               /* 设置文本居中 */
//    lv_obj_align_to(label_input, obj_input, LV_ALIGN_CENTER, 0, 0);                             /* 设置位置 */
//
//    /* 分隔线 */
//    lv_obj_t *line = lv_line_create(lv_scr_act());                                              /* 创建线条 */
//    lv_line_set_points(line, points, 2);                                                        /* 设置线条坐标点 */
//    lv_obj_align(line, LV_ALIGN_CENTER, 0, 0);                                                  /* 设置位置 */
//    lv_obj_set_style_line_color(line, lv_color_hex(0xcdcdcd),0);                                /* 设置线条颜色 */
//
//    /* 按钮矩阵（创建） */
//    lv_obj_t *btnm = lv_btnmatrix_create(lv_scr_act());                                         /* 创建按钮矩阵 */
//    lv_obj_set_size(btnm, scr_act_width()* 2/5, scr_act_width()* 2/5);                          /* 设置大小 */
//    lv_btnmatrix_set_map(btnm, num_map);                                                        /* 设置按钮 */
//    lv_obj_align(btnm, LV_ALIGN_RIGHT_MID, -scr_act_width()/16, 0);                             /* 设置位置 */
//    lv_obj_set_style_text_font(btnm, font, LV_PART_ITEMS);                                      /* 设置字体 */
//
//    /* 按钮矩阵（优化界面） */
//    lv_obj_set_style_border_width(btnm, 0, LV_PART_MAIN);                                       /* 去除主体边框 */
//    lv_obj_set_style_bg_opa(btnm, 0, LV_PART_MAIN);                                             /* 设置主体背景透明度 */
//    lv_obj_set_style_bg_opa(btnm, 0, LV_PART_ITEMS);                                            /* 设置按钮背景透明度 */
//    lv_obj_set_style_shadow_width(btnm, 0, LV_PART_ITEMS);                                      /* 去除按钮阴影 */
//    lv_obj_add_event_cb(btnm, btnm_event_cb, LV_EVENT_VALUE_CHANGED, NULL);                     /* 设置按钮矩阵回调 */
//}
//
///**
// * @brief  LVGL演示
// * @param  无
// * @return 无
// */
//void my_gui(void)
//{
//    lv_example_btnmatrix();
//}
//
//
