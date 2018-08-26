#include <cstdio>
using namespace std;
int main(){
    char a[10010];
    bool b[256] = {false};
    int i =0;
    a[i] = getchar();
    while(a[i]!='\n'){
        a[++i] = getchar();
    }
    char c;
    c = getchar();
    for(int i = 0; c !='\n'; i++){
        b[(int) c] = true;
        c = getchar();
    }
    for(int i = 0; a[i] != '\n'; i++){
        if(!b[(int)a[i]])
            printf("%c",a[i]);
    }
}
