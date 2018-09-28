/**
 * ����д��֮���ύ�����ҡ���ʽ���󡱣���Ҳ�����ˣ����˰������û�ҵ�������ˣ������±���
 * �Ĵ��룬ԭ���������֮��Ҫ����\n��ȥ���Ҽǵ���ǰpat����������·�İ�����ǰ����ֱ��
 * ������˾Ϳ����˵�ô����
 * �о�����⻹��ͦ���ӵģ�������һ��������ɵĻ���������ǰǰ�����һ����Сʱ��д�꣬
 * ������ֱ��AC������ڿ����ϵĻ����ƻ���һ����
 * ������ʱ�ָ�ĺ�����void divide(int prel, int prer, int pol, int por, int inl, int inr);
 * �����漰��in����߽�Ĵ��ݣ���Ȼ���ѵ��ǻ������׳��������˷�˼��ʱ�䡣
 * ���˿�dl�Ĵ��룬������ʵֱ����vector�Ϳ��ԣ�ֻ��Ҫ������divide֮��push���С�
 * ����Ҫ�����ô�������ѽ~
 * */
#include <iostream>
#include <vector>
using namespace std;
int n, post[32], pre[32], flag = 0;
vector<int> in;
void divide(int prel, int prer, int pol, int por){
    if(prel > prer)return;
    if(prel == prer){
        in.push_back(pre[prel]);
        return;
    }
    int k = 0;
    while(post[pol + k] != pre[prel + 1])k++;
    if(k + pol == por - 1){
        in.push_back(pre[prel]);
        divide(prel + 1, prer, pol, por - 1);
        flag = 1;
        return;
    } // empty
    divide(prel + 1, prel + 1 + k, pol, pol + k);
    in.push_back(pre[prel]);
    divide(prel + 1 + k + 1, prer, pol + k + 1, por - 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pre[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    divide(0, n - 1, 0, n - 1);
    printf("%s\n%d", flag == 0 ? "Yes" : "No", in[0]);
    for(int i = 1; i < n; i++)
      printf(" %d", in[i]);
    printf("\n");
}
