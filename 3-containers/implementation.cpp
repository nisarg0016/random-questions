#include <iostream>
#include <vector>
using std::cout, std::cin, std::vector;

int find (vector<vector<int>> visited, vector<int> inp) {
    for (auto i: visited) {
        if (i[0] == inp[0] && i[1] == inp[1] && i[2] == inp[2]) return 1;
    }
    return -1;
}

void pour(vector<int> arr, vector<int> max, int from, int to, int target, vector<int> steps, vector<int>& stepsMin, vector<vector<int>>& visited) {
    if (target == arr[0] || target == arr[1] || target == arr[2]) {
        if (steps.size() < stepsMin.size() || stepsMin.empty()) {
            int i = 0;
            stepsMin.clear();
            while (i < steps.size()) {
                stepsMin.push_back(steps[i]);
                i++;
            }
        }
        return;
    }
    if (arr[from] == 0 || arr[to] == max[to]) return;
    vector<int> nArr(3, 0);
    nArr[to] = (arr[from] + arr[to] >= max[to]) ? max[to] : arr[from] + arr[to];
    nArr[from] = arr[from] - (nArr[to] - arr[to]);
    nArr[3 - to - from] = arr[3 - to - from];
    if (find(visited, nArr) != -1) return;
    visited.push_back(nArr);
    steps.push_back(from*10 + to);
    pour(nArr, max, 0, 1, target, steps, stepsMin, visited);
    pour(nArr, max, 0, 2, target, steps, stepsMin, visited);
    pour(nArr, max, 1, 0, target, steps, stepsMin, visited);
    pour(nArr, max, 1, 2, target, steps, stepsMin, visited);
    pour(nArr, max, 2, 1, target, steps, stepsMin, visited);
    pour(nArr, max, 2, 0, target, steps, stepsMin, visited);
    return;
}

int main() {
    int A, n;
    cout << "Enter A and n: ";
    cin >> A >> n;
    vector<int> arr = {4*n+4, 0, 0};
    vector<int> max = {4*n+4, 2*n+3, 2*n+1};
    vector<int> steps, stepsMin;
    vector<vector<int>> visited;
    pour(arr, max, 0, 1, A, steps, stepsMin, visited);
    visited.clear();
    pour(arr, max, 0, 2, A, steps, stepsMin, visited);
    cout << "The number of steps required are: " << stepsMin.size() << '\n';
    for (int i = 0; i < stepsMin.size(); i++) {
        cout << max[stepsMin[i]/10] << "==>" << max[stepsMin[i]%10] << '\n';
    }
    return 0;
}
