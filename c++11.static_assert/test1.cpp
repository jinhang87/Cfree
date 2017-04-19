#include <type_traits>

//if support 64-bit
static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");

class MyEmptyClass
{
	void func(); //ok
	//virtual void func2();  //virtual false empty
	static void func3(); //ok
private:
	//int a;  //non-static false empty
	static int b;
};

//if class empty
static_assert(std::is_empty<MyEmptyClass>::value, "empty class needed");

void test1()
{
	
}