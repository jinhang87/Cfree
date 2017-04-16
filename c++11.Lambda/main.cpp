#include <iostream>

using namespace std;


/*
	[ capture ] ( params ) mutable exception attribute -> ret { body }
	[ capture ] ( params ) -> ret { body }
	[ capture ] ( params ) { body }
	[ capture ] { body }
*/
extern void test1();
extern void test2();
int main(int argc, char *argv[])
{
	test1();
	test2();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}
