#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>   //unordered_map can improve the speed exceedingly
using namespace std;
struct sch{
    string name;
    int score, ns;   //sum is recorded by double. however int must used when ordering(the last case);
};
// use two simple maps rather than one struct map to improve the speed
unordered_map<string, int> cnt;
unordered_map<string, double> sum;
vector<sch> ans;
int n;
bool cmp(sch a, sch b){
    if(a.score != b.score)
        return a.score > b.score;
    if(a.ns != b.ns)
        return a.ns < b.ns;
    return a.name < b.name;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        char bat;
        int id, score;
        string name;char ccc;
        scanf("%c%c%d", &ccc, &bat, &id);
        cin >> score >> name;
        for(int j = 0; j < name.length(); j++)
            name[j] = tolower(name[j]);
        double w = 1.0, tmpsum = 0.0;
        if(bat == 'B')tmpsum += score / 1.5;
        else if(bat == 'T')tmpsum += score * 1.5;
        else tmpsum += score * 1.0;
        sum[name] += tmpsum;
        cnt[name]++;
    }
    for(auto it = cnt.begin(); it != cnt.end(); it++){
        ans.push_back(sch{it->first, (int)sum[it->first], cnt[it->first]});
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size();
    int pre = -1, k = 1;
    for(int i = 0; i < ans.size(); i++){
        if(pre == (int)ans[i].score)
            printf("\n%d ", k);
        else{
            k = i + 1;
            printf("\n%d ", k);
            pre = (int)ans[i].score;
        }
        cout << ans[i].name <<" "<< ans[i].score <<" "<< ans[i].ns;
    }
}
