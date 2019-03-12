/*第二遍训练*/
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){ return a > b;}
int main(){
    int n, m, dp[10010][201], arr[10010];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    sort(arr + 1, arr + n + 1, cmp);
    fill(dp[0], dp[0] + 10010 * 201, -1);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= arr[i] && dp[i - 1][j - arr[i]] != -1)  //关键点
                dp[i][j] = j - arr[i];
        }
    }
    if(dp[n][m] == -1){
        printf("No Solution\n");
        return 0;
    }
    int temp = m;
    for(int i = n; i > 0; i--){
        if(temp - arr[i] == dp[i][temp]){
            if(temp != m) printf(" ");
            printf("%d", arr[i]);
            temp = dp[i][temp];
        }
    }
}
/***
 * 想这个问题想了一个多小时，dp还是练得太少。好不容易想清楚了，一动手写，全是些
 * 很低级的bug
 * 按照大佬的思路，先倒序然后dp。正序的话会有替换最优解的问题，很麻烦。
 * */
/*
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, c[10010][110], coins[10010];
vector<int> ans[110], tans[110];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    scanf("%d %d", &n, &m);
    //fill(c[0], c[0] + 110*10010, 0);
    for(int i = 1; i<=n; i++)
        scanf("%d", &coins[i]);
    sort(coins + 1, coins + n + 1, cmp);
    for(int i = 1; i <= n; i++){    ///j是第i个硬币已经处理完（拿或者不拿）之后，已经拿到的价值
        for(int j = 0; j <= m; j++){
            tans[j] = ans[j];
            ans[j].clear();
        }
        for(int j = 0; j <= m; j++){
            if(coins[i] > j){
                c[i][j] = c[i - 1][j];  ///runtime error
                ans[j] = tans[j];
            }
            else{
                if(!(c[i - 1][j - coins[i]] == 0 && coins[i] != j)){
                    c[i][j] = c[i - 1][j - coins[i]] + 1;
                    ans[j] = tans[j - coins[i]];
                    ans[j].push_back(coins[i]);
                    continue;
                }
                c[i][j] = c[i - 1][j];
                ans[j] = tans[j];
            }
        }
    }
    if(ans[m].size() == 0)
        printf("No Solution");
    else{
        for(int i = ans[m].size() - 1; i>=0; i--){
            if(i != ans[m].size() - 1)
                printf(" ");
            printf("%d", ans[m][i]);
        }
    }
}
*/