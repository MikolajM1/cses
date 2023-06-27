//
//  main.cpp
//  Coin Combinations I
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
    for (int i = 1; i<x+1; i++) {
        for (int j = 0; j<n; j++) {
            if (i - c[j] >= 0) {
                v[i] += v[i-c[j]] % MOD;
            }
        }
    }
    cout << v[x] % MOD << endl;
    return 0;
}
