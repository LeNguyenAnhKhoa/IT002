#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Counts the number of occurrences of array A in array B
 * 
 * @param A The array to search for (needle)
 * @param B The array to search in (haystack)
 * @return int The number of occurrences of A in B
 * 
 * Input:
 *   A: A vector of integers representing the sequence to search for
 *   B: A vector of integers representing the sequence to search in
 * 
 * Output:
 *   Returns an integer representing the number of times A appears as a contiguous subsequence in B
 * 
 * Example:
 *   If A = [1, 2, 3] and B = [1, 2, 3, 1, 2, 3, 4, 5], the function will return 2
 *   because [1, 2, 3] appears twice in B.
 */
int countOccurrences(const vector<int>& A, const vector<int>& B) {
    int count = 0;  // Counter for occurrences
    int n = A.size();  // Length of array A
    int m = B.size();  // Length of array B

    // Iterate through all possible starting positions in B
    for (int i = 0; i <= m - n; i++) {
        bool match = true;  // Flag to check if current subsequence matches A

        // Compare elements of A with corresponding elements in B
        for (int j = 0; j < n; j++) {
            if (B[i + j] != A[j]) {
                match = false;  // Mismatch found
                break;  // Exit inner loop
            }
        }

        // If all elements match, increment the counter
        if (match) {
            count++;
        }
    }

    return count;  // Return total number of occurrences
}

/**
 * @brief Inputs an array from the keyboard
 * 
 * @param arrayName Name of the array (for display purposes)
 * @return vector<int> The input array
 * 
 * Input:
 *   User inputs the size of the array and then its elements via the console
 * 
 * Output:
 *   Returns a vector of integers containing the input elements
 */
vector<int> inputArray(const string& arrayName) {
    int size;
    cout << "Enter the size of array " << arrayName << ": ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter " << size << " elements for array " << arrayName << ":" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    return arr;
}

/**
 * @brief Main function to run the program
 * 
 * Input:
 *   User inputs two arrays A and B via the console
 * 
 * Output:
 *   Prints the number of occurrences of array A in array B
 */
int main() {
    // Input array A
    vector<int> A = inputArray("A");

    // Input array B
    vector<int> B = inputArray("B");

    // Call the function and store the result
    int result = countOccurrences(A, B);

    // Print the result
    cout << "Number of occurrences: " << result << endl;

    return 0;
}
