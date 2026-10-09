#include <iostream>
#include <vector>

using namespace std;

int n; // number of denominations
vector<int> denom; // value of denominations
vector<int> final;

vector<vector<int>> savedSolutions;

vector<int> solution(int value, vector<int> curr) {
    vector<int> best;
    if (savedSolutions.size() > value && savedSolutions[value].size() > 0) {
        return savedSolutions[value];
    }
    for (int i = n-1; i >=0; i--) {
        int temp = denom[i];
        vector<int> temp_curr = curr;
        temp_curr.push_back(temp);
        if (value-temp == 0) {
            savedSolutions[value] = temp_curr;
            cout << "saved solution for " << value << endl;
            return temp_curr;
        }
        else if (value-temp > 0) {
            vector<int> temp_best = solution(value-temp, temp_curr);
            if (temp_best.size() < best.size() || best.size() == 0) {
                best = temp_best;
            }
        }
    }
    savedSolutions[value] = best;
    cout << "saved solution for " << value << endl;
    return best;
}


int main() {
    cin >> n;
    int val;
    for (int i=0; i<n; i++) {
        cin >> val;
        denom.push_back(val);
    }

    int k;
    cin >> k;
    vector<int> changeFor;
    for (int i=0; i<k; i++) {
        int t;
        cin >> t;
        changeFor.push_back(t);
        if (savedSolutions.size() <= t) {
            savedSolutions.resize(t + 1);
        }
    }
   

    for (int i = 0; i<k; i++) {
        vector<int> empty;
        final = solution(changeFor[i], empty);
        std::cout << changeFor[i] << " cents =";
        for (int j=n-1; j>=0; j--) {
            int count = 0;
            for (int k=0; k<final.size(); k++) {
                if (final[k] == denom[j]) {
                    count++;
                }
            }
            if (count > 0) {
                std::cout << " " << denom[j] << ":" << count;
            }
        }
        cout << endl;
    }     
    return 0;
}