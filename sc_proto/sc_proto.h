#ifndef _PROTO_H_
#define _PROTO_H_

#include <Python.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_DEV_NUM 12

typedef uint32_t *p_scanner_handle;

typedef uint32_t *p_dev_handle;

typedef struct s_dev_list{
   p_dev_handle dev_list[MAX_DEV_NUM];
   int dev_num;   
}dev_list, * p_dev_list;

/*
 *
 */
p_scanner_handle sc_scanner_create(void);

/*
 *
 */
void sc_scanner_delete(p_scanner_handle p_scanner);

/*
 *
 */
p_dev_list sc_scanner_scan(p_scanner_handle p_scanner);

/*
 *
 */
const char * sc_dev_getname(p_dev_handle p_dev);

/*
 *
 */
int sc_dev_setname(p_dev_handle p_dev);

/*
 *
 */
int sc_dev_getid(p_dev_handle p_dev);

/*
 *
 */
int sc_dev_setid(p_dev_handle p_dev, int dev_id);

#endif
