class TrieNode {
public:
    TrieNode* children[26];
    bool eow;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        eow = false;
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* end(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return nullptr;
            }
            curr = curr->children[index];
        }
        return curr;
    }

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->eow = true;
        return;
    }
    
    bool search(const string& word) {
        TrieNode* node = end(word);
        return node != nullptr && node->eow;
    }
    
    bool startsWith(const string& prefix) {
        return end(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
