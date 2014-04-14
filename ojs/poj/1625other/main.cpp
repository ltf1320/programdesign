#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define	FOR(i,n)	for(int i=0; i<n; i++)
#define CC(A, x)	memset(A, x, sizeof(A))

const int NN = 200; //最大节点数
int CH;	  //儿子个数

struct Trie{
	inline int sw(unsigned char *c) {return hash[*c];}

	void init(){
		CC(word,0); CC(fail,0); CC(chd, 0); sz = 1;
	}

	void read(int N, int P){
		unsigned char ch;
		for (int i=0; i<N; i++){
			cin>>ch; hash[ch]=i;
		}
		unsigned char str[16];
		for (int i=0; i<P; i++){
			cin>>str; insert(str, 1);
		}
	}

	void insert(unsigned char *s, int v){
		int p = 0;
		for (; *s; p=chd[p][sw(s++)])
			if (!chd[p][sw(s)]) chd[p][sw(s)] = sz++;
		word[p] += v;
	}

	void AC(){
		int *b=Que, *e=b;
		FOR(i,CH) if(chd[0][i]) *e++ = chd[0][i];
		for (int p=*b; b!=e; p=*++b){
			FOR(i,CH) if(chd[p][i]){
				fail[*e++ = chd[p][i]] = chd[fail[p]][i];
				if (word[fail[chd[p][i]]]) word[chd[p][i]] = 1;//传递病毒包含的病毒
			}else chd[p][i] = chd[fail[p]][i];
		}
	}

	int hash[256];
	int chd[NN][50], sz;//节点数组，个数
	int word[NN], fail[NN], Que[NN];
}trie;

struct Number{
	Number(){CC(A,0); A[0]=1;}
	void set(int x){CC(A,0); A[0]=1; A[1]=x;}
	void print(){
		cout<<A[A[0]];
		for (int i=A[0]-1; i>0; i--){
			if (A[i]==0){cout<<"0000"; continue;}
			for (int k=10; k*A[i]<MOD; k*=10) cout<<'0';
			cout<<A[i];
		}
		cout<<endl;
	}
	Number operator + (const Number& B){
		Number C;
		C[0]=max(A[0], B[0]);
		for (int i=1; i<=C[0]; i++)
			C[i]+=A[i]+B[i], C[i+1]+=C[i]/MOD, C[i]%=MOD;
		if (C[C[0]+1] > 0) C[0]++;
		return C;
	}
	Number operator * (const Number& B){
		Number C;
		C[0]=A[0]+B[0];
		for (int i=1; i<=A[0]; i++)
			for (int j=1; j<=B[0]; j++){
				C[i+j-1]+=A[i]*B[j], C[i+j]+=C[i+j-1]/MOD, C[i+j-1]%=MOD;
			}
		if (C[C[0]] == 0) C[0]--;
		return C;
	}
	int& operator [] (int p) {return A[p];}
	const int& operator [] (int p) const {return A[p];}
	int A[25];
	enum{MOD = 10000};
};

Number F[51][101];

int M, P;

void DP(){
	F[0][0].set(1);
	for (int i=1; i<=M; i++)
		for (int j=0; j<trie.sz; j++)
			for (int k=0; k<CH; k++){
				int id = trie.chd[j][k];
				if (!trie.word[id]) F[i][id] = F[i][id] + F[i-1][j];
			}

	Number ans;
	for (int i=0; i<trie.sz; i++)
		if (!trie.word[i]) ans = ans + F[M][i];
	ans.print();
}

int main()
{
	trie.init();

	cin>>CH>>M>>P;
	trie.read(CH, P);

	trie.AC();

	DP();

	return 0;
}
