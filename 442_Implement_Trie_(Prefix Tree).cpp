/*
442. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example
insert("lintcode")
search("code")
>>> false
startsWith("lint")
>>> true
startsWith("linterror")
>>> false
insert("linterror")
search("lintcode)
>>> true
startsWith("linterror")
>>> true

Notice
You may assume that all inputs are consist of lowercase letters a-z.

Reference
https://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/


Author: Yuan Li
Date: 9/2/2018 
Difficulty: Medium
*/

// time: O(l)
// space: O(prefixes) = O(n * l^2)
class Trie {
  public:
    Trie() {
        // do intialization if necessary
        root_.reset(new TrieNode()); // smart pointer - no need to delete
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(const string &word) {
        // write your code here
        TrieNode* p = root_.get();
        for (char c : word) {
            if (!p->children.count(c)) {
                p->children[c] = new TrieNode();
            }
            
            p = p->children[c];
        }
        
        p->word_end = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(const string &word) const {
        // write your code here
        const TrieNode* node = find(word);
        return node && node->word_end;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(const string &prefix) const {
        // write your code here
        return find(prefix) != nullptr;
    }
    
  private:
    struct TrieNode {
        TrieNode() : word_end(false) {} // constructor
        
        ~TrieNode() { // destructor
            for (auto &item : children) {
                if (item.second) {
                    delete item.second;
                }
            }    
        }
        
        bool word_end;
        unordered_map<char, TrieNode*> children;
    };
    
    unique_ptr<TrieNode> root_; // dummy head
    
  private:
    const TrieNode* find(const string &prefix) const {
        TrieNode* p = root_.get();
        for (char c : prefix) {
            if (!p->children.count(c)) {
                return nullptr;
            } 
            
            p = p->children[c];
        }
        
        return p;
    }
};
