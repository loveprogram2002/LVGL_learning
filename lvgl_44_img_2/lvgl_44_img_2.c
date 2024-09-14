// lvgl第44讲 图片部件 例程代码

#include "lvgl.h"
#include "my_gui.h"

// 宏定义
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))
// 函数宏
LV_IMG_DECLARE(img_gear);// 声明图片


// 变量声明
lv_font_t* font; // 字体大小
lv_obj_t* my_img_gear; // 图片部件
lv_obj_t* slider_rotation; // 控制图片旋转
lv_obj_t* slider_zoom; // 控制图片缩放
// 控制图片的颜色
lv_obj_t* slider_red;
lv_obj_t* slider_green;
lv_obj_t* slider_blue;
lv_obj_t* slider_opa; // 控制透明度

// 函数原型
static void lv_example_img(void);
static lv_obj_t* create_slider(lv_color_t color);
static void event_cb(lv_event_t* e);

// 函数定义
void my_gui(void)
{
    if (scr_act_width() <= 320)
    {
        font = &lv_font_montserrat_18;
    }
    else
    {
        font = &lv_font_montserrat_24;
    }
    lv_example_img();
}


static void lv_example_img(void)
{
    // 创建图片
    my_img_gear = lv_img_create(lv_scr_act());
    lv_img_set_src(my_img_gear, &img_gear);
    lv_obj_align(my_img_gear, LV_ALIGN_CENTER,
                 -(scr_act_width() / 5), 0);

    // 旋转滑块
    slider_rotation = create_slider(lv_color_hex(0xffcc00));
    lv_obj_align(slider_rotation,
                 LV_ALIGN_CENTER,
                 scr_act_width() / 4,
                 -scr_act_height() / 4);
    lv_slider_set_range(slider_rotation, 0, 3600);
    lv_slider_set_value(slider_rotation, 0, LV_ANIM_OFF);
    // 旋转标签
    lv_obj_t* label_rotation = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_rotation, slider_rotation,
                 LV_ALIGN_OUT_LEFT_MID, -80, -7);
    lv_obj_set_style_text_font(label_rotation,
                               font,
                               LV_STATE_DEFAULT);
    lv_label_set_text(label_rotation, "rotation");



    // 缩放滑块
    slider_zoom = create_slider(lv_color_hex(0x00ffdd));
    lv_obj_align_to(slider_zoom, slider_rotation,
                    LV_ALIGN_OUT_BOTTOM_LEFT,
                    0, scr_act_height() / 15);
    lv_slider_set_range(slider_zoom, 128, 512);
    lv_slider_set_value(slider_zoom, 256, LV_ANIM_OFF);
    // 缩放标签
    lv_obj_t* label_zoom = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_zoom, slider_zoom,
                 LV_ALIGN_OUT_LEFT_MID, -80, -7);
    lv_obj_set_style_text_font(label_zoom,
                               font,
                               LV_STATE_DEFAULT);
    lv_label_set_text(label_zoom, "zoom");

    // 红色滑块
    slider_red = create_slider(lv_color_hex(0xff0000));
    lv_obj_align_to(slider_red, slider_zoom,
                    LV_ALIGN_OUT_BOTTOM_LEFT,
                    0, scr_act_height() / 15);
    lv_slider_set_range(slider_red, 0, 255);
    lv_slider_set_value(slider_red, 0, LV_ANIM_OFF);
    // 红色标签
    lv_obj_t* label_red = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_red, slider_red,
                 LV_ALIGN_OUT_LEFT_MID, -80, -7);
    lv_obj_set_style_text_font(label_red,
                               font,
                               LV_STATE_DEFAULT);
    lv_label_set_text(label_red, "red");

    // 蓝色滑块
    slider_blue = create_slider(lv_color_hex(0x0000ff));
    lv_obj_align_to(slider_blue, slider_red,
                    LV_ALIGN_OUT_BOTTOM_LEFT,
                    0, scr_act_height() / 15);
    lv_slider_set_range(slider_blue, 0, 255);
    lv_slider_set_value(slider_blue, 0, LV_ANIM_OFF);
    // 蓝色标签
    lv_obj_t* label_blue = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_blue, slider_blue,
                 LV_ALIGN_OUT_LEFT_MID, -80, -7);
    lv_obj_set_style_text_font(label_blue,
                               font,
                               LV_STATE_DEFAULT);
    lv_label_set_text(label_blue, "blue");


    // 绿色滑块
    slider_green = create_slider(lv_color_hex(0x00ff00));
    lv_obj_align_to(slider_green, slider_blue,
                    LV_ALIGN_OUT_BOTTOM_LEFT,
                    0, scr_act_height() / 15);
    lv_slider_set_range(slider_green, 0, 255);
    lv_slider_set_value(slider_green, 0, LV_ANIM_OFF);
    // 绿色标签
    lv_obj_t* label_green = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_green, slider_green,
                 LV_ALIGN_OUT_LEFT_MID, -80, -7);
    lv_obj_set_style_text_font(label_green,
                               font,
                               LV_STATE_DEFAULT);
    lv_label_set_text(label_green, "green");

    // 透明度滑块
    slider_opa = create_slider(lv_color_hex(0x000000));
    lv_obj_align_to(slider_opa, slider_green,
                    LV_ALIGN_OUT_BOTTOM_LEFT,
                    0, scr_act_height() / 15);
    lv_slider_set_range(slider_opa, 0, 255);
    lv_slider_set_value(slider_opa, 128, LV_ANIM_OFF);
    // 透明度标签
    lv_obj_t* label_opa = lv_label_create(lv_scr_act());
    lv_obj_align_to(label_opa, slider_opa,
                 LV_ALIGN_OUT_LEFT_MID, -80, -7);
    lv_obj_set_style_text_font(label_opa,
                               font,
                               LV_STATE_DEFAULT);
    lv_label_set_text(label_opa, "opa");

}

