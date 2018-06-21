#include <stdio.h>
#include "./sc_proto.h"

#define DEBUG 1

#define with_init(code) \
do{\
	Py_Initialize();\
	get_current();\
	do{code}while(0);\
	Py_Finalize();\
}while(0);

#define __py_init__ {\
Py_Initialize();\
get_current();\
}

#define __py_release__ {\
Py_Finalize();\
}

#ifdef DEBUG
#define __debug__(code) \
do{\
	printf("\n<debug-in> - %s <- %s\n", __func__, __FILE__);\
	do{code}while(0);\
	printf("<debug-out> - %s <- %s\n\n", __func__, __FILE__);\
}while(0);
#else
#define __debug__(code) \
do{\
	do{code}while(0);\
}while(0);
#endif
	
dev_list g_dev_list;

void get_current(void)
{ 
   PyRun_SimpleString("import sys");
   PyRun_SimpleString("sys.path.append('./')");
//   PyRun_SimpleString("sys.path.append('./python/')");

//   PyRun_SimpleString("sys.path.append('/home/zjq/c_python/sc_proto/python/')");
	PyRun_SimpleString("sys.path.append('/home/zjq/PycharmProjects/\
server_client/')");
//	PyRun_SimpleString();
}

PyObject * get_func_from_module(const char * m, const char * f)
{
   PyObject *pModule = NULL, *pDict = NULL, *pFunc = NULL;

	__debug__(
   pModule = PyImport_ImportModule(m);
   pFunc = PyObject_GetAttrString(pModule, f);
	)
   return pFunc;
}

/*
 *  API : scanner
 */

p_scanner_handle sc_scanner_create(void)
{
	PyObject *p_class = NULL, *p_ins = NULL;

	__debug__(	
	__py_init__
   p_class = get_func_from_module("devices.scanner", "Scanner");
	p_ins = PyObject_CallObject(p_class, NULL);
	)
	return (p_scanner_handle)p_ins;
}

void sc_scanner_delete(p_scanner_handle p_scanner)
{
	PyObject *pFunc = NULL;

	__debug__(
	if (p_scanner) 
		Py_DECREF(p_scanner);	
		
	__py_release__
	)
}

p_dev_list sc_scanner_scan(p_scanner_handle p_scanner)
{
	PyObject *p_list = NULL, *p_str = NULL;	
	char * p_name = NULL;

	__debug__(
	g_dev_list.dev_num = 0;
	memset(g_dev_list.dev_list, 0, sizeof(p_dev_handle)*MAX_DEV_NUM);

	PyObject *p_ins = (PyObject *)p_scanner;
	p_list = PyObject_CallMethod(p_ins, "scanning", NULL);
	for (int index = 0; index < PyList_Size(p_list); index++) {
		p_str = PyList_GetItem(p_list, index);
//		PyArg_Parse(p_str, "s", &p_name);
//		printf("device_name : %s\n", p_name);

		g_dev_list.dev_list[index] = (p_dev_handle)p_str;			
		g_dev_list.dev_num += 1;
	}
	)

	return &g_dev_list;
}

const char * sc_dev_getname(p_dev_handle p_dev)
{
	const char * p_dev_name = NULL;
	PyObject *p_dev_ins = (PyObject *)p_dev;
	PyObject *p_str = PyObject_CallMethod(p_dev_ins, "get_name", NULL);	

	PyArg_Parse(p_str, "s", &p_dev_name);
	return p_dev_name;
}


