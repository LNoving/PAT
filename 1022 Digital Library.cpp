#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int n, id;
    map<string, vector<int>> title, author, key, pub, year;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d\n", &id);
        char cs[81];
        string s;
        getline(cin, s);
        title[s].push_back(id);
        getline(cin, s);
        author[s].push_back(id);
        while(cin >> s){
            key[s].push_back(id);
            if(getchar() == '\n')
                break;
        }
        getline(cin, s);
        pub[s].push_back(id);
        cin >> s;
        year[s].push_back(id);
    }
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        string s;
        vector <int> ans;
        getline(cin, s);
        switch(s[0]){
            case '1': ans = title[s.substr(3)]; break;
            case '2': ans = author[s.substr(3)]; break;
            case '3': ans = key[s.substr(3)]; break;
            case '4': ans = pub[s.substr(3)]; break;
            case '5': ans = year[s.substr(3)]; break;
        }
        cout << s << endl;
        if(ans.size() == 0)
            printf("Not Found\n");
        else{
            sort(ans.begin(), ans.end());
            for(int j = 0; j < ans.size(); j++){
                printf("%07d\n", ans[j]);
            }
        }
    }
}
