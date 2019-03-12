#include <iostream>
using namespace std;
int main(){
    float arr[3][3], total;
    int ans[3];
    for(int i = 0; i < 3; i++){
        int mx = 0;
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
            if(arr[i][j] > arr[i][mx])
                mx = j;
        }
        ans[i] = mx;
    }
    total = (arr[0][ans[0]] * arr[1][ans[1]] * arr[2][ans[2]] * 0.65 - 1.0) * 2.0;
    char c[3] = {'W', 'T', 'L'};
    printf("%c %c %c %.2f", c[ans[0]], c[ans[1]], c[ans[2]], total);
}
