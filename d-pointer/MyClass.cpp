
#include "MyClass.h"
#include "MyClass_p.h"

MyClass::MyClass() : d_ptr(new MyClassPrivate(this))
{
	//d_ptr = new MyClassPrivate(this);
	#define Q_D(Class) Class##Private * const d = d_func()
	//MyClassPrivate *d = d_func();
	//d->q_ptr = this; 
}

MyClass::~MyClass()
{
	
}

void MyClass::fly()
{
	handsNum = 1;
}

void MyClass::eat()
{
	//const MyClassPrivate *const d = d_func();
	MyClassPrivate * d = d_func();
	d->heartbeats = 1;
}

void MyClass::dance()
{

}

int MyClassPrivate::getHandsNum() const 
{
	const MyClass *const q = q_func();
	return q->headNum;
}