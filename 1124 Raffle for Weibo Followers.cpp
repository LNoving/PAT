#include <iostream>
#include <map>
using namespace std;
map<string, int> winner;
int main(){
    string name;
    int m, n, s, flag = 0, ans = 0;
    cin >> m >> n >> s;
    int i = s;
    for(int j = 1; j <= m; j++){
        cin >> name;
        if(flag == 0 && j != i)continue;
        if(winner[name] != 1){
            cout << name << endl;
            winner[name] = 1;
            i += n;
            ans = 1;
            if(--flag < 0)flag = 0;//Ϊ��Ӧ�������flag++
        }
        else{
            flag = 1; //�Ҹо�����Ӧ����flag++����Ϊ��һ���˺������λ��ʱ�ƺ�Ӧ�öಹһ����������Ŀû�б�����
            i++;
        }
    }
    if(ans == 0)
        cout << "Keep going...";
}
