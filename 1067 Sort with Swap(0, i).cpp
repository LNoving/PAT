/**
 * ����������ʷ�������±Ƶ�һ��AC���ʹ��еĽⷨ�кܴ����𡣡�����˵ʵ�����о��ҵ�
 * �����ö࣬������ʱһ�� = =���ⷨ����һ�仰����������λ���ϵ�Ԫ�ؾ�ƴ��������
 * ֱ���������λ�ø��е�Ԫ��Ϊֹ���о�����ⷨ����Ҳû��̰�ĵ�˼�롣����
 * */
#include <cstdio>
using namespace std;
int a[100001], n, p = 0, ans = 0;
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);
    while(p < n){
        if(a[0] == 0 && a[p] == p){p++;continue;}
        if(a[0] == 0 && a[p] != p){
            a[0] = a[p];
            a[p] = 0;
            ans++;
        }
        int k = a[0];
        while(a[k] != k){
            int t = a[0];
            a[0] = a[k];
            a[k] = t;
            ans++;
            k = a[0];
        }
    }
    printf("%d", ans);
}