//给几个数，算出每个数所占数的总和的百分比，所有的百分比加起来要等于100，取整的时候可以向上取整或向下

//先向下取整 然后看看差几个能变成100 然后 把不能被整除的前几个加一
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
#define read1           freopen("in.txt","r",stdin)
#define write1           freopen("out.txt","w",stdout)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
const int KM =48 ;
const int MOD = 95542721;
#define INF 1<<28
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn =  10001;
//int p[10000001];

int n,num[maxn],tmp;
int vis[maxn];
int ans[maxn],dd;
int sum;
int main() {
    RI(n);
    sum=0;
    FOR(i,1,n){
        RI(num[i]);
        sum+=num[i];
    }
    CLR(vis);
    tmp=0;
    FOR(i,1,n){
        ans[i]=num[i]*100/sum;
        if(num[i]*100%sum==0) {
            vis[i]=1;
        }
        else {
            vis[i]=0;
        }
        tmp+=ans[i];
    }
    dd=100-tmp;
    FOR(i,1,n){
        if(dd==0) break;
        if(!vis[i]) {
            ans[i]++;
            dd--;
            vis[i]=1;
        }
    }
    FOR(i,1,n){
        if(i!=n) PIS(ans[i]);
        else PIN(ans[i]);
    }
    return 0;
}
