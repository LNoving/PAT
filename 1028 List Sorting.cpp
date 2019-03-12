#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    string id, name;
    int grade;
} arr[100001];
bool cmp1(node a, node b){
    return a.id < b.id;
}
bool cmp2(node a, node b){
    return a.name != b.name ? a.name < b.name : a.id < b.id;
}
bool cmp3(node a, node b){
    return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}
int main(){
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> arr[i].id >> arr[i].name >> arr[i].grade;
    switch(c){
        case 1: sort(arr, arr + n, cmp1); break;
        case 2: sort(arr, arr + n, cmp2); break;
        case 3: sort(arr, arr + n, cmp3); break;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i].id << " " << arr[i].name << " " << arr[i].grade << endl;
}
