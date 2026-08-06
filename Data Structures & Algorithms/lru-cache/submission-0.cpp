struct Node {
    pair<int, int> keyval;
    Node* next;
    Node* prev;
};

class LRUCache {
public:

    Node* head = new Node();
    Node* tail = new Node();
    
    map<int, Node*> cache;
    int currsize = 0;
    int size = 0;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    
    int get(int key) {
        if (!cache.contains(key)) return -1;

        Node* current = cache[key];
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current->prev = head;
        current->next = head->next;
        head->next->prev = current;
        head->next = current;
        return cache[key]->keyval.second;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) { //update position here not done yet
            cache[key]->keyval.second = value;
            Node* current = cache[key];
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current->prev = head;
            current->next = head->next;
            head->next->prev = current;
            head->next = current;
            return;
        } 

        if (currsize == size) {
            int toRemove = tail->prev->keyval.first;
            tail->prev = tail->prev->prev;
            tail->prev->next = tail;
            delete cache[toRemove];
            cache.erase(toRemove);
            currsize--;
        }

        Node* toAdd = new Node();
        toAdd->keyval = {key, value};
        toAdd->prev = head;
        toAdd->next = head->next;
        head->next->prev = toAdd;
        head->next = toAdd;
        cache[key] = toAdd;
        currsize++;
    }
};
