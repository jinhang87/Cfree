#include <iostream>
#include <utility>
#include <vector>
#include <string>

//C++0x
using namespace std;


extern void test1();
extern void test2();
extern void test3();

int main(int argc, char *argv[])
{
	//test1();
	//test2();
	test3();
    
	cout<<"Hello C-Free!"<<endl;
	return 0;
}
