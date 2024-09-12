// lvgl第28例程讲解：按钮例程
#include "my_gui.h"
#include "lvgl.h"

// 宏定义
// 动态获取屏幕的宽度和高度
#define scr_act_width() (lv_obj_get_width(lv_scr_act()))
#define scr_act_height() (lv_obj_get_height(lv_scr_act()))

// 变量定义
static lv_label_t* label_speed; // 速度标签
static const lv_font_t* font; // 字体大小
static lv_obj_t* btn_speed_down; // 减速按钮
static lv_obj_t* btn_speed_up; // 加速按钮
static lv_obj_t* btn_stop; // 停止按钮
static int speed_val; // 速度值

// 函数声明
static void lv_example_label(void); // 显示当前速度
static void lv_example_btn_up(void);// 加速按钮
static void lv_example_btn_down(void); // 减速按钮
static void lv_example_btn_stop(void); // 减速按钮
static void event_cb(lv_event_t* e); // 按钮按下时触发的事件

//  函数定义
void my_gui(void)
{
    lv_example_label(); // 速度提示标签
    lv_example_btn_up();    // 加速按钮
    lv_example_btn_down(); // 加速按钮
    lv_example_btn_stop(); // 速度清零
}

void lv_example_label(void)// 速度提示标签
{
    // 根据屏幕宽度选择合适的字体
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
    // 设置速度标签的样式
    label_speed = lv_label_create(lv_scr_act());// 创建一个标签
    // 创建文本字体
    lv_obj_set_style_text_font(label_speed, font, LV_PART_MAIN);
    // 设置速度标签的文本内容
    lv_label_set_text(label_speed, "Speed: 0 RPM");
    // 设置标签在活动屏幕中的位置
    lv_obj_align(label_speed,
                 LV_ALIGN_CENTER, // 居中对齐
                 0,
                 -(scr_act_height() / 3)// y轴向上偏移活动屏幕的1/3高度
                 );

}

void lv_example_btn_up(void) // 加速按钮
{
    // 创建按钮部件
    btn_speed_up = lv_btn_create(lv_scr_act());
    // 确定按钮的大小
    lv_obj_set_size(btn_speed_up,
                    scr_act_width() / 4,
                    scr_act_height() / 6);
    // 设置按钮在活动屏幕中的位置
    lv_obj_align(btn_speed_up,
                 LV_ALIGN_CENTER,
                 -scr_act_width() / 3, 0);
    lv_obj_set_style_bg_opa(btn_speed_up, 100, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn_speed_up,
                              lv_color_hex(0x0000a1),
                              LV_PART_MAIN);
    lv_obj_add_event_cb(btn_speed_up,// 添加事件
                        event_cb,
                        LV_EVENT_CLICKED,
                        NULL);

    // 标签部件
    lv_obj_t* btn_up_label_text = lv_label_create(btn_speed_up);
    // 设置文本样式
    lv_obj_set_style_bg_opa(btn_up_label_text,
                            100,
                            LV_PART_MAIN);
    lv_obj_set_style_bg_color(btn_up_label_text,
                              lv_color_hex(0xccff99),
                              LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_up_label_text,
                               font,
                               LV_PART_MAIN);
    lv_label_set_text(btn_up_label_text, "Speed Up");
    // 设置标签在活动屏幕中的位置
    lv_obj_align(btn_up_label_text,
                 LV_ALIGN_CENTER,
                 0, 0);
}


void lv_example_btn_down(void) // 减速按钮
{
    // 创建一个按钮
    btn_speed_down = lv_btn_create(lv_scr_act());
    // 设置按钮的大小
    lv_obj_set_size(btn_speed_down,
                    scr_act_width() / 4,
                    scr_act_height() / 6);
    puts("test");
    lv_obj_align(btn_speed_down,
             LV_ALIGN_CENTER,
             0, 0);
    // 设置按钮的背景透明度
    lv_obj_set_style_bg_opa(btn_speed_down, 100, LV_PART_MAIN);
    // 是这按钮的背景颜色
    lv_obj_set_style_bg_color(btn_speed_down,
                              lv_color_hex(0x00a100),
                              LV_PART_MAIN);
    lv_obj_add_event_cb(btn_speed_down,
                        event_cb,
                        LV_EVENT_CLICKED,
                        NULL);
    lv_obj_t* btn_down_label_text = lv_label_create(btn_speed_down);
       // 设置文本样式
    lv_obj_set_style_bg_opa(btn_down_label_text,
                            100,
                            LV_PART_MAIN);
    lv_obj_set_style_bg_color(btn_down_label_text,
                              lv_color_hex(0x99ffcc),
                              LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_down_label_text,
                               font,
                               LV_PART_MAIN);
    lv_label_set_text(btn_down_label_text, "Speed Down");
    // 设置标签在活动屏幕中的位置
    lv_obj_align(btn_down_label_text,
                 LV_ALIGN_CENTER,
                 0, 0);
}


