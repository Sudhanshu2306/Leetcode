class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = prev = nullptr;
        }
    };

    map<int, Node*> mp;
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insertAfterHead(Node* node) {
        Node* x = head->next;
        node->next = x;
        node->prev = head;
        head->next = node;
        x->prev = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* x = mp[key];
        int y = x->val;
        deleteNode(x);
        insertAfterHead(x);
        mp.erase(key);
        mp[key] = x;
        return y;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* x = mp[key];
            deleteNode(x);
            mp.erase(key);
        }
        if (mp.size() == capacity) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }
        Node* z = new Node(key, value);
        insertAfterHead(z);
        mp[key] = z;
    }
};
