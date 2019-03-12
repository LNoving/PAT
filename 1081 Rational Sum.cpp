#include <iostream>
using namespace std;
long fac(long a, long b){
    a = abs(a);
    if(a < b)
        swap(a, b);
    while(b != 0){
        int temp = a;
        a = max(b, temp % b);
        b = min(b, temp % b);
    }
    return a;
}
int main(){
    long k, a = 0, b = 1, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        long p = 0, a1 = a, b1 = b, a2, b2;
        cin >> s;
        while(s[p] != '/')
            p++;
        a2 = stoi(s.substr(0, p).c_str());
        b2 = stoi(s.substr(p + 1).c_str());
        b = b1 * b2;
        a = a1 * b2 + a2 * b1;
        long factor = fac(a, b);
        a /= factor;
        b /= factor;
    }
    if(a % b == 0)
        cout << a / b;
    else if(a > b)
        printf("%d %d/%d", a / b, abs(a) % b, b);
    else
        printf("%d/%d", a, b);
}
