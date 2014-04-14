#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a,b,c;
    int res,mi;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        mi=min(a,min(b,c));
        res=mi+(a-mi)/3+(b-mi)/3+(c-mi)/3;
        if(mi>=1) res=max(res,mi-1+(a-mi+1)/3+(b-mi+1)/3+(c-mi+1)/3);
        if(mi>=2)res=max(res,mi-2+(a-mi+2)/3+(b-mi+2)/3+(c-mi+2)/3);
        if(mi>=3)res=max(res,mi-3+(a-mi+3)/3+(b-mi+3)/3+(c-mi+3)/3);
        printf("%d\n",res);
    }
    return 0;
}
