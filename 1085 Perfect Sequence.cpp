/**
 * ���״̬��Ĳ���ӱ���ס�˸о����о�����Ϊ�������û�к�С�������
 * */
#include <iostream>
#include <algorithm>
using namespace std;
long int n, p, arr[100010];
int dich(long int k, int a, int b){
    int i = (a + b)/2;
    while(a != b){
        if(arr[i] <= k && arr[i + 1] > k)return i;
        if(arr[i] < k)
            a = i + 1;
        else if (arr[i] > k)
            b = i;
        else
            a = i;
        i = (a + b) / 2;
    }
    return a;
}
int main(){
    cin >> n >> p;
    long int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dich(arr[i] * p, i, n - 1) - i + 1> ans)
            ans = dich(arr[i] * p, i, n - 1) - i + 1;
        if(i + ans > n)break;
    }
    cout << ans;
}
