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
double x,y,z,ans,d;
int main() {
   while(scanf("%lf%lf%lf",&x,&y,&z)==3){
   ans=0;
   d=(y-x)*60;
   if(2*z<=d) {
       ans=1-((d-2*z)*(d-2*z)+2*(d-z)*z-z*z)/(d*d);
   }
   else if(2*z>d&&d>z){
       ans=1-(2*(d-z)*(d-z)-(d-z)*(d-z))/(d*d);
   }
   else ans=1;
   
   printf("%.7lf\n",ans);
   }
   return 0;
}
