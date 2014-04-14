#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxp=10000+10;
const int maxt=1000000+100;

int preBM_bad(char* pattern ,int len,int rightmost_occur[])
{
    int i;
    for(i = 0;i<maxp;i++)
        rightmost_occur[i] = len;
    for(i = 0;i<len;i++)
    {
        rightmost_occur[pattern[i]] = i;
    }
    return 0;
}

int calc_goodsuffix(char* pattern,int len,int suffix[])
{
    int i,j,k;
    int result;
    suffix[len-1] = len;

    for(i = len-2;i>=0;i--)
    {
        k = i;
        j=len-1;
        result = 0;
        while(pattern[k--]==pattern[j--])
        {
            result++;
        }
        suffix[i] = result;
    }
    return 0;
}

int preBM_good(char* pattern ,int len,int goodskip[])
{
    int i,j;
    int *suffix = (int*)malloc(len*sizeof(int));

    calc_goodsuffix(pattern,len,suffix);

    for(i = 0;i<len;i++)
    {
          goodskip[i] = len;
    }
    j = 0;
    /*最前和最后的i+1个字符一致*/
    for(i = len-2;i>=0;--i)
    {
        if(suffix[i] == i+1) /*consider the pattern "ABCDMNPABCD"*/
        {
           for(;j<len-1-i;j++)
           {
             if(goodskip[j] == len) /*consider the pattern BBBBMNPBBBB*/
              {
                 goodskip[j] = len-1-i;
              }
            }
        }
    }

    for(i = 0;i<len-2;i++)
    {
          goodskip[len-1-suffix[i]] = len-1-i;
    }

    if(suffix)
       free(suffix);
    return 0;

}

int BM_search(char* text,int textlen,char* pattern,int patternlen)
{
    int i,j;
    int ret;
    int rightmost[maxp];
    int find = 0;
    int badskip;

    int *goodskip = (int*)malloc(sizeof(int)*patternlen) ;
    if(goodskip == NULL)
    {
        printf("malloc for goodskip failed\n");
        return -1;
    }

    preBM_bad(pattern ,patternlen,rightmost);
    ret = preBM_good(pattern,patternlen,goodskip);
    j = 0;
    while(j < textlen - patternlen)
    {
        for(i = patternlen-1;i>=0 && pattern[i] == text[j+i];i--)
        {
         ;
        }
        if(i<0)
        {
 //             FindThePattern(text,pattern,j);
              j += goodskip[0];
              find++;
        }
        else
        {
            if(i - rightmost[text[j+i]] >0)
                badskip = i - rightmost[text[j+i]];
            else
                badskip = 1;/*不走回头路*/

            j+=max(goodskip[i],badskip);
        }
    }

    if(goodskip)
    {
          free(goodskip);
    }
    return find;
}

char word[maxp];
char text[maxt];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",word);
        scanf("%s",text);
        printf("%d\n",BM_search(text,strlen(text),word,strlen(word)));
    }
}
