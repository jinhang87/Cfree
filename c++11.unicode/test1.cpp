//#include<tchar.h>
//#include<locale>
//#include<codecvt>
#include<iostream>
#include<wchar.h>

const char *s = u8"你好，世界！";
//const char16_t *us = u"好，世界！";
const char32_t *ds = U"This is a UTF-32 string.";

void test1()
{
	//1、原始字符串测试 
	std::cout << R"(中文\n\n\n\n)" << std::endl;
	std::cout << R"delimiter(The String Data \ Stuff " )delimiter" << std::endl;
	//std::cout << u8"中文" << std::endl;
	//std::cout << u"中文" << std::endl;
	//std::cout << U"中文" << std::endl;
}