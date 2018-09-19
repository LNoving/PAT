#include <iostream>
#include <vector>
using namespace std;
typedef struct{
    int val, pos, next;
} node;
node a[100010];
vector <node> neg, little, big;
int n, k, head;
int main(){
    cin >> head >> n >> k;
    for(int i = 0; i < n; i++){
        int cur, val, next;
        cin >> cur;
        cin >> a[cur].val >> a[cur].next;
        a[cur].pos = cur;
    }
    int p = head;
    while(p != -1){
        if(a[p].val < 0){
            neg.push_back(a[p]);
        }else if(a[p].val > k){
            big.push_back(a[p]);
        }else
            little.push_back(a[p]);
        p = a[p].next;
    }
    for(int i = 0; i < neg.size(); i++){
        if(i == 0)
            printf("%05d %d ", neg[i].pos, neg[i].val);
        else
            printf("%05d\n%05d %d ", neg[i].pos, neg[i].pos, neg[i].val);
    }
    for(int i = 0; i < little.size(); i++){
            if(neg.empty() && i == 0)    //做的时候这里忘了加 && i == 0 了，又debug了好久。脑子进水了
                printf("%05d %d ", little[i].pos, little[i].val);
            else
                printf("%05d\n%05d %d ", little[i].pos, little[i].pos, little[i].val);
    }
    for(int i = 0; i < big.size(); i++){
            if(neg.empty() && little.empty() && i == 0)  //同上
                printf("%05d %d ", big[i].pos,  big[i].val);
            else
                printf("%05d\n%05d %d ", big[i].pos, big[i].pos, big[i].val);
    }
    cout << "-1";
}
