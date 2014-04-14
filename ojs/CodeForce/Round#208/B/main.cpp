#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn=100000+100;
int N;
string str[maxn];
string mess;
int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        cin>>str[i];
    cin>>mess;
    int now=0,p=0;
    for(int i=0; i<(int)mess.size(); i++)
    {
        if(i==0)
        {
            if(i==(int)mess.size()-1)
                    {
                        puts("no\n");
                        return 0;
                    }
            for(; i<(int)mess.size(); i++)
            {
                if(!p&&mess[i]=='<')
                    p++;
                if(p&&mess[i]=='3')
                    break;
                if(i==(int)mess.size()-1)
                {
                    puts("no\n");
                    return 0;
                }
            }
            p=0;
        }
        if(mess[i]==str[now][p])
        {
            p++;
            if(p==(int)str[now].size())
            {
                p=0;
                if(i==(int)mess.size()-1)
                    {
                        puts("no\n");
                        return 0;
                    }
                for(i++; i<(int)mess.size(); i++)
                {
                    if(!p&&mess[i]=='<')
                        p++;
                    if(p&&mess[i]=='3')
                        break;
                    if(i==(int)mess.size()-1)
                    {
                        puts("no\n");
                        return 0;
                    }
                }
                now++;
                if(now==N)
                {
                    printf("yes\n");
                    return 0 ;
                }
                p=0;
            }
        }
        if(i==(int)mess.size()-1)
        {
            puts("no\n");
            return 0;
        }
    }
    puts("no\n");
    return 0;
}
