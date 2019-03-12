#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
int n, flag = 0, arr[1001] ; // 1 is min 2 is max -1 is not
vector<int> path;
void dfs(int k){
    if(2 * k + 1 < n){
        if(flag != -1){
            if(flag == 0){
                if(arr[k * 2 + 1] > arr[k])
                    flag = 1;
                else if(arr[k * 2 + 1] < arr[k])
                    flag = 2;
            }
            else{
                if((arr[k * 2 + 1] > arr[k] && flag == 2) || (arr[k * 2 + 1] < arr[k] &&flag == 1))
                    flag = -1;
            }
        }
        path.push_back(2 * k + 1);
        dfs(2 * k + 1);
        path.pop_back();
    }
    if(2 * k < n){
        if(flag != -1){
            if(flag == 0){
                if(arr[k * 2] > arr[k])
                    flag = 1;
                else if(arr[k * 2] < arr[k])
                    flag = 2;
            }
            else{
                if((arr[k * 2] > arr[k] && flag == 2) || (arr[k * 2] < arr[k] &&flag == 1))
                    flag = -1;
            }
        }
        path.push_back(2 * k);
        dfs(2 * k);
        path.pop_back();
    }
    else{
        for(int i = 0; i < path.size(); i++){
            if(i) printf(" ");
            printf("%d", arr[path[i]]);
        }
        printf("\n");
    }
}
int main()
{
    cin >> n;
    n++;
    for(int i = 1; i < n;i ++){
        int a;
        scanf("%d", &a);
        arr[i] = a;
    }
    path.push_back(1);
    dfs(1);
    if(flag == 1)
        printf("Min Heap");
    if(flag == 2)
        printf("Max Heap");
    if(flag == -1)
        printf("Not Heap");
    return 0;
}
