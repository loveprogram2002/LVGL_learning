// lvgl第18讲 基础对象（对齐）
#include "my_gui.h"
#include "lvgl.h"


void my_gui(void)
{
   // 重点：对齐
   lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
   lv_obj_t* obj2 = lv_obj_create(lv_scr_act());
   lv_obj_set_size(obj1, 300, 300); // 设置大小
   // 参照父对象进行对齐：只能够进行内部对齐
   // lv_obj_set_align(obj1, LV_ALIGN_CENTER);// 居中对齐
   // lv_obj_set_align(obj1, LV_ALIGN_RIGHT_MID);// 右侧居中对齐
   // // 测试外部：不对齐，子对象自动回到左上角
   // lv_obj_set_align(obj1, LV_ALIGN_OUT_RIGHT_MID);
   // 参照父对象再进行偏移：在基础对齐位置上，进行微调
   // lv_obj_align(obj1, LV_ALIGN_BOTTOM_MID, 50, 50);

   // 参照其他对象对齐（无父子关系）:obj1为基准对象
   // lv_obj_align_to(obj2, obj1, LV_ALIGN_OUT_RIGHT_MID, 0, 0);// 外部右侧居中对齐
   // lv_obj_align_to(obj2, obj1, LV_ALIGN_CENTER, 0, 0);// 内部居中对齐
   // 注意：采用对齐方式的时候，需要注意父对象的范围否则obj2会无法看见
   lv_obj_align_to(obj2, obj1, LV_ALIGN_OUT_TOP_LEFT, 0, 0);
}
