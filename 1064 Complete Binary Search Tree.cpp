/**
 * 不会，抄的。
 * */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int in[1001], n, flag = 0, level[1001];
void levelorder(int a, int b, int index){ //index start from 1  left: root * 2 right: root*2 + 1
    if(a > b) return;
    int n = b - a + 1;
    int l = log(b - a + 1) / log(2);
    int leaves = b - a + 1 - (int)(pow(2, l) + 0.1 - 1);
    int root = a + (int)(pow(2, l - 1) - 1) + min((int)(pow(2, l - 1)), leaves);
    level[index] = in[root];
    levelorder(a, root - 1, index * 2);
    levelorder(root + 1, b, index * 2 + 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);
    levelorder(0, n - 1, 1);
    for(int i = 1; i <= n; i++){
        if(i - 1)cout << " ";
        cout << level[i];
    }
}
