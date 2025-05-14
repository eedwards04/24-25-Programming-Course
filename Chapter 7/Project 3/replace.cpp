#include <iostream>

using namespace std;

void delete_repeats(char arr[], int &size);


int main() {
    char a[10] = {'a', 'b', 'a', 'c', 'a', 'd', 'e', 'f', 'e', 'f'};
    int size = 10;

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete_repeats(a, size);

    cout << "Array after deleting repeats: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\nNew size: " << size << endl;

    return 0;
}

void delete_repeats(char arr[], int &size) {
    int newSize = 0; 

    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < newSize; j++) {  // Check if arr[i] exists in arr[0] to arr[newSize-1]
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {  // If not a duplicate, keep it and move newSize forward
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    size = newSize; // Update size to reflect unique elements
}

