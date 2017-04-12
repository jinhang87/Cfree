#include <type_traits>
#include <iostream>


//std::is_function
int isf_a(int i){return i;}                           // function
int(*isf_b)(int)=isf_a;                                   // pointer to function
struct isf_C { int operator()(int i){return i;} } isf_c;  // function-like class 

void test1()
{
	// print as true & false
	std::cout << std::boolalpha;
		
	//std::is_void
    std::cout << "is_void.int: " << std::is_void<int>::value << std::endl;
    std::cout << "is_void.void: " << std::is_void<void>::value << std::endl;
	
	//std::is_integral
	int a = 0;	
	std::cout << "is_integral.int " << std::is_integral<decltype(a)>::value << std::endl;
	std::cout << "is_integral.double " << std::is_integral<double>::value << std::endl;
	std::cout << "is_integral.bool " << std::is_integral<bool>::value << std::endl;
	
	//std::is_floating_point
  	std::cout << "is_floating_point.int: " << std::is_floating_point<int>::value << std::endl;
  	std::cout << "is_floating_point.float: " << std::is_floating_point<float>::value << std::endl;
  	std::cout << "is_floating_point.const double: " << std::is_floating_point<const double>::value << std::endl;
	  	  	
 	//std::is_array
	std::cout << "is_array.int: " << std::is_array<int>::value << std::endl;
	std::cout << "is_array.int[3]: " << std::is_array<int[3]>::value << std::endl;
	//std::cout << "is_array.array<int,3>: " << std::is_array<std::array<int,3>>::value << std::endl;
	std::cout << "is_array.string: " << std::is_array<std::string>::value << std::endl;
	std::cout << "is_array.string[3]: " << std::is_array<std::string[3]>::value << std::endl; 	
 	
 	//std::is_enum
 	{
 	enum A {first,second,third};
 	class B {};
 	enum class C {alpha,beta,gamma}; //enum class
	std::cout << "is_enum.A: " << std::is_enum<A>::value << std::endl;
	std::cout << "is_enum.B: " << std::is_enum<B>::value << std::endl;
	std::cout << "is_enum.C: " << std::is_enum<C>::value << std::endl;
	std::cout << "is_enum.decltype(C::alpha): " << std::is_enum<decltype(C::alpha)>::value << std::endl;
 	}
 	
  	//std::is_union
  	
  	
  	
 	//std::is_class
 	{
	struct A {};
	class B {};
	union C {int i; float f;};
	enum class D {x,y,z};	
	std::cout << "is_class.A: " << std::is_class<A>::value << std::endl;
	std::cout << "is_class.B: " << std::is_class<B>::value << std::endl;
	std::cout << "is_class.C: " << std::is_class<C>::value << std::endl;
	std::cout << "is_class.D: " << std::is_class<D>::value << std::endl;	 	
	}
 	
 	//std::is_function
	std::cout << "is_function.decltype(a): " << std::is_function<decltype(isf_a)>::value << std::endl;
	std::cout << "is_function.decltype(b): " << std::is_function<decltype(isf_b)>::value << std::endl;
	std::cout << "is_function.decltype(c): " << std::is_function<decltype(isf_c)>::value << std::endl;
	std::cout << "is_function.C: " << std::is_function<isf_C>::value << std::endl;
	std::cout << "is_function.int(int): " << std::is_function<int(int)>::value << std::endl;
	std::cout << "is_function.int(*)(int): " << std::is_function<int(*)(int)>::value << std::endl;
 	
  	//std::is_pointer
	std::cout << "is_pointer.int: " << std::is_pointer<int>::value << std::endl;
    std::cout << "is_pointer.int*: " << std::is_pointer<int*>::value << std::endl;
    std::cout << "is_pointer.int**: " << std::is_pointer<int**>::value << std::endl;
    std::cout << "is_pointer.int(*)(int): " << std::is_pointer<int(*)(int)>::value << std::endl;
    
    
    //std::is_same
    {
	typedef int integer_type;
	struct A { int x,y; };
	struct B { int x,y; };
	typedef A C;

    std::cout << "is_same.int, const int: " << std::is_same<int, const int>::value << std::endl;
    std::cout << "is_same.int, integer_type: " << std::is_same<int, integer_type>::value << std::endl;
    std::cout << "is_same.A, B: " << std::is_same<A,B>::value << std::endl;
    std::cout << "is_same.A, C: " << std::is_same<A,C>::value << std::endl;
    std::cout << "is_same.signed char, std::int8_t: " << std::is_same<signed char,std::int8_t>::value << std::endl;   
    }
    
    //std::is_base_of
    {
	struct A {};
	struct B : A {};
  	std::cout << "is_base_of.int, int: " << std::is_base_of<int,int>::value << std::endl;
  	std::cout << "is_base_of.A, A: " << std::is_base_of<A,A>::value << std::endl;
  	std::cout << "is_base_of.A, B: " << std::is_base_of<A,B>::value << std::endl;
  	std::cout << "is_base_of.A, const B: " << std::is_base_of<A,const B>::value << std::endl;
  	std::cout << "is_base_of.A&, B&: " << std::is_base_of<A&,B&>::value << std::endl;
  	std::cout << "is_base_of.B, A: " << std::is_base_of<B,A>::value << std::endl;    	
    }
	
	
	  
}