/**һ���ܴ��vector<int>���� v[]�������Ϣ��ע��Ϊ���߼��򵥣���������� Ҫ��
�����Ϣ��Ҫ�����ѧ��ѡ�Ŀγ̣��Ͱ�ѧ�����档ע�⣬�����hashֻ��һ��������
ֻ��Ҫ������hash����Ȼ����ȥ����������Ҫ����hashֵ�����֡�
���һ��case170ms���ģ�����200ms������ͦΣ�ա�
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
int gethash(char* name){
    int ans = (int)(name[0] - 'A');
    ans *= 26;
    ans += (int)(name[1] - 'A');
    ans *= 26;
    ans += (int)(name[2] - 'A');
    ans *= 10;
    ans += (int)(name[3] - '0');
    return ans;
}
int main(){
    scanf("%d %d", &n, &k);
    char name[5];
    for(int i = 0; i < k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        for(int j = 0; j<b; j++){
            scanf("%s", &name);
            v[gethash(name)].push_back(a);
        }
    }
    for(int i = 0; i<n; i++){
        scanf("%s", &name);
        int h = gethash(name);
        printf("%s %d", name,v[h].size());
        std::sort(v[h].begin(),v[h].end());  ///sort���÷�
        for(int j = 0; j< v[h].size(); j++){
            printf(" %d", v[h][j]);
        }
        printf("\n");
    }
}
