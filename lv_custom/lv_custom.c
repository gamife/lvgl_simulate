#include "lv_custom.h"

// 下面三种方式都可以定义颜色
// #define yangshi_moren_bg lv_color_hex(0xa03080)
#define yangshi_moren_bg lv_palette_main(LV_PALETTE_RED)
// #define yangshi_moren_bg lv_color_make(0x00, 0x00, 0x00)

#define desktop_Button_Num 3

lv_style_t lvgl_WuBianKuang_cont_style;
lv_style_t lvgl_desktop_BeiJing_style;

lv_obj_t * obj_test;
void debug_color(lv_color_t color){
    obj_test = lv_obj_create(lv_scr_act());
    lv_obj_t* obj = obj_test;
    lv_obj_set_style_bg_color(obj, color, 0);
    lv_obj_set_style_border_color(obj,lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_set_style_border_width(obj, 5, 0);
    lv_obj_align(obj, LV_ALIGN_TOP_MID, 0,0);
}
void debug_color2(lv_color_t color){
    lv_obj_t * obj= lv_obj_create(obj_test);
    lv_obj_set_style_bg_color(obj, color, 0);
    lv_obj_set_style_border_color(obj,lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_set_style_border_width(obj, 5, 0);
    lv_obj_set_style_pad_all(obj, 0, 0);

    // 设置两个图层怎么显示, 比如子对象是直接覆盖在父对象上, 还是由其他混合的方式
    lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, 0);

    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM );
    lv_obj_clear_flag(obj_test, LV_OBJ_FLAG_SCROLL_ELASTIC );

    lv_obj_set_width(obj, lv_pct(50));
    lv_obj_set_height(obj, lv_pct(300));
    // lv_obj_center(obj);
    lv_obj_align(obj, LV_ALIGN_TOP_MID, 0,0);

    LV_LOG_USER("=======");
    lvgl_print_infos(obj_test);
    LV_LOG_USER("=======");
    lvgl_print_infos(obj);
    LV_LOG_USER("=======");

}

