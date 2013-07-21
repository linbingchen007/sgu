//f[n]=min(f[n-p[i]]+1,f[n])
//边界 f[0]=0  其他的f[k]=INF (k!=0)
//因为开始的时候 看错题 所以wa 了一发 人家让降序输出  我升序输出 。。。。
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

#define CLR(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define REP(i,n) for(long long i=0;i<(n);i++)
#define RI(x) scanf("%d",&x)
#define DRI(x) long long x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) long long x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) long long x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define FOREA(x,vec) for((typeof(vec.begin())) vec.begin();x!=vec.end();(x)++)
#define PIN(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define PI(x) printf("%d",x)
#define PSI(x) printf(" %d",x)
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
const long long KM =48 ;
const long long MOD = 95542721;
#define INF 1<<28
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const long long maxn =  111111;
int vis[10001];
int prime[5001];
int supprim[2501];
int tail,tails,n;
int f[10001];
int pat[10001];
int ans[10001];
int tailans;
int main() {
    //memset(vis,0,sizeof(vis));
    CLR(vis);
    vis[1]=1;
    tail=0;
    for(int i=2; i<=10000; i++) {
        if(!vis[i]) {
            prime[++tail]=i;
            for(int j=i*i; j<=10000; j+=i) //这个是 vis数组范围
                vis[j]=1;
        }
    }
    tails=0;
    FOR(i,1,tail){
        if(!vis[i]) {
            supprim[++tails]=prime[i];
           // PIS(prime[i]);

        }
    }
    FOR(i,1,10000) f[i]=INF;
    f[0]=0;
    //f[n]=min(f[n-p[i]]+1)
    FOR(i,1,10000){
        FOR(j,1,tails){
            if(i-supprim[j]>=0){
                if(f[i-supprim[j]]+1<f[i]){
                    f[i]=f[i-supprim[j]]+1;
                    pat[i]=supprim[j];
                }
            }
        }
    }
    tailans=0;
    RI(n);
    if(f[n]==INF) puts("0");
    else {
        PIN(f[n]);
        while(n!=0){
            if(n-pat[n]!=0) ans[tailans++]=pat[n];
                //PIS(pat[n]);
            else //PIN(pat[n]);
                ans[tailans++]=pat[n];
            n-=pat[n];
        }
        sort(ans,ans+tailans);
        for(int i=tailans-1;i>=0;i--){
        //FOR(i,0,tailans-1){
            if(i!=0) PIS(ans[i]);
            else PIN(ans[i]);
        }
    }
    return 0;
}
