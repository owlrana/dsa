// exactly the same code for previous map (02_MapsSTL.cpp) should work
// only difference will be that the output is going to be RANDOM

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    // inserting into the map
    m.insert(make_pair("mango", 100));

    // 2nd way to insert
    m["banana"] = 20;
    m["apple"] = 123213;
    m["bolibooch"] = 12321;
    m["pear"] = 90281;


    // updating the price
    m["banana"] += 1980;

    // searching for any element
    string key = "banana";
    //cin >> key;
    
    // map<string, int>::it = m.find(key); // this is the same as line below
    auto it = m.find(key); // using the find function to find
    if (it != m.end())
    {
        cout << "Fruit is present, price: " << m[key] << endl;
    }
    else
    {
        cout << "Fruit not present" << endl;
    }
    

    // another alternative way to find out if key is present or not
    // it stores unique keys ONLY ONCE
    // if you do m["banana"] = 200; it will not create a new one...
    // count function returns an integer (0 if not present)
    if (m.count(key))
    {
        cout << "fruit is present, again LMAO ofc..." << endl;
    }
    else
    {
        cout << "npoe......." << endl;
    }

    // ERASING 
    m.erase(key);
    

    // we can also iterate over all key, value pairs
    // observe, these are being stored lexiographically (ordered)
    for (auto it = m.begin(); it != m.end(); it ++)
    {
        cout << "Key: " << it->first << ", value: " << it->second << endl;
    }


    return 0;
}