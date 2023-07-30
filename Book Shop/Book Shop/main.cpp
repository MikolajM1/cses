//
//  main.cpp
//  Book Shop
//
//  Created by Mikołaj Małysz on 03/07/2023.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, x = 0;
    cin >> n >> x;
    vector<int> prices(n+1, 0);
    for (int i = 1; i<n+1; i++) {
        cin >> prices[i];
    }
    vector<int> pages(n+1, 0);
    for (int i = 1; i<n+1; i++) {
        cin >> pages[i];
    }
    vector<vector<int>> DP(n+1, vector<int>(x+1, 0));
    for (int i = 1; i<n+1; i++) {
        for (int j = 1; j<x+1; j++) {
            if (prices[i] > j) {
                DP[i][j] = DP[i-1][j];
            } else {
                DP[i][j] = max(pages[i]+DP[i-1][j-prices[i]], DP[i-1][j]);
            }
        }
    }
    cout << DP[n][x] << endl;
    return 0;
}
