#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct
{
    char content[50];
} Word;
Word word[1000];
int partition(int l,int h)
{
    Word k;
    strcpy(k.content,word[0].content);
    while(l<h)
    {
        while(l<h && strcmp(k.content,word[h].content)>0)
            h--;
        strcpy(word[l].content,word[h].content);
        while(l<h && strcmp(k.content,word[l].content)<0)
            l++;
        strcpy(word[h].content,word[l].content);
    }
    strcpy(word[l].content,k.content);
    return l;
}
void quicksort(int l,int h)
{
    int pos;
    if(l<h)
    {
        pos=partition(l,h);
        quicksort(l,pos-1);
        quicksort(pos+1,h);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int now;
    char sentences[10001];
    char words[50];
    while(gets(sentences))
    {
        int len=strlen(sentences);
        now=0;
        int m=0;
        for(int i=0; i<len;i++)
        {
            if(sentences[i]==' ')
                continue;
            else
            {
                while(sentences[i]!=' '&& i<len)
                    words[m++]=sentences[i++];
                words[m]='\0';
                i--;
                m=0;
                strcpy(word[now++].content,words);
            }
        }
        quicksort(0,now-1);
        for(int i=0; i<now-1; i++)
            cout<<word[i].content<<" ";
        cout<<word[now-1].content<<endl;
    }
    return 0;
}
