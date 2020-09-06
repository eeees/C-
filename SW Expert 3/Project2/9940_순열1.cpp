#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    vector<int>arr(1000000, 0);
    vector<bool>number(1000000, false);
    int t_case = 0, n = 0, num = 0, cnt = 0;

    cin >> t_case;
    for (int i = 0; i < t_case; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> num;
            arr[j] = num;
        }
        //1~N까지 숫자가 있는지 확인
        for (int k = 0; k < n; k++) {
            for (int x = 1; x <= n; x++) {
                if (arr[k] == x) {
                    if (number[(arr[k] - 1)] == true) {
                        number[(arr[k] - 1)] = false;
                    }
                    else if (number[(arr[k] - 1)] == false) {
                        number[(arr[k] - 1)] = true;
                    }
                    break;
                }
            }
        }
        for (int t = 0; t < n; t++) {
            if (number[t] == false) {
                cout << "#" << i + 1 << " " << "No" << endl;
                break;
            }
            if (t == n - 1) {
                cout << "#" << i + 1 << " " << "Yes" << endl;
            }
        }
        for (int y = 0; y < n; y++) {
            arr[y] = 0;
            number[y] = false;
        }
    }
    return 0;
}