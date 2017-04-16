#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
	Test(){cout << "ctor\n";}
	Test(const Test & m) {cout << "copy\n";}
	Test(Test && m) {cout << "move\n";}
	~Test(){ cout << "dtor\n";}
};

Test Get()
{
	Test t;
	return t;
}

void v_1()
{
	std::vector<Test> v;
    v.push_back(Test());
}

void v_2()
{
	Test m(Get());	//±àÒëÆ÷ÓÅ»¯ copy elision 
}

int test1()
{
	//v_1();
	v_2();
	return 0;
}