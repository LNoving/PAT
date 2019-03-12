#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct {
    int val, next;
} lis[100001];
int main(){
    bool exi[10001] = {0};
    vector<int> v, waste;
    int n, root;
    cin >> root >> n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        lis[a].val = b;
        lis[a].next = c;
    }
    int tmp = root;
    while(root != -1){
        if(exi[abs(lis[root].val)] == true){
            waste.push_back(root);
        }
        else{
            v.push_back(root);
        }
        exi[abs(lis[root].val)] = true;
        root = lis[root].next;
    }
    for(int i = 0; i < v.size(); i++){
        if(i == 0){
            printf("%05d %d", v[i], lis[v[i]]);
            continue;
        }
        printf(" %05d\n%05d %d", v[i], v[i], lis[v[i]]);
    }
    if(!v.empty())
        printf(" -1\n");
    for(int i = 0; i < waste.size(); i++){
        if(i == 0){
            printf("%05d %d", waste[i], lis[waste[i]]);
            continue;
        }
        printf(" %05d\n%05d %d", waste[i], waste[i], lis[waste[i]]);
    }
    if(!waste.empty())
        printf(" -1\n");
}