void lvgl_style_init(void)
{
    debug_color(lv_color_make(0xff, 0xff, 0xff));
    debug_color(lv_palette_main(LV_PALETTE_YELLOW));
    debug_color2(lv_palette_main(LV_PALETTE_GREEN));



    lv_style_init(&lvgl_WuBianKuang_cont_style);
    lv_style_set_radius(&lvgl_WuBianKuang_cont_style, 0);        // 圆角
    lv_style_set_border_opa(&lvgl_WuBianKuang_cont_style, 255);  // 边框透明度
    lv_style_set_border_width(&lvgl_WuBianKuang_cont_style, 20); // 边框宽度
    lv_style_set_border_side(&lvgl_WuBianKuang_cont_style, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);
    lv_style_set_blend_mode(&lvgl_WuBianKuang_cont_style, LV_BLEND_MODE_NORMAL);
    lv_style_set_pad_top(&lvgl_WuBianKuang_cont_style, 0);     // 内边距上侧尺寸
    lv_style_set_pad_bottom(&lvgl_WuBianKuang_cont_style, 0); // 内边距下侧尺寸
    lv_style_set_pad_left(&lvgl_WuBianKuang_cont_style, 0);    // 内边距左侧尺寸
    lv_style_set_pad_right(&lvgl_WuBianKuang_cont_style, 0);  // 内边距右侧尺寸

    // 背景色透明度
    lv_style_set_bg_opa(&lvgl_WuBianKuang_cont_style, LV_OPA_COVER);       
    lv_style_set_bg_color(&lvgl_WuBianKuang_cont_style, yangshi_moren_bg);
    // 设置渐变的目的颜色
    lv_style_set_bg_grad_color(&lvgl_WuBianKuang_cont_style, lv_palette_lighten(LV_PALETTE_GREEN, 3)); // 背景上面颜色
    lv_style_set_bg_grad_dir(&lvgl_WuBianKuang_cont_style, LV_GRAD_DIR_VER);                           // 渐变方向
    // 调整渐变色起始及结束位置
    // https://blog.csdn.net/zhango5/article/details/125610164
    // 在渐变设置接口中还提供了 lv_style_set_bg_main_stop 和  lv_style_set_bg_grad_stop，这两个接口用来设置渐变过程中的起点和终点。
    // 接口第二个参数lv_coord_t value：0 表示起点，255 表示终点，128 表示中心，均为渐变方向上。
    // 默认情况下: main_stop=0, grad_stop=255. 我理解是把对象整个分为256份, [0-main_stop]=背景色 [main_stop,grad_stop]=渐变过程 [grad_stop,255]=渐变目的色
    lv_style_set_bg_main_stop(&lvgl_WuBianKuang_cont_style, 100);
    lv_style_set_bg_grad_stop(&lvgl_WuBianKuang_cont_style, 200);

    lv_style_init(&lvgl_desktop_BeiJing_style);
    lv_style_set_bg_opa(&lvgl_desktop_BeiJing_style, LV_OPA_COVER); 
    lv_style_set_bg_color(&lvgl_desktop_BeiJing_style, lv_color_black());      
    lv_style_set_bg_grad_color(&lvgl_desktop_BeiJing_style, lv_color_black()); 

    // 设置屏幕, 无边框, 黑色
    lv_obj_add_style(lv_scr_act(), &lvgl_WuBianKuang_cont_style, LV_PART_MAIN | LV_STATE_DEFAULT); // 设置样式
    lv_obj_add_style(lv_scr_act(), &lvgl_desktop_BeiJing_style, LV_PART_MAIN | LV_STATE_DEFAULT);  // 设置样式

    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj1, &lvgl_WuBianKuang_cont_style, LV_PART_MAIN | LV_STATE_DEFAULT); // 设置样式
    lv_obj_set_style_border_color(obj1, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_set_style_bg_color(obj1, lv_palette_darken(LV_PALETTE_BLUE, 3), LV_PART_SCROLLBAR);
    lv_obj_set_height(obj1, 200);
    lv_obj_set_width(obj1, 100);
    lv_obj_center(obj1);

    lv_obj_set_content_height(obj1, 150);
    lv_obj_set_content_width(obj1, 50);

    // obj1_lable
    lv_obj_t *lable = lv_label_create(obj1);
    lv_label_set_text(lable, "gg");
    lv_obj_set_height(lable, 20);
    lv_obj_set_width(lable, 30);
    lv_obj_center(lable);

      // obj2
    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());
    // 设置默认背景颜色
    lv_obj_set_style_bg_color(obj2, lv_palette_lighten(LV_PALETTE_GREY, 3), 0);
    // 设置滚动条颜色
    lv_obj_set_style_bg_color(obj2, lv_palette_darken(LV_PALETTE_YELLOW, 3), LV_PART_SCROLLBAR);
    // 设置边框颜色
    lv_obj_set_style_border_color(obj2, lv_palette_darken(LV_PALETTE_GREEN, 3), 0);
    // 设置边框的显示
    lv_obj_set_style_border_side(obj2, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP, 0);
    // 设置边框的线条宽度
    lv_obj_set_style_border_width(obj2, 10, 0);
    // 设置box的宽高
    lv_obj_set_height(obj2, 40);
    lv_obj_set_width(obj2, 20);
    // 设置对象的位置
    lv_obj_align(obj2, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lvgl_print_infos(obj2);

    // obj2 set content size
    lv_obj_set_content_height(obj2, 80);
    lv_obj_set_content_width(obj2, 40);
    lvgl_print_infos(obj2);

    // obj2 set pad size
    lv_obj_set_style_pad_bottom(obj2, 13, 0);
    lvgl_print_infos(obj2);

    lv_obj_set_content_height(obj2, 200);
    lv_obj_set_content_width(obj2, 100);
    lvgl_print_infos(obj2);

    lv_obj_set_style_pad_bottom(obj2, 20, 0);
    lv_obj_set_content_height(obj2, 40);
    lv_obj_set_content_width(obj2, 20);
    lvgl_print_infos(obj2);

    //  此时 obj2垂直方向: content=40 pad_all=20, border=10
    lv_obj_t * obj3 = lv_obj_create(obj2);
    lv_obj_set_style_radius(obj3, 0, 0);
    // 这里设置 obj3的高, 来测试显示情况.
    lv_obj_set_height(obj3, 100);
    lv_obj_set_width(obj3, 30);
    // 设置obj3无pad
    lv_obj_set_style_pad_all(obj3, 0, LV_PART_MAIN );
    // 显示子对象的边框
    lv_obj_set_style_border_width(obj3, 4, LV_PART_MAIN);
    lv_obj_set_style_border_color(obj3, lv_palette_darken(LV_PALETTE_RED, 3),0);
    // 设置默认背景颜色
    lv_obj_set_style_bg_color(obj3, lv_palette_darken(LV_PALETTE_BLUE, 3), 0);
    // 设置按压状态的背景颜色
    lv_obj_set_style_bg_color(obj3, lv_palette_darken(LV_PALETTE_RED, 3), LV_STATE_PRESSED);
    // 中心位置可能导致松开obj3的滚动条, 滚动条归位时, obj3的上方被 obj2遮挡
    // lv_obj_align(obj3, LV_ALIGN_CENTER, 0, 0);
    // 改为 上中 位置, 不会出现滚动条复位后, 看不到子对象的情况.
    lv_obj_align(obj3, LV_ALIGN_TOP_MID, 0, 0);

    static lv_style_t style_normal;
    lv_style_init(&style_normal);
    lv_style_set_y(&style_normal, 100);

    static lv_style_t style_pressed;
    lv_style_init(&style_pressed);
    // 背景颜色
    lv_style_set_bg_color(&style_pressed, lv_palette_main(LV_PALETTE_RED));
    // 位置相对修改
    lv_style_set_translate_y(&style_pressed, -60);
    // 尺寸相对修改
    lv_style_set_transform_width(&style_pressed, 10);
    lv_style_set_transform_height(&style_pressed, 40);
    // 用百分比有问题
    // lv_style_set_transform_height(&style_pressed, lv_pct(50));

    lv_obj_t *btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_style(btn1, &style_normal, LV_STATE_DEFAULT);
    lv_obj_add_style(btn1, &style_pressed, LV_STATE_PRESSED);
    // 也就是把 (20,100) 当做原点, 找到其 左中 的位置
    lv_obj_align(btn1, LV_ALIGN_LEFT_MID, 20, 100);

    // 这里的属性就类似style的字段, 比如调用lv_style_set_transform_height()函数, 就是修改了style的LV_STYLE_TRANSFORM_HEIGHT属性, 可以点进去看源代码.
    // 只有这些属性出现变化, 才会有transition过渡的动画效果
    static const lv_style_prop_t trans_props[] = {
        LV_STYLE_TRANSFORM_WIDTH,
        // LV_STYLE_TRANSFORM_HEIGHT,
        LV_STYLE_TRANSLATE_X,
        LV_STYLE_TRANSLATE_Y,
        LV_STYLE_BG_COLOR,
        0, /*End marker*/
    };
    static lv_style_transition_dsc_t trans1;
    uint32_t duration_ms = 500;
    uint32_t delay_ms = 200;
    lv_style_transition_dsc_init(&trans1, trans_props, lv_anim_path_linear, duration_ms, delay_ms, NULL);
    // lv_style_set_transition(&style_pressed, trans1);
    lv_obj_set_style_transition(btn1, &trans1, LV_STATE_PRESSED);

    static lv_style_transition_dsc_t trans2;
    uint32_t duration_ms2 = 2000;
    uint32_t delay_ms2 = 200;
    lv_style_transition_dsc_init(&trans2, trans_props, lv_anim_path_linear, duration_ms2, delay_ms2, NULL);
    lv_obj_set_style_transition(btn1, &trans2, LV_STATE_DEFAULT);
    // 父对象可拖动
    // lv_obj_set_drag_parent(btn1, true);
    // lv_obj_remove_style_all();
}

