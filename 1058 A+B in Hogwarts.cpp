#include <iostream>
using namespace std;
int main(){
    long a, b, c, d, e, f;
    scanf("%ld.%ld.%ld %ld.%ld.%ld", &a, &b, &c, &d, &e, &f);
    c += f;
    b += c / 29 + e;
    a += b / 17 + d;
    printf("%ld.%ld.%ld", a, b % 17, c % 29);
}
