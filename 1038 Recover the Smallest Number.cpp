/**
 * ������ͬ��ͷ��ͬ���ȵ�string�Ƚϵ�ʱ�������뵽����KPM���ص��ȽϷ�������Ϊ�漰
 * ���������߼����Ƚ��ƣ������Լ������ˡ�����һ�룬��ģ���ô�򵥸��������Ҹ���
 * ô���ӡ�case 3�治Ҫ����������һ��0ô����ʲô�ÿ��ģ�����ĿҪ��һ����ì�ܡ�
 * */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string strs[10001];
int n;
bool cmp(string a, string b){
    for(int i = 0; i<min(a.length(), b.length()); i++){
        if(a[i] < b[i])return true;
        if(a[i] > b[i])return false;
    }
    string c = a + b, d = b + a;
    if (c == d)return true;
    return cmp(c, d);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> strs[i];
    sort(strs, strs + n, cmp);
    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < strs[i].length(); j++){
            if(strs[i][j] == '0' && flag)continue;
            flag = false;
            cout << strs[i][j];
        }
    }
    if(flag == true)
        cout << "0";
}