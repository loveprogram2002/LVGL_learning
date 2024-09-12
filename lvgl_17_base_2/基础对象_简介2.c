// 第17讲 基础对象 简介2
#include "my_gui.h"
#include "lvgl.h"


void my_gui(void)
{
    // 基础对象是一个集合的概念
    // 定义一个基础对象，简单理解就是一个矩形框
    // 如果是工程第一次创建部件就以活动屏幕为父对象
    // 创建一个基础的对象而且默认位于活动屏幕的左上角
    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
    // 设置部件的大小
    lv_obj_set_size(obj1, 300, 400); 
    // 测试父对象和子对象的关系：2种
    // 1.子对象随着父对象的移动而移动
     // 设置obj1部件的位置
    lv_obj_set_pos(obj1, 20, 20);
    lv_obj_t* obj2 = lv_obj_create(obj1);
    // 2.子对象的位置超出父对象的范围，则超出的部分不显示
    lv_obj_set_pos(obj2, 400, 20);
    // 一般情况下，不推荐子对象超出父对象的区域
    // 因为在使用一些对齐的方法时，有可能再也显示不了了
}
