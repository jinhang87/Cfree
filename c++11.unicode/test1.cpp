//#include<tchar.h>
//#include<locale>
//#include<codecvt>
#include<iostream>
#include<wchar.h>

const char *s = u8"��ã����磡";
//const char16_t *us = u"�ã����磡";
const char32_t *ds = U"This is a UTF-32 string.";

void test1()
{
	//1��ԭʼ�ַ������� 
	std::cout << R"(����\n\n\n\n)" << std::endl;
	std::cout << R"delimiter(The String Data \ Stuff " )delimiter" << std::endl;
	//std::cout << u8"����" << std::endl;
	//std::cout << u"����" << std::endl;
	//std::cout << U"����" << std::endl;
}