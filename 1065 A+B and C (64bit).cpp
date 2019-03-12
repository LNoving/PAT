/*
//简单方法
#include <iostream>
using namespace std;
int main(){
    long long a, b, c;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a > 0 && b > 0 && a + b < 0)
            printf("Case #%d: true\n", i + 1);
        else if(a < 0 && b < 0 && a + b >= 0)
            printf("Case #%d: false\n", i + 1);
        else if(a + b > c)
            printf("Case #%d: true\n", i + 1);
        else
            printf("Case #%d: false\n", i + 1);
    }
    return 0;
}
*/
/**
 * 虽然知道就题论题会有很多简洁的解法，还是头铁花了点时间写了个string加法出来，bug主要来自于注释那个地方。
 * */
#include <iostream>
#include <algorithm>
using namespace std;
string plu(string a, string b){
    if(a.length() > b.length()){
        string tmp = a;
        a = b;
        b = tmp;
    }
    string ans = "";
    int c = 0;
    for(int i = 1; i <= b.length(); i++){
        int aa, bb;
        if(a.length() >= i){  // 比如a.length()的值是2， a.length() >= i正常工作，而a.length() - i >= 0则一直显示为正。难道c这么弱智的吗？
            aa = a[a.length() - i] - '0';
        }
        else
            aa = 0;
        bb = b[b.length() - i] - '0';
        int tmp = aa + bb + c;
        c = tmp / 10;
        ans += (char)(tmp % 10 + '0');
    }
    if(c == 1)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}
bool cmp(string a, string b){
    int i = 0, j = 0;
    while(a[i] == '0')i++;
    while(b[j] == '0')j++;
    if(a.length() - i != b.length() - j)
        return a.length() - i > b.length() - j;
    for(int k = 0; k < a.length() - i; k++){
        if(a[i + k] != b[j + k])
            return a[i + k] > b[j + k];
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string a, b, c, left = "0", right = "0";
        cin >> a >> b >> c;
        if(a[0] == '-'){
            a = a.substr(1);
            right = plu(right, a);
        }
        else{
            left = plu(left, a);
        }
        if(b[0] == '-'){
            b = b.substr(1);
            right = plu(right, b);
        }
        else{
            left = plu(left, b);
        }
        if(c[0] == '-'){
            c = c.substr(1);
            left = plu(left, c);
        }
        else{
            right = plu(right, c);
        }
        if(cmp(left, right))
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
}
