 #include <iostream>
#include <vector>
using namespace std;

class Item{
	public:
		string name;
		int price;
		int quantity_sold;
		int total_sales;
		
		Item(string name,int price,int quantity_sold,int total_sales)
		{
			this->name=name;
			this->price=price;
			this->quantity_sold=quantity_sold;
			this->total_sales=total_sales;
		}
};

class Sorting{

    public:

        void Selectionsort(vector<Item*> arr){
	    for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++)
		{
			if((arr[i])->price>(arr[j])->price)
			{
				Item* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	    }
	    for(int i=0;i<arr.size();i++)
	    {
		cout<<"Name : "<<(arr[i])->name<<"Price : "<<(arr[i])->price<<" Quantity : " <<(arr[i])->quantity_sold<<"total_sale : " <<(arr[i])->total_sales<<endl;
	    }
        }
      
        void Bubblesort(vector<Item*> &arr){
	int count=1;

    while(count<arr.size())
    {
        for(int i=0;i<arr.size()-count;i++)
        {
            if((arr[i])->price>(arr[i+1])->price) 
            {
                Item* temp = arr[i]; 
                arr[i] = arr[i+1]; 
                arr[i+1]=temp;    
            }
        }
        count++;
    }

	for(int i =0; i<arr.size();i++)
	{
		cout<<"Name : "<<(arr[i])->name<<"Price : "<<(arr[i])->price<<" Quantity : " <<(arr[i])->quantity_sold<<"total_sale : " <<(arr[i])->total_sales<<endl;
	}
}
        
        void insertionsort(vector<Item*> arr){
            for(int i=1;i<arr.size();i++)
         {
        int current = (arr[i])->price; // 2    at index 1
        int j=i-1;           // 30    at index 0
        while((arr[j])->price>current && j>=0) // if 30>2
        {
            arr[j+1]=arr[j]; // set 2 = 30 now j set to current 
            j--;   // set j back to index 0
            
        }
        (arr[j+1])->price=current; // set 2 2 
    }
	
	for(int i =0; i<arr.size();i++)
	{
		cout<<"Name : "<<(arr[i])->name<<"Price : "<<(arr[i])->price<<" Quantity : " <<(arr[i])->quantity_sold<<"total_sale : " <<(arr[i])->total_sales<<endl;
	}
     	
}

};

class Data{
	public:
		vector<Item*> arr;
		void addItem(Item* item)
		{
			arr.push_back(item);
		}
    
		void removeItem(int index,Item* &item) {
            delete item;
            arr.erase(arr.begin() + index);
    }
        
        void unsorted()
        {
            cout<<"Unsorted"<<endl;
            for(int i =0; i<arr.size();i++)
	{
		cout<<"Name : "<<(arr[i])->name<<"Price : "<<(arr[i])->price<<" Quantity : " <<(arr[i])->quantity_sold<<"total_sale : " <<(arr[i])->total_sales<<endl;
	}
        }
        
        void Sort()
        {
	        Sorting s;
            cout<<endl;
            cout<< "Selection sort by price"<<endl;
            s.Selectionsort(arr);
            cout<<endl;
            cout<< "Bubble sort by price "<<endl;
            s.Bubblesort(arr);
            cout<<endl;
            cout<< "Insertion sort by price"<<endl;
            s.insertionsort(arr);
        }
		
};






int main()
{
	Item* item1 = new Item ("biscuit",300,5,500);
	Item* item2 = new Item("chips",200,4,1000);
	Item* item3 =new Item("cake",100,3,1500);
    Data d;
    d.addItem(item1);
    d.addItem(item2);
    d.addItem(item3);
    d.unsorted();
    d.Sort();
	

	
	

	
}
