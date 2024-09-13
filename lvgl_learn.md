# LVGL学习笔记





<img src="C:\Users\gameo\AppData\Roaming\Typora\typora-user-images\image-20240905181113418.png" alt="image-20240905181113418" style="zoom:50%;" />







## LVGL部件学习



### 2、LVGL基础对象





#### 基础对象（简介1）

lvgl在初始化时就默认创建一个活动屏幕为基础对象。通过lv_scr_act()函数获取这个活动屏幕。



当创建了第一个部件后，之后的其他同类部件就有两个父对象可选：一种就是以你已经创建好了这个部件为父对象，再创建一个新对象；另一种是以活动屏幕来作为父对象

两个规律

-   ​	当使用一个父对象创建一个子对象时，父对象就相当于子对象的一个容器，子对象是装在父对象里面的
-   利用父对象创建子对象时，子对象被创建时默认是在父对象的左上角



基础对象是所有控件的起源。

创建一个基本部件

```

```



#### 基础对象（简介2）







#### 样式（重难点）



作用：样式用于设置部件的外观，以优化显示界面和实现用户交互。



添加普通样式



```
/* 创建一个部件 */
lv_obj_t * obj = lv_obj_create(lv_scr_act()); 						

/* 设置部件的样式 */
lv_obj_set_style_bg_color(obj, lv_color_hex(0xf4b183),LV_STATE_DEFAULT);
解析第三个参数：
它是处于什么状态的时候会触发这一个设置的样式，
还可以设置这一个样式具体应用到这个部件的哪个部位

```

普通样式的优点：共享



添加本地样式：

缺点：只能应用到某一个部件上面，不能像普通样式进行共享





#### 样式复习



① LVGL 样式的设置都是使用 lv_style_t 变量

② 在设置对象的样式时，可以指定在某个部分和状态下才生效。

③ 任何数量的对象都可以使用相同的样式。

④ 样式可以级联，这意味着用户可以将多个样式分配给同一个对象，并且每个样式可以
具有不同的属性

⑤ 样式具有优先级。如果两个函数同时设置某个属性，则最后调用的函数生效。

⑦ 对象样式设置的方法分为两种：普通样式和本地样式。注意：本地样式比普通样式的
优先级更高，所以 LVGL 会优先执行本地样式。



普通样式设置的最明显特点是：共用。







填充属性的作用：LVGL图形库中用来设置界面元素（比如按钮、文本框等）与其内容之间的空间距离



#### 事件

<img src="E:\笔记与思维导图\LVGL\image-20240909000459088.png" alt="image-20240909000459088" style="zoom:50%;" />



相关API

-   添加事件

    ```c
    // 函数功能：
    // 允许你为LVGL对象（如按钮、滑动条、标签等）添加事件回调函数。
    // 这个函数允许你指定在特定事件发生时应该调用的函数，以及传递给该函数的额外数据
    lv_obj_add_event_cb(obj, event_cb, event_code, user_data);
    ```

    参数解析：

    -   **event_cb**：这是一个函数指针，指向你定义的事件回调函数。当指定的事件发生时，这个函数将被自动调用。
    -   **event_code**：这是一个宏或枚举值，指定了你想要监听的事件类型。LVGL定义了多种事件类型，比如点击（`LV_EVENT_CLICKED`）、值改变（`LV_EVENT_VALUE_CHANGED`）、长按（`LV_EVENT_LONG_PRESSED`）等。
    -   **user_data**：这是一个可选的指针，你可以传递任何自定义的数据给事件回调函数。这个数据在事件发生时不会被LVGL修改或解释，它只是简单地传递给回调函数，以便你在回调函数中根据需要使用它。如果你不需要传递任何自定义数据，可以传递 `NULL`。

-   删除事件

    ```c
    lv_obj_remove_event_cb(obj,  event_cb);
    ```

    



**不同的事件类型共用一个事件回调函数怎么处理**？

第一步，使用lv_event_code()函数获取事件类型

第二步，判断事件类型并执行相关操作

```c
static void event_cb( lv_event_t *e )
{
	 /* 第一步：获取事件类型 */
	lv_event_code_t   code = lv_event_get_code(e);		
	if ( code == LV_EVENT_CLICKED )				 /* 第二步：判断事件类型 */
	{
        		printf(“事件类型: 按下后释放\r\n”);	 		 
        		/* 第三步：执行相应操作 */
	}
	else if ( code == LV_EVENT_LONG_PRESSED)
	{
        		printf(“事件类型:按下（长按）\r\n”);	
	}
}

```



