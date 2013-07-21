想象一个栈  遇到"("压栈 遇到'')“ 弹栈 最后一个满足栈顶大于等于2 并且当前为"("为第一个改变的位置 然后 把他以后的")"都放到尾部
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
const int maxn=10001;
#define INF 1<<28
bool flag;
int buf[maxn],len,tmp,lastc,lastone;
char bc[12000];
char ansbuf[12000];
int main() {
    gets(bc);
    len=strlen(bc);
    tmp=0;
    lastc=-1;
    FOR(i,0,len-1) {
        if(bc[i]=='(') tmp++;
        else tmp--;
        if(tmp>=2&&bc[i]=='(') {
            lastc=i;
        }
    }
    if(lastc>=0) {
        lastone=0;
        FOR(i,lastc,len-1) {
            if(bc[i]==')') lastone++;
        }
        lastone--;
        memcpy(ansbuf,bc,sizeof(bc));
        ansbuf[lastc]=')';
        FORD(i,len-1,lastc+1) {
            if(lastone) {
                ansbuf[i]=')';
                lastone--;
            } else {
                ansbuf[i]='(';
            }
        }
        puts(ansbuf);
    } else puts("No solution");
    return 0;
}
