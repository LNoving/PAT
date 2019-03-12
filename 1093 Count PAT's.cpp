#include <iostream>
using namespace std;
int main(){
    long long p = 0, a = 0, t = 0;
    char c;
    c = getchar();
    while(c != '\n'){
        if(c == 'P')
            p++;
        if(c == 'A')
            a += p;
        if(c == 'T')
            t += a;
        c = getchar();
    }
    printf("%lld", t % 1000000007);
}
