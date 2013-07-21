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
#define maxn 65577
#define INF 1<<28
int n;
long long ans;
int c[maxn];
int lowbit(int x) {
    return x&-x;
}
int sum(int x) {
    int res=0;
    while(x>0) {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int num) {
    while(x<=n) {
        c[x]+=num;
        x+=lowbit(x);
    }
}
int buf[maxn]; //将范围比较大的元素映射到 1...n
struct _p{
    int val;
    int id;
};
_p buf1[maxn];
int cmp(_p a,_p b){
    return a.val<b.val;
}
int main() {
   RI(n);
   FOR(i,1,n){
       RI(buf1[i].val); //原象
       buf1[i].id=i; //原象位置
   }
   sort(buf1+1,buf1+n+1,cmp);
   buf[buf1[1].id]=1; //最小的元素映射成1
   FOR(i,2,n){   //将范围比较大的元素映射到 1...n buf[原象所在位置]=映射值
       if(buf1[i].val!=buf1[i-1].val) buf[buf1[i].id]=i;
       else buf[buf1[i].id]=buf[buf1[i-1].id];  
   }
   ans=0;
   FORD(i,n,1){ //从后往前插值 每次都检查比 所插值小的个，然后求和
       add(buf[i],1);
       ans+=sum(buf[i]-1);
   }
   cout<<ans<<endl;
   return 0;
}
