/**
 * 最开始把矩阵a设置成10001 * 10001，结果溢出了。很难受，然后随便改了个数字，没想到直接AC了。
 * 运气好而已，如果有case在卡 1 * 9999 的情况，那这个代码肯定通不过的。
 * 后来想到，因为元素总数目不变，所以用vector可以resize的特性，就能轻松完成这个任务。不过做题的时候还是没想到。
 * */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int total, a[110][110], arr[10010], m, n;
    fill(a[0], a[0] + 110 * 110, 0);
    cin >> total;
    for(int i = 0; i < total; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + total, cmp);
    for(int tm = total; tm >= sqrt(total); tm--){
        int tn = total / tm;
        if(tm * tn == total){
            m = tm;
            n = tn;
        }
    }
    int i = 0, j = 0, dir = 0, k = 0;
    while(i >= 0 && j >= 0 && i < m && j < n && a[i][j] == 0){
        a[i][j] = arr[k++];
        int ii = i, jj = j;
        switch(dir % 4){
        case 0:
            jj++;break;
        case 1:
            ii++;break;
        case 2:
            jj--;break;
        case 3:
            ii--;break;
        }
        if(ii < 0 || jj < 0 || ii >= m || jj >= n || a[ii][jj] != 0)
            dir++;
        switch(dir % 4){
        case 0:
            j++;break;
        case 1:
            i++;break;
        case 2:
            j--;break;
        case 3:
            i--;break;
        }
    }
    for(i = 0; i < m; i++){
        printf("%d", a[i][0]);
        for(int j = 1; j < n; j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }
}
