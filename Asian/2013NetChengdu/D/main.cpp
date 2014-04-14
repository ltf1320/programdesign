#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+110;
int N,M;


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d%d",&M,&N);
        printf("Case #%d: ",cas);
        if(M==1)
        {
            for(int i=0;i<N;i++)
                putchar('a');
            puts("");
        }
        else if(M==2)
        {
            switch(N)
            {
                case 1:puts("a");break;
                case 2:puts("ab");break;
                case 3:puts("aab");break;
                case 4:puts("aabb");break;
                case 5:puts("aaaba");break;
                case 6:puts("aaabab");break;
                case 7:puts("aaababb");break;
                case 8:puts("aaababbb");break;
                default:
                    printf("aa");
                    N-=2;
                    for(int i=0;i<N/6;i++)
                        printf("aababb");
                    switch(N%6)
                    {
                        case 1:puts("a");break;
                        case 2:puts("aa");break;
                        case 3:puts("aaa");break;
                        case 4:puts("aaaa");break;
                        case 5:puts("aabab");break;
                    }
            }
        }
        else
        {
            for(int i=0;i<N/3;i++)
                printf("abc");
            int t=N%3;
            if(t==1)
                puts("a");
            else if(t==2)
                puts("ab");
            else puts("");
        }
    }
    return 0;
}
