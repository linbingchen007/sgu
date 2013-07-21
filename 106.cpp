//我对题意的理解与测试数据不符。。。。。题目上说  x1<=x2 && y1<=y2 才算有解  因此 我 觉得 如果 x1>x2  || y1>y2  应该输出0才对。。。可是实际上 应该 把 x1,x2 或者 y1，y2 交换 再进行运算 。。。题目描述明显有问题 。 除了这个就没有wa的原因了。。。。
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
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define LL long long
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define maxn 101
#define maxm 28111
#define INF 1<<28
long long a,b,c,xx1,x2,yy1,y2,xx0,yy0,g,ans,t,a1,b1,left,left1,left2,right,right1,right2;

void supergcd(long long a,long long b,long long &d,long long &x,long long &y) {
    if(!b) {
        d=a;
        x=1;
        y=0;
    } else {
        supergcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}


int main() {  
    while(~scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&xx1,&x2,&yy1,&y2)) {
        c=-c;        
        if(a&&b) { //a，b不为零
            supergcd(a,b,g,xx0,yy0);
            if(c%g) { //无整数解
                ans=0;
            } else {
                t=c/g;
                a1=a/g;
                b1=b/g;
                long long tx=xx0*t,ty=yy0*t;              

                left1=(int)ceil(((double)xx1-tx)/b1);
                right1=(int)floor(((double)x2-tx)/b1);
                if(left1>right1) swap(left1,right1);
                left2=(int)ceil(((double)ty-y2)/a1);
                right2=(int)floor(((double)ty-yy1)/a1);
                if(left2>right2) swap(left2,right2);
                left=max(left1,left2);
                right=min(right1,right2);
                ans=((right-left+1)>0? right-left+1:0);
            }

        } else if(!b&&a) { //b为0 a不为0
            long long tmp;
            if(c%a==0) {
                tmp=c/a;
                if(tmp>=xx1&&tmp<=x2) ans=(y2-yy1+1)>0? (y2-yy1+1):0;
                else ans=0;
            } else ans=0;

        } else if(!a&&b) { //a为0 b不为0
            long long tmp;
            if(c%b==0) {
                tmp=c/b;
                if(tmp>=yy1&&tmp<=y2) ans=(x2-xx1+1)>0? (x2-xx1+1):0;
                else ans=0;
            } else ans=0;
        } else {
            if(c!=0) ans=0;
            else {
                long long tx1=(int)ceil(xx1);
                long long tx2=(int)floor(x2);
                long long ans1=tx2-tx1+1;
                long long ty1=(int)ceil(yy1);
                long long ty2=(int)floor(y2);
                long long ans2=ty2-ty1+1;
                ans1=ans1>0? ans1:0;
                ans2=ans2>0? ans2:0;
                ans=ans1*ans2;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