**不同的部件共用一个事件回调函数怎么处理**？



第一步，获取事件的触发部位

第二步，判断事件的触发部位并执行相应操作

```c
static void event_cb( lv_event_t *e )
{
	 /* 第一步：获取触发事件的部件 */
	lv_obj_t   *target = lv_event_get_target(e); 		
 
	if ( target == parent_obj )				 /* 第二步：判断触发事件的部件 */
	{
        		printf(“父对象触发事件 \r\n”);	 		
                /* 第三步：执行相应操作 */
	}
	else if ( target == child_obj )
	{
        		printf(“子对象触发事件 \r\n”);	
	}
}

```







#### 标签





在 LVGL 中，标签部件主要用于**文本显示**，例如标题、提示信息等。



设置文本的第二种方式产生两个问题：
    1.  所指定的缓冲区里面的内容被修改或是这个内存被释放掉了那么从这个缓冲区获取的数据将是不可靠的
    1.  ​    如果缓冲区是只读的，当对缓冲区进行写操作时那么程序崩溃



**标签部件组成部分：**

-   标签部件组成部分
-   滚动条（LV_PART_SCROLLBAR）
-   选中的文本（LV_PART_SELECTED）



**如何创建标签部件以及设置文本**？

1.  创建标签部件 

    ```c
    lv_obj_t* label  = lv_label_create(lv_scr_act());
    ```

2.  设置文本的3种方式

    -   直接设置文本，存储文本的内存动态分配 

        ```c
        lv_label_set_text( label, "hallo \n lvgl");
        ```

    -    文本不存储在动态内存，而是在指定的缓冲区中（慎用）。因为这些文本存储在代码段中，而代码段属于只读的。如果在后面的操作中修改了文本内容，则程序崩溃。

        ```c
        lv_label_set_text_static(label, "hallo");
        ```

    -   格式化显示文本

        ```c
        lv_label_set_text_fmt( label, “Value: %d”, 50);
        ```

        





**改变文本样式？**



设置文本样式

1.  背景颜色

    ```c
    // 默认情况下，对于标签的部件来说，背景透明度是完全透明的
    // 因此要先设置透明度，才可以显示背景颜色
    // 设置背景的透明度
    lv_obj_set_style_bg_opa(label, 100, LV_STATE_DEFAULT);
    // 设置背景颜色
    lv_obj_set_style_bg_color(label, 
                              lv_color_hex(0xff0000),
                              LV_STATE_DEFAULT);
    ```

2.  字体大小

    ```c
    lv_obj_set_style_text_font(label,
                                &lv_font_montserrat_30,// 30号字体
                                LV_STATE_DEFAULT);
    ```

3.  文本颜色

    ```c
     lv_obj_set_style_text_color(label,
                                    lv_color_hex(0x5084db),
                                    LV_STATE_DEFAULT);
    ```

    

设置个别文本的字体颜色

```c
// 注意：要对个别字体设置特定颜色必须开启重新着色的功能
/* 开启重新着色功能 */
lv_label_set_recolor(label, true); 						
/* 单独设置颜色 */
// 注意：16进制的颜色值与设置特定颜色的文本要有一个空格
lv_label_set_text(label, "hallo #ff0000 lvgl#");// 給lvgl单独设置颜色			
```



**当文本长度超过部件大小的时候怎么显示**？

-   情况一：默认情况下，如果没有限定标签部件大小，那它的大小自动扩展为文本大小。

-   长文本模式

    ```c
    lv_label_set_long_mode(label, LV_LABEL_LONG_...);
    // 第二个参数的取值
    enum 
    {
    	/* 默认模式, 如果部件大小已固定，超出的文本将被剪切 */
        LV_LABEL_LONG_WRAP,             		
        /* 将 label 右下角的最后 3 个字符替换为点… */
        LV_LABEL_LONG_DOT,              		
        LV_LABEL_LONG_SCROLL,           		/* 来回滚动 */
        LV_LABEL_LONG_SCROLL_CIRCULAR,  	/* 循环滚动 */
         /* 直接剪切掉部件外面的文本部分 */
        LV_LABEL_LONG_CLIP,             		 
    };
    ```

    

#### 按钮



