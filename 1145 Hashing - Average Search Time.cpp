/**
 * 54min�����ǰٶ��˲Ż����ġ�
 * ���ᣬ������֪��ʲô�Ǹ�Quadratic probing. wiki�Ͽ���һ�»��ǲ�̫���������һ��
 * ���˵Ĵ����֪��(p + j * j)% msize�����������Ŀ���Ҫ�ǿ������ֶ������ֵ����ˡ�
 * */
#include <iostream>
#include <cmath>
using namespace std;
int m, n, msize, hm[20000] = {-1}, cnt = 0; /// ע�����︳ֵ={-1}����Ч�ģ�ֻ�е�һ��ֵ��-1���ѡ�
bool isprime(int k){
    for(int i = 2; i <= sqrt(k); i++)
        if(k % i == 0)return false;
    return true;
}
int main() {
    cin >> msize >> n >> m;
    while(!isprime(msize))msize++;
    fill(hm, hm + 20000, -1);
    for(int i = 0; i < n; i++){
        int a, p, j = 0;
        cin >> a;
        p = a % msize;
        while(hm[(p + j * j)% msize] != -1 && j < msize){
            j++;
        }
        if(hm[(p + j * j)% msize] == -1)
            hm[(p + j * j)% msize] = a;
        else
            cout << a << " cannot be inserted." << endl;
    }
    for(int i = 0; i < m; i++){
        int a, p, j = 0;
        cin >> a;
        p = a % msize;
        while(hm[(p + j * j)% msize] != a && j < msize && hm[(p + j * j)% msize] != -1)
            j++;
        cnt += j + 1;
    }
    printf("%.1f", (float)cnt / (float)m);
}
