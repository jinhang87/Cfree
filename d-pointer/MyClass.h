
class MyClassPrivate;
class MyClass
{
public:
	explicit MyClass();
	~MyClass();
	void fly();
	void eat();
	void dance();
public:
	int handsNum;
	int headNum;
private:
	MyClassPrivate *const d_ptr;
	inline MyClassPrivate* d_func(){
		return reinterpret_cast<MyClassPrivate*>(d_ptr);
		}
	inline const MyClassPrivate* d_func() const{
		return reinterpret_cast<const MyClassPrivate*>(d_ptr);
		}
	friend class MyClassPrivate;
};

