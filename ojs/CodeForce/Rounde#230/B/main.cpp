#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=200;
int n;
double w[maxn][maxn];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<(w[i][j]+w[j][i])/2<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<(w[i][j]-w[j][i])/2<<" ";
        cout<<endl;
    }
    return 0;
}
