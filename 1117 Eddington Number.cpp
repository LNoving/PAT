/**
 * ����Ŀ����������Ϊ��Ŀ����˼Ҫ�������������i������֮�ʹ���i^2������i������
 * ������̰�ģ���������Ƚϸ��ӣ�ֻ���ñ��취����������tail��������һ��case��ʱ��
 * ���ҵ�����ԭ�λ��о��������٣�mdzz
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int a[100010], n;
bool cmp(int aa, int b){
    return aa > b;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    int i = 1;
    while(a[i] > i && i <= n)i++;
    cout << i - 1;
}
