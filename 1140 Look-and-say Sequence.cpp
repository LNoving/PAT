#include <iostream>
#include <cstring>
using namespace std;
int n, d;
int main(){
    cin >> d >> n;
    string tmp, s = to_string(d);
    for(int i = 1; i < n; i++){
        int sum = 1;
        char c = s[0];
        tmp = "";
        for(int j = 1; j < s.length(); j++){
            if(s[j] != c){
                tmp += c + to_string(sum);
                c = s[j];
                sum = 1;
            }
            else
                sum++;
        }
        tmp += c + to_string(sum);
        s = tmp;
    }
    cout << s;
}
