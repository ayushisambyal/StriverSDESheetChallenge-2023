#include<bits/stdc++.h>

class LRUCache
{
public:

    // Define node data structure
    class node{
        public:
            int key; 
            int val;
            node* next; 
            node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    // define and initialise head and tail
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap; // capacity allowed
    unordered_map <int, node*> mp;


    // constructor OR initialiser 
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // FXN 1 : 
    int get(int key_)
    {
        if(mp.find(key_) != mp.end()){
        // if the key existed in the map
            node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            // erasing the old adress
            deletenode(resnode);
            addnode(resnode);
            mp[key_] = head->next;
            // refreshing the adress in the map as well
            // head->next 'cause that will be the new address
            return res;
        }
        return -1;
    }

    // FXN 2 : 
    void put(int key_, int value)
    {
        if(mp.find(key_) != mp.end()){
            node* existingnode = mp[key_];
            mp.erase(key_);
            deletenode(existingnode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_, value));
        mp[key_] = head->next;
    }
};
