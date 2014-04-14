#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

long long a[10],b[10],c[10];

int main(){
    freopen("in.txt","r",stdin);
    long long n,m,i,j,k,t,ans,l,p,r,q;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    l=ans=0;
    for(i=0; i<n; i++){
        t=0;
        q=a[i];
        for(j=2; j*j<=q; j++)
        {
            while(q%j==0)
                t++,q/=j;
        }
        if(q!=1)
            t++;
        b[i]=t;
        if(t!=1)
        ans+=t;
    }
    //cout<<ans<<endl;
    for(i=n-1; i>=0; i--){
        if(!c[i])
            l++;
        while(1){
            m=0;
            p=i;
            for(j=i-1; j>=0; j--){
                if(a[i]%a[j]==0&&b[j]>m&&!c[j])
                {
                    m=b[j];
                    p=j;
                }
            }
            if(m){
                a[i]/=a[p];
                c[p]=1;
                ans-=m-1;
            }
            else
                break;
        }
    }
    ans+=l;
    if(l>1)
        ans++;
    cout<<ans<<endl;
    return 0;
}
