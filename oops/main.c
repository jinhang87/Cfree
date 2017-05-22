#include <stdio.h>

int fplus(int a, int b)
{
    return a/b;
    
}
#if 0
#endif

#define PROC_HINT(c)\
    {if(!(c)){printf("condition:(%s) fail and hint!\n", #c);}}

#define usr_assert(c, ret) {\
    if(!(c))\
    {\
        return (ret);\
    }\
}

char* char_get(void)
{
    //static char s_struItrHostMg[1*1024*1024*1024+1];
    //return (char*)s_struItrHostMg;
    
    //char s_struItrHostMg[1*1024*1024*1024+1023*1024*1024+1023*1024+768];
    //1073741824+1072693248+1047552+768
    char s_struItrHostMg[2147483382];
    char s_struItrHostMg2[1];
    return NULL;
    
}

int f()
{
    int c,a,b,s;
    int*p =NULL;
    char* pstru = NULL;
    char* pstr = "sadfsdfasfsadfasdfasdfsdfsdfsdfsdfsdf"\
    "sdfsdfsdfsdfsdasfasf";
    PROC_HINT("c");
    usr_assert(1 && 1 \
    && 1, 1);
    
    pstru = char_get();
    *p=4;
    return 0;
}

void f2()
{
    f();
    
}


int main()
{
    f2();
    return 0;
}
