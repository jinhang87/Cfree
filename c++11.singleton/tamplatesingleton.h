#include <iostream>
template <typename T> class Singleton  {  
protected:  
	static T& getInstance()  {  
		static T instance;  
		return instance;  
	}  
protected:  
	Singleton(){std::cout<<"Singleton ctor"<<std::endl;}  
  
};  
