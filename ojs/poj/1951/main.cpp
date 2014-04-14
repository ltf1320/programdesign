#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=300;
bool used[maxn];
char ss[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i=0;
    bool blank=0,start=0;
    gets(ss);
    used['A']=used['E']=used['I']=used['O']=used['U']=1;
    while(ss[i])
    {
        if(ss[i]>='A'&&ss[i]<='Z')
        {
            if(!used[ss[i]])
            {
                if(start&&blank) putchar(' ');
                putchar(ss[i]);
                blank=0;
                used[ss[i]]=1;
                start=1;
            }
        }
        else if(ss[i]==' ')
            blank=1;
        else
        {
            blank=0;
            start=1;
            putchar(ss[i]);
        }
        i++;
    }
  //  putchar('\n');
    return 0;
}
