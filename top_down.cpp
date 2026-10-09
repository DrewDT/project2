/*
Names: Jacob Milne and Andrew Thomson
Date: 10/9/2026
Description: This program takes in a list of denominations and a list of values to make change for. 
It then uses top-down dynamic programming without memoization to find the optimal way to make change for each value using the given denominations.
The program outputs the number of each denomination used to make change for each value.
*/

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