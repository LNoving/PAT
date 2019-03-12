#include <iostream>
using namespace std;
struct {
    string id, pwd;
}arr[1001];
int n, cnt, flag[1001];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        for(int j = 0; j < b.length(); j++){
            switch(b[j]){
                case 'l' : b[j] = 'L'; flag[i] = 1; break;
                case '0' : b[j] = '%'; flag[i] = 1; break;
                case 'O' : b[j] = 'o'; flag[i] = 1; break;
                case '1' : b[j] = '@'; flag[i] = 1; break;
            }
        }
        if(flag[i] == 1)
            cnt++;
        arr[i].id = a;
        arr[i].pwd = b;
    }
    if(cnt == 0){
        if(n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
        return 0;
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++){
        if(flag[i] == 0)
            continue;
        cout << arr[i].id << " " << arr[i].pwd << endl;
    }
}
