/**
 * ��״����ĸ����update() getsum()��������ôдҪ������������һ�����ݽṹ���Ѳ�ѯ
 * ���޸ĵ�ʱ�临�Ӷ�һ����һ����Ρ��ο�https://blog.csdn.net/flushhip/article/details/79165701
 * ��������https://www.liuchuo.net/archives/2265
 */
#include <iostream>
#include <stack>
#define lowbit(x) ((x)&(-x))    //�궨����lowbit��д������μ�
const int maxn = 100010;
using namespace std;
/*ԭʼ�������Ϣa[i] = n����˼������stack����ֵΪi��������n����c��
��a��Ӧ����״���顣sum(i)����ľ���С��iֵ������Ԫ�صġ�������֮��
��������Ҫ��ѯ�������е�k�������ʱ��ֻ��Ҫ�ö��ַ�����һ��iֵʹ
��sum(i)=k����*/
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
        //������Ϊ������������е�����ˣ�����������������������������ַ���ģ�����Ҳ����һ��
        if(getsum(mid) >= k){
            right = mid;
        }
        else
            left = mid + 1;    //��ǰд���ַ������ԭ�����������ûд�ԡ�
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
