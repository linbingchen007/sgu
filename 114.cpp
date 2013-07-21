//求中位数.很容易证明若把"人数"看成"城市坐标"的"数据重复次数",全部数据的中位数可以为所求.若全部数据数量为偶数,中间两个数限制的闭区间内都可以成为解.
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
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
#define read1           freopen("in.txt","r",stdin)
#define write1           freopen("out.txt","w",stdout)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
struct _p{
    double x;
    int val;
};
_p p[15001];
int cmp(_p a,_p b){
    return a.x<b.x;
}
int n,rn,fuc;
double ans;
int main() {
    RI(n);
    rn=0;
    FOR(i,1,n){
        scanf("%lf%d",&p[i].x,&p[i].val);
        rn+=p[i].val;
    }
    rn/=2;
    rn++;
    sort(p+1,p+1+n,cmp);
    fuc=0;
    FOR(i,1,n){
        if(fuc<=rn&&rn<=fuc+p[i].val){
            ans=p[i].x;
            break;
        }else{
            fuc+=p[i].val;
        }
    }
    printf("%.5lf\n",ans);
}
