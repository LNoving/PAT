/**
 * find_father()函数里面没有写return。debug了好久好久。我以为是遍历set的效率问题，
 * 于是把之前用到的所有set都改了，然而还是不行。费尽周折终于定位到了find_father()函数，
 * 一看傻眼了。唉。
 * 改进的空间：改一下union函数的合并方法，让id小的永远成为父亲，那么后面就可以不比较
 * 节点的大小。
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct {
    int exist = 0, fa, father, mother, k, child[6], estate, area;
} all[10001];
typedef struct{
    int id = 10001, estate = 0, area = 0, cnt = 0;
} node;
node ans[10001];
int find_father(int k){
    int a = k;
    while(all[a].fa != a){
        a = all[a].fa;
    }
    while(k != a){
        int tmp = all[k].fa;
        all[k].fa = a;
        k = tmp;
    }
    return a;
}
void uni(int a, int b){
    int fa = find_father(a), fb = find_father(b);
    if(fa != fb){ // add the asset of a to b;
        all[fb].fa = fa;
    }
}
bool cmp(node a, node b){
    float aa = (float)a.area / (float)a.cnt, ab = (float)b.area / (float) b.cnt;
    return aa != ab ? aa > ab : a.id < b.id;
}
int main(){
    int n, root[10001], root_num = 0;
    vector<int> people;
    vector<node> answer;
    cin >> n;
    for(int i = 0; i < 10001; i++)
        all[i].fa = i;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        people.push_back(k);
        all[k].exist = 1;
        cin >> all[k].father >> all[k].mother >> all[k].k;
        if(all[k].father != -1){
            all[all[k].father].exist = 1;
            uni(k, all[k].father);
        }
        if(all[k].mother != -1){
            all[all[k].mother].exist = 1;
            uni(k, all[k].mother);
        }
        for(int j = 0; j < all[k].k; j++){
            cin >> all[k].child[j];
            all[all[k].child[j]].exist = 1;
            uni(k, all[k].child[j]);
        }
        cin >> all[k].estate >> all[k].area;
    }
    for(int i = 0; i < 10001; i++){
        if(all[i].exist != 1)continue;
        int fat = find_father(i), j;
        ans[fat].estate += all[i].estate;
        ans[fat].area += all[i].area;
        ans[fat].cnt++;
        if(ans[fat].id > i)ans[fat].id = i;
        for(j = 0; j < root_num; j++)
            if(root[j] == fat)break;
        if(j == root_num){
            root[j] = fat;
            root_num++;
        }
    }
    for(int i = 0; i < root_num; i++)
        answer.push_back(ans[root[i]]);
    sort(answer.begin(), answer.end(), cmp);
    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++)
        printf("%04d %d %.3f %.3f\n", answer[i].id, answer[i].cnt,
               (float)answer[i].estate / (float)answer[i].cnt, (float)answer[i].area / (float)answer[i].cnt);
}
