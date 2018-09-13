#include <iostream>
using namespace std;
int m, n, level[1010], flag, ans[1010], p;
void post(int k){
    if(k * 2 <= n){
        if(level[k] > level[k * 2]){
            if(flag == -1 || flag == 2)
                flag = 2;
            else
                flag = 1;
        }
        else if(level[k] < level[k * 2]){
            if(flag == 1 || flag == 2)
                flag = 2;
            else
                flag = -1;
        }
        post(k * 2);
    }
    if(k * 2 + 1 <= n){
        if(level[k] > level[k * 2 + 1]){
            if(flag == -1 || flag == 2)
                flag = 2;
            else
                flag = 1;
        }
        else if(level[k] < level[k * 2 + 1]){
            if(flag == 1 || flag == 2)
                flag = 2;
            else
                flag = -1;
        }
        post(k * 2 + 1);
    }
    ans[p++] = level[k];
}
int main(){
    cin >> m >> n;
    for(int j = 0; j < m; j++){
        p = 0;
        flag = 0;
        for(int i = 1; i <= n; i++){
            cin >> level[i];
        }
        post(1);
        if(flag == 2)cout << "Not Heap" << endl;
        else{
            if(flag == -1)
                cout << "Min Heap" << endl;
            else
                cout << "Max Heap" << endl;
        }
        for(int i = 0; i < n; i++){
            if(i)printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
