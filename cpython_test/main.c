#include <stdio.h>
#include <python3.6m/Python.h>

#define with_init(code) {\
	Py_Initialize();\
	get_current();\
	{code}\
	Py_Finalize();\
}

PyObject * get_func_from_module(const char * m, const char * f)
{
	PyObject *pModule = NULL, *pDict = NULL, *pFunc = NULL;
	pModule = PyImport_ImportModule(m);
//	pDict = PyModule_GetDict(pModule);
//	pFunc = PyDict_GetItemString(pDict, f);
	pFunc = PyObject_GetAttrString(pModule, f);
	return pFunc;	
}

void get_current(void)
{
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
}

void test(void)
{
   Py_Initialize();
   PyRun_SimpleString("print('hello python')");
   Py_Finalize();
}

void test1(void)
{
	PyObject *pFunc = NULL, *pArg = NULL;

	with_init(
		pFunc = get_func_from_module("demo", "print_arg");
//		pFunc = PyObject_GetAttrString(pModule, "print_arg");
		pArg = Py_BuildValue("(s)", "hello python");
		PyEval_CallObject(pFunc, pArg);
	)
}

void test2(void)
{
	PyObject *pFunc = NULL, *pArg = NULL, *result = NULL;
	int sum;

	with_init(
		pFunc = get_func_from_module("demo", "add");	
		pArg = Py_BuildValue("(i, i)", 1, 2);
		result = PyEval_CallObject(pFunc, pArg);
		PyArg_Parse(result, "i", &sum);
		printf("sum=%d\n", sum);
	)
}

void test3(void)
{
	PyObject *pClass = NULL, *arg = NULL, *pIns = NULL, *result = NULL;
	char * name = NULL;	

	with_init(
		pClass = get_func_from_module("demo", "Scanner");
printf("1\n");		
//		arg = PyTuple_New(1);

//		PyTuple_SetItem(arg, 1, Py_BuildValue("(s)", "kevin"));

//		pIns = PyObject_Call(pClass, arg, NULL);

		pIns = PyInstanceMethod_New(pClass);	
printf("2\n");
//		pIns = PyInstanceMethod_New(pClass);
		result = PyObject_CallMethod(pIns, "scan", NULL);
		
//		PyArg_Parse(result, "s", &name);
//		printf("%s\n", name);
	)
}

void test5(void)
{
    Py_Initialize();    

	get_current();
  
    PyObject * pModule = NULL;    
    PyObject * pFunc = NULL;   
//    pModule = PyImport_ImportModule("demo");//Test001:Python文件名   
printf("1\n"); 
  //  pFunc   = PyObject_GetAttrString(pModule, "TestDict"); //Add:Python文件中的函数名  
    //获取Person类    
//    PyObject *pClassPerson = PyObject_GetAttrString(pModule, "Hello");  
printf("2\n");
    //创建Person类的实例  
    //PyObject *pInstancePerson = PyInstance_New(pClassPerson, NULL, NULL);//Python2.7有该接口，Python3.5没有该接口。  
	PyObject *pClassPerson = get_func_from_module("demo", "Hello");

//    arg = PyTuple_New(0);

	 PyObject * arg = NULL; 
	arg = Py_BuildValue("(s)", "kevin");

//	 PyTuple_SetItem(arg, 0, Py_BuildValue("(s)", "kevin"));
//printf("5\n");
    PyObject *pInstancePerson = PyObject_Call(pClassPerson, arg, NULL);//PyInstanceMethod_New(pClassPerson);
//printf("6\n");
//	int ret = PyObject_IsInstance(pInstancePerson, pClassPerson);
//printf("7\n"); 
//	int ret1 = PyInstanceMethod_Check(pInstancePerson);
 
//printf("3:%d:%d\n", ret, ret1);
    //调用方法    
//    PyObject_CallMethod(pInstancePerson, "greet", "s", "Hello Kitty"); //s表示传递的是字符串,值为"Hello Kitty"    
 printf("9\n");
    Py_Finalize();  
}

void call_python_fun_test(void)
{
	PyObject *pFunc = NULL;
	int sum;

	with_init(
		pFunc = get_func_from_module("demo", "create_scanner");
		PyObject_CallFunction(pFunc, NULL);
		pFunc = get_func_from_module("demo", "delete_scanner");
		PyObject_CallFunction(pFunc, NULL);
	)
}


int main(int argc, char ** argv)
{
	call_python_fun_test();

	return 0;
}
