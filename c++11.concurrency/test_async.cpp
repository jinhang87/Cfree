#include <string>
#include <future>
#include <iostream>

struct X
{
	void foo(int a,std::string const& b){
		std::cout << "foo a=" << a << ", b=" << b <<std::endl;
	}
	std::string bar(std::string const& a){
		std::string s;
		std::cout << "bar a=" << a <<std::endl;
		return s;
	}
};
struct Y
{
	double operator()(double a){
		std::cout << "Y operator() a=" << a <<std::endl;
	}
};


class move_only
{ 
public:
	move_only(){
		std::cout << "move_only()" << std::endl;
	}
	move_only(move_only&&){
		std::cout << "move_only(move_only&&)" << std::endl;
	}
	move_only(move_only const&) = delete;
	move_only& operator=(move_only&&){
		std::cout << "move_only& operator=(move_only&&)" << std::endl;
	}
	move_only& operator=(move_only const&) = delete;
	void operator()(){
		std::cout << "void operator()()" << std::endl;
	}
};

void test_async()
{
	std::cout << "test_async" << std::endl;
	X x;
	auto f1=std::async(&X::foo,&x,42,"hello"); // ����p->foo(42, "hello")��p��ָ��x��ָ��
	auto f2=std::async(&X::bar,x,"goodbye"); // ����tmpx.bar("goodbye")�� tmpx��x�Ŀ�������	
	f1.get();
	f2.get();
	
	Y y;
	auto f3=std::async(Y(),3.141); // ����tmpy(3.141)��tmpyͨ��Y���ƶ����캯���õ�
	auto f4=std::async(std::ref(y),2.718); // ����y(2.718)
	f3.get();
	f4.get();
	
	//X baz(X&);
	//auto f10=std::async(baz, std::ref(x)); // ����baz(x)
	
	auto f5=std::async(move_only()); // ����tmp()��tmp��ͨ��std::move(move_only())����õ�
	auto f6=std::async(std::launch::async,Y(),1.2); // �����߳���ִ��
	//auto f7=std::async(std::launch::deferred,baz,std::ref(x)); // ��wait()��get()����ʱִ��
	//auto f8=std::async(std::launch::deferred | std::launch::async, baz,std::ref(x)); // ʵ��ѡ��ִ�з�ʽ
	//auto f9=std::async(baz,std::ref(x));
	//f7.wait(); // �����ӳٺ���	
}