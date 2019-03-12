/**
 * 没有搞清楚题目的意思，所以在这道题上面花了很多时间。后来才发现原来就是简单的dfs
 * 直接用递归会导致段错误，改用队列之后就不会了，这说明递归调用在空间利用率上还是
 * 很吃亏的。记住这一点，以后说不定能用到。
 * */
#include <iostream>
#include <vector>
using namespace std;
struct node{
    int a, b, h;
};
int brain[61][1290][129], m, n, l, t, ans = 0, cnt;
void bfs(int a, int b, int h){
    if(brain[h][a][b] != 1)
        return;
    vector <node> v;
    v.push_back(node{a, b, h});
    while(!v.empty()){
        vector <node> tmp;
        for(int i = 0; i < v.size(); i++){
            int a = v[i].a, b = v[i].b, h = v[i].h;
            if(brain[h][a][b] == 0)
                continue;
            brain[h][a][b] = 0;
            cnt++;
            if(a + 1 < m)
                tmp.push_back(node{a + 1, b, h});
            if(a - 1 >= 0)
                tmp.push_back(node{a - 1, b, h});
            if(b + 1 < n)
                tmp.push_back(node{a, b + 1, h});
            if(b - 1 >= 0)
                tmp.push_back(node{a, b - 1, h});
            if(h + 1 < l)
                tmp.push_back(node{a, b, h + 1});
            if(h - 1 >= 0)
                tmp.push_back(node{a, b, h - 1});
        }
        v = tmp;
    }
    return;
}
int main(){
    cin >> m >> n >> l >> t;
    for(int i = 0; i < l; ++i){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                scanf("%d", &brain[i][j][k]);
            }
        }
    }
    for(int h = 0; h < l; h++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(brain[h][i][j] == 0)
                    continue;
                cnt = 0;
                bfs(i, j, h);
                if(cnt >= t)
                    ans += cnt;
            }
        }
    }
    cout << ans << endl;
}
