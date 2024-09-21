#include <iostream>
#include <set>

// Function to reverse the order of elements in an array (Task #1)
void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to copy an array in reverse order (Task #2)
void copyReverse(int* source, int* destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[size - i - 1];
    }
}

// Function to find elements of array A that are not included in array B (Task #3)
void uniqueElements(int* A, int M, int* B, int N) {
    std::set<int> setA(A, A + M);
    std::set<int> setB(B, B + N);
    std::set<int> resultSet;

    for (auto elem : setA) {
        if (setB.find(elem) == setB.end()) {
            resultSet.insert(elem);
        }
    }

    std::cout << "Elements of array A that are not in array B: ";
    for (auto elem : resultSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Task #1: Reverse the order of elements in an array
    std::cout << "Task #1: Reverse the order of elements in an array\n";
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);
    std::cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Task #2: Copy an array in reverse order
    std::cout << "\nTask #2: Copy an array in reverse order\n";
    int source[] = { 10, 20, 30, 40, 50 };
    int destination[sizeof(source) / sizeof(source[0])];
    int srcSize = sizeof(source) / sizeof(source[0]);

    copyReverse(source, destination, srcSize);
    std::cout << "Copied array in reverse order: ";
    for (int i = 0; i < srcSize; i++) {
        std::cout << destination[i] << " ";
    }
    std::cout << std::endl;

    // Task #3: Create a third array with elements from A that are not in B
    std::cout << "\nTask #3: Create an array with unique elements from A\n";
    int M, N;

    std::cout << "Enter the size of array A: ";
    std::cin >> M;

    if (M <= 0) {
        std::cout << "The size of array A must be greater than 0.\n";
        return 1;
    }

    int* A = new int[M];
    std::cout << "Enter the elements of array A: ";
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::cout << "Enter the size of array B: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "The size of array B must be greater than 0.\n";
        delete[] A;
        return 1;
    }

    int* B = new int[N];
    std::cout << "Enter the elements of array B: ";
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    uniqueElements(A, M, B, N);

    // Clean up memory
    delete[] A;
    delete[] B;

    return 0;
}
