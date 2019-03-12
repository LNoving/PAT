#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int k){
    if(k < 2)
        return false;
    for(int i = 2; i <= sqrt(k); i++){
        if(k % i == 0)
            return false;
    }
    return true;
}
int main(){
    int m, n, arr[12000];
    cin >> m >> n;
    while(!isprime(m))
        m++;
    fill(arr, arr + m, -1);
    for(int i = 0; i < n; i++){
        int pos, k = 1, temp;
        scanf("%d", &temp);
        pos = temp = temp % m;
        while(arr[pos] != -1){
            pos = (temp + k * k) % m;
            if(k++ > n)
                break;
        }
        if(i) printf(" ");
        if(arr[pos] == -1){
            printf("%d", pos);
            arr[pos] = pos;
        }
        else
            printf("-");
    }
}
