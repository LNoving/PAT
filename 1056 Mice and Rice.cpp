/**
 * ����10���ӲŶ�����Ŀ�����������û�и㶮rank����ô��ġ������ٶ��˲�֪��
 * rankֵ����һ�����µ�mice����Ŀ+1���������Ŀ��˼֮��Ȼ�ͺܼ��ˡ�
 * */
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, g, w[1001], rnk[1001];
    vector <int> play;
    cin >> n >> g;
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        play.push_back(tmp);
    }
    while(play.size() > 1){
        int maxk = -1;
        vector<int> winner, tmpwinner;
        for(int i = 0; i < play.size(); i++){
            if(w[play[i]] > maxk){
                maxk = w[play[i]];
                tmpwinner.clear();
                tmpwinner.push_back(play[i]);
            }
            else if(w[play[i]] == maxk)
                tmpwinner.push_back(play[i]);
            if(i == play.size() - 1 || (i + 1) % g == 0 ){
                maxk = -1;
                for(int j = 0; j < tmpwinner.size(); j++)
                    winner.push_back(tmpwinner[j]);
            }
        }
        for(int i = 0; i < play.size(); i++)
            rnk[play[i]] = winner.size() + 1;
        play = winner;
    }
    rnk[play[0]] = 1;
    for(int i = 0; i < n; i++){
        if(i) printf(" ");
        printf("%d", rnk[i]);
    }
}
