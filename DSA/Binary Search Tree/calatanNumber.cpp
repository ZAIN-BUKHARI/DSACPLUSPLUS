#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Catalan number
unsigned long long catalanNumber(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    unsigned long long catalan = 1;
    for (int i = 0; i < n; ++i) {
        catalan = catalan * 2 * (2 * i + 1) / (i + 2);
      
    }
//1
    return catalan;
}

// Function to calculate the number of unique BSTs using n nodes
unsigned long long countBSTs(int n) {
    return catalanNumber(n);
}

int main() {
    int n;

    // Input the value of n
    cout << "Enter the value of n: ";
    cin >> n;

    // Calculate and display the nth Catalan number
    cout << "Catalan number C(" << n << ") = " << catalanNumber(n) << endl;

    // Calculate and display the number of unique BSTs using n nodes
    cout << "Number of unique BSTs with " << n << " nodes = " << countBSTs(n) << endl;

    return 0;
}
