#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
int main()
{
    int n, m, arr[10010];
    cin >> n >> m;
    vector<vector<int>> mmm(n);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        mmm[a].push_back(b);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        fill(arr, arr + 10010, -1);
        unordered_map<int, set<int>> exist;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
            if(exist.count(arr[j]) == 0)
                cnt++;
            exist[arr[j]].insert(j);
        }
        int flag = 1;
        for(int j = 0; j < n; j++){
            for(int jj = 0; jj < mmm[j].size(); jj++)
                if(exist[arr[j]].count(mmm[j][jj]) != 0){
                    flag = 0;
                    break;
                }
        }
        if(flag)
            printf("%d-coloring\n", cnt);
        else
            printf("No\n");
    }
    return 0;
}
