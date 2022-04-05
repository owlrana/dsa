// IMPLEMENTATION OF HASHMAPS BY SEPARATE CHAINING METHOD using Node class

#include<iostream>
#include<cstring>
using namespace std;

// NODE CLASS
template<typename T>
class Node
{
public:
    string key;
    T value;
    Node<T>* next;

    // Node constructor
    Node(string aKey, T aVal)
    {
        key = aKey;
        value = aVal;
        next = NULL;
    }

    // to avoid memory leaks in case any mishap occurs
    // this is a recursive constructor call
    ~Node()
    {
        if (next != NULL)
        {
            delete next; // entire chain of ll will be deleted from this node
        }
    }
};

// HASHTABLE CLASS
template<typename T>
class Hashtable
{
    // pointer to the array of pointers
    Node<T>** table;
    int current_size;
    int table_size;

    int hashFN(string key)
    {
        int idx = 0;
        int p = 1;

        for (int j = 0; j < key.length(); j ++)
        {
            // idx should always lie inside the table
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p*27) % table_size; 
        }

        return idx;
    }

    // 
    void rehash ()
    {
        //  we need the "table" variable to retain its name with new contents
        //  as other function calls are dependent upon this table variable
        Node<T>** oldTable = table;
        int oldTableSize = table_size;
        table_size = 2*table_size; // approx. here, finding next PRIME is better 
        table = new Node<T>*[table_size];

        for (int i = 0; i < table_size; i ++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        // shift the elements from old table into the new table
        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T>* temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            // delete this entire row that you have just copied
            if (oldTable[i] != NULL)
            {
                delete oldTable[i]; // this initiates our recursive destructor
            }
        }

        delete [] oldTable;

    }

public:

    // HASHTABLE constructor
    Hashtable(int ts = 7)
    {
        table_size = ts;
        // data type of each bucket of the table's arrays (of datatype Node<T>*)
        table = new Node<T>* [table_size]; // array of Node<T> pointers for ll
        current_size = 0;

        // Having pointers as null will help us know if anything is stored or not
        for (int i = 0; i < table_size; i ++)
        {
            table[i] = NULL; // putting NULL into each bucket instead of Garbage
        }
    }

    void insert(string key, T value)
    {
        //  hashFn to find out the index
        int idx = hashFN (key);

        // to create linked list, we first need a node
        Node<T>* n = new Node<T> (key, value);
        
        // insert at head of the linked list with ID = idx
        n->next = table[idx];
        table[idx] = n;

        current_size += 1;

        // rehashing to make sure the LOAD FACTOR is under threshold
        float load_factor = current_size / (1.0*table_size);

        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    // returns the item, otherwise returns the NULL pointer
    T* search (string key)
    {
        int idx = hashFN(key);
        Node<T>*temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }

        return NULL;
    }

    // THIS ERASE FUNCTION MAY NOT WORK PROPERLY!!!!!!!
    // it's most probably UNDEFINED BEHAVIOUR
    // https://stackoverflow.com/questions/1930459/c-delete-it-deletes-my-objects-but-i-can-still-access-the-data
    void erase (string key)
    {
        int idx = hashFN(key);
        Node<T>*temp = table[idx];

        if (temp->key == key)
        {
            table[idx] = NULL;
            delete temp;
            return;
        }

        if (this->search(key) != NULL)
        {
            while (temp->next != NULL)
            {
                if (temp->next->key == key)
                {
                    Node<T>* prev = temp;
                    prev->next = prev->next->next;
                    delete temp->next;
                    return;
                }
                temp = temp->next;
            }

        }
    }

    // operator overloading for []
    // Return type should be "T&" otherwise a COPY of location is returned... 
    T& operator[] (string key)
    {
        T* f = search(key);
        if (f == NULL)
        {
            // insert as this value is not present with a garbage value
            T garbage;
            insert(key, garbage);
            f = search(key);
        }

        return *f;
    }

    // Utility function to see how our hasFN looks like for the sake of learning only...
    void print()
    {
        for (int i = 0; i < table_size; i ++)
        {
            cout << "Bucket " << i << " -> ";
            Node<T>* temp = table[i];
            while (temp!= NULL)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


int main()
{
    Hashtable<int> price_menu;

//  CHECKING PURPOSE ONLY
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Burger", 40);

    price_menu.print();


//  SEARCH FUNCTIONALITY OF HASHTAGS
    int *price = price_menu.search("Noodles");
    if (price == NULL)
    {
        cout << "Not found!" << endl;
    }
    else
    {
        cout << "Price is: " << *price << endl;
    }


//  DELETING SOMETHING FROM HASHTABLE
    price_menu.erase("Noodles");
    price_menu.print();


//  EASY ACCESS USING [] OPERATOR!!
/*
    price_menu["Dosa"] = 60;  // should be able to set a value, key present or not

    price_menu["Dosa"] += 10; // should be able to update value

    cout << price_menu["Dosa"] << endl; // should be able to search & return
*/

    cout << "Price of Burger: ";
    price_menu["Burger"] = 999;
    price_menu["Burger"] += 1;
    cout << price_menu["Burger"] << endl;

    price_menu["Saand"] = 1234;
    cout << price_menu["Saand"] << endl;

    return 0;
}