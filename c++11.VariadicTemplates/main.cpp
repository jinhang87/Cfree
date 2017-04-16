#include <iostream>

using namespace std;

extern void test1();
extern void test2();
int main(int argc, char *argv[])
{
	test1();
	test2();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}
