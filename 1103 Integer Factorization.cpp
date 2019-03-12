//老子的dp比你们的dfs不知道快到哪里去了 dfs的做法做了很久没通过，剪枝减得有问题。以后再写吧，如果有以后
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n, k, p, dp[401][401], factor[401], maxx, inf = -1, path[401][401];
    cin >> n >> k >> p;
    fill(dp[0], dp[0] + 401 * 401, inf);
    for(maxx = 1; (int)(pow(maxx, p) + 0.001) <= n; maxx++){
        factor[maxx] = pow(maxx, p) + 0.001;
        dp[1][factor[maxx]] = maxx;
        path[factor[maxx]][1] = maxx;
    }
    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= n; j++){
            for(int jj = 1; jj < maxx; jj++){
                if(j <= factor[jj])
                    break;
                if(dp[i - 1][j - factor[jj]] != inf && dp[i - 1][j - factor[jj]] + jj >= dp[i][j]){
                    dp[i][j] = dp[i - 1][j - factor[jj]] + jj;
                    path[j][i] = jj;
                }
            }
        }
    }
    if(dp[k][n] == inf)
        printf("Impossible\n");
    else{
        printf("%d = %d^%d", n, path[n][k], p);
        n -= factor[path[n][k]];
        for(int i = 1; i < k; i++){
            printf(" + %d^%d", path[n][k - i], p);
            n -= factor[path[n][k - i]];
        }
    }
    return 0;
}
