/**
 * 还是把这个模板背下吧，挺重要的
 * */
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int val;
    node *l, *r;
    node(int val) : val(val){}; //node(int val) : val(val) , l(NULL), r(NULL){};可以这样写构造函数
};
node* ll(node* root){
    node* tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    return tmp;
}
node* rr(node* root){
    node* tmp = root->r;
    root->r = tmp->l;
    tmp->l = root;
    return tmp;
}
node* lr(node* root){
    root->l = rr(root->l);
    return ll(root);
}
node* rl(node* root){
    root->r = ll(root->r);
    return rr(root);
}
int get_height(node* root){
    if(root == NULL)
        return 0;
    return max(get_height(root->l), get_height(root->r)) + 1;
}
node* ins(node* root, int val){
    if(root == NULL){
        return new node(val);
    }
    else if(val < root->val){
        // 这里是更新左子树和右子树，而不是根节点！第二次练的时候就把这里写错了，要引起注意！
        root->l = ins(root->l, val);
        if(get_height(root->l) - get_height(root->r) == 2)
            root = val < root->l->val ? ll(root) : lr(root);
    }
    else{
        root->r = ins(root->r, val);
        if(get_height(root->r) - get_height(root->l) == 2)
            root = val > root->r->val ? rr(root) : rl(root);
    }
    return root;
}
int main(){
    int n;
    cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = ins(root, val);
    }
    cout << root->val;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int val;
    node* left, *right;
    node(int val) : val(val), left(NULL), right(NULL) {};
};
int get_height(node* root){
    if(root == NULL)
        return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
}
node* ll(node* root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
node* rr(node* root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
node* lr(node* root){
    root->left = rr(root->left);
    return ll(root);
}
node* rl(node* root){
    root->right = ll(root->right);
    return rr(root);
}
node* ins(node* root, int val){
    if(root == NULL)
        return new node(val);
    if(val < root->val)
        root->left = ins(root->left, val);
    else
        root->right = ins(root->right, val);
    int weight = get_height(root->left) - get_height(root->right);
    if(weight == 2){
        if(get_height(root->left->left) > get_height(root->left->right))
            root = ll(root);
        else
            root = lr(root);
    }
    else if(weight == -2){
        if(get_height(root->right->left) < get_height(root->right->right))
            root = rr(root);
        else
            root = rl(root);
    }
    return root;
}
int main(){
    int n;
    cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = ins(root, val);
    }
    cout << root->val;
}
*/