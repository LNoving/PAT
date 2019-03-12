/**
 * 树状数组的概念和update() getsum()函数该怎么写要清楚。很巧妙的一种数据结构，把查询
 * 和修改的时间复杂度一起降了一个层次。参考https://blog.csdn.net/flushhip/article/details/79165701
 * 代码来自https://www.liuchuo.net/archives/2265
 */
#include <iostream>
#include <stack>
#define lowbit(x) ((x)&(-x))    //宏定义求lowbit的写法最好牢记
const int maxn = 100010;
using namespace std;
/*原始数组的信息a[i] = n的意思是整个stack里面值为i的数共有n个，c就
是a对应的树状数组。sum(i)求出的就是小于i值的所有元素的【个数】之和
当我们需要查询所有数中第k大的数的时候，只需要用二分法查找一个i值使
得sum(i)=k即可*/
int c[maxn];
stack<int> s;
void update(int x, int n){
    while(x < maxn){
        c[x] += n;
        x += lowbit(x);
    }
}
int getsum(int x){
    int sum = 0;
    while(x >= 1){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void PeekMedian(){
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right){
        int mid = (left + right) / 2, tmp = getsum(mid);
        //这里因为是求相等区间中的最左端，所以相等情况下向左收缩。这个二分法的模板最好也记忆一下
        if(getsum(mid) >= k){
            right = mid;
        }
        else
            left = mid + 1;    //以前写二分法出错的原因就在于这里没写对。
    }
    cout << left << endl;
}
int main(){
    int n;
    char str[20];
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        if(str[1] == 'u'){
            int tmp;
            cin >> tmp;
            s.push(tmp);
            update(tmp, 1);
        }
        else if(str[1] == 'e'){
            if(s.size() == 0)
                cout << "Invalid" << endl;
            else
            PeekMedian();
        }
        else if(str[1] == 'o'){
            if(s.size() == 0)
                cout << "Invalid" << endl;
            else{
                int tmp = s.top();
                s.pop();
                update(tmp, -1);
                cout << tmp << endl;
            }
        }
    }
}
