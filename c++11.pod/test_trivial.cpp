
#include <iostream>

/*
	ƽ���Ķ���
	1.��ƽ���Ĺ��캯��
	2.��ƽ���Ŀ������캯��
	3.��ƽ�����ƶ����캯��
	4.��ƽ���Ŀ�����ֵ�����
	5.��ƽ�����ƶ���ֵ�����
	6.��ƽ������������
	7.���ܰ����麯��
	8.���ܰ��������
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
    std::cout << std::is_trivial<A>::value << std::endl;  // �в�ƽ���Ĺ��캯��  
    std::cout << std::is_trivial<B>::value << std::endl;  // �в�ƽ���Ŀ������캯��  
    std::cout << std::is_trivial<C>::value << std::endl;  // �в�ƽ���Ŀ�����ֵ�����  
    std::cout << std::is_trivial<D>::value << std::endl;  // �в�ƽ���Ŀ�����ֵ�����  
    std::cout << std::is_trivial<E>::value << std::endl;  // �в�ƽ�����ƶ���ֵ�����  
    std::cout << std::is_trivial<F>::value << std::endl;  // �в�ƽ������������  
    std::cout << std::is_trivial<G>::value << std::endl;  // ���麯��  
    std::cout << std::is_trivial<H>::value << std::endl;  // �������  
  
    std::cout << std::is_trivial<I>::value << std::endl;  // ƽ������  
}  