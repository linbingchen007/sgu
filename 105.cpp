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
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define LL long long
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
#define maxn 101
#define maxm 28111
#define INF 1<<28
int n,ans,opt;
int main() {
    scanf("%d",&n);
    ans=n/3;
    opt=n%3;
    ans*=2;
    if(opt==2) ans++;
    printf("%d\n",ans);
    return 0;
}
