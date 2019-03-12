/**
 *     ����⻹�Ǻ��д����Եġ�
 *     �����Ƕ��˵��Ĵ������ڲ�ͬ�˵���ˮ����˳�����һ��
 * ����Ҫ���������ô��ÿ���˵��˵���������ź������ʼ��ֱ����map��ÿ���˵�
 * ��ˮ����һ�������򣬺���������ʵû�б�Ҫ��ֱ�Ӱ���������ͺ��ˣ�������Ŀ��
 * ���Ҫ��
 *     ����ǰ�ʱ���ź���֮�������Է��������ļ�¼����֮ǰ���ð����ߣ���¼һ����
 * Ѱ����һ���ķ����������߳��Ҹ��ӡ���ʵ���������ֱ�Ӽ���i�͵�i+1�������Ͼ�
 * i+=2�������Ͼ�i++�Ϳ����ˡ������Լ������⻹�ǲ������������ģ����Ӧ�ö�����
 * */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int flag, month, dd, hh, mm;
};
int price[24], day = 0, hour[24];
int totalminutes(node a){
    return (a.dd - 1)*24*60 + a.hh*60 + a.mm;
}
double calc(node a){
    return (day * (a.dd - 1) + hour[a.hh] + price[a.hh] * a.mm) / 100.0;
}
bool cmp(node a, node b){
    return a.name != b.name ? a.name < b.name : totalminutes(a) < totalminutes(b);
}
int main(){
    int n;
    for(int i = 0; i < 24; i++){
        if(i) hour[i] = hour[i - 1] + price[i - 1]*60;
        cin >> price[i];
        day += price[i]*60;
    }
    cin >> n;
    vector<node> v;
    for(int i = 0; i < n; i++){
        string s;
        node tmp = *new node();
        cin >> tmp.name;
        scanf("%d:%d:%d:%d", &tmp.month, &tmp.dd, &tmp.hh, &tmp.mm);
        cin >> s;
        tmp.flag = s == "on-line" ? 0 : 1;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    map<string, vector<node>> m;
    int i = 0;
    while(i + 1 < n){
        if(v[i].name == v[i+1].name && v[i].flag == 0 && v[i+1].flag == 1){
            m[v[i].name].push_back(v[i]);
            m[v[i].name].push_back(v[i + 1]);
            i += 2;
        }
        else
            i++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        vector<node> tmp = it->second;
        double cost = 0.0;
        for(int i = 0; i < tmp.size(); i += 2){
            if(i == 0){
                cout << tmp[i].name;
                printf(" %02d\n", tmp[i].month);
            }
            double tcost = calc(tmp[i + 1]) - calc(tmp[i]);
            cost += tcost;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                       tmp[i].dd, tmp[i].hh, tmp[i].mm, tmp[i+1].dd, tmp[i+1].hh, tmp[i+1].mm,
                       totalminutes(tmp[i+1]) - totalminutes(tmp[i]), tcost);
        }
        printf("Total amount: $%.2f\n", cost);
    }
}
