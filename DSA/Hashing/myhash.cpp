#include <iostream>
#include <list>
using namespace std;

class HasdNode{
    public:
    int key;
    char value;

    HashNode(int key,char value)
    {
        this->key=key;
        this->value=value;
    }
};

class HashMap{
    private:
        list<HasdNode<int,char>> table[10];

        int hashFunction(int key) const {
            return key % TABLE_SIZE;
    }

    public:
        void insert( int key, char value) {
            int index = hashFunction(key);
            table[index].emplace_back(key, value);
        }

        // void print()  {
        //     for (int i = 0; i < 10; ++i) {
        //         cout << "Bucket " << i << ": ";
        //         copy(table[i].begin(), table[i].end(), ostream_iterator<HashNode<K, V>>(cout, " "));
        //         cout << endl;
        //     }
    }
}
