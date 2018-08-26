/**
 * ���ּ��⾹Ȼд��һ����Сʱ��AC��̫����̫����
 * case3�϶���1000��������ͨ����¼��ÿ���˶��ǲ��ظ��ġ���������ô֪���� = = �δ����Ǹ��ö���
 * */
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int e[2000][2000], n, k, visit[2000] = {0}, tweight, tgang_w, tgang_name, gangno = 0, member;
vector<string> names, bosses;
map<string, int> gangs;
void dfs(int p,int pre){
    if(visit[p])return;
    visit[p] = gangno;
    int thisweight = 0;
    for(int i = 0; i<names.size(); i++){
        if(e[p][i]!=0){
            if(visit[i] == gangno){
                if(i != pre){
                    thisweight += e[p][i];
                    tweight += e[p][i];
                }
                else
                    thisweight += e[p][i];
                continue;
            }
            tweight += e[p][i];
            thisweight += e[p][i]; ///����Ҫ���ǣ�������˵���weight
            dfs(i, p);
            member++;
        }
    }
    if(thisweight >= tgang_w){
        tgang_name = p;
        tgang_w = thisweight;
    }
}
int main() {
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int a = 0, b = 0;
        string name1, name2;
        cin >> name1 >> name2;
        while(a < names.size() && names[a] != name1) a++;
        if(a == names.size()){
            names.push_back(name1);
        }
        while(b < names.size() && names[b] != name2) b++;
        if(b == names.size()){
            names.push_back(name2);
        }
        int w;
        cin >> w;
        e[a][b] += w;
        e[b][a] = e[a][b];
    }
    int i;
    for(i = 0; i<names.size(); i++){
        tweight = 0;
        tgang_w = 0;
        tgang_name = 0;
        member = 1;
        gangno++;
        dfs(i, i);
        if(tweight > k && member > 2){
            bosses.push_back(names[tgang_name]);
            gangs[names[tgang_name]] = member;
        }
    }
    printf("%d", bosses.size());
    sort(bosses.begin(), bosses.end());
    for(int j = 0; j<bosses.size(); j++){
        printf("\n");
        cout << bosses[j];
        printf(" %d", gangs[bosses[j]]);
    }
}