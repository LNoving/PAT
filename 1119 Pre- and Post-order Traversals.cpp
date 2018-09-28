/**
 * 代码写完之后提交，给我“格式错误”，我也是醉了，瞅了半天愣是没找到哪里错了，看了下别人
 * 的代码，原来输出完了之后还要多打个\n上去。我记得以前pat不是这种套路的啊，以前不是直接
 * 输出完了就可以了的么。。
 * 感觉这道题还是挺复杂的，晚上在一个相对轻松的环境下做，前前后后花了一个多小时才写完，
 * 还好是直接AC。如果在考场上的话估计还不一定。
 * 刚做完时分割的函数是void divide(int prel, int prer, int pol, int por, int inl, int inr);
 * 里面涉及到in数组边界的传递，虽然不难但是还是容易出错，并且浪费思考时间。
 * 看了看dl的代码，发现其实直接用vector就可以，只需要在两次divide之间push就行。
 * 还是要尽量让代码优雅呀~
 * */
#include <iostream>
#include <vector>
using namespace std;
int n, post[32], pre[32], flag = 0;
vector<int> in;
void divide(int prel, int prer, int pol, int por){
    if(prel > prer)return;
    if(prel == prer){
        in.push_back(pre[prel]);
        return;
    }
    int k = 0;
    while(post[pol + k] != pre[prel + 1])k++;
    if(k + pol == por - 1){
        in.push_back(pre[prel]);
        divide(prel + 1, prer, pol, por - 1);
        flag = 1;
        return;
    } // empty
    divide(prel + 1, prel + 1 + k, pol, pol + k);
    in.push_back(pre[prel]);
    divide(prel + 1 + k + 1, prer, pol + k + 1, por - 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pre[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    divide(0, n - 1, 0, n - 1);
    printf("%s\n%d", flag == 0 ? "Yes" : "No", in[0]);
    for(int i = 1; i < n; i++)
      printf(" %d", in[i]);
    printf("\n");
}
