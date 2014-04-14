#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int gcd(int x,int y)
{
    if(y==0) return x;
    else return(gcd(y,x%y));
}
int main()
{
    int a,b,key,word1;
    bool start=0;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
 //       if(start) puts("");
        start=1;
        int key=gcd(a,b);
        int a1=a/key;

        double err=999999.0,standard;
        standard=(double)a/b;//cout<<standard<<endl;
        int word=1;
        for(int i=1; i<b/key; i++)
        {
            int flag=0;
            //word1=word;
            for(int j=0; j<i*a1; j++)
            {
                double s1;
                err=fabs(err);
                s1=(double)j/i;
                // cout<<s1<<endl;
                s1=fabs(s1-standard);
                if(s1<=err)
                {
                    flag=1;
                    word=j;
                    err=s1;
                }
            }
            if(flag)
            {
                printf("%d/%d\n",word,i);
            }

        }
        printf("%d/%d\n\n",a/key,b/key);
    }
    return 0;
}
