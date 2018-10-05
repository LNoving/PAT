#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, cnt = 0;
    float sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s, ss;
        cin >> s;
        int flag = 0, havedot = 0, dec = 0, j;
        float val;
        for(j = 0; j < s.length(); j++){
            if(j == 0 && s[0] == '-')
                continue;
            if(!(s[j] == '.' || (s[j] >= '0' && s[j] <= '9'))){
                break;
            }
            if(s[j] == '.'){
                if(havedot == 1)
                    break;
                havedot = 1;
                continue;
            }
            if(havedot == 1){
                dec++;
                if(dec >= 3)
                    break;
            }
        }
        if(j != s.length())
            flag = 1;
        if(flag == 0)
            val = stof(s.c_str());
        if(flag == 1 || !(val >= -1000 && val <= 1000)){
            printf("ERROR: %s is not a legal number\n", s.c_str());
            continue;
        }
        sum += val;
        cnt++;
    }
    if(cnt == 0){
        printf("The average of 0 numbers is Undefined");
    }
    else if(cnt == 1){
        printf("The average of 1 number is %.2f", sum);
    }
    else{
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    }
}
