#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
float a[10010];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%f", a + i);
    }
    sort(a, a + n);
    float ans = a[0];
    for(int i = 1; i<n; i++){
        ans = (ans + a[i]) / 2;
    }
    printf("%d", (int)ans);
}