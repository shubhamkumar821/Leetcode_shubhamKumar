class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;

    LRUCache(int capacity) {
        cap = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* add) {
        Node* temp = head->next;

        add->next = temp;
        add->prev = head;

        head->next = add;
        temp->prev = add;
    }

    void deleteNode(Node* del) {
        Node* temp1 = del->next;
        Node* temp2 = del->prev;

        temp2->next = temp1;
        temp1->prev = temp2;
    }

    int get(int key) {

        if (mp.find(key) != mp.end()) {

            Node* temp = mp[key];

            // Return VALUE, not key
            int res = temp->value;

            // Remove from current position
            deleteNode(temp);

            // Put at front = most recently used
            addNode(temp);

            return res;
        }

        return -1;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* existing = mp[key];

            mp.erase(key);
            deleteNode(existing);
            delete existing;
        }

        // Cache is full
        if (mp.size() == cap) {

            Node* lru = tail->prev;

            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        // Add new node at front
        Node* newNode = new Node(key, value);

        addNode(newNode);
        mp[key] = newNode;
    }
};