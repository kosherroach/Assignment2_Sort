//
//  ahh.h
//  ass_11
//
//  Created by P S on 11/7/22.
//

#ifndef Entry_hpp
#define Entry_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <istream>

//#include <pair>

using namespace std;

template<class T>
struct NodeType
{
    T item; // Data
    NodeType<T> *link; // Link to the next node in the list
};

template<class T>
class Entry
{
private:
    NodeType<T> *key_head;
    NodeType<T> *value_tail;
  
    
public:
    Entry();
    //~Entry();
    string About(); // Returns text about you - the author of this class
    void Addkey_head(T value); // Adds an object to the key_head of the list
    void Addvalue_tail(T value); // Adds an object to the value_tail of the list
    string removekey_head(); // Removed an object from the key_head of the list. If the list is empty, return empty
    string peekkey_head(); // Returns the value from the key_head of the list
    bool contains(T value);
    void print(); // print library
    bool isEmpty();
    
    // Helper Functions
    string key();
    int value();
    
    string GetName();
    // Helper Functions.
    //void peek();
    // Removal
    void remove();
    
    // Print and Sort Functions.
    void RevPrint(NodeType<T> *key_head);
    //void radixSort(vector<T> &file);
    bool searchRec(NodeType<T> *curr, T val);
    
    void countingSort(Entry<T> *arr, int length, int key);
    
    void Sort(Entry<T> *phoneBook, const int &length);
    
    void radixSort(Entry<T> *arr, int val);

    size_t get_max(Entry<T> *arr, int length);

    Entry<T> readFile(string &filename);
    void display(Entry<T> &v);
    
    int size();
    
    string main_key;
    string main_value;
    
    string *main_k;

};

template<class T>
Entry<T>::Entry()
{
    key_head = NULL;
    value_tail = NULL;
}

// Changed the string to void <--- Error!

/*template<class T>
void Entry<T>::peek()
{
    T firstElement;
    firstElement = key_head->item;
    cout << firstElement << " ";
}
*/
/*
template<class T>
string Entry<T>::peekkey_head()
{
    peek();
    
    return " ";
}
*/
// changed the string to void <--- Error!


template<class T>
string Entry<T>::key()
{
    return main_key;
}

template<class T>
int Entry<T>::value()
{
    return main_value;
}


template<class T>
string Entry<T>::GetName()
{
    return main_key + " " + main_value;
}
/*
template<class T>
Entry<T> Entry<T>::getIndex()
{
    return main_key + " " + main_value;
}
*/
template<class T>
void Entry<T>::remove()
{
    NodeType<T> *tempPtr = key_head;
    
    key_head = key_head->link;
    
    delete tempPtr;
}

template<class T>
string Entry<T>::removekey_head()
{
    
    remove();
    
    return " ";
}

template<class T>
string Entry<T>::About()
{
    string name;
    cout << "Enter the author of this code: ";
    getline(cin, name);
    return name;
}

//int value
template<class T>
void Entry<T>::Addkey_head(T value)
{
    // Pointer to the new node.
    NodeType<T>* add = new NodeType<T>;
    
    // Stores the info the new node.
    add->item = value;
    
    // Inserts the node before the current first node and connects them.
    add->link = key_head;
    
    // Links to the next node
    key_head = add;
    
    if (value_tail == NULL)
    {
        value_tail = add;
    }
    
    
    
    
    /*
     if (key_head == NULL)
     {
     add->item = value;
     add->link = key_head;
     add = key_head;
     }
     
     
     
     Psuedocode from Professor:
     
     NodeType<string> add = new NodeType<string>; // Create a new node
     
     if (list == NULL) // is key_head NUll
     key_head->value = add; // Link both and value_tail to the new node
     value_tail->value = add;
     else
     add->next = key_head; // Link the new node to the key_head
     key_head = add;
     */
}

template<class T>
void Entry<T>::Addvalue_tail(T value)
{
    NodeType<T> *add = new NodeType<T>;
    
    // Add value to the list.
    add->item = value;
    
    // New link to the list.
    add->link = NULL;
    
    if (key_head == NULL)
    {
        key_head = add;
        value_tail = add;
    }
    else
    {
        value_tail->link = add;
        
        value_tail = add;
    }
        /*
         Psuedocode from Professor:
        
         // Wrong Code?!
         
         NodeType<string> add = new NodeType<string>; // Create a new node;
         
            if (list == NULL) // is key_head NULL?
                key_head->value = add; // link both key_head and value_tail to the new node
                value_tail->value = add;
            else
                value_tail->next = add; // Link the next node after the key_head?
                value_tail = add;
         
         */
}


// Recursive call to the print function

template<class T>
void Entry<T>::RevPrint(NodeType<T> *key_head)
{
    if (key_head != NULL)
    {
        RevPrint(key_head->link);
        
        cout << key_head->item << " ";
    }
}
 
template<class T>
void Entry<T>::print()
{
    if(key_head != NULL)
    {
        RevPrint(key_head);
    }
    else
    {
        cout << "Empty Linked List" << endl;
    }
}

// Error<- Missing Recursion.

/*
template<class T>
void Entry<T>::print()
{
    NodeType<T> *current;
    
    current = key_head;
    
    while(current != NULL)
    {
        cout << current->item << " ";
        
        current = current->link;
    }
}
*/

// Error <- Missing Recursion.
template<class T>
bool Entry<T>::searchRec(NodeType<T> *curr, T val)
{
    if (curr == NULL)
    {
        return false;
    }
    else if (curr->item == val)
    {
        return true;
    }
    
    return searchRec(curr->link, val);
}

