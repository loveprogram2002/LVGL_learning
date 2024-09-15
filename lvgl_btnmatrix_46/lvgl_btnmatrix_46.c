// lvgl第46讲 按钮矩阵部件
#include "lvgl.h"
#include "my_gui.h"

/* 定义按钮数组，最后一个元素必须为空 */
// 这里的换行符表示在新的一行设置按钮
static const char *map[] = { "#ff0000 btn1#",  "btn2", "btn3",
                    "\n", "btn4", "btn5", "6     ", ""  };

static void event_cb(lv_event_t* e);

void my_gui(void)
{
    lv_obj_t* btnm = lv_btnmatrix_create(lv_scr_act());
    lv_btnmatrix_set_map(btnm, map);
    lv_obj_center(btnm);
//    lv_btnmatrix_set_btn_width(btnm, 0, 1);
//    lv_btnmatrix_set_btn_width(btnm, 1, 1);
//    lv_btnmatrix_set_btn_width(btnm, 2, 2);
//    lv_btnmatrix_set_map(btnm, map);	/* 设置按钮 */
//    lv_btnmatrix_set_btn_width(btnm, 2, 2);
    // 设置隐藏按键的属性
//       lv_btnmatrix_set_btn_ctrl(btnm, 0, LV_BTNMATRIX_CTRL_HIDDEN);
    // 设置按钮不可点击的状态
//     lv_btnmatrix_set_btn_ctrl(btnm, 0, LV_BTNMATRIX_CTRL_DISABLED);
    // 当点击任意一个按钮并松开按钮后，按钮的状态保持不变。
//    lv_btnmatrix_set_btn_ctrl(btnm, 0, LV_BTNMATRIX_CTRL_CHECKABLE);
    // 允许重新着色
    // 十六进制颜色值和文本之间必须要有一个空格
//    lv_btnmatrix_set_btn_ctrl(btnm, 0, LV_BTNMATRIX_CTRL_RECOLOR);
    // 清除单个按钮的重新着色属性
//    lv_btnmatrix_clear_btn_ctrl(btnm, 0, LV_BTNMATRIX_CTRL_RECOLOR);
    // 设置所有属性
    lv_btnmatrix_set_btn_ctrl_all(btnm,
                                  LV_BTNMATRIX_CTRL_CHECKABLE |LV_BTNMATRIX_CTRL_RECOLOR);
    // 开启按钮互斥。注意：需要先设置允许状态切换的属性
    lv_btnmatrix_set_one_checked(btnm, true);

//  lv_obj_add_event_cb(btnm, event_cb, LV_EVENT_VALUE_CHANGED, NULL);


}



static void event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    uint8_t id = 0;
    id = lv_btnmatrix_get_selected_btn(target);
    printf("%s: id = %d\n",
            lv_btnmatrix_get_btn_text(target, id), id);


}
