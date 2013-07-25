#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define CLR(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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
#define RIIII(w,x,y,z) scanf("%d%d%d%d",&w,&x,&y,&z)
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
const int maxn=22;
int n,m,ans;
struct _p{
    int r,h;
};
_p buf[maxn];
int tn;
int calv(){
    int res=0;
    FOR(i,1,tn){
        res+=buf[i].r*buf[i].r*buf[i].h;
    }
    return res;
}
int cals(){
    int res=buf[1].r*buf[1].r;
    FOR(i,1,tn){
        res+=2*buf[i].r*buf[i].h;
    }
    return res;
}
int tv;
long long nod;
void DFSVISIT(int r,int h,int save,int stage){
    nod++;
    if(stage==m){
        if(calv()==n){
            int ts=cals();
            if(ts<ans){
                ans=ts;


            }

            /*
             PIN(ts);
                FOR(i,1,tn){
                    PIS(buf[i].r);
                }
                puts(" R!");
                FOR(i,1,tn){
                    PIS(buf[i].h);
                }
                puts(" H!");
            */

            //ans=min(ans,cals());
        }
        return ;
    }
    FORD(i,buf[stage].r-1,1){
    //FOR(i,1,sqrt(save)){//Rk
        //if(i>=buf[stage].r) break;
        //FOR(j,1,save){//Hk
        FORD(j,buf[stage].h-1,1){

            //if(j>=buf[stage].h) break;
            if(tv+i*i*j*(m-stage)<n) continue;
            if(i*i*j>n) break;
            buf[stage+1].r=i;
            buf[stage+1].h=j;

            tn=stage+1;
            tv+=i*i*j;
            DFSVISIT(i,j,save-i*i*j,stage+1);
            tv-=i*i*j;
            tn=stage;
        }
    }
}

int main() {
    nod=0;
    RII(n,m);
    ans=1<<28;
    tv=0;
    FOR(i,m,sqrt(n)){//R1
        FOR(j,m,n){//H1
            if(i*i*j*m<n) continue;
            //if(i*i*j==n&&m==1) {
              //  printf("%d\n",2*i*(i+j));
              //  return 0;
            //}
            if(i*i*j>n) break;
            buf[1].r=i;
            buf[1].h=j;
            tn=1;
            tv=i*i*j;
            DFSVISIT(i,j,n-i*i*j,1);
            tv=0;
            tn=0;
        }
    }
    if(ans!=1<<28)
    PIN(ans);
    else puts("-1");
    //PIN(nod);
    return 0;
}
