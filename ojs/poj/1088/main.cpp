#include <iostream>
#include <stdio.h>
using namespace std;
int lencal(int i,int j);
int arr[101][101];
int isn[101][101]={0}; //记录已算过的值
int R,C;
int main()
{
    freopen("in.txt","r",stdin);
    int max=0,len;
    cin>>R>>C;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            cin>>arr[i][j];
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
        {
            len=lencal(i,j);
            max=len>max?len:max;
        }
    cout<<max<<endl;
    return 0;
}
//f[i][j]=max{f[i+1][j],f[i-1][j],f[i][j+1],f[i][j-1]}+1
int lencal(int i,int j)
{
    if(isn[i][j])
        return isn[i][j]+1;
    int result=0,tem;
    if(j>0&&(arr[i][j-1]-arr[i][j]<0))
    {
        result=lencal(i,j-1);
    }
    if(j<C-1&&(arr[i][j+1]-arr[i][j]<0))
    {
        tem=lencal(i,j+1);
        result=result>tem?result:tem;
    }
    if(i<R-1&&(arr[i+1][j]-arr[i][j]<0))
    {
        tem=lencal(i+1,j);
        result=result>tem?result:tem;
    }
    if(i>0&&(arr[i-1][j]-arr[i][j]<0))
    {
        tem=lencal(i-1,j);
        result=result>tem?result:tem;
    }
    isn[i][j]=result;
    return result+1;
}