// 创建滑块
static lv_obj_t* create_slider(lv_color_t color)
{
    lv_obj_t* slider = lv_slider_create(lv_scr_act());
    lv_obj_set_size(slider, 200, 20); // 设置大小
    lv_obj_remove_style(slider, NULL, LV_PART_KNOB); // 移除滑块的旋钮
    lv_obj_set_style_bg_opa(slider, 30, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(slider, lv_color_darken(color, 100),
                              LV_PART_MAIN);
    lv_obj_set_style_bg_color(slider, color,
                              LV_PART_INDICATOR);
    lv_obj_add_event_cb(slider,
                        event_cb,
                        LV_EVENT_VALUE_CHANGED,
                        NULL);

    return slider;
}

static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);

    if (slider_rotation == target)
    {
        lv_img_set_angle(my_img_gear,
                        lv_slider_get_value(slider_rotation)
                        );
    }
    else if (slider_zoom == target)
    {
        lv_img_set_zoom(my_img_gear,
                        lv_slider_get_value(slider_zoom)
                        );
    }
    // 设置透明度
    lv_obj_set_style_img_recolor_opa(my_img_gear,
                                     lv_slider_get_value(slider_opa),
                                     LV_PART_MAIN);           /* 设置重新着色透明度 */
     /* 设置图片重新着色 */
    lv_obj_set_style_img_recolor(my_img_gear,
                                 // r g b
                                 lv_color_make(lv_slider_get_value(slider_red),
                                               lv_slider_get_value(slider_green),
                                               lv_slider_get_value(slider_blue)),
                                 LV_PART_MAIN);
}

