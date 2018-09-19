/**
 * 54min，还是百度了才会做的。
 * 不会，根本不知道什么是个Quadratic probing. wiki上看了一下还是不太清楚，看了一眼
 * 别人的代码才知道(p + j * j)% msize这个东西。妈的考试要是考到这种东西我又得凉了。
 * */
#include <iostream>
#include <cmath>
using namespace std;
int m, n, msize, hm[20000] = {-1}, cnt = 0; /// 注意这里赋值={-1}是无效的，只有第一个值是-1而已。
bool isprime(int k){
    for(int i = 2; i <= sqrt(k); i++)
        if(k % i == 0)return false;
    return true;
}
int main() {
    cin >> msize >> n >> m;
    while(!isprime(msize))msize++;
    fill(hm, hm + 20000, -1);
    for(int i = 0; i < n; i++){
        int a, p, j = 0;
        cin >> a;
        p = a % msize;
        while(hm[(p + j * j)% msize] != -1 && j < msize){
            j++;
        }
        if(hm[(p + j * j)% msize] == -1)
            hm[(p + j * j)% msize] = a;
        else
            cout << a << " cannot be inserted." << endl;
    }
    for(int i = 0; i < m; i++){
        int a, p, j = 0;
        cin >> a;
        p = a % msize;
        while(hm[(p + j * j)% msize] != a && j < msize && hm[(p + j * j)% msize] != -1)
            j++;
        cnt += j + 1;
    }
    printf("%.1f", (float)cnt / (float)m);
}
