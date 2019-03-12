#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s1, s2, tmp;
    int exp, i;
    cin >> tmp;
    for(i = 0; tmp[i] != 'E'; i++){
        s1 += tmp[i];
    }
    for(i++; i < tmp.size(); i++){
        s2 += tmp[i];
    }
    exp = stoi(s2.c_str());
    if(s1[0] == '-' && s1[1] != '0')
        cout << s1[0];
    if(exp < 0){
        cout << "0.";
        for(int j = 0; j < -exp - 1; j++)
            cout << "0";
        for(int j = 1; j < s1.size(); j++)
            if(s1[j] != '.')
                cout << s1[j];
    }
    else{
        cout << s1[1];
        for(i = 3; i - 2 <= exp || i < s1.size(); i++){
            if(i - 2 == exp + 1)
                cout << '.';
            if(i < s1.size())
                cout << s1[i];
            else
                cout << '0';
        }
    }
    return 0;
}
