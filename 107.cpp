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
/*
111111111
119357639
380642361
388888889
611111111
619357639
880642361
888888889
*/
int n;
int main() {
    scanf("%d",&n);
    if(n<9) puts("0");
    else if(n==9){
        puts("8");
    }
    else{
        printf("72");
        for(int i=1;i<=n-10;i++){
            putchar('0');
        }
        putchar('\n');
    }
    return 0;
}

