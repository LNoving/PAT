#include <iostream>
#include <cmath>
using namespace std;
int n, a[10001][2], t;
bool isprime(int k){
    if(k < 2)return false;
    if(k == 2)return true;
    for(int i = 2; i <= pow(k, 0.5); i++)
        if(k % i == 0)return false;
    return true;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &t);
        a[t][0] = i;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        if(!a[t][0] > 0)
            printf("%04d: Are you kidding?\n", t);
        else if(a[t][1] == 1)
            printf("%04d: Checked\n", t);
        else if(a[t][0] == 1)
            printf("%04d: Mystery Award\n", t);
        else if(isprime(a[t][0]))
            printf("%04d: Minion\n", t);
        else
            printf("%04d: Chocolate\n", t);
        a[t][1] = 1;
    }
}
