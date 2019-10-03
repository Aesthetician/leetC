class WordDictionary {
    struct TrieNode {
        bool isEnd;
        vector<TrieNode*> children;
        TrieNode():isEnd(false), children(vector<TrieNode*> (26, NULL)) {}
        ~TrieNode() {
            for (int i = 0; i < 26; ++i)
                delete children[i];
        }
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* crt = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!crt->children[word[i] - 'a']) 
                crt->children[word[i] - 'a'] = new TrieNode();
            crt = crt->children[word[i] - 'a'];
        }
        crt->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(root, word, 0);
    }
    
    bool helper(TrieNode* root, string& word, int i) {
        if (!root) return false;
        if (i == word.size()) return root->isEnd;
        if (word[i] == '.') {
            for (int j = 0; j < 26; ++j) {
                if (helper(root->children[j], word, i + 1)) return true;
            } 
            return false;
        }
        return helper(root->children[word[i] - 'a'], word, i + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
