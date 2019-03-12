#include<iostream>
using namespace std;
int main(){
    int n, price, exist[1001] = {0}, a = 1001, temp;
    scanf("%d%d", &n, &price);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        if(price >= temp && exist[price - temp] > 0)
            a = min(min(temp, price - temp), a);
        exist[temp]++;
    }
    if(a == 1001)
        printf("No Solution\n");
    else
        printf("%d %d\n", a, price - a);
}
/***
 * ˵��hash����ʵ�ܼ򵥣����ǻ��˸��洢�ķ�ʽ��������hash��bucket��������
 * ����ʱ�临�ӶȻ��Ǻ���Ҫ�ġ�һ��Ҫ�����˼�롣
 */
/*
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
const int value = 1009;
int coins[value] = {0};
int main(){
    int k, a = value, b = value;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        scanf("%d", &k);
        coins[k]++;
        if(k < m && coins[m-k] && a > min(k, m-k)){
            if(k != m - k || (k == m - k && coins[m - k] >= 2)){
                a = min(k, m-k);
                b = m - a;
            }
        }
    }
    if(a == value){
        printf("No Solution");
    }else{
        printf("%d %d", a, b);
    }
}
*/