#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake{
    float weight, price, unit;
};
int n, d;
mooncake cakes[1001];
bool cmp(mooncake a, mooncake b){
    return a.unit > b.unit;
}
int main(){
    scanf("%d %d", &n, &d);
    for(int i = 0; i<n; i++){
        scanf("%f", &(cakes[i].weight));
    }
    for(int i =0; i< n;i++){
        scanf("%f", &(cakes[i].price));
        cakes[i].unit = cakes[i].price / cakes[i].weight;
    }
    sort(cakes, cakes + n, cmp);
    float w = 0, profit = 0;
    for(int i = 0; i<n; i++){
        if(w + cakes[i].weight >= d){
            profit += (d - w) * cakes[i].unit;
            break;
        }
        else{
            w += cakes[i].weight;
            profit += cakes[i].price;
        }
    }
    printf("%.2f", profit);
}