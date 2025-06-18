#include <iostream>
#include <fstream>

using namespace std;

void flip(int* arr, int i, int k) {
    for (int j = 0; j < k; j++) {
        arr[i + j] = 1 - arr[i + j];
    }
}

int minFlips(int* arr, int n, int k) {
    if (k <= 0 || k > n) return -1;

    int flips = 0;
    for (int i = 0; i <= n - k; i++) {
        if (arr[i] == 0) {
            flip(arr, i, k);
            flips++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            return -1;
    }

    return flips;
}

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int testCaseNum = 1;
    while (!infile.eof()) {
        int n, k;
        infile >> k >> n;

        if (infile.fail()) {
            break;
        }

        if (n <= 0 || k <= 0 || k > n) {
            cout << "Test case " << testCaseNum << ": Invalid n or k values." << endl;

            for (int i = 0; i < n; i++) {
                int skip;
                infile >> skip;
            }
            testCaseNum++;
            continue;
        }

        int* arr = new int[n];
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (!(infile >> arr[i]) || (arr[i] != 0 && arr[i] != 1)) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "Test case " << testCaseNum << ": Invalid array values (must be binary)." << endl;
            delete[] arr;
            for (int j = 0; j < n; j++) {
                int skip;
                infile >> skip;
            }
            testCaseNum++;
            continue;
        }

        int result = minFlips(arr, n, k);
        cout << "Test case " << testCaseNum << ": " << result << endl;

        delete[] arr;
        testCaseNum++;
    }

    infile.close();
    return 0;
}
