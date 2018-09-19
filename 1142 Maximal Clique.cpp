#include <iostream>
using namespace std;
int nv, ne, e[210][210], m, clique[210], visit[210];
int main(){
    cin >> nv >> ne;
    for(int i = 0; i < ne; i++){
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int k, flag = 1;
        fill(visit, visit + 210, 0); //�����ʱ��������д����fill(visit, visit + nv, 0);һ��case����ȥ�����Ŵ��뿴��һ��Сʱ���ҵ���������Ϊ��
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> clique[j];
            visit[clique[j]] = 1;
        }
        for(int p = 0; p < k; p++){
            for(int j = p + 1; j < k; j++){   ///j���Դ�p+1��ʼ��������j��p��ͬ����������ҽ�ʡһ���ʱ�䣻
                if(e[clique[j]][clique[p]] != 1){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)break;
        }
        if(flag == 1)
            for(int j = 1; j <= nv; j++){
                if(visit[j] == 1)continue;
                int p;
                for(p = 0; p < k; p++){
                    if(e[j][clique[p]] != 1)break;
                    if(p == k - 1){
                        flag = 2;
                    }
                }
                if(flag == 2)break;
            }
        if(i)printf("\n");
        if(flag == 0)
            cout << "Not a Clique";
        if(flag == 1)
            cout << "Yes";
        if(flag == 2)
            cout << "Not Maximal";
    }
}
