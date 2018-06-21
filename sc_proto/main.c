#include <stdio.h>
#include "./sc_proto.h"

int main(int argc, char ** argv)
{

	p_scanner_handle p_scanner = NULL;
	p_dev_list p_camera_list = NULL;	

	p_scanner = sc_scanner_create();

	printf("create scanner 0x%x\n", (unsigned int)p_scanner);

	p_camera_list = sc_scanner_scan(p_scanner);

	printf("camera number : %d\n", p_camera_list->dev_num);

	for (int i = 0; i < p_camera_list->dev_num; i++) {
		printf("get camera : %s\n", sc_dev_getname(p_camera_list->dev_list[i]));
	}

	sc_scanner_delete(p_scanner);

/*
	void * p = malloc(10*1024*1024);

	printf("buff p: %x\n", p);
*/
	return 0;
}
