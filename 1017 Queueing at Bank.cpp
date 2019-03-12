#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
    int time, proc;
} custs[20000];
int window[1010], n, k, cnt, total;
double sum = 0.0;
bool cmp(node a, node b){
    return a.time < b.time;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        custs[i].proc = min(p * 60, 3600);
        custs[i].time = 3600 * h + 60 * m + s;
        if(custs[i].time <= 17 * 3600)
            cnt++;
    }
    sort(custs, custs + n, cmp);
    int p = 0, now = 8 * 3600;
    while(p < cnt){
        int i, next = window[0];
        for(int j = 0; j < k; j++){
            if(window[j] < next)
                next = window[j];
        }
        if(now + next < custs[p].time)
            next = custs[p].time - now;
        for(int j = 0; j < k; j++){
            window[j] = max(window[j] - next, 0);
        }
        now += next;
        ////有这句的时候最后一个case老是过不去，注释掉这句以后就可以了，大概意思
        //就是只要你在队列里，就会给你服务，即使已经过了下班时间，和1026题不同
        //if(now > 17 * 3600) break；
        for(i = 0; i < k; i++){
            if(window[i] == 0)
                break;
        }
        window[i] = custs[p].proc;
        total += now - custs[p].time;
        sum += now - custs[p].time;
        p++;
    }
    printf("%.1f", sum / 60.0 / (double)(cnt));
}
