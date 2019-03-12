/**
 * 代码比较长，看起来很丑。有时间可以优化一下。
 * */
#include <iostream>
using namespace std;
char num[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
bool first = true;
int read(long n, int flag){   // read以万以内数字为整体输出结果。
    if(n / 1000 > 0){
        if(!flag){
            if(first) first = false; else printf(" ");
            printf("ling");
            flag = 1;
        }
        if(first) first = false; else printf(" ");
        printf("%s Qian", num[n / 1000]);
        if(flag == -1)
            flag = 1;
    }
    else if(flag == 1)
        flag = 0;
    n %= 1000;
    if(n / 100 > 0){
        if(!flag){
            if(first) first = false; else printf(" ");
            printf("ling");
            flag = 1;
        }
        if(first) first = false; else printf(" ");
        printf("%s Bai", num[n / 100]);
        if(flag == -1)
            flag = 1;
    }
    else if(flag == 1)
        flag = 0;
    n %= 100;
    if(n / 10 > 0){
        if(!flag){
            if(first) first = false; else printf(" ");
            printf("ling");
            flag = 0;
        }
        if(first) first = false; else printf(" ");
        printf("%s Shi", num[n / 10]);
        if(flag == -1)
            flag = 1;
    }
    else if(flag == 1)
        flag = 0;
    n %= 10;
    if(n > 0){
        if(!flag){
            if(first) first = false; else printf(" ");
            printf("ling");
            flag = 1;
        }
        if(first) first = false; else printf(" ");
        printf("%s", num[n]);
        if(flag == -1)
            flag = 1;
    }  // 读个位的时候不记“零”， 例如二十万三千
    return flag;
}
int main(){
    long a;
    int flag = -1;
    cin >> a;
    if(a == 0)
        printf("ling\n");
    if(a < 0){
        printf("Fu");
        first = false;
        a = -a;
    }
    if(a / 100000000 > 0){
        flag = read(a / 100000000, flag);
        printf(" Yi");
        if(flag == -1)
            flag = 1;
    }
    a %= 100000000;
    if(a / 10000 > 0){
        flag = read(a / 10000, flag);
        printf(" Wan", num[a / 10000]);
    }
    else if(flag == 1)
        flag = 0;
    a %= 10000;
    if(a > 0){
        flag = read(a, flag);
    }
}
