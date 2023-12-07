#include <iostream>
#include <map>
#include <string>
char alpabet[]={'!','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
using namespace std;


template <typename K, typename V>
struct hashMap {
    K key;
    V value;
    hashMap* next;

    hashMap(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

// Hashmap class with separate chaining
template <typename K, typename V, size_t TableSize>
class HashMap {
private:
    hashMap<K, V>* table[TableSize];

    // Hash function to map keys to indices
    size_t hashFunction(const K& key) const {
        // This is a simple example; in practice, you'd use a more robust hash function
        return hash<K>{}(key) % TableSize;
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
    // ~HashMap() {
    //     // Release allocated memory
    //     for (size_t i = 0; i < TableSize; ++i) {
    //         hashMap<K, V>* current = table[i];
    //         while (current != nullptr) {
    //             hashMap<K, V>* next = current->next;
    //             delete current;
    //             current = next;
    //         }
    //     }
    // }

    // Insert a key-value pair into the hashmap
    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key);
        hashMap<K, V>* newNode = new hashMap<K, V>(key, value);

        // Insert at the beginning (front) of the linked list at the calculated index
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Retrieve the value associated with a key
    V get(const K& key) const {
        size_t index = hashFunction(key);

        // Iterate through the linked list at the calculated index
        hashMap<K, V>* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        // Key not found
        throw std::out_of_range("Key not found");
    }
    V getKey(const K& key) const {
        size_t index = hashFunction(key);

        // Iterate through the linked list at the calculated index
        hashMap<K, V>* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->key;
            }
            current = current->next;
        }

        // Key not found
        throw std::out_of_range("Key not found");
    }

    // // Print the contents of the hashmap
    void print() const {
        for (size_t i = 0; i < TableSize; ++i) {
            cout << "Bucket " << i << ": ";
            hashMap<K, V>* current = table[i];
            while (current != nullptr) {
                cout << "Key: " << current->key << ", Value: " << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};


class Node
{
    public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data=data;
            next = NULL;
        }
};
void insertAtTail(Node* &head,int data)
{
    Node* node = new Node(data);
    if(head==NULL) // 1st attemp if work
    {
        head=node;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL)  // 3rd attempt this while work
    {
        temp=temp->next;
    }
    temp->next=node;  // 2nd attemp this line call
}
void displayNode(Node* head)
{
    Node* temp = head;
    cout<<"Head->";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|-->";
        temp=temp->next;
    }
    cout<<"NULL";
        
}
int size(Node* head)
{   int count=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;

        
}
int getDataAtIndex(Node* head,int index) {
        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        if (current != NULL) {
            return current->data;
        } 
        
    }

class Cryptography{
    // map<int,char> map;
    HashMap<int, char, 27> myHashMap;
    Node* list1 = NULL;
    int row = 2;
    

    
    //KEY          2x2      ROW     COLUMN          PUBLIC_KEY
    int public_key[2][2] = {{3, 5}, {1, 2}};   //   [3   5]  
    int priate_key[2][2] = {{2, -5}, {-1, 3}}; //   [1   2]
                                               //  PRIVATE_KEY
                                              //   [2   -5]  
                                              //   [-1   3]

    public:
        Cryptography()
        {
                // map[i]=alpabet[i]; 
        for(int i=1;i<27;i++)
        {
                myHashMap.insert(i,alpabet[i]);
        }
        // myHashMap.print();
        }
        bool evenOddChecker()
        {
            if(size(list1)%2==0)
                return true;
            else
                return false;

            
        }
        void stringToNumber(string msg)
        {
            for(int i=0;i<msg.length();i++)
            {

                // for (auto it = map.begin(); it != map.end(); ++it) 
                //     {
                //        if(msg[i]== it->second)
                //        {
                //         insertAtTail(list1,it->first);
                //         break;
                //        }
                //     }
                for(int k=1;k<27;k++)
                {
                   if(msg[i] == myHashMap.get(k))
                       {
                        insertAtTail(list1,k);
                        break;
                       } 
                }
            }
            displayNode(list1);
        }
        // void printNumbers()
        // {
        //     for(int i=0;i<size(list1);i++)
        //     {
                
        //         // if(getDataAtIndex(list1,i)==myHashMap.get(i))
        //         // {
        //         //     if(myHashMap.getKey(i)>9)
        //                  cout << " KEY :" << "| Value :"<< myHashMap.get(i) <<endl;
        //             // else
        //                 //  cout << " KEY :0"<< myHashMap.getKey(i) << "| Value :"<< myHashMap.get(i) <<endl;
        //         // }
                
        //     }
            
        // }
        void matrix()
        {    
            if(!evenOddChecker())
                insertAtTail(list1,0);

            int col=size(list1);
            int matrix[row][col];
            int index=0;
                
           
        
            // PUTTING 1D ARR ELEMENTS IN 2D ARR COL FIRST THEN ROW
            for (int i = 0; i < col/2; ++i)
            {
                for (int j = 0; j < 2; ++j) 
                    matrix[j][i]=getDataAtIndex(list1,index++);
                
            } 

    
    int encrypted2DList[2][100] = {{0}};
    int decrypted2DList[2][100] = {{0}};  

   // Encryption 
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col/2; ++j) 
                {
                    for (int k = 0; k < row; ++k)
                        encrypted2DList[i][j] += public_key[i][k] * matrix[k][j];           
                }
            }
   //Printing  Encryption  
        cout << "Encrypted:" << endl;
        for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col/2; ++j) {
            cout << encrypted2DList[i][j];
        }
    }
    

    //Decryption
    cout<<endl;
    for (int i = 0; i < row; ++i) 
       {
            for (int j = 0; j < col/2; ++j) 
            {
                for (int k = 0; k < row; ++k)
                    decrypted2DList[i][j] += priate_key[i][k] * encrypted2DList[k][j];         
            }
       }
       cout << "Decrypted:" << endl;
       
    //Printing Decryption
        // cout << "decrypted:" << endl;
        // for(int i=0;i<size(list1);i++)
        //     {
        //         for (auto it = map.begin(); it != map.end(); ++it) 
        //         {
        //             if(getDataAtIndex(list1,i)==it->first){
        //                 auto temp = map.find(getDataAtIndex(list1,i));
        //                 cout<< temp->first;
        //             }
        //         }
        //     }

        cout<<endl;
        cout << "Output:" << endl;
        // for(int i=0;i<size(list1);i++)
        //     {
        //         for (auto it = map.begin(); it != map.end(); ++it) 
        //         {
        //             if(getDataAtIndex(list1,i)==it->first){
        //                 auto temp = map.find(getDataAtIndex(list1,i));
        //                 cout<< temp->second;
        //             }
        //         }
        //     }

    
            
    }
        
        
    
};

int main()
{
    string msg;
    cout<<"Enter msg-> : ";
    cin>>msg;
    Cryptography a;
    a.stringToNumber(msg);
    // a.printNumbers();
    // a.matrix();
   

    return 0;
}