按钮部件组成部分：主体(LV_PART_MAIN)



知识点1：创建按钮部件 

```c
// 在活动屏幕中创建一个按钮，默认放在屏幕的左上角
lv_obj_t* btn = lv_btn_create(lv_src_create()); 
```



知识点2：设置按钮的样式

```c
/* 大小 */	
lv_obj_set_size( btn, 100, 50 );								   
// 存在父对象的中央位置
lv_obj_set_align( btn, LV_ALIGN_CENTER );						   
/* 背景颜色 */
lv_obj_set_style_bg_color( btn, lv_color_hex(0xffe1d4), LV_STATE_PRESSED );
```



知识点3：添加事件

```c
/* 开启状态切换 */
lv_obj_add_flag( btn, LV_OBJ_FLAG_CHECKABLE );					    
// 这行代码的作用是为btn对象添加一个事件回调函数event_cb
// 该函数将在btn对象的值改变时被调用
lv_obj_add_event_cb( btn, event_cb, LV_EVENT_VALUE_CHANGED,NULL );	 
```

解析：

```
lv_obj_add_flag 函数用于给LVGL对象（如按钮、标签等）添加特定的标志（flag），
以改变其行为或外观。
```

LV_OBJ_FLAG_CHECKABLE 标志的作用

-   **可勾选（Checkable）**：当给对象（如按钮）添加 `LV_OBJ_FLAG_CHECKABLE` 标志后，该对象就变成了一个可勾选（或可切换状态）的控件。对于按钮来说，这通常意味着用户可以通过点击来切换按钮的“选中”和“未选中”状态。
-   **状态切换**：默认情况下，按钮可能只响应点击事件来执行某些动作（如调用回调函数）。但添加了 `LV_OBJ_FLAG_CHECKABLE` 后，按钮会记住它的状态（选中或未选中），并且可以根据需要改变其外观（如显示勾选标记）来反映其当前状态。
-   **外观变化**：通常，LVGL会根据控件的状态（如是否选中）自动调整其外观。对于按钮来说，这可能意味着在选中状态下，按钮的背景色、边框或图标会发生变化，以向用户表明其当前状态。



第三个参数`LV_EVENT_VALUE_CHANGED`是一个枚举值，用于指定要监听的事件类型。在LVGL中，事件系统允许开发者为对象定义和监听各种事件，以便在特定条件满足时执行自定义代码。

`LV_EVENT_VALUE_CHANGED`是一个特定的事件类型，它通常在对象的值或状态发生变化时被触发。对于不同类型的对象，这个“值”的含义可能不同：

-   对于**滑块（Slider）**或**滚动条（Scrollbar）**，这通常意味着用户通过拖动改变了滑块的位置，从而改变了其值。
-   对于**复选框（Checkbox）**或**开关（Switch）**，这表示用户通过点击改变了其选中/未选中的状态。
-   对于**按钮（Button）**，虽然按钮通常不直接关联到一个“值”，但如果你将按钮的点击视为一种“状态”的变化（即从未点击到点击），并且你通过某种方式（如变量）来跟踪这种变化，那么理论上你也可以为按钮的点击事件使用`LV_EVENT_VALUE_CHANGED`（尽管更常见的做法是直接使用`LV_EVENT_CLICKED`）。然而，在标准用法中，按钮的点击通常是通过`LV_EVENT_CLICKED`事件来处理的。







#### 开关



功能：开关部件常用于控制某个功能的开启和关闭，它可以直接显示被控对象的状态。



开关的组成部分

-   主体：LV_PART_MAIN
-   手柄：LV_PART_KNOB
-   指示器：LV_PART_INDICATOR



步骤：

1.  创建开关部件

    ```c
    lv_obj_t* switch1 = lv_switch_create(parent);
    ```

2.  添加或清除开关状态

    ```c
    lv_obj_add_state(switch1, LV_STATE_CHECKED)// 添加状态
    lv_obj_clear_state(switch1, LV_STATE_CHECKED)// 清除状态
    ```

    -   `LV_STATE_CHECKED`：这是一个预定义的状态标志，用于表示对象的选中状态。在LVGL中，这个标志通常用于表示复选框（checkbox）或开关（switch）对象是否被激活或选中。

3.  获取（判断）开关状态

    ```c
    lv_obj_has_state(switch1, LV_STATE_CHECKED)
    // 返回值是布尔类型，开则返回真，关则返回假
    ```



