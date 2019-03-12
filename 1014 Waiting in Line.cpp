/**
 * 懒得做了，代码是抄的lc大佬的。有时间可以再做一下
 * */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int poptime, endtime;
    queue<int> q;
};
int main(){
    int n, m, k, q, index = 1;
    cin >> n >> m >> k >> q;
    vector<int> time(k + 1), result(k + 1);
    for(int i = 1; i <= k; i++)
        cin >> time[i];
    vector<node> windows(n + 1);
    vector<bool> sorry(k + 1, false);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(index <= k){
                windows[j].q.push(time[index]);
                if(windows[j].endtime >= 9 * 60)
                    sorry[index] = true;
                windows[j].endtime += time[index];
                if(i == 1)
                    windows[j].poptime = windows[j].endtime;
                result[index] = windows[j].endtime;
                index++;
            }
        }
    }
    while(index <= k){
        int tmpmin = windows[1].poptime, tmpwindow = 1;
        for(int i = 2; i <= n; i++){
            if(windows[i].poptime < tmpmin){
                tmpwindow = i;
                tmpmin = windows[i].poptime;
            }
        }
        windows[tmpwindow].q.pop();
        windows[tmpwindow].q.push(time[index]);
        windows[tmpwindow].poptime += windows[tmpwindow].q.front();
        if(windows[tmpwindow].endtime >= 9 * 60)
            sorry[index] = true;
        windows[tmpwindow].endtime += time[index];
        result[index] = windows[tmpwindow].endtime;
        index++;
    }
    for(int i = 1; i <= q; i++){
        int query, minute;
        cin >> query;
        minute = result[query];
        if(sorry[query])
            cout << "Sorry" << endl;
        else
            printf("%02d:%02d\n", minute / 60 + 8, minute % 60);
    }
}

/*
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


void s();

int n, m, k, q;

int tim[1001] = {0};
int query[1001];
int ans[1001];

int window[20] = {0}; // the first element stores the amount of the waiting customers.
int win_time[20] = {0};
int line[20][11];
int minutes = -1;
int waits = 1;  // the first people out of the yellow line;

void to_window();
void init_line();
void update_line(int no);
bool check_end();

int main() {

    s();
}

void s(){

    cin >> n >> m >> k >> q;
    m--;
    for(int i = 1; i<=k; i++){
        cin >> tim[i];
    }
    for(int i = 0; i<q; i++){
        cin >> query[i];
    }

    //initialization
    init_line();
    to_window();
    while(!check_end()){
        to_window();
    }

    for(int i = 0; i<q; i++){
        if(i)
            cout <<"\n";
        if(ans[query[i]] > 540)
            cout << "Sorry";
        else
            printf("%02d:%02d", 8 + ans[query[i]] / 60, ans[query[i]] % 60);
    }


}

void init_line(){
    if (k > n*m){
        for(int i = 1; i<=m; i++){  // number in line
            for(int j = 0; j<n; j++) { //window
                line[j][i] = waits++;
            }
        }
        for(int i = 0; i<n; i++)
            line[i][0] = m;
    }
    else{
        for(int i = 1; i<=m; i++){  // number in line
            for(int j = 0; j<n; j++) { //window
                line[j][i] = waits++;
                if(waits > k)
                    break;
            }
        }
        for(int i = 0; i<n; i++)
            line[i][0] = i > k%n ? k/n : k/n +1;
    }
}

void to_window(){
    minutes++;

    if(m == 0){
        for(int i = 0; i<n; i++){
            if(win_time[i] == 0){
                ans[window[i]] = minutes;
                update_line(i);
                win_time[i] = tim[window[i]];
            }else if(win_time[i] == 0&& line[i][0] == 0){
            ans[window[i]] = minutes;
            window[i] = 0;
        }
        win_time[i]--;
    }
        return;
    }

    for(int i = 0; i<n; i++){
        if(win_time[i] == 0 && line[i][0] != 0){
            ans[window[i]] = minutes;
            update_line(i);
            win_time[i] = tim[window[i]];
        }else if(win_time[i] == 0&& line[i][0] == 0){
            ans[window[i]] = minutes;
            window[i] = 0;
        }
        win_time[i]--;
    }
}

void update_line(int no){
    if(m == 0){
        if(waits <= k)
            window[no] = waits++;
        else
            window[no] = 0;
        return;
    }
    window[no] = line[no][1];
    for(int i = 1; i<line[no][0]; i++){
        line[no][i] = line[no][i+1];
    }
    line[no][line[no][0]] = 0;
    line[no][0]--;
    if(waits <= k){
        line[no][++line[no][0]] = waits++;
    }
}

bool check_end(){
    for(int i = 0; i<n; i++)
        if(window[i] != 0)
            return false;
    return true;
}
*/