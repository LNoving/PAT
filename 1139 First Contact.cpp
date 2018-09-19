/**
 * 题目比较坑的点：-0000的处理，输出的时候要%04d
 *
 *我又双叒叕他妈的把 = 写成 == 了，而且复制过去四个全是错的。根本找不到bug。妈的傻逼。
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m, k, gender[10010] = {0};
vector<int> e[10010];
bool cmp(vector<int> a, vector<int> b){
    if(a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string aa, bb;
        cin >> aa >> bb;
        int a = stoi(aa), b = stoi(bb);
        gender[abs(a)] = a > 0 ? 1 : -1;
        gender[abs(b)] = b > 0 ? 1 : -1;
        if(a == 0)
            gender[a] = aa[0] == '-' ? -1 : 1;
        if(b == 0)
            gender[b] = bb[0] == '-' ? -1 : 1;
        e[abs(a)].push_back(abs(b));
        e[abs(b)].push_back(abs(a));
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        vector<vector<int>> ans;
        for(int ii = 0; ii < e[a].size(); ii++){
            int curii = e[a][ii];
            if(curii == b || curii == a)continue;
            if(gender[curii] != gender[a])
                continue;
            for(int jj = 0; jj < e[ curii ].size(); jj++){
                int curjj = e[curii][jj];
                if(curjj == b || curjj == a)continue;
                if(gender[curjj] != gender[b])
                    continue;
                for(int kk = 0; kk < e[curjj].size(); kk++){
                    int curkk = e[curjj][kk];
                    if(curkk == b){
                        vector<int> tmp;
                        tmp.push_back(curii);
                        tmp.push_back(curjj);
                        ans.push_back(tmp);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans.size() << endl;
        for(int j = 0; j < ans.size(); j++){
            printf("%04d %04d\n", ans[j][0], ans[j][1]);
        }
    }
}
