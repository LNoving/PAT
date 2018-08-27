/**
 * 没有模拟归并过程，而是自己根据归并的特点搞个判断的方法出来。不是我觉得模拟太慢了，
 * 而是，，忘了归并怎么写了。。￣へ￣。这个题没有卡时间的case
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int n, init[101], part[101], flag = 1; //1 represents merge sort
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> init[i];
    for(int i = 0; i < n; i++)
        cin >> part[i];
    int k, j, m; // m is the size of each sub-sequence in current merge sort step. k is the step of insertion
    for(k = 0; k < n - 2; k++){
        if(part[k + 1] < part[k])break;
    }
    for(j = n - 1; j > k; j--)
        if(part[j] != init[j])break;
    if(j == k){
        cout << "Insertion Sort\n";
        sort(part, part + k + 2);
    }
    else{
        cout << "Merge Sort\n";
        for(m = k + 1; m > 0; m--){
            for(j = 1; j < n; j++){
                if(j % m != 0 && part[j] < part[j - 1])
                    break;
            }
            if(j == n)break;
        }
        for(j = 0; j < n; j = j + 2 * m)
            sort(part + j, part + min(j + 2 * m, n));
    }
    for(int i = 0; i < n; i++){
        if(i)cout << " ";
        cout << part[i];
    }
}
