//pӦ����long���洢���������һ��case����ȥ��
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, arr[100010], ans = 0;
    long p;
    cin >> n >> p;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        //���ַ��Ŀ⺯����������Ĵ���Ч��һ��
        ans = max((int)(upper_bound(arr + i, arr + n, arr[i] * p) - (arr + i)), ans);
        /*
        int l = i + ans, r = n - 1;
        if(l > n - 1)
            break;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(arr[mid] > arr[i] * p)
                r = mid - 1;
            else
                l = mid;
        }
        if(arr[l] <= arr[i] * p && l - i + 1> ans)
            ans = l - i + 1;
        */
    }
    cout << ans;
    return 0;
}
