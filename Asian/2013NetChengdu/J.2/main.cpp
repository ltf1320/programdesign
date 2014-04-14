#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int a[110000],ans[110000];
int tow[40];
int d[40];
int n,m;
void add(int p)
{
    int x=a[p];
    int i=0;
    while (x!=0)
    {
        if (x%2)
        d[i]++;
        x=x/2;
        i++;
    }

}
void down(int p)
{
    int x=a[p];
    int i=0;
    while (x!=0)
    {
        if (x%2)
        d[i]--;
        x=x/2;
        i++;
    }

}
bool ok()
{
    int p=0;
    for (int i=0;i<=30;i++)
    if (d[i]) p+=tow[i];
    if (p<m) return 1;
    else return 0;
}
int find(int h)
{

    while (!ok())
    {
        down(h);
        h++;
    }

    return h;
}

void work(int p)
{
    int h=ans[p-1];

    ans[p]=find(h);

}
int main()
{
    freopen("in.txt","r",stdin);

    int t,num=0;
    cin>>t;
    tow[0]=1;
    for (int i=1;i<=30;i++)
    tow[i]=tow[i-1]*2;

    while (t--)
    {
        num++;
        memset(d,0,sizeof(d));
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);

        ans[0]=1;
        long long sum=0;
        for (int i=1;i<=n;i++)
        {
            add(i);
            work(i);
            sum+=i-ans[i]+1;
        }
        cout<<"Case #"<<num<<": "<<sum<<endl;


    }
    return 0;
}

