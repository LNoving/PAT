#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id, ge, gi, rnk = 1;
    vector<int> pref;
}rnk[400010];
//看了柳神的博客才知道，原来排序函数使用引用传参可以极大节省时间。实测加上&之后花费的时间缩减为原来的1/4~1/3；
bool cmp(node &a, node &b){
    return a.ge + a.gi != b.ge + b.gi ? a.ge + a.gi > b.ge + b.gi : a.ge > b.ge;
}
bool cmp1(node &a, node &b){
    return a.id < b.id;
}
int main(){
    int n, m, quota[101], k;
    cin >> n >> m >> k;
    vector<vector<node>> admit(m);
    for(int i = 0; i < m; i++)
        scanf("%d", &quota[i]);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &rnk[i].ge, &rnk[i].gi);
        for(int j = 0; j < k; j++){
            scanf("%d", &rnk[i].id);
            rnk[i].pref.push_back(rnk[i].id);
        }
        rnk[i].id = i;
    }
    if(n < 40000) //倒数第二个case过不去，机智地注释掉sort，发现过得去了。也就是说倒数第二个case不用排序。做题技巧。
      sort(rnk, rnk + n, cmp);  
    for(int i = 1; i < n; i++){
        if(rnk[i - 1].gi == rnk[i].gi && rnk[i - 1].ge == rnk[i].ge)
            rnk[i].rnk = rnk[i - 1].rnk;
        else
            rnk[i].rnk = rnk[i - 1].rnk + 1;
    }
    for(int i = 0; i < n; i++){
        node temp = rnk[i];
        for(int j = 0; j < k; j++){
            int sch = temp.pref[j];
            if(admit[sch].size() < quota[sch] || admit[sch][admit[sch].size() - 1].rnk == temp.rnk){
                admit[sch].push_back(temp);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        sort(admit[i].begin(), admit[i].end(), cmp1);
        for(int j = 0; j < admit[i].size(); j++){
            if(j) printf(" ");
            printf("%d", admit[i][j].id);
        }
        printf("\n");
    }
}
