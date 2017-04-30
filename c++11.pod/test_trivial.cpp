
#include <iostream>

/*
	平凡的定义
	1.有平凡的构造函数
	2.有平凡的拷贝构造函数
	3.有平凡的移动构造函数
	4.有平凡的拷贝赋值运算符
	5.有平凡的移动赋值运算符
	6.有平凡的析构函数
	7.不能包含虚函数
	8.不能包含虚基类
*/

class A { A(){} };  
class B { B(B&){} };  
class C { C(C&&){} };  
class D { D operator=(D&){} };  
class E { E operator=(E&&){} };  
class F { ~F(){} };  
class G { virtual void foo() = 0; };  
class H : G {};  
class I {};  


void test_trivial()  
{  
    std::cout << std::is_trivial<A>::value << std::endl;  // 有不平凡的构造函数  
    std::cout << std::is_trivial<B>::value << std::endl;  // 有不平凡的拷贝构造函数  
    std::cout << std::is_trivial<C>::value << std::endl;  // 有不平凡的拷贝赋值运算符  
    std::cout << std::is_trivial<D>::value << std::endl;  // 有不平凡的拷贝赋值运算符  
    std::cout << std::is_trivial<E>::value << std::endl;  // 有不平凡的移动赋值运算符  
    std::cout << std::is_trivial<F>::value << std::endl;  // 有不平凡的析构函数  
    std::cout << std::is_trivial<G>::value << std::endl;  // 有虚函数  
    std::cout << std::is_trivial<H>::value << std::endl;  // 有虚基类  
  
    std::cout << std::is_trivial<I>::value << std::endl;  // 平凡的类  
}  