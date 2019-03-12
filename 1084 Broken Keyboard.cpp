#include <iostream>
using namespace std;
int main(){
    int broken[260] = {0};
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    while(i < a.size()){
        a[i] = tolower(a[i]);
        if(j < b.size())
            b[j] = tolower(b[j]);
        if(j >= b.size() || a[i] != b[j]){
            if(broken[a[i]] != 1){
                if(a[i] >= 'a' && a[i] <= 'z')
                    printf("%c", a[i] + 'A' - 'a');
                else
                    printf("%c", a[i]);
            }
            broken[a[i]] = 1;
        }
        else
            j++;
        i++;
    }
}
