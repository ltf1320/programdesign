#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Mod = 100000;
const int size = 120;
__int64 g[size][size];

struct Node
{
    int fail,son[4],end;
    void Init()
    {
        fail = -1;
        memset(son, -1, sizeof(son));
        end = 0;
    }
} node[size];

int node_Num = 0;
int q[size], head, tail;

int Index(char a)
{
    switch (a)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    }
}

void Insert(char *s)
{
    int p=0;
    for (int i=0; s[i]; i++)
    {
        if (node[p].end) break;
        if (node[p].son[Index(s[i])] == -1)
        {
            node_Num++;
            node[p].son[Index(s[i])] = node_Num;
            node[node_Num].Init();
        }
        p = node[p].son[Index(s[i])];
    }
    node[p].end++;
}

void Build_Ac()
{
    head = tail = 0;
    int temp = 0, p = 0, i;
    q[tail++] = 0;
    while (head < tail)
    {
        temp = q[head++];
        for (i = 0; i < 4; i++)
            if (node[temp].son[i] != -1)
            {
                if  (temp == 0) node[node[temp].son[i]].fail = 0;
                else
                {
                    p = node[temp].fail;
                    while (p != -1)
                    {
                        if (node[p].son[i] != -1)
                        {
                            node[node[temp].son[i]].fail = node[p].son[i];
                            if (node[node[p].son[i]].end)
                                node[node[temp].son[i]].end++;
                            break;
                        }
                        p  = node[p].fail;
                    }
                    if (p == -1) node[node[temp].son[i]].fail =  0;
                }
                q[tail++] = node[temp].son[i];
            }
    }
}

void MatrixMul(__int64 b[][size], __int64 c[][size], int sz)
{
    int i, j, k;
    __int64 temp[size][size] = {0};
    for (i = 0; i < sz; i++)
        for (j = 0; j < sz; j++)
            for (k = 0; k < sz; k++)
            {
                temp[i][j] += b[i][k]*c[k][j];
                if (temp[i][j] >= Mod)
                    temp[i][j] %= Mod;
            }

    for (i = 0; i < sz; i++)
        for (j = 0; j < sz; j++)
            b[i][j] = temp[i][j];
}

void MatrixPow(__int64 tot[][size], __int64 a[][size], int sz, int n)
{
    while (n > 0)
    {
        if (n&1) MatrixMul(tot,a, sz);
        MatrixMul(a, a, sz);
        n >>= 1;
    }
}

int N = 2000000000;
int M;
char word[14];
__int64 tot[size][size];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i, j;
    while (scanf("%d%d", &M, &N) != EOF)
    {
        node_Num = 0;
        node[0].Init();
        memset(g, 0, sizeof(g));
        for (i = 0; i < M; i++)
        {
            scanf("%s", word);
            Insert(word);
        }
        Build_Ac();

        node_Num++;
        for (i = 0; i < node_Num; i++)
            if(!node[i].end)
                for (j = 0; j < 4; j++)
                {
                    if (node[i].son[j] != -1 && node[node[i].son[j]].end==0)
                        g[i][node[i].son[j]]++;
                    else if (node[i].son[j]== -1)
                    {
                        if (i==0)  g[0][0]++;
                        else
                        {
                            int temp = i;
                            while (node[temp].son[j]== -1)
                            {
                                if (temp==0)break;
                                temp = node[temp].fail;
                            }
                            if(node[temp].son[j] != -1 && node[node[temp].son[j]].end==0)
                                g[i][node[temp].son[j]]++;
                            else if (node[temp].son[j]== -1&& temp==0)
                                g[i][0]++;
                        }
                    }
                }
        for(int i=0;i<node_Num;i++)
        {
            for(int j=0;j<node_Num;j++)
                printf("%d ",g[i][j]);
            printf("\n");
        }
        memset(tot, 0, sizeof(tot));
        for (i = 0; i < node_Num; i++)
            tot[i][i] = 1;
        MatrixPow(tot, g, node_Num, N);
        __int64 ans = 0;
        for (i = 0; i < node_Num; i++)
            if (node[i].end==0)
            {
                ans += tot[0][i];
                if (ans>=Mod) ans %= Mod;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
