#include <cstdio>
#include <math.h>
using namespace std;
long long int n, a, len = 0, tmp;
int main(){
    scanf("%lld", &n);
    for(long long i = 2; i <= sqrt(n); i++){ //最后一个大case很大。用sqrt()可以过，否则过不了
        int tmp = 1, k;
        for(k = 0; k < 13; k++){
            tmp *= (i + k);
            if(n % tmp != 0)
                break;
        }
        if(k > len){
            a = i;
            len = k;
        }
    }
    if(len == 0){
        a = n;
        len++;
    }
    printf("%lld\n", len);
    for(int i = 0; i < len; i++){
        if(i)printf("*");
        printf("%lld", a + i);
    }
}
