#include <iostream>
#include <vector>

using namespace std;

// Function to check if all processes can finish
bool isSafe(vector<vector<int>>& max, vector<vector<int>>& allocation, vector<int>& available) {
    int n = max.size(); // Number of processes
    int m = available.size(); // Number of resources

    vector<int> work = available;
    vector<bool> finish(n, false);

    while (true) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; ++j) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; ++j) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < n; ++i) {
        if (!finish[i]) return false;
    }
    return true;
}

int main() {
    int n, m; // Number of processes and resources

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resource types: ";
    cin >> m;

    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> allocation(n, vector<int>(m));
    vector<int> available(m);

    cout << "Enter the max matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> max[i][j];
        }
    }

    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the available resources:\n";
    for (int i = 0; i < m; ++i) {
        cin >> available[i];
    }

    if (isSafe(max, allocation, available)) {
        cout << "The system is in a safe state.\n";
    } else {
        cout << "The system is not in a safe state. Deadlock might occur.\n";
    }

    return 0;
}
