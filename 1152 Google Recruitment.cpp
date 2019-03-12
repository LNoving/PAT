#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool isprime(long long a){
    if(a <= 1)
        return false;
    if(a == 2)
      return true;
    for(long long i = 2; i <= sqrt(a * 1.0) + 0.1; i++){
        if(a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int l, k, flag = 1;
    long long num;
    cin >> l >> k;
    string s;
    cin >> s;
    for(int i = 0; i <= l - k; i++){
        string tmp = s.substr(i, k);
        num = std::stol(tmp);
        if(isprime(num)){
            for(int j = 0; j < k - to_string(num).size(); j++)
                cout << 0;
            cout << num;
            flag = 0;
            break;
        }
    }
    if(flag)
        cout << 404;
    return 0;
}
