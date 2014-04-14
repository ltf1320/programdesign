#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxp=10000+10;
const int maxt=1000000+100;

int last[30];
char word[maxp];
char text[maxt];
int wlen,tlen;
void getGood()
{
    for(int i=0;i<30;i++)
        last[i]=wlen;
    for(int i=0;i<wlen;i++)
    {
        last[word[i]-'A']=i;
    }
}
int suffix[maxp];
void getSuffix()
{
    int i,j,k;
    int result;
    suffix[wlen-1] = wlen;
    for(i = wlen-2;i>=0;i--)
    {
        k = i;
        j=wlen-1;
        result = 0;
        while(word[k--]==word[j--])
        {
            result++;
        }
        suffix[i] = result;
    }
}
int goodskip[maxp];
void getGoodSkip()
{
    getSuffix();
    int i,j;
    for(i = 0;i<wlen;i++)
    {
          goodskip[i] = wlen;
    }
    j = 0;
    /*最前和最后的i+1个字符一致*/
    for(i = wlen-2;i>=0;--i)
    {
        if(suffix[i] == i+1) /*consider the pattern "ABCDMNPABCD"*/
        {
           for(;j<wlen-1-i;j++)
           {
             if(goodskip[j] == wlen) /*consider the pattern BBBBMNPBBBB*/
              {
                 goodskip[j] = wlen-1-i;
              }
            }
        }
    }
    for(i = 0;i<wlen-2;i++)
    {
          goodskip[wlen-1-suffix[i]] = wlen-1-i;
    }
    goodskip[wlen-1]=0;
}

int match()
{
    getGoodSkip();
    getGood();
    int i,j,badskip;
    j = 0;
    int find=0;
    while(j <= tlen - wlen)
    {
        for(i = wlen-1;i>=0 && word[i] == text[j+i];i--)
        {
         ;
        }
        if(i<0)
        {
              j ++;
              find++;
        }
        else
        {
            if(i - last[text[j+i]-'A'] >0)
                badskip = i - last[text[j+i]-'A'];
            else
                badskip = 1;/*不走回头路*/

            j+=max(goodskip[i],badskip);
        }
    }
    return find;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",word);
        scanf("%s",text);
        wlen=strlen(word);
        tlen=strlen(text);
        printf("%d\n",match());
    }
    return 0;
}
