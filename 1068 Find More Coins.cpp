/*�ڶ���ѵ��*/
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
            if(j >= arr[i] && dp[i - 1][j - arr[i]] != -1)  //�ؼ���
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
 * �������������һ����Сʱ��dp��������̫�١��ò�����������ˣ�һ����д��ȫ��Щ
 * �ܵͼ���bug
 * ���մ��е�˼·���ȵ���Ȼ��dp������Ļ������滻���Ž�����⣬���鷳��
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
    for(int i = 1; i <= n; i++){    ///j�ǵ�i��Ӳ���Ѿ������꣨�û��߲��ã�֮���Ѿ��õ��ļ�ֵ
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