#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class HugeMem
{  
public:  
    HugeMem(int size): sz(size > 0 ? size : 1) 
	{  
        c = new int[sz];
        cout << "HugeMem()" << endl;
    }  
    ~HugeMem() 
	{ 
		delete [] c; 
		cout << "~HugeMem()" << endl;
	}  
    HugeMem(HugeMem && hm): sz(hm.sz), c(hm.c) 
	{  
        hm.c = nullptr; 
		cout << "move HugeMem()" << endl; 
    }  
    int * c;  
    int sz;  
};  

class Moveable
{  
public:  
    Moveable():i(new int(3)), h(1024) 
	{
		cout << "Moveable()" << endl;
	}  
    ~Moveable() 
	{ 
		delete i;
		cout << "~Moveable()" << endl; 
	}  
    Moveable(Moveable && m):  i(m.i), h(move(m.h))
	{
        m.i = nullptr;  
        cout << "move Moveable()" << endl; 
    }  
    int* i;  
    HugeMem h;  
};  
 
Moveable GetTemp() {  
	cout << __func__  << " start" << endl;
    Moveable tmp = Moveable();  
    cout << hex << "Huge Mem from " << __func__ 
        << " @" << tmp.h.c << endl; // Huge Mem from GetTemp @0x603030  
    return tmp;  
}  

void test3()
{
	cout << __func__  << " start" << endl;
    Moveable a(GetTemp());  
    cout << hex << "Huge Mem from " << __func__ 
        << " @" << a.h.c << endl;   // Huge Mem from main @0x603030  	
}