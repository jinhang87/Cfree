#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

template<class ... Types> struct Tuple { };

Tuple<> t0;    // Types�����κ�ʵ��
Tuple<int> t1;    // Types����һ��ʵ�Σ�int
Tuple<int, float> t2;    // Types��������ʵ�Σ�int��float
//Tuple<0> error;    // ����0����һ������


template <typename... TS>   // typename... TSΪģ���βΰ���TSΪģʽ
static void MyPrint(const char* s, TS... args)  // TS... argsΪ�����βΰ���argsΪģʽ
{
    printf(s, args...);
}

template <typename... TS> 
struct SomeStruct
{
	static const int size = sizeof...(TS);//��䳤��������
};



// ��ͨ��C�����䳤�β�
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