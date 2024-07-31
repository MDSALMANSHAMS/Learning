/*
Insersion
Delition
Searching

Finding a unque index for all element, to store them is called hash value.
By applying Hash function (k mod 10),

{hash value -> hash function -> hash table}

Hash fn.:
1. Division method
2. Mid square method
3. Digit folding method
4. Multiplication method

Collisions:
When 2 element have same hash value.
1. open hashing (seperate chaning (adding using linked list))
2. closed hashing
   a. linear probing
   b. quadratic probing
   c. double hashing
*/

// seperate chaning

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class hashing
{
    vector<list<int>> hashtable;
    int buckets;

public:
    hashing(int size)
    {
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key)
    {
        return key % buckets;
    }

    void addKey(int key)
    {
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key)
    {
        int idx = hashvalue(key);
        auto s = find(hashtable[idx].begin(), hashtable[idx].end(), key);
        cout << "Found at: " << *s << endl;
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void deleteKey(int key)
    {
        int idx = hashvalue(key);
        if (searchKey(key) != hashtable[idx].end())
        {
            hashtable[idx].erase(searchKey(key));
            cout << key << " is deleted" << endl;
        }
        else
            cout << "Key is not present in the hashtable" << endl;
    }
};

int main()
{
    hashing h(10);
    h.addKey(5);
    h.addKey(1);
    h.addKey(4);
    h.addKey(7);
    h.addKey(2);
    h.addKey(8);

    // h.searchKey(8);

    // h.deleteKey(5);

    return 0;
}