void lvgl_print_infos(lv_obj_t *obj)
{
    int32_t x, y, border_width, pad_top, pad_bottom, pad_left, pad_right, w, h, content_w, content_h;

    lv_obj_update_layout(obj);

    x = lv_obj_get_x(obj);
    y = lv_obj_get_y(obj);

    border_width = lv_obj_get_style_border_width(obj, LV_PART_MAIN);

    pad_top = lv_obj_get_style_pad_top(obj, LV_PART_MAIN);
    pad_bottom = lv_obj_get_style_pad_bottom(obj, LV_PART_MAIN);
    pad_left = lv_obj_get_style_pad_left(obj, LV_PART_MAIN);
    pad_right = lv_obj_get_style_pad_right(obj, LV_PART_MAIN);

    w = lv_obj_get_width(obj);
    h = lv_obj_get_height(obj);

    content_w = lv_obj_get_content_width(obj);
    content_h = lv_obj_get_content_height(obj);

    LV_LOG_USER(" xy:\t%d,%d\n pad:\t\t%d,%d,%d,%d\n border:\t%d\n box_w_h:\t%d,%d\n content_w_h:\t%d,%d",
                x, y,
                pad_top, pad_bottom, pad_left, pad_right,
                border_width,
                w, h,
                content_w, content_h);
}
