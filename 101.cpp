//骨牌是边 数字是点 求出欧拉路 或者 欧拉回路  而且要判断是否联通 不然会做很多无用功 100个dfs 估计就超时了  所以 要判断 是否联通 不连通直接 nosolution

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

using namespace std;
#define clr(x) memset(x,0,sizeof(x))
#define maxn 10
#define maxm 222
//无向边

int d[maxn],first[maxn],u[maxm],v[maxm],w[maxm],next1[maxm],pp[maxm],pf[maxm],vis[maxm];
int m,noo,flag;

int dfs(int fuc,int path) {
    vis[fuc]=1;
    vis[fuc^1]=1;  //同一个骨牌的正向边 与 反向边的vis 标记为true
    pp[path]=fuc;
    // pf[path]=w[fuc];
    if(path==m) return 1;


    for(int e=first[v[fuc]]; e!=-1; e=next1[e]) {
        if(!vis[e]&&dfs(e,path+1)) return 1;
    }
    vis[fuc]=0; //回溯
    vis[fuc^1]=0;
    return 0;
}
void print() {
    for(int i=1; i<=m; i++) {
        printf("%d %c\n",abs(w[pp[i]]),(w[pp[i]]>0? '+':'-')); //打印答案
    }
}
void dfvi(int i) {
    vis[i]=1;
    for(int e=first[i]; e!=-1; e=next1[e]) {
        if(!vis[v[e]]) dfvi(v[e]);
    }
}
int main() {
    scanf("%d",&m);
    clr(d);
    for(int i=0; i<=6; i++)
        first[i]=-1;
    int e=0;
    for(int i=1; i<=m; i++) {
        //cin>>u[e]>>v[e];
        scanf("%d%d",&u[e],&v[e]);
        w[e]=i; //这是有向图
        d[u[e]]++;
        d[v[e]]++;
        next1[e]=first[u[e]];
        first[u[e]]=e; //添加正向边
        e++;
        u[e]=v[e-1];
        v[e]=u[e-1];
        w[e]=-i;
        next1[e]=first[u[e]];
        first[u[e]]=e; //添加反向边
        e++;
    }
    noo=0; //度数为奇数的点的个数
    for(int i=0; i<=6; i++) {
        if(d[i]%2) noo++;
    }
    int g=0;
    for(int i=0; i<=6; i++) {
        if(first[i]!=-1&&!vis[i]) {
            dfvi(i);
            g++;
        }//求强连通分支数 不一定包含所有的点 
    }
    clr(vis);
    flag=false;
    if(g==1) {//如果是强连通图
        if(noo==2) { //奇数度数点 那么这个点 就是起点 欧拉路
            for(int i=0; i<=6; i++) {
                //clr(vis);
                if(first[i]!=-1&&(d[i]%2)&&dfs(first[i],1)) {
                    flag=true;
                    break;
                }
            }
        } else if(noo==0) { //一定存在欧拉回路
            for(int i=0; i<=6; i++) {
                //clr(vis);
                if(first[i]!=-1&&dfs(first[i],1)) {
                    flag=true;
                    break;
                }
            }
        }
    }
    if(flag) print();
    else puts("No solution");
    return 0;
}
