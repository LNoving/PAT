/**
 * ע�������п���ȱ���Ŀ��û����ȷ˵����һ�㣬����һ�����˷��˺ܶ�ʱ�䡣
 * ʱ�临�Ӷȴ���� o(m * l) ��ʵʱ�临�ӶȻ�����Сһ�㣬��һ��color����ŵ�
 * ӳ�䣬���������ӽ�o(l) ������case 3 ��case 4 �ȴ��еĽⷨ���ǿ��˺ܶ�ġ�
 * ���Ĺ���������˵�һ���Ǽ�ʹ��ǰ��ƥ�䣬��ǰ����Ҳ������Ϊǰ�����г��ȵ�����
 * ������
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, l, last[201], cur[201], fav[201], strip, ans;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> fav[i];
    cin >> l;
    fill(last, last + 201, 0);
    fill(cur, cur + 201, 0);
    for(int i = 0; i < l; i++){
        cin >> strip;
        for(int j = 0; j < m; j++){
            if(strip == fav[j]){
                if(j > 0){
                    if(cur[j - 1] != 0)
                        cur[j] = max(last[j - 1] + 1, last[j] + 1);
                }
                else
                    cur[j] = last[j] + 1;
            }
            else
                cur[j] = max(cur[j - 1], last[j]);
        }
        for(int j = 0; j < m; j++)
            last[j] = cur[j];
    }
    cout << last[m - 1];
}
