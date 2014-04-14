#include <iostream>
#include <cstdio>
using namespace std;
const int day[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m,res;
    while(scanf("%d%d",&y,&m)!=EOF)
    {
        res=1;
        while(m<=day[y])
        {
            if(m%7==0){res=-1;break;}
            m+=m%7;
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
