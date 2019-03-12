/**
 * 很简单的一道题，但是做了整整一个半小时。完全忘了堆和堆排序是什么，花了很多时间
 * 复习。后面也出现了几个小失误，都是没有想清楚导致的。还是要戒骄戒躁，多思考。
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int n, ini[101], half[101], ins = 0;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ini[i];
    for(int i = 0; i < n; i++)
        cin >> half[i];
    int a = 0, b = n - 1;
    while(a < n - 1 && half[a] <= half[a + 1])
        a++;
    b = a + 1;
    while(b < n && ini[b] == half[b])
        b++;
    if(b == n){ // insertion sort
        ins = 1;
        sort(half, half + a + 2);
    }
    else{  // heap
        for(a = 0; a < n; a++)
            if(half[a] > half[0])
                break;
        swap(half[a - 1], half[0]);
        for(int i = 0; i * 2 + 1<= a - 2; i++){ // 调整是自上而下调整，初始建堆是外部自下而上进行内部自上而下的调整。
            if(i * 2 + 2 <= a - 2){
                if(half[i] < max(half[i * 2], half[i * 2 + 1])){
                    if(half[i * 2 + 1] > half[i * 2 + 2])
                        swap(half[i * 2 + 1], half[i]);
                    else
                        swap(half[i * 2 + 2], half[i]);
                }
            }
            else      
                if(half[i] < half[i * 2 + 1])
                    swap(half[i], half[i * 2 + 1]);
        }
    }
    if(ins)
        printf("Insertion Sort\n%d", half[0]);
    else
        printf("Heap Sort\n%d", half[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", half[i]);
    printf("\n");
}
