#include <iostream>
using namespace std;
int main(){
    int arr[10008], n, ans = -1, left = 0, temp = 0, a, b;
    cin >> n;
    a = 0, b = n - 1;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        temp += arr[i];
        if(temp < 0){
            left = i + 1;
            temp = 0;
        }
        else if(temp > ans){
            ans = temp;
            a = left, b = i;
        }
    }
    printf("%d %d %d", ans < 0 ? 0 : ans, arr[a], arr[b]);
}
