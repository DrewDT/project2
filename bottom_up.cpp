#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){

    int n; // number of denominations
    cin >> n;
    vector<int> denom; // value of denominations
    vector<vector<int>> solutions; // keep track of solutions
    vector<int> temp;

    int val;
    for (int i=0; i<n; i++) {
        cin >> val;
        denom.push_back(val);
        temp.push_back(0);
    }
    temp.push_back(0);
    solutions.push_back(temp);

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++) { // number of sub solutions
        cout << "i: " << i << endl;
        int currDenom = 0;
        int currBestLoc = i-1;
        int currBest = solutions[i-1][n];
        for (int j = 1; j < n; j++) { // number of denominations
            if (i - denom[j] >= 0 && solutions[i - denom[j]][n] < currBest) {
                currBest = solutions [i - denom[j]][n];
                currBestLoc = i - denom[j];
                currDenom = j;
            }
        }
        solutions.push_back(solutions[currBestLoc]);
        solutions[i][currDenom] += 1;
        solutions[i][n] += 1;

        cout << "Subsolution at " << i << ": ";
        for (int j=0; j<n; j++) {
            cout << solutions[i][j] << " ";
        }
        cout << endl;
    }
    cout << k << " cents = ";
    for (int i=n-1; i>=0; i--) {
        if (solutions[k][i] > 0) {
            cout << denom[i] << ":" << solutions[k][i] << " ";
        }
    }
    cout << endl;

	return 0;
}