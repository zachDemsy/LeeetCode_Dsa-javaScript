#include <string>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isRoot;

    TrieNode() : isRoot(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isRoot = true;
    }

    std::string findShortestRoot(const std::string& word) {
        TrieNode* node = root;
        std::string shortestRoot;

        for (char c : word) {
            if (node->children.find(c) != node->children.end()) {
                shortestRoot.push_back(c);
                node = node->children[c];
                if (node->isRoot) {
                    return shortestRoot;
                }
            } else {
                return word;
                
            }
        }

        return word;
    }
};

class Solution {
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        Trie trie;
       
        for (const std::string& root : dictionary) {
            trie.insert(root);
        }

        std::istringstream iss(sentence);
        std::string word, result;

        while (iss >> word) {
        
            std::string shortestRoot = trie.findShortestRoot(word);
            result += shortestRoot + " ";
        }

      
        return result.substr(0, result.size() - 1);
    }
};
