#include <iostream>
#include <vector>
using namespace std;
int main(){
    long a, k = 2, aa;
    vector <long> v;
    cin >> a;
    aa = a;
    while(a != 1){
        if(a % k == 0){
            v.push_back(k);
            a /= k;
            continue;
        }
        k++;
    }
    if(aa == 1){      //特殊情况 a=1 个人认为题目出得不够好，因为1应该不能算作prime factor 
      printf("1=1");
      return 0;
    }
    int cnt = 1, flag = 0;
    printf("%ld=", aa);
    for(int i = 1; i <= v.size(); i++){
        if(i == v.size() || v[i] != v[i - 1]){
            if(flag++) printf("*");
            if(cnt > 1)
                printf("%ld^%d", v[i - 1], cnt);
            else
                printf("%ld", v[i - 1]);
            cnt = 1;
        }
        else if(v[i] == v[i - 1])
            cnt++;
    }
}
