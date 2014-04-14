#include <iostream>
#include <stdio.h>
using namespace std;
int invertion(char* str,int n);

int main()
{
    int lenth,num;
//    freopen("in.txt","r",stdin);
    cin>>lenth>>num;
    char str[101][60];
    char **result=new char*[num];
    int k[101]={0};
    for(int i=0;i<num;i++)
    {
        cin>>str[i];
    }
    for(int i=0;i<num;++i)
    {
        int j,tem;
        k[i]=invertion(str[i],lenth);
        for(j=i;j>0;j--)
        {
            if(k[j-1]>k[j])
            {
                tem=k[j-1];
                k[j-1]=k[j];
                k[j]=tem;
            }
            else break;
        }
        for(int f=i-1;f>=j;f--)
        {
            result[f+1]=result[f];
        }
        result[j]=str[i];
    }
    for(int i=0;i<num;i++)
        cout<<result[i]<<endl;
    return 0;
}

int invertion(char* str,int n)
{
    int sum=0;
    for(int i=0;i<n;i++,++str)
    {
        for(char *p=str;p<str+n-i;++p)
        {
            if((*p-*str)<0)
                sum++;
        }
    }
    return sum;
}
