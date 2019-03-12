#include <iostream>
using namespace std;
int main(){
    char sell[1001], need[1001];
    int exist[256] = {0}, n = 0, m = 0, flag = 0;
    sell[n] = getchar();
    while(sell[n] != '\n'){
        exist[(int)sell[n]]++;
        sell[++n] = getchar();
    }
    need[m] = getchar();
    while(need[m] != '\n'){
        if(isalnum(need[m]))
            exist[(int)need[m]]--;
        need[++m] = getchar();
    }
    for(int i = 0; i < 256; i++)
        if(exist[i] < 0)
            flag -= exist[i];
    if(flag == 0)
        printf("Yes %d\n", n - m);
    else
        printf("No %d\n", flag);
}
