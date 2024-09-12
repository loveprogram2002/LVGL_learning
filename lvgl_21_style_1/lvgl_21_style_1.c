// 样式属性设置：本地样式和普通样式
#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
//    // 1.添加普通样式
//    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
//    // 注意：样式变量必须是静态局部变量或是动态开辟的或是全局变量
//    static lv_style_t style;
//    lv_style_init(&style);// 初始化样式
//    // 设置背景颜色
//    lv_style_set_bg_color(&style, lv_color_hex(0XFB3D3D));
//    // 设置部件的样式：在默认状态下应用这个样式
//    lv_obj_add_style(obj1, &style, LV_STATE_DEFAULT);

    // 2.添加本地样式
    lv_obj_t* obj2 = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(obj2,
                              lv_color_hex(0XFB3D3D),
                              LV_STATE_PRESSED);

}
