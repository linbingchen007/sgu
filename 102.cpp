#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define clr(x) memset(x,0,sizeof(x))
#define maxn 10
#define maxm 222
//无向边

int vis[10001];
int main() {
    int N;
    int c=0;
    scanf("%d",&N);
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=2; i<=N; i++) {
        if(!vis[i]) {
            //prime[c++]=i;
            for(int j=i*i; j<=N; j+=i) //这个是 vis数组范围
                vis[j]=1;
        }
    }


    int *phi=(int*)malloc((N+1)*sizeof(int));
    for(int i=1; i<=N; i++) {
        phi[i]=i;
    }
    for(int i=2; i<=N; i++) {
        if(!vis[i]) {
            for(int j=i; j<=N; j+=i) {
                phi[j]=phi[j]/i*(i-1); //此处注意先/i再*（i-1)，否则范围较大时会溢出
            }
        }

    }
    printf("%d\n",phi[N]);
    // Phi[j]为 j=j/i*(i-1)  i为j的质因数

    return 0;
}
