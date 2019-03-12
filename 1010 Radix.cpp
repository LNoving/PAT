/**
 * 照着大佬的代码修修改改总算是AC了，有两点很疑惑。一是r = max(a, i)，既然输入的字符串
 * 只能代表0 ~ 35的数字，那么大于36的radix有什么意义呢？经过测试，case 5 10 13 15是
 * radix大于36的。这种关键信息在题目里面一点也不提及，我觉得有些过于刻意增加不必要的
 * 难度。
 * 第二个问题是为什么getnum里面会产生小于0的数。初步猜错是因为大数溢出，导致7个case
 * 过不去。解决方法仅仅是加上一个tmp < 0，但其实本质上没有解决溢出的问题。就算是考
 * 察时间复杂度也用不到这么大的数吧，感觉这道题太过吹毛求疵。
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
    long long l = (isdigit(c) ? c - '0' : c - 'a' + 10) + 1, r = max(a, l), flag = 0, ans = -1, tmp; // r = max(a, l) 很奇怪的点
    while(l <= r){
        long long mid = (l + r) / 2;
        tmp = getnum(n2, mid);
        if(tmp > a || tmp < 0)        // 不加tmp < 0的话 case 6 8 10 12 13 15 16过不去
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