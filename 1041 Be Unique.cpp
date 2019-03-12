#include <iostream>
using namespace std;
int exist[10001], bets[100001], n, ans = -1;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &bets[i]);
        exist[bets[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(exist[bets[i]] == 1){
            ans = bets[i];
            break;
        }
    }
    if(ans == -1)
        printf("None\n");
    else
        printf("%d\n", ans);
}