template<class T>
bool Entry<T>::contains(T val)
{
    /*
     NodeType<T> *currPtr;
     
     // currPtr = key_head;
     
     if (key_head == NULL)
     {
     cout << "Cannot search an empty list" << endl;
     }
     
     else
     {
     currPtr = key_head;
     
     while(currPtr != NULL)
     {
     //if (contains(currPtr->item) == value); // (recursion part)
     if (currPtr->item == value)
     {
     return true;
     }
     else
     {
     currPtr = currPtr->link;
     }
     }
     if (true)
     {
     cout << "Item is found in the list" << endl << endl;
     }
     else
     {
     cout << "Item is not in the list" << endl << endl;
     }
     }
     return false;
     */
    // Helper Definition.
    
    /*
     NodeType<T> *curr;
     
     curr = key_head;
     
     if (curr == NULL)
     {
     return false;
     }
     if (curr->item == value)
     {
     return true;
     }
     
     return true;
     */
    NodeType<T> *curr;
    
    curr = key_head;
    
    bool happy = searchRec(curr->link, val);
    
    if (happy == false)
    {
        return false;
    }
    if (happy == true)
    {
        return true;
    }
    
    return happy;
    //return contains(curr->next, value);
}
 

template<class T>
bool Entry<T>::isEmpty()
{
    // Check the list for all possible values?
    // Check for one value
    // inefficient
    /*
    if (key_head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
     */
    // Optimal
    return (key_head == NULL);
}

template<class T>
Entry<T> Entry<T>::readFile(string &file)
{
    ifstream source;
    source.open(file);
    Entry<T> lines;
    Entry<T> ko[1000];
    //lines.key();
    string line; //= main_key;
    string index; // = main_value;
    int count = 0;
    
    while(!source.eof())
    {
        source >> index;
        ko[count].main_key = index;
        //lines.Addvalue_tail(line);
        //istringstream iss(line);
        //ko >> index;
        count++;
        //lines = ko[count];
        
    }
    
    Sort(ko, file.size());
    
    //radixSort(ko, file.size());
    
    
    for (int k = 0; k < file.size(); k++) {
        //cout << "\n\t";
        //radixSort(ko[k], file.size());
        cout << ko[k].main_key << endl;
    }

    //string ko2[];
    //ko2 = ko;
    //radixSort(ko, 10);
    
    
    /*
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19 - 1; j++)
        {
            if(ko[j].value() > ko[j+1].value())
            {
                Entry<T> temp = ko[j];
                ko[j] = ko[j+1];
                ko[j+1] = temp;
            }
        }
    }
    //Entry<T> *show;



    //lines.radixSort(lines, 4);
     */
    //lines.print();

    /*
    for (auto it = 0; it < line.size(); it++)
    {
        cout << ko[it].main_key << endl;// << " " << ko[it].key();
        //cout << endl;
    }
     */
    
    return lines;
}

// Radix Sort

template<class T>
size_t Entry<T>::get_max(Entry<T>* arr, int length)
{
    size_t max = arr[0].size();
    for (int i = 1; i < length; i++)
    {
        if (arr[i].size() > max)
        {
            max = arr[i].size();
        }
    }
    return max;
}

template<class T>
void Entry<T>::countingSort(Entry<T> *arr, int length, int key)
{
    //key = readLine(key[0]);
    string *b = NULL; int *c = NULL;
    b = new string[length];
    c = new int[257];
    
    // First loop of the array to find the value;
    /*for (int i = 0; i < 257; i++)
    {
        arr[0] = 0;
    }
    */
    // Second loop of the array to find the second bucket.
    for (int j = 0; j < length; j++)
    {
        // tenary equation.
        c[key < arr[j].size() ? (int)(unsigned char)arr[j][key] + 1 : 0]++;
    }
    
    // Second and half loop of the array to find the fourth bucket.
    for (int f = 1; f < 257; f++)
    {
        c[f] += c[f-1];
    }
    
    // Third loop of the array to find the third bucket.
    for (int k = 1; k < 257; k++)
    {
        b[c[key < arr[k].size() ? (int)(unsigned char)arr[k][key] + 1 : 0] - 1] = arr[k];
        c[k < arr[k].size() ? (int)(unsigned char)arr[k][key] + 1 : 0]--;
    }
    
    // Fourth Loop of the array to find the fourth bucket.
    for (int l = 0; l < length; l++)
    {
        arr[l] = b[l];
    }
    
    delete [] b;
    delete [] c;
}

template<class T>
void Entry<T>::radixSort(Entry<T> *arr, int val)
{
    size_t max = get_max(arr, val);
    for (int i = 0; i < max; i++)
    {
        countingSort(arr, val, max - 1);
    }
}
 
template <class T>
void Entry<T>::Sort(Entry<T> *phoneBook, const int &length)
{
    for (int i = 0; i < length; i++)//for n-1 passes
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (phoneBook[j].GetName() > phoneBook[j + 1].GetName())
            {
                Entry<T> temp = phoneBook[j];
                phoneBook[j] = phoneBook[j + 1];
                phoneBook[j + 1] = temp;
            }
        }
    }
}

template<class T>
int Entry<T>::size()
{
    NodeType<T> * curr;
    int count = 0;
    curr = key_head;
    while (curr != NULL)
    {
        count++;
        curr = curr->link;
    }
    return count;
}

/*
template<class T>
void Entry<T>::display(Entry<T> &v)
{
    v.Addkey_head(std::make_pair(main_key, main_value));
    
    //v.radixSort()
}
*/

#endif /* Entry_hpp */

