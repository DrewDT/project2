#include <iostream>
#include <vector>

using namespace std;

void print(){ 
    
}

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
    vector<int> changeFor;
    for (int i=0; i<k; i++) {
        int t;
        cin >> t;
        changeFor.push_back(t);
    }

    int furthest = 1;

    for (int h=0; h<k; h++) {
        int change = changeFor[h];
        if (change < furthest) {
            std::cout << change << " cents =";
            for (int i=n-1; i>=0; i--) {
                if (solutions[change][i] > 0) {
                    std::cout << " " << denom[i] << ":" << solutions[change][i];
                }
            }
            std::cout << endl;            
        }
        else {
            for (int i = furthest; i <= change; i++) { // number of sub solutions
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
            }
            std::cout << change << " cents =";
            for (int i=n-1; i>=0; i--) {
                if (solutions[change][i] > 0) {
                    std::cout << " " << denom[i] << ":" << solutions[change][i];
                }
            }
            std::cout << endl;      
            furthest = change + 1;      
        }
    }

    

	return 0;
}