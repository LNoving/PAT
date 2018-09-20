#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int says[102], n, w1, w2;
set<int> liers;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> says[i];
    for(w1 = 1; w1 < n; w1++){
        for(w2 = w1 + 1; w2 <= n; w2++){
            liers.clear();
            for(int i = 1; i <= n; i++){
                if(abs(says[i]) == w1 || abs(says[i]) == w2){
                    if(says[i] > 0)
                        liers.insert(i);
                }else{
                    if(says[i] < 0)
                        liers.insert(i);
                }
            }
            if(liers.size() == 2 && ((liers.find(w1) == liers.end() && liers.find(w2) != liers.end()) || (liers.find(w2) == liers.end() && liers.find(w1) != liers.end()) ))
                break;
        }
        if(liers.size() == 2 && ((liers.find(w1) == liers.end() && liers.find(w2) != liers.end()) || (liers.find(w2) == liers.end() && liers.find(w1) != liers.end()) ) )
                break;
    }
    if(liers.size() == 2)
        cout << w1 << " " << w2;
    else
        cout << "No Solution";
}
