// lvgl第43讲 图片部件 基础知识
#include "lvgl.h"
#include "my_gui.h"

LV_IMG_DECLARE(zhengdian);
void event_cb(lv_event_t* e);


void my_gui(void)
{
   lv_obj_t* img = lv_img_create(lv_scr_act());
   lv_img_set_src(img, &zhengdian);
   lv_obj_center(img);
   // 设置图片偏移
   // 多出来的地方回到左侧
//   lv_img_set_offset_x(img, 100);
//   lv_img_set_offset_y(img, 200);
   //图片重新着色：只能对图片的整体进行着色
   // 但不能对部件的某个部分进行着色
   // 首先设置透明度
//   lv_obj_set_style_img_recolor_opa(img, 100, LV_PART_MAIN);
//   lv_obj_set_style_img_recolor(img,
//                                lv_color_hex(0XFF1100),
//                                LV_PART_MAIN);
    lv_img_set_zoom(img, 512);
    lv_img_set_angle(img, 900); // 顺时针旋转90度
    lv_obj_update_layout(img);
    lv_img_set_pivot(img, 0, 0);
}


void event_cb(lv_event_t* e)
{

}

