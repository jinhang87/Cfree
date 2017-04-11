#include <iostream>

using namespace std;

#define offsetof2(TYPE, MEMBER) ((unsigned int) &((TYPE *)0)->MEMBER)

typedef struct
{
	char a;
	int b;
	double c;
}S1;

typedef struct
{
	char a;
	S1 s;
}S2;


void test1()
{
	S1 s1;
	S2 s2;
	cout << sizeof(s1) << endl;
	cout << sizeof(s1.a) << endl;
	cout << sizeof(s1.b) << endl;
 	cout << sizeof(s1.c) << endl;
 	cout << sizeof(s2) << endl;
 	cout << offsetof2(s2, s) << endl;
}