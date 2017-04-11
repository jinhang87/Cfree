

class A
{
public:
	virtual void func(int);
};

class B: A
{
public:
	virtual void func(double) override;//complier error
	virtual void func2(int) final;
};

class C: B
{
public:
	void func2(int); //error, B::func is final
};

void test1()
{
	
}
