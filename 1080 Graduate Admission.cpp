#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id, ge, gi, rnk = 1;
    vector<int> pref;
}rnk[400010];
//��������Ĳ��Ͳ�֪����ԭ��������ʹ�����ô��ο��Լ����ʡʱ�䡣ʵ�����&֮�󻨷ѵ�ʱ������Ϊԭ����1/4~1/3��
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
    if(n < 40000) //�����ڶ���case����ȥ�����ǵ�ע�͵�sort�����ֹ���ȥ�ˡ�Ҳ����˵�����ڶ���case�����������⼼�ɡ�
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
