#include <iostream>
#include <vector>

using namespace std;

int LLIS(vector<int> sequence, int n);

int main() {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    /*
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(8);
     */

    cout << LLIS(arr, arr.size()) << endl;
    return 0;
}

int LLIS(vector<int> sequence, int n) {

    vector<vector<int> > L(n);
    L[0].push_back(sequence.at(0));
    int maxLen = 1, maxIndex = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence.at(j) < sequence.at(i) and L.at(i).size() < L.at(j).size()) {
                L[i] = L[j];
            }
        }
        L[i].push_back(sequence[i]);
        if (maxLen < L[i].size())
            maxLen = L[i].size();
        maxIndex = i;
    }

    vector<int> max = L[maxIndex];

    for (int x : max)
        cout << x << " ";
    cout << endl;

    return maxLen;
}