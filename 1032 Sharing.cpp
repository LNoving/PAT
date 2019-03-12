#include <iostream>
using namespace std;
struct {
    int p, next, flag = 0;
} arr[100001];
int main(){
    int s1, s2, n, ans = -1;
    cin >> s1 >> s2 >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        char c;
        cin >> tmp;
        cin >> c >> arr[tmp].next;
    }
    while(s1 != -1){
        arr[s1].flag = 1;
        s1 = arr[s1].next;
    }
    while(s2 != -1 && ans == -1){
        if(arr[s2].flag == 1)
            ans = s2;
        s2 = arr[s2].next;
    }
    if(ans == -1)
        cout << ans;
    else
        printf("%05d", ans);
}
