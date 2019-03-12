#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int diff;
    cin >> diff;
    if(diff%10 == diff/10%10 && diff%10 == diff/100%10 && diff%10 == diff/1000){
        printf("%04d - %04d = 0000\n", diff, diff);
        return 0;
    }
    while(1){
        int arr[4], a = diff, b = 0, tmp;
        for(int i = 0; i < 4; i++){
            arr[i] = a % 10;
            a /= 10;
        }
        sort(arr, arr + 4);
        for(int i = 3; i >= 0; i--){
            a *= 10;
            a += arr[i];
        }
        tmp = a;
        for(int i = 0; i < 4; i++){
            b *= 10;
            b += tmp % 10;
            tmp /= 10;
        }
        diff = a - b;
        printf("%04d - %04d = %04d\n", a, b, diff);
        if(diff == 6174)
            break;
    }
}
