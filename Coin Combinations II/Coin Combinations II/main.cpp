//
//  main.cpp
//  Coin Combinations II
//
//  Created by Mikołaj Małysz on 27/06/2023.
//

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int main(int argc, const char * argv[]) {
    int n, x = 0;
    cin >> n >> x;
    vector<int> c(n, 0);
    for (int i = 0; i<n; i++) {
        cin >> c[i];
    }
    vector<long long> v(x+1, 0);
    v[0] = 1;
    for (int i = 0; i<n; i++) {
        for (int j = 1; j<x+1; j++) {
            if (j - c[i] >= 0) {
                v[j] += v[j-c[i]] % MOD;
            }
        }
    }
    cout << v[x] % MOD << endl;
    return 0;
}
