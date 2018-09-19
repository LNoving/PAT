/**
 * For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
 * ����ÿ���ڵ㣬��������Ȩ����ͬ�����Ǹ��ݹ�Ķ��塣�����ʱ����������㣬ֻ���ж���ÿ����
 * �㵽���ڵ��Ȩ�أ�������case���ǹ���ȥ������д����30���ӣ�debug��Сʱ�����������������
 * �������ѵ��Ľⷨ������������������ֱ��dfs�ĺ��٣�������һ����Խ�е�23333
 * */
#include <iostream>
#include <vector>
using namespace std;
int k, rbt[100] = {0};
int dfs(int l, int r){
    if(l > r)return 0;
    if(l == r){
        return rbt[l] > 0 ? 1 : 0;
    }
    int i = l + 1;
    while(i <= r && abs(rbt[i]) < abs(rbt[l]))i++;
    if(rbt[l] > 0){
        int lw = dfs(l + 1, i - 1), rw = dfs(i, r);
        return lw == rw && lw != -1 ? lw + 1 : -1;
    }
    else{
        if(rbt[l + 1] < 0 || (i <= r && rbt[i] < 0) )return -1;
        int lw = dfs(l + 1, i - 1), rw = dfs(i, r);
        return lw == rw && lw != -1 ? lw : -1;
    }
}
int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> rbt[j];
        }
        if(rbt[0] > 0 && dfs(0, n - 1) != -1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        fill(rbt, rbt + 100, 0);
    }
}
