//就是带个限制 其他的没什么  计算的时候判断下就行了
//以后初始化的时候要看自己 的数组开的够不够大 不然 wa到死。。。。。
//因为 first=-1的时候 初始化 从 1到2n 不知道 当时怎么想的  应该是 1到n啊！！！
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif

using namespace std;
#define clr(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define LL long long
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define maxn 333
#define maxm 28111 //无相边的话要开2倍
#define INF 1<<28
int d[maxn];
int n,m;
int first[maxn];
int u[maxm],v[maxm],w[maxm],next1[maxm];
int ric[maxn],tib[maxn],tip[maxn],c[maxn],pre[maxn],ap[maxn];


bool inq[maxn];

void getcolor(int t,int p,int &k,int &flag) { //flag 1为蓝 0为紫色  k下次变色所需时间
    if(t<ric[p]) {
        k=ric[p]-t;
        flag=c[p];
        return ;
    }
    if(c[p]==1) { //如果是初始蓝色
        int tmp=(t-ric[p])%(tib[p]+tip[p]);
        if(tmp>=0&&tmp<tip[p]) { //当前是紫色
            flag=0;
            k=tip[p]-tmp; 
            return ;
        } else { //当前是蓝色
            flag=1;
            k=(tib[p]+tip[p])-tmp;
            return ;
        }
    } else {
        int tmp=(t-ric[p])%(tib[p]+tip[p]);
        if(tmp>=0&&tmp<tib[p]) {//当前是蓝色
            flag=1;
            k=tib[p]-tmp;
            return ;
        } else {//当前是紫色
            flag=0;
            k=tib[p]+tip[p]-tmp;
            return ;
        }
    }
}
int staytime(int curtime,int u,int v) {
    int k1,k2,t; //距离下次变色的时间
    int flag1,flag2;
    getcolor(curtime,u,k1,flag1);
    getcolor(curtime,v,k2,flag2);
    if (flag1==flag2) return 0;
    else {
        t=0;
        FOR(i,1,5) {//五次变色仍然不连通 那么永远不连通
            t+=min(k1,k2);
            getcolor(curtime+t,u,k1,flag1);
            getcolor(curtime+t,v,k2,flag2);
            if(flag1==flag2) return t;
        }
        return INF;
    }
}
void SPFA(int s) {
    queue <int> q;

    for(int i=1; i<=n; i++){
        d[i]=(i==s? 0:INF);
        pre[i]=-1;
    }
    clr(inq);//初始化
    q.push(s);
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        inq[x]=false;
        for(int e=first[x]; e!=-1; e=next1[e]) {
            int tmp=staytime(d[x],u[e],v[e]);
            if(d[x]+w[e]+tmp<d[v[e]]&&(d[x]+w[e]+tmp)>0) {
                d[v[e]]=d[x]+w[e]+tmp;//松弛
                pre[v[e]]=x; //打印节点
                if(!inq[v[e]]) { //如果已经在队列中 就不要重复加了
                    inq[v[e]]=true;
                    q.push(v[e]);
                }
            }
        }
    }

}
int tu,tv,tw,s,t,e;
/*  //递归打印可能会爆内存 所以我改成了迭代
void print(int i) {
    if(path[i]!=-1) {
        print(path[i]);
        printf(" %d",i);
    } else printf("%d",i);
    return ;
} */
int main() {
    scanf("%d%d",&s,&t);
    scanf("%d%d",&n,&m);
    char tc[5];
    e=0;
    for(int i=0; i<=n+2; i++)
        first[i]=-1;
    for(int i=1; i<=n; i++) {
        scanf("%s%d%d%d",tc,&ric[i],&tib[i],&tip[i]);
        if(tc[0]=='B') {
            c[i]=1;
        } else c[i]=0;
    }
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d",&tu,&tv,&tw);
        //cin>>u[e]>>v[e]>>w[e]; //这是有向图
        u[e]=tu;
        v[e]=tv;
        w[e]=tw;
        next1[e]=first[u[e]];
        first[u[e]]=e;
        e++;
        u[e]=tv;
        v[e]=tu;
        w[e]=tw;
        next1[e]=first[u[e]];
        first[u[e]]=e;
        e++;
    }
    for(int i=0;i<=n;i++){
        pre[i]=-1;
    }
    SPFA(s);
    if(d[t]!=INF) {
        printf("%d\n",d[t]);
        int tail=0;

        for(int i=t;i!=-1;i=pre[i]){
            ap[tail++]=i;
        }
        //printf("%d",s);
        for(int i=tail-1;i>=0;i--){
            if(i!=tail-1) putchar(' ');
            printf("%d",ap[i]);
        }
        //print(t);
        puts("");
    } else puts("0");
    return 0;
}
