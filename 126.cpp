//sgu 126 模拟 
//模拟题 如果 模拟次数超过 64*64 次 说明进入死循环了 鸽笼定理

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
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define LL long long
#define maxn 100000001
#define INF 1<<28
//P, M, C, K, R and V
int a,b,num;
int main() {
    //read;
    // write;
    scanf("%d%d",&a,&b);
    num=0;
    while(a&&b&&num<=1200){
        if(a>b) swap(a,b);
        //a+=a;
        b-=a;
        a+=a;
        num++;
    }
    if(num>1200) puts("-1");
    else printf("%d\n",num);
    return 0;
}
