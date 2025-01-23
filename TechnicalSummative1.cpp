#include <iostream>
using namespace std;

void menu();
void display(int array1[], int currentSize);
void insert(int array1[], int& currentSize);
void deleteElement(int array1[], int& currentSize);

// constant variable for maximum array size
const int MAXIMUMSIZE = 20;

// array
int array1[MAXIMUMSIZE] = { 1, 2, 3, 4, 5 };

// menu
void menu() {
    cout
        << "-------------------------\n"
        << "Menu:\n"
        << "    [1] Display Elements\n"
        << "    [2] Insert Elements\n"
        << "    [3] Delete Elements\n"
        << "    [4] Swap Elements\n"
        << "    [5] Reverse Array\n"
        << "    [6] Find Element\n"
        << "    [7] Exit\n"
        << "-------------------------";
}

// display elements
void display(int array1[], int currentSize) {
    for (int i = 0; i < currentSize; i++) {
        cout << array1[i] << "\n";
    }
}

// insert element
void insert(int array1[], int& currentSize) {
    int userValue, index;

    // check if the array exceeds the maximum size
    if (currentSize >= MAXIMUMSIZE) {
        cout << "The array is already full. Cannot insert a new element.\n";
        return;
    }

    // user inputs value
    cout << "\nEnter the value you want to insert.\n> ";
    cin >> userValue;

    // user inputs index
    cout << "\nEnter index (0 to " << currentSize << ").\n> ";
    cin >> index;

    // check if index is valid (user index limit should be next to the last index)
    if (index < 0 || index > currentSize) {
        cout << "Invalid position. Please enter an index between 0 and " << currentSize << ".\n";
        return;
    }

    // decrement for 0 index
    for (int i = currentSize; i > index; i--) {
        array1[i] = array1[i - 1];
    }

    // insert element
    array1[index] = userValue;
    currentSize++;

    cout << "Element inserted successfully.\n";
    
    // display the current array
    display(array1, currentSize);
}

// delete
void deleteElement(int array1[], int& currentSize) {
    int userIndex;

    // check if array is empty
    if (currentSize <= 0) {
        cout << "Array is empty. Cannot delete element.\n";
        return;
    }

    // display the array
    cout << "\nArray:\n";
    display(array1, currentSize);

    // user input
    cout << "\nEnter position of the index to delete (0 to " << currentSize - 1 << ").\n> ";
    cin >> userIndex;

    // index should not be less than 0 and greater than the current array size
    if (userIndex < 0 || userIndex >= currentSize) {
        cout << "Invalid index. Please enter an index between 0 and " << currentSize - 1 << ".\n";
        return;
    }

    // loop continues as long as user index is less than current size
    for (int i = userIndex; i < currentSize - 1; i++) {
        array1[i] = array1[i + 1];
    }

    currentSize--;

    cout << "Element deleted successfully.\n";
    display(array1, currentSize);
}

void swap(int array1[], int& currentSize) {

}

int main() {
    int userChoice;
    int currentSize = 5;

    while (true) {
        menu();
        cout << "\nEnter your choice\n> ";
        cin >> userChoice;

        switch (userChoice) {
        case 1:
            display(array1, currentSize);
            break;
        case 2:
            insert(array1, currentSize);
            break;
        case 3:
            deleteElement(array1, currentSize);
            break;
        case 7:
            cout << "Exit";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}