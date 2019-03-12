/**
 * 随便写完，跑了一下发现只过了第一个case，想想代码应该没什么大的bug，遂考虑在末尾加了一句
 * printf("\n");
 * 果然AC。
 * 大佬的解法里还排序了一下，对比位置有没有发生变化，我暂时没想通为什么要这么做。
 * */
#include <iostream>
using namespace std;
int main(){
    int n, arr[100001], l = -1, r = 999999999, pivot[100001] = {0}, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > l)
            l = arr[i];
        else
            pivot[i] = 1;
    }
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] < r){
            r = arr[i];
            if(pivot[i] == 0)
                cnt++;
        }
        else
            pivot[i] = 1;
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++){
        if(pivot[i] == 1)
            continue;
        if(cnt == -1)
            printf(" ");
        printf("%d", arr[i]);
        cnt = -1;
    }
    printf("\n");
}
