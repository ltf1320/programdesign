/*打素数表解决的问题
关键在阶层不要算出来，不然会溢出，将每个数累加就行
*/

#define END_

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const int Prinum=100;
const int maxn=10000;
bool isn[maxn+1000];
int pri[Prinum];  //ËØÊý±í

int main()
{
    memset(isn,0,sizeof(isn));
    for(int i=4; i<maxn; i+=2)
        isn[i]=1;
    int k=0;
    int i;
    pri[k++]=2;
    for(i=3; i<sqrt(maxn); i+=2)
    {
        if(!isn[i])
        {
            pri[k++]=i;
            int s=2*i;
            for(int j=i*i; j<maxn; j+=s)
                isn[j]=1;
        }
    }
    for(; k<Prinum; ++i)
    {
        if(!isn[i])
            pri[k++]=i;
    }
    while(1)
    {
        int n,num;
        int result[Prinum+10]= {0};
        cin>>n;
        if(n==0) break;
        for(int k=2; k<=n; k++)
        {
            num=k;
            for(i=0; i<Prinum; ++i)
            {
                while(1)
                {
                    if(!(num%pri[i]))
                    {
#ifndef END_
                        cout<<num<<" "<<pri[i]<<endl;
                        system("pause");
#endif
                        num/=pri[i];
                        result[i]++;
                    }
                    else break;
                }
                if(num==1)
                    break;
            }
        }
        for(i=Prinum-1; i>=0; --i)
            if(result[i]) break;
        for(int j=0; j<=i; ++j)
            cout<<result[j]<<" ";
        cout<<endl;
    }
    return 0;
}
