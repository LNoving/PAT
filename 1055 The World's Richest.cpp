#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
    char name[10];
    int age, worth;
}arr[100005];
bool cmp(node &a, node &b){
    if(a.worth != b.worth)
        return a.worth > b.worth;
    return a.age != b.age ? a.age < b.age : strcmp(a.name, b.name) < 0;
}
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n; i++){
        scanf("%s%d%d", arr[i].name, &arr[i].age, &arr[i].worth);  // 288ms 102ms 看来时间难搞的题最好用scanf
        //cin >> arr[i].name >> arr[i].age >> arr[i].worth;  // 397ms 210ms
    }
    sort(arr, arr + n, cmp);
    vector<node> ans;
    int cnt = 1;
    ans.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(arr[i - 1].age != arr[i].age)
            cnt = 0;
        if(++cnt <= 100)
            ans.push_back(arr[i]);
    }
    for(int i = 0; i < k; i++){
        int a, b, cnt;
        scanf("%d%d%d", &cnt, &a, &b);
        vector<node> temp;
        for(int j = 0; j < ans.size(); j++){
          if(ans[j].age >= a && ans[j].age <= b)
                temp.push_back(ans[j]);
          if(temp.size() == cnt) break;
        }
        printf("Case #%d:\n", i + 1);
        for(int j = 0; j < temp.size(); j++)
            printf("%s %d %d\n", temp[j].name, temp[j].age, temp[j].worth);
        if(temp.size() == 0)
            printf("None\n");
    }
}
