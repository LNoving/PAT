/**
 * 当年看起来稚嫩的丑丑的代码既简洁又高效，现在还有两周就考试了，妈的用了一大堆stl花了一个半小时
 * 还AC不了，我还考他妈个什么东西。
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct node{
    int id, score;
};
bool cmp(node a, node b){
    return a.score > b.score;
}
int main(){
    int n, q;
    char s[] = "ACME";
    map<int, vector<int>> best;
    vector<node> c, m, e, a;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int id, cc, mm, ee, aa;
        scanf("%d%d%d%d", &id, &cc, &mm, &ee);
        c.push_back(node{id, cc});
        m.push_back(node{id, mm});
        e.push_back(node{id, ee});
        a.push_back(node{id, cc + mm + ee});
        best[id].resize(4);
        fill(best[id].begin(), best[id].end(), 0);
    }
    sort(c.begin(), c.end(), cmp);
    sort(m.begin(), m.end(), cmp);
    sort(e.begin(), e.end(), cmp);
    sort(a.begin(), a.end(), cmp);
    int rnk = 1;
    best[a[0].id][0] = 1;
    for(int i = 1; i < n; i++){
        if(a[i].score != a[i - 1].score)
            rnk = i + 1;
        best[a[i].id][0] = rnk;
    }
    rnk = 1;
    best[c[0].id][1] = 1;
    for(int i = 1; i < n; i++){
        if(c[i].score != c[i - 1].score)
            rnk = i + 1;
        best[c[i].id][1] = rnk;
    }
    rnk = 1;
    best[m[0].id][2] = 1;
    for(int i = 1; i < n; i++){
        if(m[i].score != m[i - 1].score)
            rnk = i + 1;
        best[m[i].id][2] = rnk;
    }
    rnk = 1;
    best[e[0].id][3] = 1;
    for(int i = 1; i < n; i++){
        if(e[i].score != e[i - 1].score)
            rnk = i + 1;
        best[e[i].id][3] = rnk;
    }
    for(int i = 0; i < q; i++){
        int tmp, k = 0;
        cin >> tmp;
        if(best.count(tmp) != 0){
            for(int j = 0; j < 4; j++)
                if(best[tmp][j] < best[tmp][k])
                    k = j;
            printf("%d %c\n", best[tmp][k], s[k]);
        }
        else
            printf("N/A\n");
    }
}

/*
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct Student{
    string id;
    int c;
    int m;
    int e;
    int sum;
};
bool judge(int a, int b);
bool judge(int a, int b){
    return a > b;
}
int main() {
    int n, m;
    Student stu[2000];
    string check[2000];
    int c[2000] = {0};
    int math[2000] = {0};
    int e[2000] = {0};
    int sum[2000] = {0};
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
        stu[i].sum = stu[i].c + stu[i].m + stu[i].e;
        c[i] = stu[i].c;
        math[i] = stu[i].m;
        e[i] = stu[i].e;
        sum[i] = stu[i].sum;
    }

    for(int i = 0; i<m; i++){
        cin >> check[i];
    }

    sort(c, c+n, judge);
    sort(e, e+n, judge);
    sort(math, math+n, judge);
    sort(sum, sum+n, judge);

    for(int i = 0; i<m; i++){
        if(i)
            cout << "\n";
        int j;
        int rk[5];
        for(j = 0; j<n; j++){
            if(stu[j].id == check[i]){
                break;
            }
        }
        if(stu[j].id != check[i]){
            cout << "N/A";
            continue;
        }
        int k;
        for(k = 0; k<n; k++){
            if(stu[j].sum == sum[k])
                break;
        }
        rk[0] = k;
        for(k = 0; k<n; k++){
            if(stu[j].c == c[k])
                break;
        }
        rk[1] = k;
        for(k = 0; k<n; k++){
            if(stu[j].m == math[k])
                break;
        }
        rk[2] = k;
        for(k = 0; k<n; k++){
            if(stu[j].e == e[k])
                break;
        }
        rk[3] = k;
        rk[4] = 2001;
        int mk = 4;
        for(k = 0; k<4; k++){
            if(rk[k] < rk[mk])
                mk = k;
        }
        cout << rk[mk] + 1;
        switch (mk){
            case 0: cout << " A";break;
            case 1: cout << " C";break;
            case 2: cout << " M";break;
            case 3: cout << " E";break;
            default:;
        }
    }
}
*/