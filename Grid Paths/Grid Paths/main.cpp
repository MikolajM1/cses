//
//  main.cpp
//  Grid Paths
//
//  Created by Mikołaj Małysz on 03/07/2023.
//

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int main(int argc, const char * argv[]) {
    int n = 0;
    char temp = '.';
    cin >> n;
    vector<vector<int>> v = {};
    for (int i = 0; i<n; i++) {
        v.push_back({});
        for (int j = 0; j<n; j++) {
            cin >> temp;
            if (i == 0 && j == 0 && temp != '*') {
                v[i].push_back(1);
            } else {
                v[i].push_back(0);
            }
            if (temp == '.') {
                if (i-1 >= 0) {
                    v[i][j] += v[i-1][j] % MOD;
                }
                if (j-1 >= 0) {
                    v[i][j] += v[i][j-1] % MOD;
                }
            }
        }
    }
    cout << v[n-1][n-1] % MOD << endl;
    return 0;
}
