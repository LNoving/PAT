#include <iostream>
#include <cctype>
using namespace std;
int main(){
    int day = 0, flag = 0, hour, minute;
    char s[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(flag == 0 && a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G')
            day = a[i] - 'A' + flag++;
        else if(flag == 1 && a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))){
            if(isdigit(a[i]))
                hour = a[i] - '0';
            else
                hour = a[i] - 'A' + 10;
            break;
        }
    }
    for(int i = 0; i < min(c.size(), d.size()); i++){
        if(c[i] == d[i] && isalpha(c[i])){
            minute = i;
            break;
        }
    }
    printf("%s %02d:%02d", s[day], hour, minute);
}
