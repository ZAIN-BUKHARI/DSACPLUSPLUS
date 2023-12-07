#include <iostream>
#include <string>
using namespace std;


struct Node {
    int key;
    int value;
    Node* next;

    Node(int key, int value) {
        this->key=key;
        this->value=value;
        next=NULL;
    }
};

class HashMap {
private:
    int TableSize = 10;
    Node* table;

    int hashFunction(int key)  {
        return key % TableSize;
    }

public:
    // HashMap() {
    //     for (int i = 0; i < TableSize; ++i) {
    //         table[i] = NULL;
    //     }
    // }

    // Destructor
    // ~HashMap() {
    //     // Release allocated memory
    //     for (int i = 0; i < TableSize; ++i) {
    //         Node<int, char>* current = table[i];
    //         while (current != NULL) {
    //             Node<int, char>* next = current->next;
    //             delete current;
    //             current = next;
    //         }
    //     }
    // }

    // Insert a key-value pair into the hashmap
    // void insert(int key, char value) {
    //     int index = hashFunction(key);
    //     Node<int, char>* newNode = new Node<int, char>(key, value);

    //     // Insert at the beginning (front) of the linked list at the calculated index
    //     newNode->next = table[index];
    //     table[index] = newNode;
    // }

    // Retrieve the value associated with a key
//     char get(int key)  {
//         int index = hashFunction(key);

//         // Iterate through the linked list at the calculated index
//         Node<int, char>* current = table[index];
//         while (current != NULL) {
//             if (current->key == key) {
//                 return current->value;
//             }
//             current = current->next;
//         }

//         // Key not found
//         throw std::out_of_range("Key not found");

// }
};

int main()
{
    // HashMap map;

    return 0;
}