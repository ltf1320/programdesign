#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000;
char str[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int len,k,i;
    bool a=0;
    char ch;
    while(~scanf("%c",&ch))
    {
        if(ch=='\n')
            break;
        if(a) printf("\n");
        a=1;
        k=0;
        while(ch!='\n')
        {
            str[k++]=ch;
            ch=getchar();
        }
        str[k]=0;
        len=strlen(str);
        if(!len) break;
        for(i=0; i<len/16; i++)
        {
            printf("%.3x0: ",i);
            for(k=16*i; k<16*(i+1); k++)
            {
                printf("%.2x",str[k]);
                if(str[k]>='a'&&str[k]<='z')
                    str[k]-=32;
                else if(str[k]>='A'&&str[k]<='Z')
                    str[k]+=32;
                if(k%2) printf(" ");
            }
            for(int j=16*i;j<16*(i+1);j++)
                printf("%c",str[j]);
            if((i+1)*16<len) printf("\n");
        }
        if(i*16<len)
        {
            printf("%.3x0: ",i);
            for(k=16*i; k<len; k++)
            {
                printf("%.2x",str[k]);
                if(str[k]>='a'&&str[k]<='z')
                    str[k]-=32;
                else if(str[k]>='A'&&str[k]<='Z')
                    str[k]+=32;
                if(k%2) printf(" ");
            }
            for(;k<16*(i+1);k++)
            {
                printf("  ");
                if(k%2) printf(" ");
            }
            for(k=16*i;k<len;k++)
                printf("%c",str[k]);
 //           for(;k<16*(i+1);k++)
  //              printf(" ");
        }
    }
    return 0;
}
