/***
 * �������������һ����Сʱ��dp��������̫�١��ò�����������ˣ�һ����д��ȫ��Щ
 * �ܵͼ���bug
 * ���մ��е�˼·���ȵ���Ȼ��dp���о��������Ҳ�ܵõ��𰸡���������ȥ����
 * �����ʱ��������±�㷴�ˣ�Ȼ����ַ�����case debug������һ��Сʱ���ҵ����⡣zz
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
