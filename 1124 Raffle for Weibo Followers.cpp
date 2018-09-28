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
            if(--flag < 0)flag = 0;//为了应对下面的flag++
        }
        else{
            flag = 1; //我感觉这里应该是flag++，因为当一个人横跨两个位置时似乎应该多补一个。可能题目没有表达清楚
            i++;
        }
    }
    if(ans == 0)
        cout << "Keep going...";
}