void lv_example_btn_stop(void) // 减速按钮
{
        // 创建按钮部件
    btn_stop = lv_btn_create(lv_scr_act());
    // 确定按钮的大小
    lv_obj_set_size(btn_stop,
                    scr_act_width() / 4,
                    scr_act_height() / 6);
    // 设置按钮在活动屏幕中的位置
    lv_obj_align(btn_stop,
                 LV_ALIGN_CENTER,
                 +scr_act_width() / 3, 0);
    lv_obj_set_style_bg_opa(btn_stop, 100, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn_stop,
                              lv_color_hex(0x0000b1),
                              LV_PART_MAIN);
    lv_obj_add_event_cb(btn_stop,
                        event_cb,
                        LV_EVENT_CLICKED,
                        NULL);

    // 标签部件
    lv_obj_t* btn_stop_label_text = lv_label_create(btn_stop);
    // 设置文本样式
    lv_obj_set_style_bg_opa(btn_stop_label_text,
                            100,
                            LV_PART_MAIN);
    lv_obj_set_style_bg_color(btn_stop_label_text,
                              lv_color_hex(0xff0000),
                              LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_stop_label_text,
                               font,
                               LV_PART_MAIN);
    lv_label_set_text(btn_stop_label_text, "Speed Stop");
    // 设置标签在活动屏幕中的位置
    lv_obj_align(btn_stop_label_text,
                 LV_ALIGN_CENTER,
                 0, 0);
}


static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    if (btn_speed_up == target)
    {
        speed_val += 10;
    }
    else if (btn_speed_down == target)
    {
        speed_val -= 10;
    }
    else
    {
        speed_val = 0;
    }
    lv_label_set_text_fmt(label_speed,
                          "Speed: %d RPM", speed_val);
}


