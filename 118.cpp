//数字根 就是 mod9 记住就行了。。。然后就是同余模定理了

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
#define maxn 10001
#define INF 1<<28
int k,n,ans;
int a[1001];

int main() {
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]=a[i]%9;
        }
        ans=1;
        for(int i=n;i>=1;i--){
            if(i!=1)  ans=(ans*a[i]+1)%9;
            else ans=(ans*a[i])%9;
        }
        printf("%d\n",(ans==0? 9:ans));
    }
    return 0;
}
