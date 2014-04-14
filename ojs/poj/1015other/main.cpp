#include<stdio.h>
#include<stdlib.h>
#define N 1000
#define NN 25
//sub ��plus ���
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
	int ans[NN];//��·��
	while(~scanf("%d%d",&n,&m),n||m){

		for(i=1;i<=n;i++){

			scanf("%d%d",&x,&y);
			sub[i]=x-y;
			plus[i]=x+y;
		}
		//��ʼ��
		for(i=0;i<NN;i++)
			for(j=0;j<N;j++)
				map[i][j]=path[i][j]=-1;

			size =m*NN;		//��Ϊ����ڸ�ֵ�����Կ���ѡ��ÿ����+���̶�ֵ��Ϊ��ʼֵ
			//map �洢 ѡ �� i �� �� ʱ ����Ϊ j ʱ,���ĺ�

			//path �洢·��
			map[0][size]=path[0][size]=0;

			for(i = 1 ; i <= n ; i++){			//��ѡ���һ����

				if(map[1][size+sub[i]] <plus[i]){		//��֤�� ��Ϊ size+sub[i] ʱ��plus Ϊ���ֵ

					map[1][size+sub[i]] = plus[i];
					path[1][size+sub[i]] = i;
				}
			}
			// �� i ���� i+1
			for(i = 1 ; i < m ; i++){

				for( j = 0 ; j < 2*size ; j++){		//ö�ٲ�Ϊ j ʱ���������

					if(path[i][j]>=0){	//��� ��Ϊ j ʱ������·��ͨ��

						for( k = 1 ; k <= n ; k++){			//ö��N����

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

			//���Ǹ�����ֵ ��С�� ��
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
