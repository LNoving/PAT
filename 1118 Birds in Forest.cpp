/***
 * ����ǰ�����򵥵Ĳ��鼯���㷨���������ܷ��������ˡ�������Լ�û�����������ǿ���
 * ���˵ġ���Ȼ���뻹��Ҫ�Լ���һ�²��ܼ�ס��
 * lc���еĴ����������trees��birds�ķ�����������Щ��������û��ϸ�������������Ҳ��AC��
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[10010] = {0}, cnt[10010] = {0}, n, trees = 0, birds = 0;
int find_father(int k){
    int a = k;
    while(a != arr[a])
        a = arr[a];
    while(k != a){
        int tmp = arr[k];
        arr[k] = a;
        k = tmp;
    }
    return a;
}
void uni(int a, int b){
    int fa = find_father(a);
    int fb = find_father(b);
    if(fa != fb)
        arr[fa] = fb;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            if(arr[b] != 0){
                int tmp = arr[b];
                arr[b] = b;
                uni(tmp, b);
            }
            else{
                arr[b] = b;
                birds++;
            }
            if(j != 0)
                uni(b, c);
            c = b;
        }
    }
    for(int i = 1; i <= 10010; i++)
        if(arr[i] == i)
            trees++;
    printf("%d %d\n", trees, birds);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(find_father(a) == find_father(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
