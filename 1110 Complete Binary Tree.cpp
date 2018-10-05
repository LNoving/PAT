#include <iostream>
#include <vector>
using namespace std;
struct {
    int l, r, isroot = 1;
} bst[21];
int main(){
    int n, root, cnt = 1, last, ended = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s != "-"){
            bst[i].l = stoi(s.c_str());
            bst[bst[i].l].isroot = 0;
        }
        else
            bst[i].l = -1;
        cin >> s;
        if(s != "-"){
            bst[i].r = stoi(s.c_str());
            bst[bst[i].r].isroot = 0;
        }
        else
            bst[i].r = -1;
    }
    for(int i = 0; i < n; i++)
        if(bst[i].isroot == 1)
            root = i;
    vector<int> lev;
    lev.push_back(root);
    last = root;
    while(!lev.empty()){
        vector<int> tmp;
        for(int i = 0; i < lev.size(); i++){
            if(bst[lev[i]].l != -1){
                tmp.push_back(bst[lev[i]].l);
                cnt++;
            }
            else{
                ended = 1;
                break;
            }
            if(bst[lev[i]].r != -1){
                tmp.push_back(bst[lev[i]].r);
                cnt++;
            }
            else{
                ended = 1;
                break;
            }
        }
        if(!tmp.empty())
            last = tmp[tmp.size() - 1];
        if(ended)
            break;
        lev = tmp;
    }
    if(cnt == n)
        printf("YES %d", last);
    else
        printf("NO %d", root);
}
