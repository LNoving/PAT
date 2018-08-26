/**
 * 总有个题目，让我莫名心酸
 * */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
float tank, termi, unit, ans = 0, remain = 0;
int n, pos;
struct station{
    float price, dis;
} sts[501];
bool cmp(station a, station b){
    return a.dis < b.dis;
}
int main(){
    scanf("%f %f %f %d", &tank, &termi, &unit, &n);
    for(int i = 0; i < n; i++){
        scanf("%f %f", &(sts[i].price), &(sts[i].dis));
    }
    sort(sts, sts + n, cmp);
    while(true){
        float curmin = 999999;
        int j, pmin;
        for(j = 0; pos + j + 1 < n; j++){
            if(sts[pos + j + 1].dis - sts[pos].dis > tank * unit)break;
            if(sts[pos + j + 1].price <= curmin){
                pmin = pos + j + 1;
                curmin = sts[pmin].price;
                if(sts[pmin].price <= sts[pos].price){
                    j++;
                    break;
                }
            }
        }
        if((j == 0 && pos + 1 < n) || (pos + 1 == n && (termi - sts[pos].dis) > tank * unit )){
            ans = -1;
            unit = sts[pos].dis + tank * unit;
            break;
        }
        if(termi - sts[pos].dis <= tank * unit){
            if( j + 1 == n || sts[pos].price <= sts[pmin].price){
                ans += ( (termi - sts[pos].dis) / unit - remain) * sts[pos].price;
                break;
            }
        }
        if(sts[pmin].price > sts[pos].price){ /// fill to full
            ans += (tank - remain) * sts[pos].price;
            remain = tank - (sts[pmin].dis - sts[pos].dis) / unit;
        }else{                                 /// fill to next
            ans += ( (sts[pmin].dis - sts[pos].dis) / unit - remain ) * sts[pos].price;
            remain = 0;
        }
        pos = pmin;
    }
    if(sts[0].dis != 0){
        ans = -1;
        unit = 0;
    }
    if(ans == -1){
        printf("The maximum travel distance = %.2f", unit);
    }else{
        printf("%.2f", ans);
    }
}