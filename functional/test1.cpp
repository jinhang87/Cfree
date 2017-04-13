#include <iostream>
#include <map>
#include <functional>

using namespace std;

// normal function
int add(int i, int j)
{
	return i+j;
}

//lambda
auto mod = [](int i, int j){return i%j;};

//函数对象类 
struct divid
{
	int operator()(int denominator, int divisor)
	{
		return denominator/divisor;
	}
}; 

map<char, function<int(int,int)>> map_binops = 
{
	{ '+', add },
	{ '-', minus<int>() },
	{ '*', [](int i, int j){return i*j;} },
	{ '/', divid() },
	{ '%', mod },
};

void test1()
{
	cout << map_binops['+'](10,5) << endl;
	cout << map_binops['-'](10,5) << endl;
	cout << map_binops['*'](10,5) << endl;
	cout << map_binops['/'](10,5) << endl;
	cout << map_binops['%'](10,5) << endl;
}
