// Array Concept Simulation - Interactive Learning Tool
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

class ArraySimulation {
private:
    int arr[MAX_SIZE];
    int size;
    
    // Display array with index
    void displayArray() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "\nCurrent Array:" << endl;
        cout << "Index: ";
        for (int i = 0; i < size; i++) {
            cout << setw(4) << i;
        }
        cout << endl;
        
        cout << "Value: ";
        for (int i = 0; i < size; i++) {
            cout << setw(4) << arr[i];
        }
        cout << endl;
        cout << "Size: " << size << endl;
    }
    
    // Check if index is valid
    bool isValidIndex(int index) {
        return (index >= 0 && index < size);
    }

public:
    ArraySimulation() : size(0) {}
    
    // Insert element at end
    void insertEnd() {
        if (size >= MAX_SIZE) {
            cout << "Error: Array is full!" << endl;
            return;
        }
        
        int value;
        cout << "Enter value to insert: ";
        cin >> value;
        
        arr[size] = value;
        size++;
        cout << "Value inserted at index " << (size - 1) << endl;
        displayArray();
    }
    
    // Insert element at specific position
    void insertAtPosition() {
        if (size >= MAX_SIZE) {
            cout << "Error: Array is full!" << endl;
            return;
        }
        
        int pos, value;
        cout << "Enter position (0 to " << size << "): ";
        cin >> pos;
        
        if (pos < 0 || pos > size) {
            cout << "Error: Invalid position!" << endl;
            return;
        }
        
        cout << "Enter value: ";
        cin >> value;
        
        // Shift elements to the right
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
        
        cout << "Value inserted at index " << pos << endl;
        displayArray();
    }
    
    // Delete element at specific position
    void deleteAtPosition() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        int pos;
        cout << "Enter position to delete (0 to " << (size - 1) << "): ";
        cin >> pos;
        
        if (!isValidIndex(pos)) {
            cout << "Error: Invalid position!" << endl;
            return;
        }
        
        cout << "Deleted value: " << arr[pos] << endl;
        
        // Shift elements to the left
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        
        displayArray();
    }
    
    // Delete from end
    void deleteEnd() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        cout << "Deleted value: " << arr[size - 1] << endl;
        size--;
        
        cout << "Element removed from end" << endl;
        displayArray();
    }
    
    // Search element
    void searchElement() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        int value;
        cout << "Enter value to search: ";
        cin >> value;
        
        bool found = false;
        cout << "\nSearch Results:" << endl;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "  Found at index " << i << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "  Value not found in array!" << endl;
        }
    }
    
    // Access element at index
    void accessElement() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        int index;
        cout << "Enter index (0 to " << (size - 1) << "): ";
        cin >> index;
        
        if (isValidIndex(index)) {
            cout << "Value at index " << index << ": " << arr[index] << endl;
        } else {
            cout << "Error: Index out of bounds!" << endl;
        }
    }
    
    // Update element
    void updateElement() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        int index, value;
        cout << "Enter index to update (0 to " << (size - 1) << "): ";
        cin >> index;
        
        if (!isValidIndex(index)) {
            cout << "Error: Index out of bounds!" << endl;
            return;
        }
        
        cout << "Current value: " << arr[index] << endl;
        cout << "Enter new value: ";
        cin >> value;
        
        arr[index] = value;
        cout << "Value updated successfully!" << endl;
        displayArray();
    }
    
    // Traverse and display
    void traverse() {
        displayArray();
    }
    
    // Sort array
    void sortArray() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        // Bubble sort with visualization
        cout << "\nSorting in ascending order..." << endl;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
            cout << "Pass " << (i + 1) << ": ";
            for (int k = 0; k < size; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        cout << "\nArray sorted successfully!" << endl;
        displayArray();
    }
    
    // Reverse array
    void reverseArray() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        for (int i = 0; i < size / 2; i++) {
            swap(arr[i], arr[size - 1 - i]);
        }
        cout << "Array reversed successfully!" << endl;
        displayArray();
    }
    
    // Get array statistics
    void getStatistics() {
        if (size == 0) {
            cout << "Error: Array is empty!" << endl;
            return;
        }
        
        int sum = 0, maxVal = arr[0], minVal = arr[0];
        double average;
        
        for (int i = 0; i < size; i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
            minVal = min(minVal, arr[i]);
        }
        
        average = (double)sum / size;
        
        cout << "\n--- Array Statistics ---" << endl;
        cout << "Size: " << size << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << fixed << setprecision(2) << average << endl;
        cout << "Maximum: " << maxVal << endl;
        cout << "Minimum: " << minVal << endl;
    }
    
    // Clear array
    void clearArray() {
        size = 0;
        cout << "Array cleared successfully!" << endl;
    }
    
    // Main menu
    void runSimulation() {
        int choice;
        while (true) {
            cout << "\n========== ARRAY SIMULATION ==========" << endl;
            cout << "1. Insert at End" << endl;
            cout << "2. Insert at Position" << endl;
            cout << "3. Delete at Position" << endl;
            cout << "4. Delete from End" << endl;
            cout << "5. Search Element" << endl;
            cout << "6. Access Element" << endl;
            cout << "7. Update Element" << endl;
            cout << "8. Traverse (Display)" << endl;
            cout << "9. Sort Array" << endl;
            cout << "10. Reverse Array" << endl;
            cout << "11. Get Statistics" << endl;
            cout << "12. Clear Array" << endl;
            cout << "13. Exit" << endl;
            cout << "=====================================" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch(choice) {
                case 1:
                    insertEnd();
                    break;
                case 2:
                    insertAtPosition();
                    break;
                case 3:
                    deleteAtPosition();
                    break;
                case 4:
                    deleteEnd();
                    break;
                case 5:
                    searchElement();
                    break;
                case 6:
                    accessElement();
                    break;
                case 7:
                    updateElement();
                    break;
                case 8:
                    traverse();
                    break;
                case 9:
                    sortArray();
                    break;
                case 10:
                    reverseArray();
                    break;
                case 11:
                    getStatistics();
                    break;
                case 12:
                    clearArray();
                    break;
                case 13:
                    cout << "Thank you for using Array Simulation!" << endl;
                    return;
                default:
                    cout << "Error: Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main() {
    cout << "\n" << endl;
    cout << "   ARRAY CONCEPT SIMULATION TOOL   " << endl;
    cout << "   Learn Array Operations Visually   " << endl;
    cout << "\n" << endl;
    
    ArraySimulation sim;
    sim.runSimulation();
    
    return 0;
}
