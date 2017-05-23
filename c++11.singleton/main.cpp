#include <iostream>
#include "tamplatesingleton.h"
#include <thread>

using namespace std;

class SingletonA final : public Singleton<SingletonA>  
{  
friend Singleton<SingletonA>;  
public:  
	using Singleton<SingletonA>::getInstance;  
private:  
	SingletonA(){cout<<"SingletonA ctor"<<endl;}  
  
};  

int main(int argc, char *argv[])
{
    cout<<"Hello C-Free!"<<endl;
    
 	thread t1([](){
		SingletonA::getInstance();
		});  
	t1.detach();  
 	thread t2([](){
		SingletonA::getInstance();
		});  
	t2.detach();  
 	thread t3([](){
		SingletonA::getInstance();
		});  
	t3.detach();  
 	thread t4([](){
		SingletonA::getInstance();
		});   
	t4.detach();  
	SingletonA::getInstance();  
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
