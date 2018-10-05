#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, arr[100001], s1 = 0, s2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for(int i = 0; i < n / 2; i++)
        s1 += arr[i];
    for(int i = n / 2; i < n; i++)
        s2 += arr[i];
    printf("%d %d", n % 2, s2 - s1);
}
