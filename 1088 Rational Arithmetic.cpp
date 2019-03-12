/**
 * ����⻹�ǱȽ��鷳�ģ�Ҫ���ǵ�ϸ�ںܶࡣ������һ����Сʱ��AC���Լ�����̫���ˣ�
 * ���Ǿ��������ú����ɡ�
 * ���ҡ�����Сѧ�α��ϵ�֪ʶ��ĺ���Ҫ��
 * */
#include <iostream>
using namespace std;
long long calc(long long a1, long long b1){
    a1 = a1 > 0 ? a1 : - a1;
    b1 = b1 > 0 ? b1 : - b1;
    if(a1 < b1){
        long long tmp = a1;
        a1 = b1;
        b1 = tmp;
    }
    while(b1 != 0){
        long long tmp = a1 % b1; //��ʵշת������͸���������Ĳ�������������%����-����-���һ��case��ʱ����%һ���Ӿ�������ˡ�
        if(tmp >= b1)
            a1 = tmp;
        else{
            a1 = b1;
            b1 = tmp;
        }
    }
    return a1;
}
void print(long long a, long long b){
    long long i = 0, t = 1;
    int sgn = a * b < 0;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    if(b == 0){
        printf("Inf");
        return;
    }
    if(a >= b){
        i = a / b;
        a = a % b;
    }
    if(a * b)
        t = calc(a, b);
    a /= t;
    b /= t;
    if(sgn){
        printf("(-");
        if(i)
            printf("%lld", i);
        if(i * a)
            printf(" ");
        if(a)
            printf("%lld/%lld", a, b);
        if(!a && !i)
            printf("0");
        printf(")");
    }
    else{
        if(i)
            printf("%lld", i);
        if(i * a)
            printf(" ");
        if(a)
            printf("%lld/%lld", a, b);
        if(!a && !i)
            printf("0");
    }
}
int main(){
    long long a1, b1, a2, b2, i1 = 0, i2 = 0;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    long long t1 = 1, t2 = 1;
    if(a1 * b1)
      t1 = calc(a1, b1);
    if(a2 * b2)
      t2 = calc(a2, b2);
    a1 = a1 / t1;
    b1 = b1 / t1;
    a2 = a2 / t2;
    b2 = b2 / t2;
    print(a1, b1);
    printf(" + ");
    print(a2, b2);
    printf(" = ");
    print(a1 * b2 + a2 * b1, b1 * b2);
    printf("\n");

    print(a1, b1);
    printf(" - ");
    print(a2, b2);
    printf(" = ");
    print(a1 * b2 - a2 * b1, b1 * b2);
    printf("\n");

    print(a1, b1);
    printf(" * ");
    print(a2, b2);
    printf(" = ");
    print(a1 * a2, b1 * b2);
    printf("\n");

    print(a1, b1);
    printf(" / ");
    print(a2, b2);
    printf(" = ");
    print(a1 * b2 , b1 * a2);
    printf("\n");
}
