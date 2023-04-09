#include <stdio.h>
#include <stdlib.h>
#include "lvgl/lvgl.h"
#include "uiobj_popconfirm.h"


static lv_obj_t* popconfirm_draw_base_bg(lv_obj_t *parent)
{
    lv_obj_t *obj;
    obj = lv_obj_create(parent);
    lv_obj_set_size(obj, POPCONFIRM_WIDTH, POPCONFIRM_HIGH);
    lv_obj_align(obj,LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(obj,0, 0);
    lv_obj_set_style_border_width(obj, 0, 0);
    lv_obj_set_style_bg_color(obj, lv_color_make(240, 240 ,240), 0);
    return obj;
}

static void popconfirm_draw_tittle(struct popcfirm_st *popcfirm, char *title_str)
{
                /* title bg */
    lv_obj_t *lvtitle_bg;
    lv_obj_t *lvtitle_labl;
    popcfirm->title_bg = lv_obj_create(popcfirm->bg_obj);
    lvtitle_bg = popcfirm->title_bg;
    lv_obj_set_style_bg_color(lvtitle_bg, lv_color_make(232, 232, 232), 0);
    lv_obj_set_style_radius(lvtitle_bg, lv_obj_get_style_radius(popcfirm->bg_obj, 0), 0);
    lv_obj_set_size(lvtitle_bg, POPCONFIRM_WIDTH, 50);
    lv_obj_set_pos(lvtitle_bg, 0, 0);
    lv_obj_set_style_pad_all(lvtitle_bg,0, 0);
    lv_obj_set_style_border_width(lvtitle_bg, 0, 0);

                /* title text */
    popcfirm->title_labl = lv_label_create(popcfirm->title_bg);
    lvtitle_labl = popcfirm->title_labl;
    lv_obj_set_align(lvtitle_labl, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(lvtitle_labl, &lv_font_montserrat_22, 0);
    lv_obj_set_style_text_color(lvtitle_labl, lv_color_white(), 0);
    if(title_str != NULL) {
        lv_label_set_text(lvtitle_labl, title_str);
    }
}

static void popcfirm_draw_option_button(struct popcfirm_st *popcfirm, struct popattr_st *pattr)
{
    lv_style_t *btnbg_defutyle = popcfirm->btn_styl;
    lv_style_init(btnbg_defutyle);
    popcfirm->cfirm_bg = lv_obj_create(popcfirm->bg_obj);
    popcfirm->cancl_bg = lv_obj_create(popcfirm->bg_obj);
    popcfirm->cfirm_labl = lv_label_create(popcfirm->cfirm_bg);
    popcfirm->cancl_labl = lv_label_create(popcfirm->cancl_bg);

        /* bg common style .default state*/
    lv_style_set_radius(btnbg_defutyle, lv_obj_get_style_radius(popcfirm->bg_obj, 0));
    lv_style_set_pad_all(btnbg_defutyle, 0);
    lv_style_set_width(btnbg_defutyle, 100);
    lv_style_set_height(btnbg_defutyle, 50);
    lv_style_set_bg_color(btnbg_defutyle, lv_color_make(30, 130, 236));
    lv_obj_add_style(popcfirm->cancl_bg, btnbg_defutyle, LV_STATE_DEFAULT);
    lv_obj_add_style(popcfirm->cfirm_bg, btnbg_defutyle, LV_STATE_DEFAULT);

    lv_obj_align(popcfirm->cfirm_bg, LV_ALIGN_BOTTOM_LEFT, 50, -30);     /* posotion */
    lv_obj_set_style_bg_color(popcfirm->cfirm_bg, lv_color_make(232, 232, 232), LV_STATE_PRESSED);  /* bg pressed */

    lv_obj_align(popcfirm->cancl_bg, LV_ALIGN_BOTTOM_RIGHT, -50, -30);      /* posotion */
    lv_obj_set_style_bg_color(popcfirm->cancl_bg, lv_color_make(232, 232, 232), LV_STATE_PRESSED);  /* bg pressed */

        /* text common style. */
}

struct popcfirm_st* popconfirm_create_show(struct popattr_st *pattr)
{
    struct popcfirm_st *popcfirm;

    if(pattr == NULL || pattr->parent == NULL) {
        return NULL;
    }
    popcfirm = malloc(sizeof(struct popcfirm_st));
    if(popcfirm == NULL) {
        perror("Error: popcfirm malloc failed! \n");
        return NULL;
    }
    popcfirm->btn_styl = malloc(sizeof(lv_style_t));
    if(popcfirm->btn_styl == NULL) {
        perror("Error: btn_styl malloc failed! \n");
        return NULL;
    }
    popcfirm->bg_obj = popconfirm_draw_base_bg(pattr->parent);
    popconfirm_draw_tittle(popcfirm, pattr->title_str);
    popcfirm_draw_option_button(popcfirm, pattr);
    return popcfirm;
}

/*
void popconfirm_destroy(struct popconfirm_st *popcfirm)
{

}
*/