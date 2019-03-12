#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[62], cnt;
vector<int> ans;
int in(int k){
    int tmp = k;
    if(arr[++k] != -1){
        k = in(k);
        if(arr[k] != -1)
            k = in(k);
        else
            k++;
    }
    else{
        if(arr[++k] != -1)
            k = in(k);
        else
            k++;
    }
    ans.push_back(arr[tmp]);
    return k;
}
int main(){
    fill(arr, arr + 62, -1);
    cin >> n;
    for(int i = 0; cnt < n; i++){
        string s;
        cin >> s;
        if(s == "Push"){
            cin >> arr[i];
        }
        else
            cnt++;
    }
    in(0);
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    printf("\n");
}
