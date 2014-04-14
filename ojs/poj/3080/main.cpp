#include <iostream>

using namespace std;
const int maxn=100;
/*
int wa[maxn],wb[maxn],wv[maxn],wsm[maxn];
int sa[maxn],r[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m; i++)       //第一次基数排序，按字母排序
        wsm[i]=0;
    for(i=0; i<n; i++) wsm[x[i]=r[i]]++;
    for(i=1; i<m; i++) wsm[i]+=wsm[i-1];
    for(i=n-1; i>=0; i--)
        sa[--wsm[x[i]]]=i;   //sa[i]表示排名第i位的字母在原序列第sa[i]处

    for(j=1,p=1; p<n; j*=2,m=p) //倍增
    {
        //第二关键字（后j个字符的大小顺序（之前已经得出了））进行排序
        for(p=0,i=n-j; i<n; i++)y[p++]=i;  //一次基数排序，先把不够长的放在前面
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;//然后将之前排名对着的位置往前移j位
        for(i=0; i<n; i++)
            wv[i]=x[y[i]];   //按照排好的顺序把序列放入wv中
        //第一关键字（前j个字符的大小顺序）
        for(i=0; i<m; i++) wsm[i]=0;   //一次基数排序,进行倍增
        for(i=0; i<n; i++) wsm[wv[i]]++;
        for(i=1; i<m; i++) wsm[i]+=wsm[i-1];
        for(i=n-1; i>=0; i--) sa[--wsm[wv[i]]]=y[i];//排好k=2*j的后缀数组了

        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)//x中为rank值，相等的要相同
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
*/
int SA[maxn],Rank[maxn];
int tjs[maxn],js[maxn];
int ss[maxn],tss[maxn];

void redouble(int n,int m)
{
    int p;
    for(int i=0;i<m;i++) js[maxn]=0;
    memccpy(Rank,ss,sizeof(tmp));
    for(int i=0;i<n;i++) js[ss[i]]++;
    for(int i=1;i<n;i++) js[i]+=js[i-1];
    for(int i=0;i<n;i++) sa[--js[ss[i]]]=i;
    for(int k=1,p=1;p<n;m=p,k++)
    {
        for(int i=n-j;i<n;i++) tjs[p++]=i;
        for(int i=0;i<n-j;i++) if(sa[i]>j) tjs[p++]=sa[i]-j;
        for(int i=0;i<n;i++) tss[i]=
    }
}

int main()
{
    char s[10]="acabdacc";
    for(int i=0;i<9;i++)
        r[i]=s[i]-'a'+1;
    r[8]=0;
    da(8,26);
    return 0;
}
