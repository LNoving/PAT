#include <cstdio>
using namespace std;
int n;
bool a[10000000];
int main(){
    scanf("%d", &n);
    int b;
    for(int i = 0; i < n; i++){
        scanf("%d", &b);
        if(b > 0 && b < 10000000)
        a[b] = true;
    }
    b = 1;
    while(a[b] == true)b++;
    printf("%d", b);
}
