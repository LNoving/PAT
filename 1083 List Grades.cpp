#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    string name, id;
    int grade;
} arr[10001];
bool cmp(node a, node b){
    return a.grade > b.grade;
}
int main(){
    int n, a, b, flag = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].name >> arr[i].id >> arr[i].grade;
    }
    sort(arr, arr + n, cmp);
    cin >> a >> b;
    for(int i = 0; i < n; i++){
        if(arr[i].grade >= a && arr[i].grade <= b){
            cout << arr[i].name << " " << arr[i].id << endl;
            flag = 1;
        }
    }
    if(!flag)
        cout << "NONE" << endl;
}
