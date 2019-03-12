/**
 * ���Ŵ��еĴ������޸ĸ�������AC�ˣ���������ɻ�һ��r = max(a, i)����Ȼ������ַ���
 * ֻ�ܴ���0 ~ 35�����֣���ô����36��radix��ʲô�����أ��������ԣ�case 5 10 13 15��
 * radix����36�ġ����ֹؼ���Ϣ����Ŀ����һ��Ҳ���ἰ���Ҿ�����Щ���ڿ������Ӳ���Ҫ��
 * �Ѷȡ�
 * �ڶ���������Ϊʲôgetnum��������С��0�����������´�����Ϊ�������������7��case
 * ����ȥ��������������Ǽ���һ��tmp < 0������ʵ������û�н����������⡣�����ǿ�
 * ��ʱ�临�Ӷ�Ҳ�ò�����ô������ɣ��о������̫����ë��á�
 * */
#include <iostream>
#include <algorithm>
using namespace std;
long long getnum(string s, long long radix){
    long long a = 0;
    for(int i = 0; i < s.size(); i++){
        a *= radix;
        a += isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
    }
    return a;
}
int main(){
    string n1, n2;    // radix of n1
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if(tag == 2)
        swap(n1, n2);
    char c = *max_element(n2.begin(), n2.end());
    long long a = getnum(n1, radix);
    long long l = (isdigit(c) ? c - '0' : c - 'a' + 10) + 1, r = max(a, l), flag = 0, ans = -1, tmp; // r = max(a, l) ����ֵĵ�
    while(l <= r){
        long long mid = (l + r) / 2;
        tmp = getnum(n2, mid);
        if(tmp > a || tmp < 0)        // ����tmp < 0�Ļ� case 6 8 10 12 13 15 16����ȥ
            r = mid - 1;
        else if(tmp == a){
            ans = mid;
            break;
        }
        else
            l = mid + 1;
    }
    if(ans != -1)
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
}