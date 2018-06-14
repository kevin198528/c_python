#include <stdio.h>
#include "./sc_proto.h"

#define with_init(code) {\
	Py_Initialize();\
	get_current();\
	{code}\
	Py_Finalize();\
}

#define __py_init__ {\
Py_Initialize();\
get_current();\
}

#define __py_release__ {\
Py_Finalize();\
}

dev_list g_dev_list;

const char * s_py_path = "sys.path.append('../../PycharmProjects/\
server_client/server_client/devices')";

void get_current(void)
{
   PyRun_SimpleString("import sys");
   PyRun_SimpleString("sys.path.append('./')");
   PyRun_SimpleString(s_py_path);
}

PyObject * get_func_from_module(const char * m, const char * f)
{
   PyObject *pModule = NULL, *pDict = NULL, *pFunc = NULL;
   pModule = PyImport_ImportModule(m);
   pFunc = PyObject_GetAttrString(pModule, f);
   return pFunc;
}

/*
 *  API : scanner
 */

p_scanner_handle sc_scanner_create(void)
{
	PyObject *p_class = NULL, *p_ins = NULL;

	__py_init__

   p_class = get_func_from_module("scanner", "Scanner");
	p_ins = PyObject_CallObject(p_class, NULL);

	return (p_scanner_handle)p_ins;
}

void sc_scanner_delete(p_scanner_handle p_scanner)
{
	PyObject *pFunc = NULL;

	if (p_scanner) {
		Py_DECREF(p_scanner);	
		printf("free p_scanner\n");
	}

	__py_release__
}

p_dev_list sc_scanner_scan(p_scanner_handle p_scanner)
{
	PyObject *p_ins = (PyObject *)p_scanner;

	printf("in sc_scanner_scan : 0x%x\n", p_ins);
	PyObject_CallMethod(p_ins, "scanning", NULL);
}