设置开关的大小时，宽度和高度比例最好是（2，1）





#### 复选框



功能：复选框部件常用于选择某个内容的开启和关闭，可以理解为自带标签的开关。



复选框的组成部分

-   主体：LV_PART_MAIN
-   勾选框：LV_PART_INDICATOR



创建复选框

```c
lv_obj_t* checkbox = lv_checkbox_create(parent);
```



文本设置

```c
lv_checkbox_set_text(checkbox, "text");// 设置文本内容
// 设置复选框和文本的间距
lv_obj_set_style_pad_column(checkbox, 20, LV_STATE_DEFAULT);
```



添加或清除复选框状态

```c
/* 添加状态：默认选中且不可修改 */
lv_obj_add_state(checkbox, LV_STATE_CHECKED | LV_STATE_DISABLED);	
/* 清除复选框的状态 */	
lv_obj_clear_state(checkbox, LV_STATE_CHECKED | LV_STATE_DISABLED);
```



判断（获取）复选框的状态

```c
 /* 返回值：1，选中； 0，非选中 */
lv_obj_has_state(checkbox, LV_STATE_CHECKED);					
```







#### 进度条



功能：进度条部件常用于显示当前任务的完成进度。



组成

-   主体:LV_PART_MAIN
-   指示器：LV_PART_INDICATOR





知识点1：创建进度条部件

```c
lv_obj_t* bar = lv_bar_create(parent); 
```



知识点2：设置大小、当前值、范围值

```c
lv_obj_set_size( bar, 400, 20 );							/* 设置大小 */
lv_bar_set_range( bar, -100, 100 );						/* 设置范围值 */
lv_bar_set_value( bar, 50, LV_ANIM_ON );					/* 设置当前值 */  
```

解析上述三行代码：

-   对于上述三行代码而言，虽然开启了动画效果，但是因为动画时间太短了，无法观察到动画。


-   注意：默认创建出来的进度条，在lv8.2版本中值的范围是1\~ 100；在lv9版本中值的范围是0 \~ 100。换句话说，进度条的初始值取决于lvgl的版本

-   范围值的设置必须放在设置当前值的前面。

lv_bar_set_value()函数的第三个参数是一个动画控制标志，用于指定在改变值时是否应该应用动画效果。

第三个参数：用于控制动画的开启或关闭。



知识点3：设置动画时间

动画设置必须放在当前值设置之前 

```c
lv_obj_set_style_anim_time( bar, 500, LV_STATE_DEFAULT );	
```

解析：第二个参数指定了动画的持续时间，单位是毫秒。这表明， 当`bar`对象的状态发生变化（比如从不可见变为可见，或者值的变化导致视觉上的更新）时，这个变化将在500毫秒内平滑过渡完成。



知识点4：设置模式、起始值

```c
lv_bar_set_mode( bar, LV_BAR_MODE_RANGE );			/* 设置模式 */
lv_bar_set_start_value( bar, -50, LV_ANIM_OFF );			/* 设置起始值 */
enum {
    LV_BAR_MODE_NORMAL,			/* 默认模式 */
    // 从零值绘制到当前值（当前值可以小于0）该模式下不允许设置起始值
    LV_BAR_MODE_SYMMETRICAL,	
    // 允许设置起始值，但起始值必须小于当前值
    LV_BAR_MODE_RANGE,		
};
```



进度条使用的注意事项

-   当进度条高度大于宽度时，其方向变为垂直。
-   动画时间设置需要放在当前值设置之前 ，否则看不到动画效果。
-   **动画时间指的是旧值刷新到新值的绘图时间，并不是现实中当前值变化所需的时间**。



注意：在V8.2版本的LVGL中，默认模式也允许设置起始值，但是后续的版本可能会修改。

因此，在设置进度条的起始值时，最好先使用LV_BAR_MODE_RANGE模式。





#### 加载器



功能：加载器部件常用于提示当前任务正在加载。



加载器部件组成：

-   主体：LV_PART_MAIN
-   指示器：LV_PART_INDICATOR
-   手柄：LV_PART_KNOB





创建加载器部件：

```c
lv_obj_t* spinner = lv_spinner_create(parent, spin_time, arc_length );
```

第二参数表示指示器旋转一圈的时间（以毫秒为单位）。

第三个参数表示arc_length 形参表示指示器的长度。



