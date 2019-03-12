#include <iostream>
using namespace std;
int main(){
    int n;
    string arr1[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string arr2[13] = { "","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int ans = 0;
        if(s[0] >= '0' && s[0] <= '9'){
            int a = stoi(s.c_str());
            if(a >= 13){
                cout << arr2[a / 13];
                if(a % 13)
                    cout << " " << arr1[a % 13];
            }
            else
                cout << arr1[a];
        }
        else{
            if(s == "tret")
                cout << "0";
            else{
                if(s.length() <= 4){
                    for(int j = 1; j < 13; j++){
                        if(arr2[j] == s)
                            ans = j * 13;
                    }
                    for(int j = 0; j < 13; j++){
                        if(arr1[j] == s)
                            ans = j;
                    }
                    cout << ans;
                }
                else{
                    string s1 = s.substr(0, 3), s2 = s.substr(4);
                    for(int j = 1; j < 13; j++){
                        if(arr2[j] == s1){
                            ans += j;
                            break;
                        }
                    }
                    ans *= 13;
                    for(int j = 0; j < 13; j++){
                        if(arr1[j] == s2){
                            ans += j;
                            break;
                        }
                    }
                    cout << ans;
                }
            }
        }
        printf("\n");
    }
}
