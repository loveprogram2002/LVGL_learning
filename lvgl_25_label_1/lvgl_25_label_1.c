// lvgl第25讲 标签部件基础知识的讲解
#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
    // 创建一个标签部件
    lv_obj_t* label = lv_label_create(lv_scr_act());

    lv_obj_set_size(label, 100, 100);
    lv_obj_center(label);
//    // 一、设置文本的3种方式
//    // 1 直接设置文本
//    lv_label_set_text(label, "hello lvgl");
//    // 2 在指定缓冲区中（谨慎使用）
//    // 它的文本存储在代码段中，而代码段是只读的。
//    // 如果在后面的操作中区修改这里面的内容时，程序崩溃
//    lv_label_set_text_static(label, "hello lvgl");
//    // 格式化显示文本
//    lv_label_set_text_fmt(label, "hello %d", 500);

    // 二、修改文本的样式
    // 注意：默认情况下，对于标签的部件来说，背景透明度是完全透明的
    // 文本颜色的设置
    // 默认情况下是完全透明的
    // 设置背景的透明度
    lv_obj_set_style_bg_opa(label, 100, LV_STATE_DEFAULT);
    // 设置背景颜色
    lv_obj_set_style_bg_color(label,
                          lv_color_hex(0xff0000),
                          LV_STATE_DEFAULT);
    // 设置文本颜色
    lv_obj_set_style_text_color(label,
                                lv_color_hex(0x5084db),
                                LV_STATE_DEFAULT);
    // 设置字体大小
    lv_obj_set_style_text_font(label,
                                 &lv_font_montserrat_30,
                                 LV_STATE_DEFAULT);
//    lv_label_set_recolor(label, true);// 开启重新着色的功能
//    // 注意：颜色值和要更改颜色的文本之间必须有一个空格
//    lv_label_set_text_fmt(label, "hello #00FF00 %d#", 500);
//    lv_label_set_text(label,
//                      "hello #ff0000 lvgl#"
//                      );
//    // 三、长文本模式即当文本长度超过部件长度时
//    lv_label_set_text(label,
//                      "hello #ff0000 lvgl# \n hello #ffff00 lvgl#"
//                      );
//
//    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

