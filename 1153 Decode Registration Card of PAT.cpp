/**不止case2有NA，其他也有。考试的时候跪在这点上面了，本来可以满分的。唉。*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node{
    string name;
    int score;
};
struct node1{
    int site, num;
};
bool cmp1(node &a, node &b){
    return a.score != b.score ? a.score > b.score : a.name < b.name;
}
bool cmp2(node1 &a, node1 &b){
    return a.num != b.num ? a.num > b.num : a.site < b.site;
}
vector<node> la, lb, lt;
int sitetests[1001], sitescore[1001];
unordered_map <int, unordered_map<int, int>> mmp;
int main(){
    string str;
    int score, n, m, type;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str >> score;
        int site = stoi(str.substr(1, 3)), date = stoi(str.substr(4, 6));
        sitetests[site]++;
        sitescore[site] += score;
        mmp[date][site]++;
        switch(str[0]){
            case 'A': la.push_back(node{str, score}); break;
            case 'B': lb.push_back(node{str, score}); break;
            default: lt.push_back(node{str, score});
        }
    }
    sort(la.begin(), la.end(), cmp1);
    sort(lb.begin(), lb.end(), cmp1);
    sort(lt.begin(), lt.end(), cmp1);
    for(int i = 0; i < m; i++){
        cin >> type;
        int flag = 0;
        printf("Case %d: %d ", i + 1, type);
        if(type == 1){
            cin >> str;
            cout << str << endl;
            vector<node> tmp;
            switch(str[0]){
                case 'A': tmp = la; break;
                case 'B': tmp = lb; break;
                case 'T': tmp = lt; break;
            }
            for(int j = 0; j < tmp.size(); j++){
                cout << tmp[j].name << " " << tmp[j].score << endl;
                flag = 1;
            }
        }
        if(type == 2){
            int site;
            cin >> site;
            printf("%d\n", site);
            if(sitetests[site] != 0){
                printf("%d %d\n", sitetests[site], sitescore[site]);
                flag = 1;
            }
        }
        if(type == 3){
            int date;
            cin >> date;
            printf("%06d\n", date);
            vector<node1> tmp;
            for(auto it = mmp[date].begin(); it != mmp[date].end(); it++){
                tmp.push_back(node1{it->first, it->second});
            }
            sort(tmp.begin(), tmp.end(), cmp2);
            for(int j = 0; j < tmp.size(); j++){
                printf("%d %d\n", tmp[j].site, tmp[j].num);
                flag = 1;
            }
        }
        if(!flag)
            printf("NA\n");
    }
}
