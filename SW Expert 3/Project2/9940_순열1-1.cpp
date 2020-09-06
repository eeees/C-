#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>arr(1000000, 0);
    vector<bool>valid(1000000, false);
    int t_case = 0, n = 0,num=0;
    
    cin >> t_case;
    for (int i = 0; i < t_case; i++) {

       
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        for (int k = 0; k < n; k++) {
            valid[arr[k] - 1] = true;
        }
        for (int k = 0; k < n; k++) {
            if (valid[k] == false) {
                cout << "#" << i + 1 << " " << "No" << endl;
                break;
            }
            num = k;
        }
        if (num == n - 1) {
            cout << "#" << i + 1 << " " << "Yes" << endl;
        }
        for (int k = 0; k < n; k++) {
            arr[k] = 0;
            valid[k] = false;
        }
    }
    return 0;
}