#include <iostream>

#define HAS_MEMBER(member)\
    template<typename T, typename... Args>struct has_member_##member\
{\
private:\
    template<typename U> static auto Check(int) -> decltype(std::declval<U>().member(std::declval<Args>()...), std::true_type()); \
    template<typename U> static auto Check(...) -> decltype(std::false_type()); \
public:\
static const bool value = std::is_same<decltype(Check<T>(0)), std::true_type>::value; \
}; \


HAS_MEMBER(a)
HAS_MEMBER(c)

struct A
{
    A(int) {}
    void b() {}
    void c(int, bool) {}
};

void example_has_member()
{
	std::cout << has_member_a<A>::value << std::endl;
    std::cout << has_member_c<A, int, bool>::value << std::endl;
    std::cout << has_member_c<A, int>::value << std::endl;
}


