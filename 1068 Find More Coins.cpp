/***
 * 想这个问题想了一个多小时，dp还是练得太少。好不容易想清楚了，一动手写，全是些
 * 很低级的bug
 * 按照大佬的思路，先倒序然后dp。感觉正序或许也能得到答案。但是懒得去试了
 * 定义的时候把数组下标搞反了，然后二分法对着case debug了整整一个小时才找到问题。zz
 * */
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
