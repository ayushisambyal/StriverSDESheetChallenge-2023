#include <bits/stdc++.h> 

// DEFINE STRUCT NODE
struct Node{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};

// DEFINE STRUCT LIST
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};


// GIVEN CLASS LFUC
class LFUCache
{
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxsize, minfreq, cursize;

public:
    LFUCache(int capacity)
    {
        maxsize = capacity;
        minfreq = 0;
        cursize = 0;
    }


    int updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->cnt] -> removeNode(node);
        if(node->cnt == minfreq && freqListMap[node->cnt]->size == 0)
            minfreq++;
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node -> cnt+1) != freqListMap.end())
            nextHigherFreqList = freqListMap[node -> cnt+1];
        
        node->cnt += 1;
        nextHigherFreqList -> addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
        
    }

    int get(int key)
    {
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key]; // address
            int val = node->value; // value
            updateFreqListMap(node); // update when accecced
            return val;
        }   
        return -1;
    }

    void put(int key, int value)
    {
        if(maxsize == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(cursize == maxsize){
                List* list = freqListMap[minfreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minfreq] -> removeNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            // new val has to be added
            minfreq = 1;
            List* listfreq = new List();
            if(freqListMap.find(minfreq) != freqListMap.end())
                listfreq = freqListMap[minfreq];
            
            Node* node = new Node(key, value);
            listfreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minfreq] = listfreq;
        }
    }
};
