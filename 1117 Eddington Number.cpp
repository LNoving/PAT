/**
 * 对题目理解错误。我以为题目的意思要是求出满足连续i个数字之和大于i^2的最大的i，于是
 * 考虑用贪心，发现问题比较复杂，只好用笨办法来遍历更新tail，还导致一个case超时，
 * 亏我当年马原课还研究过爱丁顿，mdzz
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int a[100010], n;
bool cmp(int aa, int b){
    return aa > b;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    int i = 1;
    while(a[i] > i && i <= n)i++;
    cout << i - 1;
}
