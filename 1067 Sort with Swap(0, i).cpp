/**
 * 绝对是我有史以来最懵逼的一次AC。和大佬的解法有很大区别。。但是说实话，感觉我的
 * 好理解得多，而且用时一样 = =，解法就是一句话，遇到不在位置上的元素就拼命换啊换
 * 直到换到这个位置该有的元素为止。感觉这个解法好像也没用贪心的思想。。。
 * */
#include <cstdio>
using namespace std;
int a[100001], n, p = 0, ans = 0;
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);
    while(p < n){
        if(a[0] == 0 && a[p] == p){p++;continue;}
        if(a[0] == 0 && a[p] != p){
            a[0] = a[p];
            a[p] = 0;
            ans++;
        }
        int k = a[0];
        while(a[k] != k){
            int t = a[0];
            a[0] = a[k];
            a[k] = t;
            ans++;
            k = a[0];
        }
    }
    printf("%d", ans);
}