// 正点原子官方例程代码
//#include "lvgl.h"
//#include <stdio.h>
//
//
//#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
//    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
//#endif
//
//static const lv_font_t* font;       /* 定义字体 */
//
//static lv_obj_t *label_speed;       /* 速度提示文本 */
//static lv_obj_t *btn_speed_up;      /* 加速按钮 */
//static lv_obj_t *btn_speed_down;    /* 减速按钮 */
//static lv_obj_t *btn_stop;          /* 急停按钮 */
//
//static int32_t speed_val = 0;       /* 速度值 */
//
///* 获取当前活动屏幕的宽高 */
//#define scr_act_width() lv_obj_get_width(lv_scr_act())
//#define scr_act_height() lv_obj_get_height(lv_scr_act())
//
//
///**
// * @brief  按钮回调
// * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
// * @return 无
// */
//static void btn_event_cb(lv_event_t * e)
//{
//    lv_obj_t *target = lv_event_get_target(e);      /* 获取触发源 */
//
//    if(target == btn_speed_up)                      /* 加速按钮 */
//    {
//        speed_val += 30;
//    }
//    else if(target == btn_speed_down)               /* 减速按钮 */
//    {
//        speed_val -= 30;
//    }
//    else if(target == btn_stop)                     /* 急停按钮 */
//    {
//        speed_val = 0;
//    }
//    lv_label_set_text_fmt(label_speed, "Speed : %d RPM", speed_val);    /* 更新速度值 */
//}
//
//
///**
// * @brief  速度值提示标签
// * @param  无
// * @return 无
// */
//static void lv_example_label(void)
//{
//    /* 根据活动屏幕宽度选择字体 */
//    if (scr_act_width() <= 320)
//    {
//        font = &lv_font_montserrat_10;
//    }
//    else if (scr_act_width() <= 480)
//    {
//        font = &lv_font_montserrat_14;
//    }
//    else
//    {
//        font = &lv_font_montserrat_20;
//    }
//
//    label_speed = lv_label_create(lv_scr_act());                                    /* 创建速度显示标签 */
//    lv_obj_set_style_text_font(label_speed, font, LV_PART_MAIN);                    /* 设置字体 */
//    lv_label_set_text(label_speed, "Speed : 0 RPM");                                /* 设置文本 */
//    lv_obj_align(label_speed, LV_ALIGN_CENTER, 0, -scr_act_height() / 3);           /* 设置标签位置 */
//}
///**
// * @brief  加速按钮
// * @param  无
// * @return 无
// */
//static void lv_example_btn_up(void)
//{
//    btn_speed_up = lv_btn_create(lv_scr_act());                                     /* 创建加速按钮 */
//    lv_obj_set_size(btn_speed_up, scr_act_width() / 4, scr_act_height() / 6);       /* 设置按钮大小 */
//    lv_obj_align(btn_speed_up, LV_ALIGN_CENTER, -scr_act_width() / 3, 0);           /* 设置按钮位置 */
//    lv_obj_add_event_cb(btn_speed_up, btn_event_cb, LV_EVENT_CLICKED, NULL);        /* 设置按钮事件 */
//
//    lv_obj_t* label = lv_label_create(btn_speed_up);                                /* 创建加速按钮标签 */
//    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* 设置字体 */
//    lv_label_set_text(label, "Speed +");                                            /* 设置标签文本 */
//    lv_obj_set_align(label,LV_ALIGN_CENTER);                                        /* 设置标签位置 */
//}
//
///**
// * @brief  减速按钮
// * @param  无
// * @return 无
// */
//static void lv_example_btn_down(void)
//{
//    btn_speed_down = lv_btn_create(lv_scr_act());                                   /* 创建加速按钮 */
//    lv_obj_set_size(btn_speed_down, scr_act_width() / 4, scr_act_height() / 6);     /* 设置按钮大小 */
//    lv_obj_align(btn_speed_down, LV_ALIGN_CENTER, 0, 0);                            /* 设置按钮位置 */
//    lv_obj_add_event_cb(btn_speed_down, btn_event_cb, LV_EVENT_CLICKED, NULL);      /* 设置按钮事件 */
//
//    lv_obj_t* label = lv_label_create(btn_speed_down);                              /* 创建减速按钮标签 */
//    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* 设置字体 */
//    lv_label_set_text(label, "Speed -");                                            /* 设置标签文本 */
//    lv_obj_set_align(label,LV_ALIGN_CENTER);                                        /* 设置标签位置 */
//}
//
///**
// * @brief  急停按钮
// * @param  无
// * @return 无
// */
//static void lv_example_btn_stop(void)
//{
//    btn_stop = lv_btn_create(lv_scr_act());                                         /* 创建急停按钮 */
//    lv_obj_set_size(btn_stop, scr_act_width() / 4, scr_act_height() / 6);           /* 设置按钮大小 */
//    lv_obj_align(btn_stop, LV_ALIGN_CENTER, scr_act_width() / 3, 0);                /* 设置按钮位置 */
//    lv_obj_set_style_bg_color(btn_stop, lv_color_hex(0xef5f60), LV_STATE_DEFAULT);  /* 设置按钮背景颜色（默认） */
//    lv_obj_set_style_bg_color(btn_stop, lv_color_hex(0xff0000), LV_STATE_PRESSED);  /* 设置按钮背景颜色（按下） */
//    lv_obj_add_event_cb(btn_stop, btn_event_cb, LV_EVENT_CLICKED, NULL);            /* 设置按钮事件 */
//
//    lv_obj_t* label = lv_label_create(btn_stop);                                    /* 创建急停按钮标签 */
//    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* 设置字体 */
//    lv_label_set_text(label, "Stop");                                               /* 设置标签文本 */
//    lv_obj_set_align(label,LV_ALIGN_CENTER);                                        /* 设置标签位置 */
//}
//
///**
// * @brief  LVGL演示
// * @param  无
// * @return 无
// */
//void my_gui(void)
//{
//    lv_example_label();             /* 速度提示标签 */
//    lv_example_btn_up();            /* 加速按钮 */
//    lv_example_btn_down();          /* 减速按钮 */
//    lv_example_btn_stop();          /* 急停按钮 */
//}
