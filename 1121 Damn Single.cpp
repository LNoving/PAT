#include <iostream>
#include <map>
using namespace std;
map <int, int> m;
map <int, bool> pres;
int n, a, b, zero = 0, cnt = 0;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        if(a == 0 || b == 0) zero = a == 0 ? b : a;
        m[a] = b;
        m[b] = a;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        pres[a] = true;
        ++cnt;
        if(m[a] == 0 && a != zero)continue;
        if(m[a] != 0){
            if(pres[m[a]] == true){
                pres[m[a]] = false;
                pres[a] = false;
                cnt -= 2;
            }
        }
        else{
            if(pres[zero] == true){
                pres[m[a]] = false;
                pres[a] = false;
                cnt -= 2;
            }
        }
    }
    cout << cnt << endl;
    for(auto it = m.begin(); it != m.end(); it++){
        if(pres[(it -> first)]){
            if(cnt == 0)printf(" ");
            printf("%05d", (it -> first));
            cnt = 0;
        }
    }
}
