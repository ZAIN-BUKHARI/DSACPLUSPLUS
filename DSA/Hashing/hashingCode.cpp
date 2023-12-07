#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

// HashNode represents a key-value pair in the hashmap
template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;

    HashNode(const K& key, const V& value) : key(key), value(value) {}
};

// Hashmap class with separate chaining
template <typename K, typename V>
class HashMap {
private:
    static const int TABLE_SIZE = 10;  // Size of the hashmap array
    list<HashNode<K, V>> table[10];

    // Hash function to map keys to indices
    int hashFunction(const K& key) const {
        // This is a simple example; in practice, you'd use a more robust hash function
        return key% TABLE_SIZE;
    }

public:
    // Insert a key-value pair into the hashmap
    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
    }

    // Retrieve the value associated with a key
    // V get(const K& key) const {
    //     int index = hashFunction(key);

    //     // Iterate through the list at the calculated index
    //     for (const auto& node : table[index]) {
    //         if (node.key == key) {
    //             return node.value;
    //         }
    //     }

    //     // Key not found
    //     throw out_of_range("Key not found");
    // }

    // // Remove a key-value pair from the hashmap
    // void remove(const K& key) {
    //     int index = hashFunction(key);

    //     // Use erase-remove idiom to remove the node with the specified key
    //     table[index].remove_if([key](const HashNode<K, V>& node) { return node.key == key; });
    // }

    // Print the contents of the hashmap
    // void print() const {
    //     for (int i = 0; i < TABLE_SIZE; ++i) {
    //         cout << "Bucket " << i << ": ";
    //         copy(table[i].begin(), table[i].end(), ostream_iterator<HashNode<K, V>>(cout, " "));
    //         cout << endl;
    //     }
    // }
};

int main() {
    HashMap<string, int> myHashMap;

    myHashMap.insert("one", 1);
    myHashMap.insert("two", 2);
    myHashMap.insert("three", 3);

    // myHashMap.print();


    return 0;
}
