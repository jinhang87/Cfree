#include <iostream>

/*
	��׼���ֵĶ���
	1.���зǾ�̬��Ա����ͬ�ķ���Ȩ��
	2.�̳��������ֻ����һ�����зǾ�̬���ݳ�Ա
	3.����ĵ�һ���Ǿ�̬��Ա�������ǻ�������
	4.û���麯��
	5.û�������
	6.���зǾ�̬��Ա�����ϱ�׼��������
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
    std::cout << std::is_standard_layout<A>::value << std::endl;  // Υ������1����Աa��b���в�ͬ�ķ���Ȩ��  
    std::cout << std::is_standard_layout<B>::value << std::endl;  // Υ������2���̳���������(��)���ϵ����зǾ�̬��Ա  
    std::cout << std::is_standard_layout<C>::value << std::endl;  // Υ������3����һ���Ǿ�̬��Ա�ǻ�������  
    std::cout << std::is_standard_layout<D>::value << std::endl;  // Υ������4�����麯��  
    std::cout << std::is_standard_layout<E>::value << std::endl;  // Υ������5���������  
    std::cout << std::is_standard_layout<F>::value << std::endl;  // Υ������6���Ǿ�̬��Աx�����ϱ�׼��������  
}  