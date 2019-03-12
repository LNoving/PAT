#include <iostream>
#include <vector>
using namespace std;
struct {
    int l = -1, r = -1;
} tree[11];
bool flag = false;
void in(int k){
    if(k == -1)
        return;
    in(tree[k].l);
    if(flag)
        printf(" ");
    flag = true;
    printf("%d", k);

    in(tree[k].r);
}
int main(){
    int n, isroot[11] = {0}, root;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        if(a != "-"){
            tree[i].r = stoi(a.c_str());
            isroot[stoi(a.c_str())] = 1;
        }
        if(b != "-"){
            tree[i].l = stoi(b.c_str());
            isroot[stoi(b.c_str())] = 1;
        }
    }
    for(root = 0; root < n; root++)
        if(isroot[root] == 0)
            break;
    vector<int> v = {root};
    while(!v.empty()){
        vector<int> tmp;
        for(int i = 0; i < v.size(); i++){
            if(v[i] != root)
                printf(" ");
            printf("%d", v[i]);
            if(tree[v[i]].l != -1)
                tmp.push_back(tree[v[i]].l);
            if(tree[v[i]].r != -1)
                tmp.push_back(tree[v[i]].r);
        }
        v = tmp;
    }
    printf("\n");
    in(root);
}
