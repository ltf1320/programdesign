#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define sz(x) ((x).size())

const int N = 100009;
const ll oo = 0x3f3f3f3f3f3f3f3fll;

int n, ex, A, B;

int dpMx[N], dpMn[N], a[N];

int dfsMx(int x){
	if(x <= 1) return 0;
	int & ret = dpMx[x];
	if(ret + 1) return ret;
	return ret = dfsMx(x - 1) + x - 1;
}

int dfsMn(int x){
	if(x <= 1) return 0;
	int & ret = dpMn[x];
	if(ret + 1) return ret;
	int a = (x - 1) / 2;
	int b = x - 1 - a;
	return ret = dfsMn(a) + dfsMn(b) + x - 1;
}

void print(int l, int r, int ex){
	if(l > r) return ;
	if(l == r){
		a[l] = l;
		return ;
	}
	int k = (l * A + r * B) / (A + B);
	int x = r - l;
	ex -= x;
	for(int i = 0; i <= x / 2; i++){
		int left = dfsMn(i), right = dfsMx(i), ret = -1;
		while(left <= right){
			int mid = (left + right) >> 1;
			if(dfsMx(x - i) < ex - mid) left = mid + 1;
			else if(dfsMn(x - i) > ex - mid) right = mid - 1;
			else {
				ret = mid;
				break;
			}
		}
		if(ret == -1) continue;
		print(l, l + i - 1, ret);
		print(l + i + 1, r, ex - ret);
		a[l + i] = l + i;
		swap(a[l + i], a[r]);
		/*
		if(k < i + l){
			for(int j = i + l - 1; j >= k; j--)
				swap(a[j], a[j + 1]);

		}

		else*/{
			swap(a[k], a[r]);
		}
		break;
	}
}

int main(){
	memset(dpMx, -1, sizeof(dpMx));
	memset(dpMn, -1, sizeof(dpMn));
	while(scanf("%d%d%d%d", &n, &ex, &A, &B) == 4){
		if(ex > dfsMx(n) || ex < dfsMn(n)){
			puts("NOWAY");
			continue;
		}
		print(0, n - 1, ex);
		for(int i = 0; i < n; i++){
			if(i) printf(" ");
			printf("%d", a[i] + 1);
		}
		puts("");
	}
	return 0;
}
