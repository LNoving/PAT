/***
 * ˵��hash����ʵ�ܼ򵥣����ǻ��˸��洢�ķ�ʽ��������hash��bucket��������
 * ����ʱ�临�ӶȻ��Ǻ���Ҫ�ġ�һ��Ҫ�����˼�롣
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
const int value = 1009;
int coins[value] = {0};
int main(){
    int k;
    int a = value, b = value;
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
