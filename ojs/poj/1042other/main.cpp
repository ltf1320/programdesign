#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct data {
       int f,d,id;
}a[30],b;
int n,t,tran[30],x,ans,maxi,save[30],tmp[30],tt;
priority_queue <data> q;
bool operator<(data a,data b) {
     if (a.f==b.f) return a.id>b.id;
     else return a.f<b.f;
}
int main() {

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while (~scanf("%d",&n)) {
          if (n==0) break;
          scanf("%d",&t);
          t *= 12;
          for (int i=1;i<=n;i++)
              scanf("%d",&a[i].f);
          for (int i=1;i<=n;i++) {
              scanf("%d",&a[i].d);
              a[i].id = i;
          }
          tran[1] = 0;
          for (int i=2;i<=n;i++) {
              scanf("%d",&x);
              tran[i] = tran[i-1] + x;
          }

          ans = -1;
          memset(save,0,sizeof(save));
          for (int i=1;i<=n;i++) {
              maxi = 0;
              memset(tmp,0,sizeof(tmp));
              tt = t - tran[i];
              while (!q.empty()) q.pop();
              for (int j=1;j<=i;j++)
                  q.push(a[j]);
              while (tt>0) {
                    b = q.top();
                    q.pop();
                    tt--;
                    maxi += b.f;
                    tmp[b.id]++;
                    b.f -= b.d;
                    if (b.f<=0) b.f = 0;
                    q.push(b);
              }
              if (maxi>ans) {
                            ans = maxi;
                            for (int j=1;j<=i;j++)
                                save[j] = tmp[j];
              }
          }

          for (int i=1;i<n;i++)
              printf("%d, ",save[i]*5);
          printf("%d\n",save[n]*5);
          printf("Number of fish expected: %d\n\n",ans);
    }
    return 0;
}
