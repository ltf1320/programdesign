#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
int si,sj,sb,sg,ei,ej;
int map[30][30];            //0-G 1-B 2-T
int dist[30][30][6][21];
bool vis[30][30][6][21];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int ki[8]={-2,-1,1,2,2,1,-1,-2};
int kj[8]={1,2,2,1,-1,-2,-2,-1};
int chk(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)
        return 1;
    return 0;
}
struct heapnode
{
    int i,j,b,g,t;
    bool operator < (const heapnode& rhs) const
    {
        return t>rhs.t;
    }
};
int dijsktra()
{
	priority_queue <heapnode> q;
	memset(dist,INF,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[si][sj][sb][sg]=0;
	q.push((heapnode){si,sj,sb,sg,0});
	while(!q.empty())
	{
	    heapnode x=q.top();q.pop();
		int i=x.i,j=x.j,b=x.b,g=x.g,t=x.t;
		if(vis[i][j][b][g])continue;
        vis[i][j][b][g]=true;
        if(i==ei && j==ej)
            return t;
		for(int k=0;k<4;k++)
		{
		    int x=i+di[k];
		    int y=j+dj[k];
		    if(!chk(x,y))
                continue;
            if((map[i][j]==0 && map[x][y]==0) || (map[i][j]>0 && map[x][y]>0)) //Run
            {
                if(map[x][y]==2 && b>0 && dist[x][y][b-1][g]>t+3)   //Titan
                {
                    dist[x][y][b-1][g]=t+3;
                    q.push((heapnode){x,y,b-1,g,t+3});
                }
                else if(map[x][y]!=2 && dist[x][y][b][g]>t+3)       //ground or building
                {
                    dist[x][y][b][g]=t+3;
                    q.push((heapnode){x,y,b,g,t+3});
                }
            }
            if(g>=2)                                                            //Jet
            {
                if(map[x][y]==2 && b>0 && dist[x][y][b-1][g-2]>t+1) //Titan
                {
                    dist[x][y][b-1][g-2]=t+1;
                    q.push((heapnode){x,y,b-1,g-2,t+1});
                }
                else if(map[x][y]!=2 && dist[x][y][b][g-2]>t+1)     //ground or building
                {
                    dist[x][y][b][g-2]=t+1;
                    q.push((heapnode){x,y,b,g-2,t+1});
                }
            }
		}
		for(int k=0;k<8;k++)                                                    //Hook
		{
		    int x=i+ki[k];
		    int y=j+kj[k];
		    if(!chk(x,y))
                continue;
            if(g>=1)
            {
                if(map[x][y]==2 && b>0 && dist[x][y][b-1][g-1]>t+2) //Titan
                {
                    dist[x][y][b-1][g-1]=t+2;
                    q.push((heapnode){x,y,b-1,g-1,t+2});
                }
                else if(map[x][y]==1 && dist[x][y][b][g-1]>t+2)     //building
                {
                    dist[x][y][b][g-1]=t+2;
                    q.push((heapnode){x,y,b,g-1,t+2});
                }
            }
		}
	}
	return -1;
}

int main()
{
    char c;
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%d%d%d%d",&si,&sj,&sb,&sg);
        si--,sj--;
        for(int i=0;i<n;i++)
        {
            getchar();
            for(int j=0;j<m;j++)
            {
                scanf("%c",&c);
                if(c=='G')
                    map[i][j]=0;
                else if(c=='B')
                    map[i][j]=1;
                else if(c=='T')
                    map[i][j]=2;
                else
                {
                    map[i][j]=1;
                    ei=i;
                    ej=j;
                }
            }
        }
        int k=dijsktra();
        if(k==-1)
            printf("Eran!!\n");
        else
            printf("%d\n",k);
    }
    return 0;
}
