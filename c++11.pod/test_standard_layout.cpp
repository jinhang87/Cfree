#include <iostream>

/*
	标准布局的定义
	1.所有非静态成员有相同的访问权限
	2.继承树中最多只能有一个类有非静态数据成员
	3.子类的第一个非静态成员不可以是基类类型
	4.没有虚函数
	5.没有虚基类
	6.所有非静态成员都符合标准布局类型
*/


class A   
{   
private:  
    int a;  
public:  
    int b;  
};  
  
class B1  
{  
    static int x1;  
};  
  
class B2  
{  
    int x2;  
};  
  
class B : B1, B2  
{  
    int x;  
};  
  
class C1 {};  
class C : C1  
{  
    C1 c;  
};  
  
class D { virtual void foo() = 0; };  
class E : D {};  
class F { A x; };  
  
void test_standard_layout()
{  
    std::cout << std::is_standard_layout<A>::value << std::endl;  // 违反定义1。成员a和b具有不同的访问权限  
    std::cout << std::is_standard_layout<B>::value << std::endl;  // 违反定义2。继承树有两个(含)以上的类有非静态成员  
    std::cout << std::is_standard_layout<C>::value << std::endl;  // 违反定义3。第一个非静态成员是基类类型  
    std::cout << std::is_standard_layout<D>::value << std::endl;  // 违反定义4。有虚函数  
    std::cout << std::is_standard_layout<E>::value << std::endl;  // 违反定义5。有虚基类  
    std::cout << std::is_standard_layout<F>::value << std::endl;  // 违反定义6。非静态成员x不符合标准布局类型  
}  