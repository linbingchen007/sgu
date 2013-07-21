比较坑爹是 有的墙是一个点 例如(0,0,0,0) 这种情况要认为 形成了回路。。。。。。。。。。。这 真的算墙么！！！！
#include<iostream>
#include<cstdio>
#include <map>
#include<algorithm>
#include<cstring>
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
#define maxn 200002
int p[maxn];
int n,m,q,x,y,x1,x2,y1,y2,ansi;
int findset(int x) {
    return p[x]==x? x:p[x]=findset(p[x]);
}
struct _p {
    int x,y;

};
struct _l {
    _p u,v;
};
map <pair<int,int>,int> lis;

_l tmp;

_l lin[maxn];
_p fuc;
int main() {
    RI(n);
    FOR(i,1,n) {
        RIIII(tmp.u.x,tmp.u.y,tmp.v.x,tmp.v.y);
        lin[i]=tmp;
        p[i]=i;
    }

    //lis[fuc]=1;
    ansi=-1;
    FOR(i,1,n){
        if(lin[i].u.x==lin[i].v.x&&lin[i].u.y==lin[i].v.y){
            ansi=i;
                break;
        }
        if(lis.count(pair<int,int>(lin[i].u.x,lin[i].u.y))==0&&lis.count(pair<int,int>(lin[i].v.x,lin[i].v.y))==0) {//新树
            lis[pair<int,int>(lin[i].u.x,lin[i].u.y)]=i;
            lis[pair<int,int>(lin[i].v.x,lin[i].v.y)]=i;
        }
        else if(lis.count(pair<int,int>(lin[i].u.x,lin[i].u.y))!=0&&lis.count(pair<int,int>(lin[i].v.x,lin[i].v.y))==0){//插入树中形成树
            x=findset(i);
            y=findset(lis[pair<int,int>(lin[i].u.x,lin[i].u.y)]);
            if(x!=y) p[x]=y;
            lis[pair<int,int>(lin[i].v.x,lin[i].v.y)]=y;
        }else if(lis.count(pair<int,int>(lin[i].u.x,lin[i].u.y))==0&&lis.count(pair<int,int>(lin[i].v.x,lin[i].v.y))!=0){//插入树中形成树
            x=findset(i);
            y=findset(lis[pair<int,int>(lin[i].v.x,lin[i].v.y)]);
            if(x!=y) p[x]=y;
            lis[pair<int,int>(lin[i].u.x,lin[i].u.y)]=y;
        }else{ //插入后形成回路 或者连接两棵树
            x=findset(lis[pair<int,int>(lin[i].u.x,lin[i].u.y)]);
            y=findset(lis[pair<int,int>(lin[i].v.x,lin[i].v.y)]);
            if(x!=y){ //两棵树
                p[x]=y;
            }
            else{
                ansi=i;
                break;
            }
        }

    }
    if(ansi!=-1)
    cout<<ansi<<endl;
    else puts("0");
    return 0;
}

