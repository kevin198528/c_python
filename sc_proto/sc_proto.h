#ifndef _PROTO_H_
#define _PROTO_H_

#include <Python.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_DEV_NUM 12
#define H_LINE_SIZE 2048
#define V_LINE_SIZE 2048

typedef uint32_t *p_scanner_handle;

typedef uint32_t *p_dev_handle;

typedef struct s_dev_list{
   p_dev_handle dev_list[MAX_DEV_NUM];
   int dev_num;   
}dev_list, * p_dev_list;

typedef struct s_frame{
	char * p_one_frame;
	int frame_len;	
}frame, * p_frame;

#ifdef __cplusplus
extern "C" {
#endif

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
 * ret : 0 success, -1 fail
 */
int sc_dev_open(p_dev_handle p_dev);

/*
 *
 */
void sc_dev_close(p_dev_handle p_dev);

/*
 *  get one frame
 */
p_frame sc_dev_getframe(p_dev_handle p_dev);


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

#ifdef __cplusplus
}
#endif


#endif
