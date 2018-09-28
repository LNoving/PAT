#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, cnt[50010] = {0}, exist[50010] = {0};
vector<int> rec;
bool cmp(int a, int b){
    return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int tmp, last = rec.size() == 0 ? 0 : rec[rec.size() - 1];
        cin >> tmp;
        if(i != 0){
            printf("%d:", tmp);
            for(int j = 0; j < rec.size(); j++)
                printf(" %d", rec[j]);
            printf("\n");
        }
        cnt[tmp]++;
        if(exist[tmp] != 1){
            if(rec.size() < k){
                rec.push_back(tmp);
                exist[tmp] = 1;
            }
            else
                if(cnt[tmp] > cnt[last] || (cnt[tmp] == cnt[last] && tmp < last)){
                    exist[rec[rec.size() - 1]] = 0;
                    rec.pop_back();
                    rec.push_back(tmp);
                    exist[tmp] = 1;
                }
        }
        sort(rec.begin(), rec.end(), cmp);
    }
}
