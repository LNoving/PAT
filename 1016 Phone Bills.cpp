/**
 *     这道题还是很有代表性的。
 *     首先是对账单的处理，由于不同人的流水打乱顺序混在一起，
 * 所以要先想清楚怎么把每个人的账单整理出来排好序。我最开始是直接用map把每个人的
 * 流水整理到一起再排序，后来想想其实没有必要，直接按名字排序就好了，符合题目的
 * 输出要求。
 *     其次是按时间排好序之后，如何配对符合条件的记录。我之前是用挨个走，记录一个，
 * 寻找下一个的方法，代码冗长且复杂。其实对于这道题直接检测第i和第i+1个，符合就
 * i+=2，不符合就i++就可以了。看来自己想问题还是不够清楚。这种模拟题应该多练。
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
