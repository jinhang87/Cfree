#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
 
void test1()
{ 
    // the type of a closure cannot be named, but can be inferred with auto
    auto func1 = [](int i) { return i+4; };
    std::cout << "func1: " << func1(6) << '\n'; 
 
    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i+4; };
    std::cout << "func2: " << func2(6) << '\n'; 
}