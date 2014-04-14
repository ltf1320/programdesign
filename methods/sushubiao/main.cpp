#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


bool isn[100000000]={0};
int sushu[1000000];
void printpri(int n)
{
    int k=0,i;
    int sqrtn=sqrt(n);
    for(i=4;i<n;i+=2)
        isn[i]=1;
    sushu[k++]=2;
    for(i=3;i<sqrtn;i+=2)
        if(isn[i]==0)
        {
            sushu[k++]=i;
            for(int s=2*i,j=i*i;j<n;j+=s)
                isn[j]=1;
        }
    for(;i<n;i++)
        if(isn[i]==0)
            sushu[k++]=i;
    for(i=0;i!=k;++i)
        cout<<sushu[i]<<endl;
}

int main()
{
    freopen("out.txt","w",stdout);
    printpri(1000000);
}
