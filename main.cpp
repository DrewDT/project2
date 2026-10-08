#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){

    int n; // number of denominations
    cin >> n;
    vector<int> denom; // value of denominations
    vector<vector<int>/* vec(n, 0)*/> solutions; // keep track of solutions
    vector<int> temp;

    for (int i=0; i<n; i++) {
        cin >> denom.push_back();
        temp.push_back(0);
    }
    temp.push_back(0);
    solutions.push_back(temp);

    cin >> k;

    for (int i = 1; i < k; i++) { // number of sub solutions
        int currDenom = 0;
        int currBestLoc = i-1;
        int currBest = solutions[i-1][n];
        for (int j = 1; j < n; j++) { // number of denominations
            if (i - denoms[j] >= 0 && solutions[i - denoms[j]][n] < currBest) {
                currBest = solutions [i][n];
                currBestLoc = i - denoms[j];
                currDenom = denoms[j];
            }
        }
        solutions.push_back(solutions[currBestLoc]);
        solutions[i][currDenom] += 1;
        solutions[i][n] += 1;
    }

    for (int i=0; i<n; i++) {
        cout << denoms[i] << ": " << solutions[k][i] << endl;
    }

	return 0;
}