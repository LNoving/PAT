/***
 * 考试前看过简单的并查集的算法，过了三周发现忘完了。这道题自己没做出来，还是看的
 * 别人的。果然代码还是要自己敲一下才能记住。
 * lc大佬的代码里面计算trees和birds的方法看起来有些繁琐，我没仔细看，反正我这个也能AC。
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[10010] = {0}, cnt[10010] = {0}, n, trees = 0, birds = 0;
int find_father(int k){
    int a = k;
    while(a != arr[a])
        a = arr[a];
    while(k != a){
        int tmp = arr[k];
        arr[k] = a;
        k = tmp;
    }
    return a;
}
void uni(int a, int b){
    int fa = find_father(a);
    int fb = find_father(b);
    if(fa != fb)
        arr[fa] = fb;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            if(arr[b] != 0){
                int tmp = arr[b];
                arr[b] = b;
                uni(tmp, b);
            }
            else{
                arr[b] = b;
                birds++;
            }
            if(j != 0)
                uni(b, c);
            c = b;
        }
    }
    for(int i = 1; i <= 10010; i++)
        if(arr[i] == i)
            trees++;
    printf("%d %d\n", trees, birds);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(find_father(a) == find_father(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
