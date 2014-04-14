#include<stdio.h>
#include<stdlib.h>
#define N 1000
#define NN 25
//sub 存差，plus 存和
int sub[NN*10],plus[NN*10];
int map[NN][N],path[NN][N];
int n,m;
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int x,y,i,j,k;
	int t=1;
	int size;
	int ans[NN];//存路径
	while(~scanf("%d%d",&n,&m),n||m){

		for(i=1;i<=n;i++){

			scanf("%d%d",&x,&y);
			sub[i]=x-y;
			plus[i]=x+y;
		}
		//初始化
		for(i=0;i<NN;i++)
			for(j=0;j<N;j++)
				map[i][j]=path[i][j]=-1;

			size =m*NN;		//因为差存在负值，所以可以选择每个数+个固定值做为初始值
			//map 存储 选 第 i 个 人 时 ，差为 j 时,最大的和

			//path 存储路径
			map[0][size]=path[0][size]=0;

			for(i = 1 ; i <= n ; i++){			//做选择第一个人

				if(map[1][size+sub[i]] <plus[i]){		//保证在 差为 size+sub[i] 时，plus 为最大值

					map[1][size+sub[i]] = plus[i];
					path[1][size+sub[i]] = i;
				}
			}
			// 由 i 计算 i+1
			for(i = 1 ; i < m ; i++){

				for( j = 0 ; j < 2*size ; j++){		//枚举差为 j 时的所有情况

					if(path[i][j]>=0){	//如果 差为 j 时，存在路径通过

						for( k = 1 ; k <= n ; k++){			//枚举N个人

							if(map[i+1][j+sub[k]]<map[i][j]+plus[k]){

								for( x = i, y = j ; x >= 1; x--){

									if(path[x][y] == k) break;
									y -= sub[path[x][y]];
								}
								if( x <1){

									map[i+1][j+sub[k]] = map[i][j] + plus[k];
									path[i+1][j+sub[k]] = k;
								}
							}
						}
					}
				}
			}

			//找那个绝对值 最小的 点
			for( j = 0 ; j <= 2*size ; j++){

				if( map[m][size+j] >=0||map[m][size-j]>=0){

					if(map[m][size+j] >map[m][size-j])
						i = size +j;
					else i=size -j;
					break;
				}
			}

			x=0;
			for(j = m ,k = i;j >= 1;j--){

				ans[x++] = path[j][k];
				k -=sub[ans[x-1]];
			}
			qsort(ans,m,sizeof(int),cmp);
			printf("Jury #%d\n",t++);
			printf("Best jury has value %d for prosecution and value %d for defence:\n",(map[m][i]+(i-size))/2,(map[m][i]-(i-size))/2);
			for(i=0;i<x;i++){

				printf(" %d",ans[i]);
			}
			puts("");
	}

	return 0;
}
