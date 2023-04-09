#ifndef __UIOBJ_POPCONFIRM_H_
#define __UIOBJ_POPCONFIRM_H_
#include "lvgl/lvgl.h"


#define POPCONFIRM_WIDTH    (640)
#define POPCONFIRM_HIGH    (360)



struct popattr_st{
    lv_obj_t *parent;
    char *title_str;
    char *cfirm_str;
    char *canel_str;
    lv_event_cb_t cfirm_cb;
    lv_event_cb_t cancl_cb;
};

struct popcfirm_st{
    lv_obj_t *bg_obj;
    lv_obj_t *title_labl;
    lv_obj_t *title_bg;
    lv_obj_t *cfirm_labl;
    lv_obj_t *cfirm_bg;
    lv_obj_t *cancl_labl;
    lv_obj_t *cancl_bg;
    lv_style_t *btn_styl;
};

struct popcfirm_st* popconfirm_create_show(struct popattr_st *pattr);

//void popconfirm_destroy(struct popconfirm_st *popcfirm);

#endif