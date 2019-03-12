/**
 * �и��ܹؼ��ĵ���Ŀû����ȷ˵����ֻ�Ǻ����޵İ�ʾ��
 * On the other hand, if when it is the turn of a VIP pair, yet no VIP table is
 * available, they can be assigned as any ordinary players.
 * ���������λ��vip������ʱ���ڿյ�vip������ŷ���С��
 * ��vip��ѡ�����vip�������������С�Ŀ�������Ŀ�и���û�����������
 * ����ͨ��ģ�����������������Ŀ�Ѷȵ�������ĺܶ��ġ�
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int arrive = 0, playtime = 0, vip = 0, serve = 0;
};
bool cmp(node a, node b){
    return a.arrive < b.arrive;
}
int main(){
    vector<node> waits, vips, ans;
    int n, cur = 8 * 60 * 60, kw = 0, kv = 0, m, k, inf = 24 * 3600 * 9999;
    node tables[101];
    cin >> n;
    for(int i = 0; i < n; i++){
        int h, mm, s, time, v;
        node tmp = *new node();
        scanf("%d:%d:%d %d %d", &h, &mm, &s, &time, &v);
        tmp.arrive = h * 60 * 60 + mm * 60 + s;
        tmp.vip = v;
        tmp.playtime = time <= 120 ? time * 60 : 7200;
        if(v)
            vips.push_back(tmp);
        else
            waits.push_back(tmp);
    }
    cin >> k >> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        tables[tmp - 1].vip = 1;
    }
    for(int i = 0; i < k; i++)
        tables[i].playtime = 0;
    sort(vips.begin(), vips.end(), cmp);
    sort(waits.begin(), waits.end(), cmp);
    while(kv < vips.size() || kw < waits.size()){
        int pass = inf, kk = 0, firstvip = -1;
        for(int i = 0; i < k; i++){
            if(tables[i].playtime < pass)
                pass = tables[i].playtime;
        }
        int tmp = min(kw < waits.size() ? waits[kw].arrive : inf, kv < vips.size() ? vips[kv].arrive : inf);
        if(cur + pass < tmp)
            pass = tmp - cur;
        cur += pass;
        if(cur >= 21 * 3600) break;
        for(int i = 0; i < k; i++){
            tables[i].playtime = max(0, tables[i].playtime - pass);
            if(tables[i].playtime < tables[kk].playtime)
                kk = i;
            if(firstvip == -1 && tables[i].playtime == 0 && tables[i].vip)
                firstvip = i;
        }
        if(tables[kk].vip && kv < vips.size() && vips[kv].arrive <= cur){ //first table is vips and there is a vip in queue
            vips[kv].serve = cur;
            tables[kk].playtime = vips[kv].playtime;
            tables[kk].serve++;
            ans.push_back(vips[kv++]);
        }
        else if(kv < vips.size() && vips[kv].arrive <= cur && (kw >= waits.size() || waits[kw].arrive >= vips[kv].arrive)){
            if(firstvip != -1){
                // first is vip, and there is a vip table which is not the first;
                vips[kv].serve = cur;
                tables[firstvip].playtime = vips[kv].playtime;
                tables[firstvip].serve++;
                ans.push_back(vips[kv++]);
            }
            else{ // vip serve
                vips[kv].serve = cur;
                tables[kk].playtime = vips[kv].playtime;
                tables[kk].serve++;
                ans.push_back(vips[kv++]);
            }
        }
        else{
            waits[kw].serve = cur;
            tables[kk].playtime = waits[kw].playtime;
            tables[kk].serve++;
            ans.push_back(waits[kw++]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", ans[i].arrive/3600, ans[i].arrive%3600/60, ans[i].arrive%60
            ,ans[i].serve/3600, ans[i].serve%3600/60, ans[i].serve%60, (ans[i].serve - ans[i].arrive + 30)/60);
    }
    cout << tables[0].serve;
    for(int i = 1; i < k; i++)
        cout << " " << tables[i].serve;
}
