#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<list<pair<int,string>>> table;
    size_t size;

    // Hash function to map keys to indices
    size_t hashFunction(int key) const {
        return key % size;
    }

public:
    HashTable(size_t tableSize) : size(tableSize), table(tableSize) {}

    // Insert a key-value pair into the hash table
    void insert(int key, const string& value) {
        size_t index = hashFunction(key);

        // Check if the key already exists in the list at the computed index
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                std::cout << "Key " << key << " already exists. Cannot insert duplicate keys." << std::endl;
                return;
            }
        }

        // If not, insert the new key-value pair at the end of the list
        table[index].emplace_back(key, value);
    }

    // Search for a key in the hash table and return its value
    std::string search(int key) const {
        size_t index = hashFunction(key);

        // Search for the key in the list at the computed index
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return entry.second;
            }
        }

        return "Key not found";
    }

    // Remove a key from the hash table
    void remove(int key) {
        size_t index = hashFunction(key);

        // Search for the key in the list at the computed index
        auto& entries = table[index];
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->first == key) {
                entries.erase(it);
                std::cout << "Key " << key << " removed successfully." << std::endl;
                return;
            }
        }

        std::cout << "Key " << key << " not found. Cannot remove." << std::endl;
    }
};

int main() {
    // Example usage of the HashTable class
    HashTable hashTable(10);

    hashTable.insert(1, "Alice");
    hashTable.insert(2, "Bob");
    hashTable.insert(11, "Charlie");
    hashTable.insert(21, "David");

    std::cout << "Search for key 2: " << hashTable.search(2) << std::endl;
    std::cout << "Search for key 5: " << hashTable.search(5) << std::endl;

    hashTable.remove(2);
    hashTable.remove(5);

    return 0;
}
