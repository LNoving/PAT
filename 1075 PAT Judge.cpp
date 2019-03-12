#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id, score = 0, scores[7] = {-1, -1, -1, -1, -1, -1, -1}, perfects = 0 ,show = 0;
};
bool cmp(node &a, node &b){
    if(a.score != b.score)
        return a.score > b.score;
    return a.perfects != b.perfects ? a.perfects > b.perfects : a.id < b.id;
}
int main(){
    int n, k, m, scores[7];
    cin >> n >> k >> m;
    for(int i = 1; i <= k; i++)
        cin >> scores[i];
    vector<node> arr(n + 1);
    for(int i = 0; i < m; i++){
        int id, no, score;
        cin >> id >> no >> score;
        arr[id].scores[no] = max(arr[id].scores[no], max(score, 0));
    }
    for(int i = 1; i <= n; i++){
        arr[i].id = i;
        for(int j = 1; j <= k; j++){
            if(arr[i].scores[j] != -1){
                arr[i].score += arr[i].scores[j];
                arr[i].show = 1;
            }
            if(arr[i].scores[j] == scores[j])
                arr[i].perfects++;
        }
    }
    sort(arr.begin() + 1, arr.end(), cmp);
    for(int i = 1, r = 1; i <= n; i++){
        if(i > 1 && arr[i].score != arr[i - 1].score)
            r = i;
        if(arr[i].show == 0) break;
        printf("%d %05d %d", r, arr[i].id, arr[i].score);
        for(int j = 1; j <= k; j++){
            if(arr[i].scores[j] == -1)
                printf(" -");
            else
                printf(" %d", arr[i].scores[j]);
        }
        printf("\n");
    }
}
