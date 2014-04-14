#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cnt[5];
char tmp[1000];

int main()
{
    memset(cnt,0,sizeof(cnt));
    gets(tmp);
    for(int i=0;i<(int)strlen(tmp);i+=2)
    {
        cnt[tmp[i]-'0']++;
    }
    bool start=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<cnt[i];j++)
        {
            if(start) printf("+");
            start=1;
            printf("%d",i);
        }
    }
    puts("");
    return 0;
}
