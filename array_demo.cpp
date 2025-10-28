// Array and Linked List Demonstration in C++
// This program shows basic operations on arrays and simple linked lists

#include <iostream>
using namespace std;

// ========== ARRAY OPERATIONS ==========

/**
 * Display all elements in an array
 * @param arr - Array to display
 * @param size - Size of the array
 */
void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Insert an element at a specific position in an array
 * @param arr - Array to insert into
 * @param size - Current size of array (will be incremented)
 * @param pos - Position to insert at (0-based index)
 * @param value - Value to insert
 */
void insertInArray(int arr[], int &size, int pos, int value) {
    // Check if position is valid
    if (pos < 0 || pos > size) {
        cout << "✗ Invalid position!" << endl;
        return;
    }
    
    // Shift elements to the right to make space
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[pos] = value;
    size++;
    cout << "✓ Inserted " << value << " at position " << pos << endl;
}

/**
 * Delete an element at a specific position in an array
 * @param arr - Array to delete from
 * @param size - Current size of array (will be decremented)
 * @param pos - Position to delete at (0-based index)
 */
void deleteFromArray(int arr[], int &size, int pos) {
    // Check if position is valid
    if (pos < 0 || pos >= size) {
        cout << "✗ Invalid position!" << endl;
        return;
    }
    
    int deletedValue = arr[pos];
    
    // Shift elements to the left to fill the gap
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    size--;
    cout << "✓ Deleted " << deletedValue << " from position " << pos << endl;
}

// ========== LINKED LIST OPERATIONS ==========

/**
 * Node structure for linked list
 * Each node contains data and a pointer to the next node
 */
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    
    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;  // Initialize next pointer to null
    }
};

/**
 * Display all elements in a linked list
 * @param head - Pointer to the first node of the list
 */
void displayList(Node* head) {
    cout << "Linked List: ";
    Node* current = head;
    
    // Traverse the list until we reach the end (nullptr)
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

/**
 * Insert a new node at the beginning of the linked list
 * @param head - Reference to the head pointer (will be modified)
 * @param value - Value to insert
 */
void insertAtBeginning(Node*& head, int value) {
    // Create a new node
    Node* newNode = new Node(value);
    
    // Make new node point to current head
    newNode->next = head;
    
    // Update head to point to new node
    head = newNode;
    
    cout << "✓ Inserted " << value << " at beginning" << endl;
}

/**
 * Insert a new node at the end of the linked list
 * @param head - Reference to the head pointer
 * @param value - Value to insert
 */
void insertAtEnd(Node*& head, int value) {
    // Create a new node
    Node* newNode = new Node(value);
    
    // If list is empty, make new node the head
    if (head == nullptr) {
        head = newNode;
        cout << "✓ Inserted " << value << " as first element" << endl;
        return;
    }
    
    // Traverse to the last node
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    // Add new node at the end
    current->next = newNode;
    cout << "✓ Inserted " << value << " at end" << endl;
}

/**
 * Delete a node with a specific value from the linked list
 * @param head - Reference to the head pointer (may be modified)
 * @param value - Value to delete
 */
void deleteNode(Node*& head, int value) {
    // Check if list is empty
    if (head == nullptr) {
        cout << "✗ List is empty!" << endl;
        return;
    }
    
    // If head node contains the value
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "✓ Deleted " << value << " from list" << endl;
        return;
    }
    
    // Search for the node with the value
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    // If value was found
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "✓ Deleted " << value << " from list" << endl;
    } else {
        cout << "✗ Value " << value << " not found in list" << endl;
    }
}

/**
 * Free all memory used by the linked list
 * @param head - Reference to the head pointer
 */
void deleteList(Node*& head) {
    Node* current = head;
    Node* next;
    
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
    cout << "✓ Deleted entire list" << endl;
}

// ========== MAIN FUNCTION - DEMO ==========

int main() {
    cout << "\n📊 Array and Linked List Demo\n" << endl;
    
    // ===== ARRAY DEMONSTRATION =====
    cout << "===== ARRAY OPERATIONS =====\n" << endl;
    
    // Initialize an array with some values
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;  // Current number of elements
    
    cout << "Initial array:" << endl;
    displayArray(arr, size);
    
    // Insert elements
    cout << "\nInserting 25 at position 2:" << endl;
    insertInArray(arr, size, 2, 25);
    displayArray(arr, size);
    
    cout << "\nInserting 5 at position 0:" << endl;
    insertInArray(arr, size, 0, 5);
    displayArray(arr, size);
    
    // Delete elements
    cout << "\nDeleting element at position 3:" << endl;
    deleteFromArray(arr, size, 3);
    displayArray(arr, size);
    
    // ===== LINKED LIST DEMONSTRATION =====
    cout << "\n===== LINKED LIST OPERATIONS =====\n" << endl;
    
    // Create an empty linked list
    Node* head = nullptr;
    
    // Insert elements
    cout << "Building the list:" << endl;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    displayList(head);
    
    cout << "\nInserting at beginning:" << endl;
    insertAtBeginning(head, 5);
    displayList(head);
    
    cout << "\nInserting at end:" << endl;
    insertAtEnd(head, 40);
    displayList(head);
    
    // Delete elements
    cout << "\nDeleting node with value 20:" << endl;
    deleteNode(head, 20);
    displayList(head);
    
    cout << "\nDeleting node with value 5:" << endl;
    deleteNode(head, 5);
    displayList(head);
    
    // Clean up memory
    cout << "\nCleaning up:" << endl;
    deleteList(head);
    
    cout << "\n✨ Demo completed!\n" << endl;
    cout << "💡 Tip: Arrays provide O(1) access but O(n) insertion/deletion." << endl;
    cout << "   Linked lists provide O(1) insertion/deletion at head but O(n) access.\n" << endl;
    
    return 0;
}
