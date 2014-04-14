#define END_
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int inf=~(unsigned int)0>>1;

int main()
{
#ifndef END_
    freopen("in.txt","r",stdin);
#endif
    int n,spr[120][120],pnum;
    while(1)
    {
        cin>>n;
        if(n==0) break;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        memset(spr,0,sizeof(spr));
        for(int i=1; i<=n; ++i)
        {
            cin>>pnum;
            for(int j=0; j<pnum; ++j)
            {
                int people,time;
                cin>>people>>time;
                spr[i][people]=time;
            }
        }
        for(int i=1; i<=n; ++i) //floyd
        {
            for(int j=1; j<=n; ++j)
            {
                if(spr[i][j]==0)
                    spr[i][j]=inf;
            }
            spr[i][i]=0;
        }
#ifndef END_
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
                cout<<spr[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl;
#endif
        spr[0][0]=0;
        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    if(spr[i][k]!=inf && spr[k][j]!=inf && (spr[i][j]>spr[i][k]+spr[k][j]))
                        spr[i][j]=spr[i][k]+spr[k][j];
#ifndef END_
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
                cout<<spr[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl;
        system("pause");
#endif
        bool imp=0;
        for(int i=1; i<=n/2+1; ++i) //判断是否存在不可达
        {
            int j;
            for(j=1; j<=n; ++j)
            {
                if(j==i) continue;
                if(spr[i][j]!=inf||spr[j][i]!=inf) break;
            }
            if(j>n)
            {
                imp=1;
                break;
            }
        }
        if(imp)
        {
            cout<<"disjoint"<<endl;
            continue;
        }
        int mini,min;
        mini=0,min=inf;
        for(int i=1; i<=n; ++i) //找到最快方法
        {
            int max=0;
            for(int j=1; j<=n; ++j)
                if(spr[i][j]>max)
                    max=spr[i][j];
            if(max&&max<min)
            {
                mini=i;
                min=max;
            }
        }
        cout<<mini<<" "<<min<<endl;
    }
    return 0;
}
