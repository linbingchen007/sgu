//0居然不是自然数。。。。。。 这题就是2分 因为函数是单调的 令答案为5k 则 q=k+k/5+k/5/5+k/5/5/5.......
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
int fuc,q;
int mid,low,high;
int judge(int tmp) {

    int res=tmp;
    tmp/=5;
    while(tmp) {
        res+=tmp;
        tmp/=5;
    }
    return res;
}
int main() {
    //read;
    // write;
    scanf("%d",&q);
    if(q==0) {puts("1");goto en;
    }
    low=1,high=q;
    int res;
    while(low<=high) {
        mid=low+(high-low)/2;
        if(judge(mid)<=q) {
            low=mid+1;
            res=mid;
        } else {
            high=mid-1;
        }
    }
    if(judge(res)==q)
        printf("%d",res*5);
    else puts("No solution");
    en:
    return 0;
}
