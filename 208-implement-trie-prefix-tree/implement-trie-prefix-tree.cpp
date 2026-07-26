class Trie {
public:
    Trie* child[26];
    bool isEnd;

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    void insert(string word) {
        Trie* node = this;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                node->child[idx] = new Trie();
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            }

            node = node->child[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            }

            node = node->child[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */