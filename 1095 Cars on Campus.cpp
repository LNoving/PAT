//写代码50min，有一个bug改了半个多小时。其实理一理思路很简单。最傻逼的地方在于忘记了格式，找了好久才发现。
//后天第二次考pat，但愿好运！
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct node{
    string plate;
    int time, status; // 1 is in, 0 is out
};
bool cmp(node a, node b){
    return a.time < b.time;
}
int main(){
    int n, q, cnt = 0, MAX = 24 * 3600 + 1;
    cin >> n >> q;
    vector<node> arr;
    for(int i = 0; i < n; i++){
        string plate, status;
        int h, m, s, flag;
        cin >> plate;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> status;
        flag = status == "in" ? 1 : 0;
        arr.push_back(node{plate, h * 3600 + m * 60 + s, flag});
    }
    sort(arr.begin(), arr.end(), cmp);
    map<string, int> last;
    map<string, int> parktime;
    for(int i = 0; i < arr.size(); i++){
        node cur = arr[i];
        int thelast = last.count(cur.plate) == 0 ? -1 : last[cur.plate];
        last[cur.plate] = i;
        if(cur.status == 1)
            continue;
        if(thelast == -1 || arr[thelast].status != 1){
            arr[i].status = -1;
            continue;
        }
        parktime[cur.plate] += cur.time - arr[thelast].time;
        arr[thelast].status = 2;  // the in record is valid
    }
    int start = 0;
    vector<int> ans(MAX);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].status == 1 || arr[i].status == -1)
            continue;
        fill(ans.begin() + start, ans.begin() + arr[i].time, cnt);
        if(arr[i].status == 0)
            cnt--;
        else if(arr[i].status == 2)
            cnt++;
        start = arr[i].time;
    }
    fill(ans.begin() + start, ans.begin() + MAX, cnt);
    for(int i = 0; i < q; i++){
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        printf("%d\n", ans[h * 3600 + m * 60 + s]);
    }
    vector<string> result;
    for(auto it = parktime.begin(); it != parktime.end(); it++){
        if(result.empty() || it->second > parktime[result[0]]){
            result.clear();
            result.push_back(it->first);
        }
        else if(it->second == parktime[result[0]])
            result.push_back(it->first);
    }
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    int time = parktime[result[0]];
    printf("%02d:%02d:%02d\n", time / 3600, (time % 3600) / 60, time % 60);
    return 0;
}
