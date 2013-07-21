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
void div(int l,int r,int p){
    int k=l+(r-l+1)/2-1;
    if(l==r) {
        PIN(p);
        return ;
    }
    if(p>k){
        if((r-l+1)%2) div(l,k+1,l+r-p);
        else div(l,k,l+r-p);
    }
    else{
        if((r-l+1)%2) div(k+2,r,k+2+k-p);
        else div(k+1,r,k+1+k-p);
    }
}
int n,q;
int main() {
    //memset(vis,0,sizeof(vis));
    RII(n,q);
    div(1,n,q);
    return 0;
}
