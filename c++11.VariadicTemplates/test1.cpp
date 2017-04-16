#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

template<class ... Types> struct Tuple { };

Tuple<> t0;    // Types不含任何实参
Tuple<int> t1;    // Types含有一个实参：int
Tuple<int, float> t2;    // Types含有两个实参：int和float
//Tuple<0> error;    // 错误：0不是一个类型


template <typename... TS>   // typename... TS为模板形参包，TS为模式
static void MyPrint(const char* s, TS... args)  // TS... args为函数形参包，args为模式
{
    printf(s, args...);
}

template <typename... TS> 
struct SomeStruct
{
	static const int size = sizeof...(TS);//求变长参数个数
};



// 普通的C函数变长形参
static void MyCPrint(const char *s, ...)
{
    char strBuffer[1024];
    va_list ap;
    va_start(ap, s);
    vsprintf(strBuffer, s, ap);
    va_end(ap);
    printf(strBuffer);
}


void test1()
{
	SomeStruct<int, double , float> st;
	cout <<  "size = " << st.size << endl;
}