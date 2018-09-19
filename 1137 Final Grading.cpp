/**
 * round up to 是向上舍入的意思。
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct node{
    string name;
    int point = -1, mid = -1, fin = -1, gra = -1;
};
int p, mm, n;
map <string, node> m;
vector <node> v;
bool cmp(node a, node b){
    return a.gra != b.gra ? a.gra > b.gra : a.name < b.name;
}
int main(){
    cin >> p >> mm >> n;
    for(int i = 0; i < p; i++){
        string s;
        int a;
        cin >> s >> a;
        m[s].name = s;
        m[s].point = a;
    }
    for(int i = 0; i < mm; i++){
        string s;
        int a;
        cin >> s >> a;
        m[s].name = s;
        m[s].mid = a;
    }
    for(int i = 0; i < n; i++){
        string s;
        int a;
        cin >> s >> a;
        m[s].name = s;
        m[s].fin = a;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second.mid > it->second.fin)
            it->second.gra = (int)(0.6 * it->second.fin + 0.4 * it->second.mid + 0.5);
        else
            it->second.gra = it->second.fin;
        if(it->second.point < 200 || it->second.gra < 60)
            continue;
        v.push_back(it->second);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].name;
        printf(" %d %d %d %d\n", v[i].point, v[i].mid, v[i].fin, v[i].gra);
    }
}
