// leetcode question https://leetcode.com/problems/lfu-cache/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class node{
public:
    int key;
    int val;
    int freq;
    node* prev;
    node* next;
};

class LFUCache {
    int cap;
    int count;
    unordered_map<int, pair<node*, node* > > freq_dlist;        // left and right node
    unordered_map<int, node*> key_node;
    int least;
    
    void bump(node* n){
        // cout<<"bumping "<< n->val << " to freq "<<n->freq+1<<endl;
        // updating neighbors
        if(n->prev){
            n->prev->next = n->next;
        }
        if(n->next){
            n->next->prev = n->prev;
        }
        // update lroot and rroot if n is one or both of them
        if(freq_dlist[n->freq].first == n){
            freq_dlist[n->freq].first = n->next;
        }
        if(freq_dlist[n->freq].second == n){
            freq_dlist[n->freq].second = n->prev;
        }
        // increment freq
        n->freq++;
        
        // append n to left of new freq;
                    // put node in freq_dlist
        node* lmost = freq_dlist[n->freq].first;
        if(!lmost){             
            // if left node is nullptr, then it means dlist at this freq is empty
            freq_dlist[n->freq].first = n;
            freq_dlist[n->freq].second = n;
            n->next = nullptr;
            n->prev = nullptr;
        }
        else{     
            // if not empty then we just append to left
            n->prev = nullptr;
            n->next = lmost;
            freq_dlist[n->freq].first = n;
            lmost->prev = n;
        }
        if(!freq_dlist[least].first) // if n was only element in least freq, which means that freq_dlist is now empty
        {
            least++;
        }
    }
public:
    LFUCache(int capacity) {
        cap = capacity;
        count = 0;
        least = 1;
    }
    
    int get(int key) {
        // cout<< "get "<< key<< endl;
        if(key_node.find(key) == key_node.end()){
            return -1;
        }

        node* n = key_node[key];
        // update neighbors if they exist
        bump(n);
        return n->val;
    }
    
    void put(int key, int value) {
        // cout<<"put " << key<< " " << value<<endl;
        if(key_node.find(key) == key_node.end()){
            // insert
            node* n = new node();
            n->key = key;
            n->val = value;
            n->freq = 1;
            key_node[key] = n;
            
            // put node in freq_dlist
            node* lmost = freq_dlist[1].first;
            if(!lmost){             
                // if left node is nullptr, then it means dlist at this freq is empty
                freq_dlist[1].first = n;
                freq_dlist[1].second = n;
            }
            else{     
                // if not empty then we just append to left
                n->next = lmost;
                freq_dlist[1].first = n;
                lmost->prev = n;
            }
            count++;
            if(count > cap){
                node* to_delete = freq_dlist[least].second;       // right most of least freq
                // cout<<"deleting value "<<to_delete->key<< " at freq "<< to_delete->freq<< ", least was "<<least<<endl;
                freq_dlist[least].second = to_delete->prev;
                if(!to_delete->prev){   // if only 1 element in that freq, and that element is deleted
                    freq_dlist[least].first = nullptr;
                }else{
                    to_delete->prev->next=nullptr;
                }
                key_node.erase(to_delete->key);
                delete(to_delete);   // not necessary for leetcode, but good memory management
                // delete least used
                count--;
                
            }
            least = 1; // at the end of insert (which may or maynot result in deleting) least is always 1
        }else{
            // update
            node* n = key_node[key];
            n->val = value;  // update alue;
            bump(n);
        }
    }
};

