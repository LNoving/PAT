#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a = (s.size() + 2) / 3, b = s.size() + 2 - 2 * a;
    for(int i = 0; i < a - 1; i++){
        printf("%c", s[i]);
        for(int j = 0; j < b - 2; j++)
            printf(" ");
        printf("%c\n", s[s.size() - 1 - i]);
    }
    for(int i = 0; i < b; i++){
        printf("%c", s[a + i - 1]);
    }
}
