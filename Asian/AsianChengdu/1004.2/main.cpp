#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define LL long long
LL numa[2][2], numb[2][2];
void matrix(LL a[2][2], LL b[2][2], int mark, LL MOD) {
    LL temp[2][2];
    temp[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
    temp[0][1] = (a[0][0] * b[1][0] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
    temp[1][0] = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
    temp[1][1] = (a[1][0] * b[1][0] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
    if (mark) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                numa[i][j] = temp[i][j];
            }
        }
    } else {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                numb[i][j] = temp[i][j];
            }
        }
    }
}
LL cal(LL n, LL MOD) {
    numa[0][0] = 1;
    numa[0][1] = 0;
    numa[1][0] = 0;
    numa[1][1] = 1;
    numb[0][0] = 3;
    numb[0][1] = 1;
    numb[1][0] = 1;
    numb[1][1] = 0;

    while (n) {
        if (n & 1) {
            matrix(numa, numb, 1, MOD);
        }
        matrix(numb, numb, 0, MOD);
        n >>= 1;
    }
    return numa[0][1];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
#endif
            LL n;
            while (~scanf("%I64d", &n)) {
                printf("%I64d\n",
                        cal(cal(cal(n, 183120LL), 222222224LL),1000000007LL));
        }
        return 0;
}
