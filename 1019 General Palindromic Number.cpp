#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long n, base;
    cin >> n >> base;
    vector<long> ans, tmp;
    if(n == 0)
        ans.push_back(0);
    while(n != 0){
        ans.push_back(n % base);
        n /= base;
    }
    tmp = ans;
    reverse(ans.begin(), ans.end());
    if(tmp == ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i) printf(" ");
        printf("%ld", ans[i]);
    }
}
