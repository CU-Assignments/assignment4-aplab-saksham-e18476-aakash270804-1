#include <iostream>
#include <vector>

using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> res = {1};
    while (res.size() < n) {
        vector<int> temp;
        for (int num : res) {
            if (num * 2 - 1 <= n) temp.push_back(num * 2 - 1);
        }
        for (int num : res) {
            if (num * 2 <= n) temp.push_back(num * 2);
        }
        res = temp;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = beautifulArray(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
