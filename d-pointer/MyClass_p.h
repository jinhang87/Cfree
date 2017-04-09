
class MyClass;
class MyClassPrivate
{
public:
	MyClassPrivate(MyClass *parent): q_ptr(parent){}
	int getHandsNum() const;
	int heartbeats;	
private:
	MyClass* q_ptr;
	inline MyClass* q_func(){return reinterpret_cast<MyClass*>(q_ptr);}
	inline const MyClass* q_func() const{return reinterpret_cast<const MyClass*>(q_ptr);}
};