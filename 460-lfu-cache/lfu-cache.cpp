class Node {
public:
    int key, val, freq;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->freq = 1;
        next = prev = nullptr;
    }
};
class List{
public:
    int size;
    Node* head, *tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next=tail; tail->prev=head;
        size=0;
    }
    

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }

    void insertAfterHead(Node* node) {
        Node* x = head->next;
        node->next = x;
        node->prev = head;
        head->next = node;
        x->prev = node;
        size++;
    }
};
class LFUCache {
public:
    map<int,Node*> mp;
    map<int,List*> freqmp;
    int cap,mini,currsize;

    LFUCache(int capacity) {
        cap=capacity; mini=0; currsize=0;
    }

    void f(Node* n){
        mp.erase(n->key);
        freqmp[n->freq]->deleteNode(n);

        if(n->freq==mini && freqmp[n->freq]->size==0) mini++;

        List* list;
        if(freqmp.find(n->freq+1)!=freqmp.end()) list=freqmp[n->freq+1];
        else list=new List();

        n->freq+=1;
        list->insertAfterHead(n);
        freqmp[n->freq]=list;
        mp[n->key]=n;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* n=mp[key];
            int ans=n->val;
            f(n);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* n=mp[key];
            n->val=value;
            f(n);
        }
        else{
            if(currsize==cap){
                List* list=freqmp[mini];
                mp.erase(list->tail->prev->key);
                freqmp[mini]->deleteNode(list->tail->prev);
                currsize--;
            }
            mini=1; currsize++;

            List* list;
            if(freqmp.find(mini)!=freqmp.end()) list=freqmp[mini];
            else list=new List();

            Node* n=new Node(key,value);
            list->insertAfterHead(n);
            mp[key]=n; freqmp[mini]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */