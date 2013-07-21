//将区间 按a的升序 b的降序 进行排序
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
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
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
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
const int KM =48 ;
const int MOD = 95542721;
#define INF 1<<28
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn =  161111;
//int p[10000001];
struct _s{
    int a,b;
};
_s buf[maxn];
int cmp(_s sa,_s sb){
    if(sa.a!=sb.a) return sa.a<sb.a;
    else return sa.b>sb.b;
}
int n,tmpi,ans;
int main() {
    RI(n);
    FOR(i,1,n){
        RII(buf[i].a,buf[i].b);
    }
    sort(buf+1,buf+1+n,cmp);
    tmpi=1;
    ans=1;
    FOR(i,2,n){
        if(buf[i].b>buf[tmpi].b) {
            ans++;
            tmpi=i;
        }
    }
    ans=n-ans;
    PIN(ans);
    return 0;
}
