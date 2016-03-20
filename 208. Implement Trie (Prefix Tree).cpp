class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isString;
    // Initialize your data structure here.
    TrieNode() {
        isString = false;
    }
};

class Trie {
public:
    
    
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * ptr = root;
        for (int i = 0; i < word.size(); i++) {
            if (ptr -> children.find(word[i]) == ptr -> children.end()) {
                TrieNode * tmp = new TrieNode();
                ptr -> children[word[i]] = tmp;
            }
            ptr = ptr -> children[word[i]];
        }
        
        ptr -> isString = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * ptr = root;
        
        for (int i = 0; i < word.size(); i++) {
            if (ptr -> children.find(word[i]) != ptr -> children.end()) {
                ptr = ptr -> children[word[i]];
            }
            else {
                return false;
            }
        }
        
        return ptr -> isString;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * ptr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (ptr -> children.find(prefix[i]) == ptr -> children.end())
                return false;
            ptr = ptr -> children[prefix[i]];
        }
        
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
