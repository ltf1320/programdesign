#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=1<<30;
const int maxn=200+10;
const int maxm=40000+20;
struct EDGE
{
    int u, v, c, nxt;
};
EDGE bf[maxm],bf2[maxm];
int ent=2,ent2;
int box[maxn],box2[maxn];
int cur[maxn], ps[maxn], dep[maxn];
void add(int u, int v, int c)
{
    bf[ent].u = u;
    bf[ent].v = v;
    bf[ent].c = c;
    bf[ent].nxt = box[u];
    box[u] = ent ++;
    bf[ent].u = v;
    bf[ent].v = u;
    bf[ent].c = 0;
    bf[ent].nxt = box[v];
    box[v] = ent ++;
}
void add2(int u, int v, int c)
{
    bf2[ent2].u = u;
    bf2[ent2].v = v;
    bf2[ent2].c = c;
    bf2[ent2].nxt = box2[u];
    box2[u] = ent2 ++;
    bf2[ent2].u = v;
    bf2[ent2].v = u;
    bf2[ent2].c = 0;
    bf2[ent2].nxt = box2[v];
    box2[v] = ent2 ++;
}
int dinic(int s, int t)
{
    int tr, res = 0;
    int i, j, k, f, r, top;
    while(1)
    {
        memset(dep, -1, sizeof(dep));
        for(f = dep[ps[0]=s] = 0, r = 1; f != r;)
            for(i = ps[f ++], j = box[i]; j; j = bf[j].nxt)
                if(bf[j].c && dep[k=bf[j].v] == -1)
                {
                    dep[k] = dep[i] + 1;
                    ps[r ++] = k;
                    if(k == t)
                    {
                        f = r; break;
                    }
                }
        if(dep[t] == -1) break;
        memcpy(cur, box, sizeof(cur));
        i = s, top = 0;
        while(1)
        {
            if(i == t)
            {
                for(tr = inf, k = 0; k < top; k ++)
                    if(bf[ps[k]].c < tr)
                        tr = bf[ps[f=k]].c;
                for(k = 0; k < top; k ++)
                {
                    bf[ps[k]].c -= tr;
                    bf[ps[k]^1].c += tr;
                }
                i = bf[ps[top=f]].u;
                res += tr;
            }
            for(j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
            {
                if(bf[j].c && dep[i]+1 == dep[bf[j].v]) break;
            }
            if(cur[i])
            {
                ps[top ++] = cur[i];
                i = bf[cur[i]].v;
            }
            else
            {
                if(top == 0) break;
                dep[i] = -1;
                i = bf[ps[-- top]].u;
            }
        }
    }
    return res;
}
void getvalue()
{
    for(int i=2;i<ent;i++)
    {
        bf[i].c=bf2[i].c;
        bf[i].nxt=bf2[i].nxt;
        bf[i].u=bf2[i].u;
        bf[i].v=bf2[i].v;
    }

}
int main()
{
    int T,n,m;
    int f,to,c,ans;
    int cas=0;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d%d",&n,&m);
        memset(box,0,sizeof(box));
        memset(box2,0,sizeof(box2));
        ent=ent2=2;
        ans=0;
        printf("Case #%d:\n",cas);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&f,&to,&c);
            add(f,to,c);
            add(to,f,c);
            add2(f,to,c);
            add2(to,f,c);
            int vv=dinic(1,n);
            getvalue();
            if(vv>ans)
            {
                printf("%d %d\n",i,vv-ans);
                ans=vv;
            }
        }
    }
    return 0;
}
