#include <iostream>
#include <string>

// Node represents a key-value pair in the hashmap
template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;

    Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

// Hashmap class with separate chaining
template <typename K, typename V, size_t TableSize>
class HashMap {
private:
    Node<K, V>* table[TableSize];

    // Hash function to map keys to indices
    size_t hashFunction(const K& key) const {
        // This is a simple example; in practice, you'd use a more robust hash function
        return std::hash<K>{}(key) % TableSize;
    }

public:
    // Constructor
    HashMap() {
        // Initialize the table
        for (size_t i = 0; i < TableSize; ++i) {
            table[i] = nullptr;
        }
    }

    // Destructor
    ~HashMap() {
        // Release allocated memory
        for (size_t i = 0; i < TableSize; ++i) {
            Node<K, V>* current = table[i];
            while (current != nullptr) {
                Node<K, V>* next = current->next;
                delete current;
                current = next;
            }
        }
    }

    // Insert a key-value pair into the hashmap
    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key);
        Node<K, V>* newNode = new Node<K, V>(key, value);

        // Insert at the beginning (front) of the linked list at the calculated index
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Retrieve the value associated with a key
    V get(const K& key) const {
        size_t index = hashFunction(key);

        // Iterate through the linked list at the calculated index
        Node<K, V>* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        // Key not found
        throw std::out_of_range("Key not found");
