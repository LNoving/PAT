/**
 * ���д�꣬����һ�·���ֻ���˵�һ��case���������Ӧ��ûʲô���bug���쿼����ĩβ����һ��
 * printf("\n");
 * ��ȻAC��
 * ���еĽⷨ�ﻹ������һ�£��Ա�λ����û�з����仯������ʱû��ͨΪʲôҪ��ô����
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