//// 实例代码
//
//#include "lvgl.h"
//#include <stdio.h>
//
//
///* 获取当前活动屏幕的宽高 */
//#define scr_act_width()  lv_obj_get_width(lv_scr_act())
//#define scr_act_height() lv_obj_get_height(lv_scr_act())
//
///* 定义图片部件、滑块部件 */
//static lv_obj_t *img;
//static lv_obj_t *slider_zoom, *slider_angle, *slider_r, *slider_g, *slider_b, *slider_opa;
//
//LV_IMG_DECLARE(img_gear);                     /* 声明图片 */
//
//
///**
// * @brief  滑块事件回调
// * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
// * @return 无
// */
//static void slider_event_cb(lv_event_t *e)
//{
//    lv_img_set_zoom(img, lv_slider_get_value(slider_zoom));                                         /* 设置图片缩放 */
//    lv_img_set_angle(img, lv_slider_get_value(slider_angle));                                       /* 设置图片旋转角度 */
//
//    /* 设置图片重新着色 */
//    lv_obj_set_style_img_recolor(img,
//                                 lv_color_make(lv_slider_get_value(slider_r), lv_slider_get_value(slider_g), lv_slider_get_value(slider_b)),
//                                 LV_PART_MAIN);
//
//    lv_obj_set_style_img_recolor_opa(img, lv_slider_get_value(slider_opa), LV_PART_MAIN);           /* 设置重新着色透明度 */
//}
//
///**
// * @brief  创建滑块
// * @param  color:颜色值
// * @return *slider：创建成功的滑块部件
// */
//static lv_obj_t *my_slider_create(lv_color_t color)
//{
//    lv_obj_t *slider = lv_slider_create(lv_scr_act());                                              /* 创建滑块 */
//    lv_obj_set_height(slider, scr_act_height() / 20);                                               /* 设置高度 */
//    lv_obj_set_width(slider, scr_act_width() / 3);                                                  /* 设置宽度 */
//    lv_obj_remove_style(slider, NULL, LV_PART_KNOB);                                                /* 移除旋钮 */
//    lv_obj_set_style_bg_color(slider,color,LV_PART_INDICATOR);                                      /* 设置滑块指示器颜色 */
//    lv_obj_set_style_bg_color(slider,lv_color_darken(color, 100),LV_PART_MAIN);                     /* 设置滑块主体颜色、透明度 */
//    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);                     /* 设置滑块回调 */
//    return slider;
//}
//
///**
// * @brief  图片部件实例
// * @param  无
// * @return 无
// */
//static void lv_example_img(void)
//{
//    img = lv_img_create(lv_scr_act());                                                              /* 创建图片部件 */
//    lv_img_set_src(img, &img_gear);                                                                 /* 设置图片源 */
//    lv_obj_align(img, LV_ALIGN_CENTER, -scr_act_width() / 5, 0);                                    /* 设置图片位置 */
//    lv_obj_update_layout(img);                                                                      /* 更新图片参数 */
//
//    /* 图片缩放控制滑块 */
//    slider_zoom = my_slider_create(lv_color_hex(0x989c98));                                         /* 创建滑块 */
//    lv_slider_set_range(slider_zoom, 128, 512);                                                     /* 设置滑块的范围 */
//    lv_slider_set_value(slider_zoom, 256, LV_ANIM_OFF);                                             /* 设置滑块的值 */
//    lv_obj_align(slider_zoom, LV_ALIGN_CENTER, scr_act_width() / 4, -scr_act_height() / 4);         /* 设置滑块位置 */
//
//    /* 旋转角度控制滑块 */
//    slider_angle = my_slider_create(lv_color_hex(0x989c98));                                        /* 创建滑块 */
//    lv_slider_set_range(slider_angle, 0, 3600);                                                     /* 设置滑块的范围 */
//    lv_obj_align_to(slider_angle, slider_zoom, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20); /* 设置滑块位置 */
//
//    /* 红色通道控制滑块 */
//    slider_r = my_slider_create(lv_color_hex(0xff0000));                                            /* 创建滑块 */
//    lv_slider_set_range(slider_r, 0, 255);                                                          /* 设置滑块的范围 */
//    lv_obj_align_to(slider_r, slider_angle, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);    /* 设置滑块位置 */
//
//    /* 绿色通道控制滑块 */
//    slider_g = my_slider_create(lv_color_hex(0x00ff00));                                            /* 创建滑块 */
//    lv_slider_set_range(slider_g, 0, 255);                                                          /* 设置滑块的范围 */
//    lv_obj_align_to(slider_g, slider_r, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);        /* 设置滑块位置 */
//
//    /* 蓝色通道控制滑块 */
//    slider_b = my_slider_create(lv_color_hex(0x0000ff));                                            /* 创建滑块 */
//    lv_slider_set_range(slider_b, 0, 255);                                                          /* 设置滑块的范围 */
//    lv_obj_align_to(slider_b, slider_g, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);        /* 设置滑块位置 */
//
//    /* 着色透明度控制滑块 */
//    slider_opa = my_slider_create(lv_color_hex(0x000000));                                          /* 创建滑块 */
//    lv_slider_set_range(slider_opa, 0, 255);                                                        /* 设置滑块的范围 */
//    lv_slider_set_value(slider_opa, 150, LV_ANIM_OFF);                                              /* 设置滑块的值 */
//    lv_obj_align_to(slider_opa, slider_b, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);      /* 设置滑块位置 */
//}
//
///**
// * @brief  LVGL演示
// * @param  无
// * @return 无
// */
//void my_gui(void)
//{
//    lv_example_img();
//}

