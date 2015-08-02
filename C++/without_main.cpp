#include<stdio.h>
#define decode(b,d,c,a,p,e,f) a##b##c##d
#define begin decode(a,n,i,m,a,t,e)

int begin()
{
    printf("hi");
    return 0;
}
