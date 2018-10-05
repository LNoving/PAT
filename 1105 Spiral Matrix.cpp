/**
 * �ʼ�Ѿ���a���ó�10001 * 10001���������ˡ������ܣ�Ȼ�������˸����֣�û�뵽ֱ��AC�ˡ�
 * �����ö��ѣ������case�ڿ� 1 * 9999 ����������������϶�ͨ�����ġ�
 * �����뵽����ΪԪ������Ŀ���䣬������vector����resize�����ԣ������������������񡣲��������ʱ����û�뵽��
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
