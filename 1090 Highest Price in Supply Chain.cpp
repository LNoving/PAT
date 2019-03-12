/**
 * r和p的存储要用double类型。用float会有3个大case过不去。pow返回的好像还是float，
 * 有点迷，不知道为什么出错。
 * */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int n, root, ans = 0, depth = 0, num = 0;
vector<int> chain[100001];
double p, r;
void dfs(int k){
    depth++;
    if(depth == ans)
        num++;
    if(depth > ans){
        ans = depth;
        num = 1;
    }
    for(int i = 0; i < chain[k].size(); i++)
        dfs(chain[k][i]);
    depth--;
}
int main(){
    cin >> n >> p >> r;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp == -1){
            root = i;
            continue;
        }
        chain[tmp].push_back(i);
    }
    dfs(root);
    printf("%.2f %d", p * pow(1 + r/100, ans - 1), num);
}
