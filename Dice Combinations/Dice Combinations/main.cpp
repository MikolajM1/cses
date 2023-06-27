//
//  main.cpp
//  Dice Combinations
//
//  Created by Mikołaj Małysz on 26/06/2023.
//

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main(int argc, const char * argv[]) {
    int n = 0;
    cin >> n;
    vector<long long> v(n+1, 0);
    v[1] = 1;
    for (int i = 2; i<n+1; i++) {
        if (i < 7) {
            v[i]++;
        }
        for (int j = 1; j<7; j++) {
            if (i-j < 1) {
                break;
            }
            v[i] += v[i-j] % MOD;
        }
    }
    cout << v[n] % MOD << endl;
    return 0;
}
