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
const int maxn =  111111;
//int p[10000001];
int f[]= {0,1,1,3,1,1,4};
int k;
int main() {
    RI(k);
    if(k==1) puts("8");
    else{
        PIN(f[(k-2)%6+1]);
    }
    
    return 0;
}