设置圆弧颜色

```c
/* 设置主体圆弧颜色 */
lv_obj_set_style_arc_color( spinner,
                        lv_color_hex(0x4a9f00), 
                        LV_PART_MAIN );
/* 设置指示器圆弧颜色 */
lv_obj_set_style_arc_color(spinner, 
						lv_color_hex(0x83bd55), 
						LV_PART_INDICATOR);
```



设置圆弧宽度

```c
/* 设置主体圆弧宽度 */
lv_obj_set_style_arc_width( spinner, 30, LV_PART_MAIN );	
/* 设置指示器圆弧宽度 */
lv_obj_set_style_arc_width( spinner, 30, LV_PART_INDICATOR );	
```



#### LED部件



注意：打开、关闭LED时，亮度不绝对是255、0，具体要看相关的宏定义（可修改）



功能：LED部件常用于指示控制对象的状态。

组成部分：主体（LV_PART_MAIN)



创建LED部件

```c
lv_obj_t   *led = lv_led_create(parent);
```



设置LED颜色、l亮度

```c
lv_led_set_color( led, lv_color_hex(0xff0000) );  		/* 设置LED颜色 */
lv_led_set_brightness( led, 0 );				/* 设置LED亮度，范围0~255*/
```



设置LED状态

```c
/* 打开LED（设置亮度为255）*/
lv_led_on( led );	
/* 关闭LED */
lv_led_off( led );	
/* 翻转LED状态 */
lv_led_toggle( led );
```





#### 列表



功能：列表部件常用于多选一的场景，默认会展现多个选项。



列表组成：

-   主体：LV_PART_MAIN
-   滚动条：LV_PART__SCROLLBAR



创建列表部件

```c
lv_obj_t* list = lv_list_create( parent );
```



知识点2：添加列表文本

```c
lv_list_add_text( list, “Settings" );
```



知识点3：添加列表按钮

```c
lv_obj_t  *btn= lv_list_add_btn( list, LV_SYMBOL_WIFI, “WLAN"); 
```



知识点4：获取列表按钮文本

```c
lv_list_get_btn_text( list, list_btn );
```







#### 下拉列表



功能：下拉列表部件常用于多选一的场景，点击后可展现多个选项。

组成:

-   按钮：BUTTON
-   列表：LIST

<img src="E:\Note_Xmind\LVGL\Zhengdian\PC_Learn\LVGL_PC\image-20240913085454262.png" alt="image-20240913085454262" style="zoom: 50%;" />





知识点1：创建下拉列表

```c
lv_obj_t   *dd = lv_dropdown_create( parent );
```



知识点2：设置选项内容

```c
/* 设置选项 */
lv_dropdown_set_options( dd, "a\nb\nc\nd");	   		
/* 设置选项 （静态）*/
lv_dropdown_set_options_static( dd, "a\nb\nc\nd ");		
/* 添加选项，索引从0开始 */
lv_dropdown_add_option( dd, "e", 4);					
```

解析第二个函数

 `lv_dropdown_set_options_static()` 函数的作用是为指定的下拉列表控件设置一组静态的选项。这些选项在下拉列表创建后不会改变，除非你再次调用此函数来更新它们。

使用 `lv_dropdown_set_options_static()` 函数适用于以下场景：

-   当下拉列表的选项在程序运行期间是固定不变的，例如，一个包含预定义设置选项的配置菜单。
-   你希望下拉列表的选项在程序启动时就完全确定，并且在程序运行期间不需要动态添加或删除选项。
-   这对于创建具有固定选项的下拉菜单非常有用，可以简化界面设计并减少运行时的资源消耗。





知识点3：设置当前所选项

```c
lv_dropdown_set_selected( dd, 1);					/* 注意：索引从0开始 */
```



知识点4：获取选项内容

```c
lv_dropdown_get_selected( dd);		/* 获取索引 */

char buf[10];
lv_dropdown_get_selected_str( dd, buf, sizeof(buf));	/* 获取选项文本 */
```



知识点5：设置方向和图标

```c
lv_dropdown_set_dir(dd, LV_DIR_RIGHT);				/* 设置列表展开方向 */
lv_dropdown_set_symbol(dd, LV_SYMBOL_RIGHT);			/* 设置图标 */
```





####  滚轮



功能：滚轮部件常用于多选一的场景，它以滚轮的形式来展现多个选项。

