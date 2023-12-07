#include <iostream>
#include <map>  
#include <string>
#include <typeinfo>
char alpabet[]={'!','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//KEY          2x2      ROW     COLUMN          PUBLIC_KEY
    int public_key[2][2] = {{3, 5}, {1, 2}};   //   [3   5]  
    int priate_key[2][2] = {{2, -5}, {-1, 3}}; //   [1   2]
                                               //  PRIVATE_KEY
                                              //   [2   -5]  
                                              //   [-1   3]
using namespace std;


struct Node
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
    map<int,char> map;  // O(logn)
    Node* list1 = NULL; //O(n)
    int row = 2;
    

    
    

    public:
        Cryptography(string msg)
        {
        for(int i=1;i<53;i++)
                map[i]=alpabet[i]; //  1='A'
        stringToNumber(msg);
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

                for (auto it = map.begin(); it != map.end(); ++it) 
                    {
                        if(msg[i]== it->second)
                       {
                        insertAtTail(list1,it->first);
                        break;
                       }
                    }
            }
            printNumbers();
        }
        void printNumbers()
        {
            for(int i=0;i<size(list1);i++)
            {
                for (auto it = map.begin(); it != map.end(); ++it) 
                {

                if(getDataAtIndex(list1,i)==it->first)
                {
                    if(it->first>9)
                         cout << " KEY :"<< it->first << "| Value :"<<it->second <<endl;
                    else
                         cout << " KEY :0"<< it->first << "| Value :"<<it->second <<endl;
                }
                }
            }
            matrix();
        }
        void matrix()
        {    
            

            displayNode(list1);
            if(!evenOddChecker())
                insertAtTail(list1,0);
            
            int col=size(list1);
            int encrypted2DList[2][100] = {{0}};
            int decrypted2DList[2][100] = {{0}}; 
            int matrix[row][col];
            int index=0;
                
           
        
            // PUTTING 1D ARR ELEMENTS IN 2D ARR COL FIRST THEN ROW
            for (int i = 0; i < col/2; ++i)
            {
                for (int j = 0; j < 2; ++j) 
                    matrix[j][i]=getDataAtIndex(list1,index++);
                
            } 

    
     

   // Encryption 
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col/2; ++j) 
                {
                    for (int k = 0; k < row; ++k)
                        encrypted2DList[i][j] += public_key[i][k] * matrix[k][j];           
                }
            }

   //Printing  Encryption  
            cout << "\nEncrypted:" << endl;
                for (int i = 0; i < row; ++i) {
                    for (int j = 0; j < col/2; ++j)
                    {
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
    for (int i = 0; i < row; ++i) 
    {
        for (int j = 0; j < col/2; ++j) 
            cout << decrypted2DList[i][j];
    }


        cout<<endl;
        cout << "Output:" << endl;
        for(int i=0;i<size(list1);i++)
            {
                for (auto it = map.begin(); it != map.end(); ++it) 
                {
                    if(getDataAtIndex(list1,i)==it->first){
                        auto temp = map.find(getDataAtIndex(list1,i));
                        cout<< temp->second;
                    }
                }
            }

    
            
    }

        
        
    
};

int main()
{
    string msg;
    cout<<"Enter msg-> : ";
    getline(cin, msg);
    Cryptography a(msg);
   

    return 0;
}