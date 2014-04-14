#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
const int MOD=19;
int getHas(char *a)
{
    int res=0,i=1;
    while(*a)
    {
        res|=(*a<<i);
        a++;
    }
    return res;
}

struct momo
{
    char str[maxn];
    int has;
    momo(char *s){
        strcpy(str,s);
        has=getHas(str);
        next=NULL;
    }
    momo(){next=0;}
    momo *next;
    bool operator==(const momo &a)
    {
        for(int i=0;str[i-1];i++)
        {
            if(str[i]!=a[i]) return false;
        }
        return true;
    }
};
momo MHashead[20];

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
