#include <iostream>

using namespace std;


extern void test1();


/*
	C++ 11添加了两个继承控制关键字：override和final。
	override确保在派生类中声明的重载函数跟基类的虚函数有相同的签名。
	final阻止类的进一步派生和虚函数的进一步重载。
*/

int main(int argc, char *argv[])
{
	test1();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}
