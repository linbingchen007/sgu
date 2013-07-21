/*
 . .      # .      # #    # #       # .    . #
|#|#     |#|.     |#|.    .|#|     |#|#   |#|#
1         2         3      4        5       6
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int LL;
const int maxn = 1<<11;
#define bin(i) (1<<i)
#define emp(a,i) (!(a&bin(i)))
int n,m,full;
LL g[maxn],f[maxn]; //f为当前行状态 g为枚举当前行状态后,对下一行的影响
void dfs(int a,int b,LL k) {
    if(a == full) { //当前行已经满了
        g[b] += k; //下一行的b状态的 填充数+k
        return ;
    }
    for(int i=0; i<m; ++i)
        if(emp(a,i)) { //当前行第i个元素为空
            if(i+1<m&&emp(a,i+1)) {//并且 第i+1个元素也为空 并且 i+1未超出范围
                dfs(a|bin(i)|bin(i+1),b,k); // //横向填充
                if(emp(b,i)) dfs(a|bin(i)|bin(i+1),b|bin(i),k);// 如果下一行的第i个元素也为空 5号填充
                if(i+1<m&&emp(b,i+1))dfs(a|bin(i)|bin(i+1),b|bin(i+1),k); // 如果i+1未超出范围 并且下一行的第i+1元素为空  6号填充
            }
            if(emp(b,i)) { //如果下一行的第i个元素为空
                dfs(a|bin(i),b|bin(i),k); //竖向填充
                if(i+1<m&&emp(b,i+1))dfs(a|bin(i),b|bin(i)|bin(i+1),k); //i+1未超范围 并且下一行的i+1元素为空 3号填充
                if(i>=1&&emp(b,i-1))dfs(a|bin(i),b|bin(i)|bin(i-1),k); //i-1未超范围，并且下一行的i-1元素为空 4号填充
            }
            break; //每次进行一个状态的填充
        }
}
int main() {
    cin >> n >> m;
    full = (1<<m)-1;
    f[full] = 1;//第一行的上一行 默认为填满
    for(int k=0; k<=n; ++k) { // 要枚举出 n+1行的状态
        for(int i=0; i<=full; ++i) //枚举上一行状态
            if(f[i]) {
                dfs(i,0,f[i]); // 当前行为i 下一行为零 进行dfs下一行
            }
        memcpy(f,g,sizeof(g));//下一行 变成 当前行
        memset(g,0,sizeof(g));//当前行 变成 下一行
    }
    cout <<f[0] <<endl; //输出下一行为0时的方案数
    return 0;
}