滚轮组成部分：

-   主体：LV_PART_MAIN
-   选项框：LV_PART_SELECTED





知识点1：创建滚轮部件 

```c
lv_obj_t   *roller= lv_roller_create( parent );
```



知识点2：设置选项间隔

```c
lv_obj_set_style_text_line_space(roller, 30, LV_STATE_DEFAULT);	   
```



知识点3：设置选项内容、滚动模式

```c
/* 正常模式 */
lv_roller_set_options(roller, “a\nb\nc\nd”, LV_ROLLER_MODE_NORMAL); 
// 无限循环模式：占用内存较大
lv_roller_set_options(roller, "a\nb\nc\nd", LV_ROLLER_MODE_INFINITE);
```



知识点4：设置当前所选项

```c
lv_roller_set_selected(roller, 3, LV_ANIM_ON);
```



知识点5：设置可见行数

```c
lv_roller_set_visible_row_count(roller, 2);
```



知识点6：获取选项内容

```c
lv_roller_get_selected(roller);					/* 获取索引 */
char buf[10];
/* 获取选项文本 */
lv_roller_get_selected_str(roller, buf, sizeof(buf));		
```



#### 滑块



功能：滑块部件常用于调节某个参数的值，它以直线滑动的形式来修改数值。



滑块部件组成部分：

-   主体：LV_PART_MAIN
-   指示器：LV_PART_INDICATOR
-   旋钮：LV_PART_KNOB





知识点1：创建滑块部件 

```C
lv_obj_t   *slider = lv_slider_create( parent );
```



知识点2：设置大小、当前值、范围值

```C
lv_obj_set_size(slider, 20, 200);				/* 高度>宽度时，滑块为纵向 */
lv_slider_set_value(slider, 50, LV_ANIM_OFF);				/* 设置当前值 */
lv_slider_set_range(slider, -100, 100);					/* 设置范围值 */
```



知识点3：获取当前值

```C
lv_slider_get_value(slider);
```



知识点4：模式设置

```
lv_slider_set_mode(slider, LV_SLIDER_MODE_...);
```



知识点5：设置、获取左值

```C
lv_slider_set_left_value(slider, 20, LV_ANIM_OFF);			/* 设置左值 */
lv_slider_get_left_value(slider);						/* 获取左值 */
```



注意：在模式设置中，对于LV_SLIDER_MODE_SYMMETRICAL，滑块总是从零开始绘制



####  圆弧



功能：圆弧部件以弧形滑动的形式来调节、显示某个参数的值。



圆弧部件组成部分：

-   背景弧：LV_PART_MAIN
-   前景弧：LV_PART_INDICATOR
-   旋钮：LV_PART_KNOB



知识点1：创建圆弧部件 

```C
lv_obj_t   *arc = lv_arc_create( parent );
```



知识点2：设置当前值、范围值

```C
lv_arc_set_value(arc, 80);				/* 设置当前值（需要在范围值之内）*/
lv_arc_set_range(arc, 0, 200);						/* 设置范围值 */
```



知识点3：设置圆弧角度

```
lv_arc_set_angles(arc, 135, 270);			/* 设置前景弧角度 */
lv_arc_set_bg_angles(arc, 135, 45);			/* 设置背景弧角度 */

```



知识点4：设置旋转角度

```C
lv_arc_set_rotation(arc, 180);
```



知识点5：获取当前值

```C
lv_arc_get_value(arc);
```



知识点6：设置模式、圆弧绘制速率

```C
lv_arc_set_mode(arc, LV_ARC_MODE_REVERSE);				/* 设置模式 */
lv_arc_set_change_rate(arc, 90);					/* 绘制速率：90°/秒 */
```



重要的注意事项：

-   背景弧的默认起始角度是135度

-   **背景弧角度设置必须放在前景弧角度之前。**

-   **前景弧角度设置的范围必须包含在背景弧角度设置的范围内。**

-   当前景弧的起始角度大于背景弧的起始角度，如果修改当前值时，lgvl就会强制修改前景弧的起始角度，把前景弧的起始角度更改为背景弧的起始角度。

-   设置前景弧的函数尽量不要使用。

-   如果只是仅仅调用前景弧函数去设置圆弧，但是当前值是不会跟着前景圆弧变化的。

    因此当前值设置和前景弧设置函数不要混用。简单来说，就是图和值对不上的问题。

    



