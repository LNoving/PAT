#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main(){
    int n, index;
    set <int> s;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        index = 0;
        for(int j = 0; j < str.length(); j++)
            index += (int) (str[j] - '0');
        s.insert(index);
    }
    vector<int> v;
    for(auto it = s.begin(); it != s.end(); it++)
        v.push_back(*it);
    sort(v.begin(), v.end()); //对set排序编译不通过，no match for 'operator-' (operand types are 'std::_Rb_tree_const_iterator<int>' and 'std::_Rb_tree_const_iterator<int>')|
    printf("%d\n", v.size());
    for(auto it = v.begin(); it != v.end(); it++){
        if(it != v.begin())printf(" ");
        printf("%d", (*it));
    }
}
