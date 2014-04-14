//迭代加深搜索，每次增加搜索的深度
//注意数值的类型！！

#include <iostream>
#include <cstdlib>
using namespace std;
int maxd;
int a,b;
double val;
const double dev=1e-7;
double abs(const double a){return a>0?a:-a;}
bool ids(int d,double sum,int now)
{
    if(d==maxd)
    {
        if(abs(sum-val)<dev)
        {
            return 1;
        }
        else return 0;
    }
	int k=(maxd-d)/abs(val-sum)+1;  //迭代上限，还剩下maxd-d个数,到val的值为val-sum，为能到达val现在可以填的最小的数即1/k
    for(int i=now;i<=k;++i)
    {
        if(ids(d+1,sum+1.0/i,i+1))
        {
            cout<<"1/"<<i<<" ";
            return 1;
        }
    }
    return 0;
}


int main()
{
    cin>>a>>b;
    maxd=1;
	val=static_cast<double>(a)/b;
    while(!ids(0,0,1))
    {
        maxd++;
    }
    return 0;
}
