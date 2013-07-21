///wa了半天 发现没考虑询问的f[i] 的自变量可能重复
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <map>


using namespace std;
#define clr(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define LL long long
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define maxn 101
#define maxm 28111
#define INF 1<<28

const int mod=64;
int vis[64];
int f[5555];
struct _s {
    int val,id;
};
_s a[5555];
int num,n,k,top;
int cmp(_s a,_s b) {
    return a.val<b.val;
}
int main() {
     //read;
   // write;


    scanf("%d%d",&n,&k);

    for(int i=1; i<=k; i++) {
        a[i].id=i;
        scanf("%d",&a[i].val);
    }

    top=1;
    sort(a+1,a+1+k,cmp);

    num=0;
    for(int i=1; i<=n; i++) {
        if(!vis[i%mod]) {
            num++;
             //printf("%d:%d\n",num,i);
            while(num==a[top].val) f[a[top++].id]=i;
        } else vis[i%mod]=0; //用过一次后 及时清除 以便下次使用
        int tmp=i;
        int ans=i;
        while(tmp) {
            ans+=tmp%10;
            tmp/=10;
        }
        vis[ans%mod]=1;
    }
    printf("%d\n",num);
    for(int i=1; i<=k; i++) {
        if(i!=1) putchar(' ');
        printf("%d",f[i]);
    }
    puts("");
    //printf("%d",num[n]);
    return 0;
}
