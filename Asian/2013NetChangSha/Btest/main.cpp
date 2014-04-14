#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T;
int n,expect,A,B;
bool less_than(int x, int y)
{
    T++;
    return x < y;
}
void work(int array[],int  l,int  r)
{
    if (l >= r) return;
    swap(array[(l * A + r * B) / (A + B)], array[r]);
    int index = l;
    for (int i = l; i < r; i++)
        if (less_than(array[i], array[r]))
            swap(array[index++], array[i]);
    swap(array[r], array[index]);
    work(array, l, index - 1);
    work(array, index + 1, r);
}

void Input(int &n,int &expect,int &A,int &B,int arr[])
{
    scanf("%d%d%d%d",&n,&expect,&A,&B);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

int array[10000+100];

int  main()
{
    freopen("in.txt","r",stdin);
    T = 0;
    Input(n, expect, A, B, array);
    work(array, 0, n - 1);
    cout<<T<<endl;
    if (T == expect)
        puts("YES");
    else
        puts("NO");
    return 0;
}
