
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
const int MAXN = 365+1000+4;
const int inf = 99999999;

class Arc{
public:
    int to,w;
    int l,r;
    Arc *next,*anti;
    Arc *add( int tt,int ll,int rr,Arc *&b ){
        to = tt; l = ll; r = rr;
        w = rr-ll;next = b;b = this; return this;
    }
};

int d[ MAXN ],S,T,bound,countt,in[ MAXN ],out[ MAXN ];
Arc a[ MAXN *80 ],*biao[ MAXN ];

void init( int n ){
    bound = n;S = n - 2;T = n - 1;
    for( int i = 0; i < n; i++ )
        biao[i] = NULL;
    memset( in, 0, sizeof(in) );
    memset( out, 0, sizeof(out) );
    countt = 0;
}

void add( int from,int to, int l,int r ){
    Arc *p1 = a[ countt++ ].add( to, l, r, biao[from] );
    Arc *p2 = a[ countt++ ].add( from, 0, 0, biao[to] );
    p1->anti = p2;
    p2->anti = p1;
}

int bfs( void ){
    queue<int> q;
    fill( d,d+MAXN,-1 );
    d[ S ] = 0;
    q.push( S );
    while( !q.empty() ){
        int u = q.front();q.pop();
        for( Arc *p=biao[u]; p!=NULL; p=p->next )
            if( d[ p->to ] == -1 && p->w > 0 )
                d[ p->to ] = d[u] + 1,q.push( p->to );
    }
    return d[ T ] != -1;
}

int dinic( int u ,int sum){
    int f,o = sum;
    if( u == T ) return sum;
    for( Arc *p = biao[u]; p!=NULL && sum; p=p->next )
        if( d[p->to] == d[u] + 1 && p->w > 0){
            f = dinic( p->to, min( p->w,sum) );
            p->w -= f;
            p->anti->w += f;
            sum -= f;
        }
    return o - sum;
}

int max_flow1( void ){
    int total = 0;
    while( bfs() )
        total += dinic( S, 2100000000 );
    return total;
}

int max_flow(){
	int i,now_flow,total,min_dist;
	Arc *ge[MAXN],*di[MAXN],*path[MAXN];
	int dist[MAXN],countdist[MAXN],his[MAXN],pre[MAXN],n=bound;
	Arc *p,*locate;
	bool flag;
	memset( dist,0,sizeof(dist) );
	memset( countdist,0,sizeof( countdist) );
	countdist[0] = n;
	for( i = 0; i < n ; i++ ) di[i] = ge[i] = biao[i];
	for( total = 0, now_flow = inf,i = S; dist[i] < n; ){
		his[i] = now_flow;
		for( flag = false,p=di[i]; p!=NULL; p= p->next){
			if( p->w > 0 && dist[i] ==dist[p->to] + 1 ){
				now_flow = min( now_flow,p->w );
				pre[ p->to ] = i;
				path[ p->to ] = p;
				di[i] = p;
				i = p->to;
				if( i == T ){
					for( total += now_flow; i != S; i = pre[i] )
						path[i]->w -= now_flow, path[i]->anti->w += now_flow;
					now_flow = inf;
				}
				flag = true;
				break;
			}
		}
		if( !flag ){
			for( min_dist = n-1,p=ge[i];p!= NULL;p=p->next )
				if( p->w > 0 && dist[p->to] < min_dist )
					min_dist = dist[p->to],locate = p;
			di[i] = locate;
			if( !(--countdist[ dist[i] ] ) ) break;
			countdist[ dist[i] = min_dist+1 ] ++;
			if( i != S )
				i = pre[i],now_flow = his[i];

		}
	}
	return total;
}

void construct( void ){
    for( int i = 0; i < bound - 2; i++ )
        for( Arc *p=biao[i]; p!=NULL; p = p->next ){
            in[ p->to ] += p->l;
            out[ i ] += p->l;
        }
    for( int i = 0; i < bound - 2; i++ ){
            add( S, i, 0, in[i]  );
            add( i, T, 0, out[i] );
    }
}

bool full( void ){
    for( Arc *p = biao[S]; p != NULL; p = p->next )
        if( p->w > 0 ) return false;
    return true;
}

int main(void){
    freopen("in.txt","r",stdin);
    int n,m,from,to;
    int i,j,c,d,r,l;
    while( scanf("%d%d",&n,&m) != EOF ){
        init(n+m+4);
        for( i = 0; i < m; i++ ){
            scanf("%d",&j);
            add( n+i, n+m+1, j, inf );
        }
        queue<int> q;
        for( i = 0; i < n; i++ ){
            scanf("%d%d",&c,&d);
            add( n+m, i, 0, d );
            while( c-- ){
                scanf("%d%d%d",&j,&r,&l);
                q.push( countt );
                add( i, n+j, r, l );
            }
        }
        j = countt;
        add( n+m+1, n+m, 0, inf );
        construct();
        max_flow();

        if( !full() ){
            puts("-1\n");continue;
        }
        a[j].w = a[j+1].w = 0;
        S = n+m;T = S+1;
        max_flow1();
        int total = 0;
        for( Arc *p = biao[S]; p != NULL; p = p->next )
            if( p->to >= 0 && p->to < n ) {
                total += p->r - p->w;
            }
        printf("%d\n",total);
        while( !q.empty() ){
            int u = q.front();q.pop();
            printf("%d\n",a[u].r - a[u].w );
        }
        printf("\n");
    }
    return 0;
}

