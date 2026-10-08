#include <iostream>
#include <vector>

using namespace std;

int n; // number of denominations
vector<int> denom; // value of denominations
vector<int> final;

vector<int> solution(int value, vector<int> curr) {
    vector<int> best;
    for (int i = n-1; i >=0; i--) {
        int temp = denom[i];
        vector<int> temp_curr = curr;
        temp_curr.push_back(temp);
        //cout << "Temp curr:";
        //for (int j = 0; j < temp_curr.size(); j++) {
        //    cout << temp_curr[j] << " ";
        //}
        if (value-temp == 0) {
            return temp_curr;
        }
        else if (value-temp > 0) {
            vector<int> temp_best = solution(value-temp, temp_curr);
            if (temp_best.size() < best.size() || best.size() == 0) {
                best = temp_best;
            }
        }
    }
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
    }

    vector<int> empty;
    final = solution(changeFor[0], empty);

    cout << "The best solution for " << changeFor[0] << " is: ";
    for (int i=0; i<final.size(); i++) {
        cout << final[i] << " ";
    }
    cout << endl;
    return 0;
}