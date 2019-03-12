#include <iostream>
using namespace std;
int main(){
    int n, fgrade = -1, mgrade = 101, tmpgrade;
    string fid, fname, mid, mname, tmpname, tmpid;
    cin >> n;
    for(int i = 0; i < n; i++){
        char gen;
        cin >> tmpname >> gen >> tmpid >> tmpgrade;
        if(gen == 'M' && tmpgrade < mgrade){
            mgrade = tmpgrade;
            mname = tmpname;
            mid = tmpid;
        }
        if(gen == 'F' && tmpgrade > fgrade){
            fgrade = tmpgrade;
            fname = tmpname;
            fid = tmpid;
        }
    }
    if(fgrade == -1)
        printf("Absent\n");
    else
        cout << fname << " " << fid << endl;
    if(mgrade == 101)
        printf("Absent\n");
    else
        cout << mname << " " << mid << endl;
    if(fgrade == -1 || mgrade == 101)
        printf("NA\n");
    else
        cout << fgrade - mgrade << endl;

}
