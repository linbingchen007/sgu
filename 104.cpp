//f[i][j]  表示第i种花插在第j个花瓶的最优值
//f[i][j]=max(f[i-1][k]+g[i][j])  (i-1<=k<j)
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
#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif

using namespace std;
#define clr(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define LL long long
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define maxn 101
#define maxm 28111
#define INF 1<<28
int f[maxn][maxn];
int g[maxn][maxn];
int F,v;
struct _s {
    int x,y;
};
_s p[maxn][maxn];
void print(int x,int y){
    if(p[x][y].x){
        print(p[x][y].x,p[x][y].y);
        printf(" %d",y);
    }else printf("%d",y);
    return ;
}
int main() {
    scanf("%d%d",&F,&v);
    for(int i=1; i<=F; i++) {
        for(int j=1; j<=v; j++) {
            scanf("%d",&g[i][j]);
        }
    }
    clr(f);
    clr(p);
    for(int i=1; i<=F; i++) {
        for(int j=1; j<=v; j++) {
            f[i][j]=-(INF);
            for(int k=i-1; k<j; k++) {
                if(f[i-1][k]+g[i][j]>f[i][j]) {
                    f[i][j]=f[i-1][k]+g[i][j];
                    p[i][j].x=i-1;
                    p[i][j].y=k;
                }
                //f[i][j]=max(f[i][j],f[i-1][k]+g[i][j]);
            }
        }
    }
    int ans=-(INF),ansi;
    for(int i=F; i<=v; i++) {
        if(f[F][i]>ans) {
            ans=f[F][i];
            ansi=i;
        }
    }
    printf("%d\n",ans);
    print(F,ansi);
    puts("");
    return 0;
}
