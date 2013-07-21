//1001步内必须循环
#include<iostream>
#include<cstdio>
#include <map>
#include<algorithm>
#include<cstring>
using namespace std;
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define CLR(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PIN(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')

typedef long long int LL;
const int maxn = 1002;
int a,b,c,m,k,t,fuci;
int f[maxn];
//xi = (alpha * xi-1^2 + beta * xi-1 + gamma) mod M, for i >= 1.
int fun(int x){
    return (((a*x)%m)*x+b*x+c)%m;
}
int main() {
    RIII(f[0],a,b);
    RIII(c,m,k);
    map<int,int> lis;
    lis[f[0]]=0;
    FOR(i,1,1000){
        f[i]=fun(f[i-1]);
        if(lis.count(f[i])){
            t=i-lis[f[i]];
            fuci=lis[f[i]];
            break;
        }else lis[f[i]]=i;
    }
    if(k<fuci) cout<<f[k]<<endl;
    else{
        cout<<f[fuci+(k-fuci)%t]<<endl;
    }
   return 0;
}
