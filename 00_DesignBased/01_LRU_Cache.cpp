// leetcode question https://leetcode.com/problems/lru-cache/

#include<iostream>
#include<unordered_map>
using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//defining structure of a linked list node 
 class node{
    public: 
        int key,val;
        node *next,*prev;

        node(int _key,int _val){
            key=_key,val=_val;
            next=prev=nullptr;
        }
};

class LRUCache {
    // we are declaring a dummy head and tail node
    // these two nodes are dummy because we don't really care what's stored in them 
    //rather we care for the elements stored between 'head' and 'tail' nodes, 
    //node next to 'head' and 
    //node prev to 'tail'
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    int size;//keeping track of max size of our LRU cache 

    // hashmap that stores key of type 'int' and value as 'pointer to a node'
    //the 'value' is basically the exact memory location of a node present in our LL which has a key = key(of hashmap) 
    unordered_map<int, node*> hashmap;
public:
    //our initial configuration 
    LRUCache(int capacity) {
         
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }

    //whether it's a 'get' operation or 'put' operation every time a new node is inserted or already present node is looked up 
    //it will always be inserted at the start of LL i.e 'head->next' and not 'head';
    void add_node(node* newnode){
        newnode->next=head->next;
        newnode->prev=head;
        head->next->prev=newnode;
        head->next=newnode;
    }
    //when we want to remove a particular 'node' when a pointer to that 'node' is given
    void del_node(node* delnode){
        delnode->next->prev=delnode->prev;
        delnode->prev->next=delnode->next;
        
    }

    int get(int key) {
        //when key is not present
        if(hashmap.find(key)== hashmap.end())
            return -1;
        
        //delete the node in LL with 'key' using the pointer to that node given by the hashmap[key] 
        del_node(hashmap[key]);
        // add that node to the front of LL(head->next) using the pointer given by the hashmap[key]
        add_node(hashmap[key]);
        //establish a new pointer for this node
        hashmap[key]=head->next;
        
        //return the value that we were suppose to
        return head->next->val;
    }
    
    // inserts a new or modify (key,value) pair in the LRU cache 
    void put(int key, int value) {
        //if the pair that we are trying to insert already exist in the hashmap 
        // then remove the node from LL with key=key(from hashmap)
        //and also remove the 'key' from hashmap
        if(hashmap.find(key)!= hashmap.end())
        {
            del_node(hashmap[key]);
            hashmap.erase(key);
            
        }
        // if we have already reached the maximum allowed capacity then remove the lRU used (key,value) pair from our hashmap
        //and the node with key=key(from hashmap) from our LL 
        if(hashmap.size()==size){
            hashmap.erase(tail->prev->key);
            del_node(tail->prev);
        }
        
        // these two are the common statements of the aformentioned 'if condition' 
        //adding a new node to LL and pointer to that node in the hashmap
        
        add_node(new node(key,value));
        hashmap[key]=head->next;
            
        
    }
};

