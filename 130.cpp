//f[i]=f[0]f[i-1]+f[1]f[i-2]+.....f[i-1]f[0]

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

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const long long maxn =  111111;

long long f[33],k;
int main() {
    CLR(f);
    f[1]=1;
    f[0]=1;
    FOR(i,2,30){
        FOR(j,0,i-1){
            f[i]+=f[j]*f[i-1-j];
        }
    }
    cin>>k;
    cout<<f[k]<<' '<<k+1<<endl;
    return 0;
}
