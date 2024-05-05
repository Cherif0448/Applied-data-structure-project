#ifndef TRIECLASS_H
#define TRIECLASS_H


#include <iostream>
#include <vector>
#include <memory>
#include <queue>

using namespace std;

class TrieNode {
public:
    vector<unique_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : children(27), isEndOfWord(false) {}

    int getIndex(char c) {
        if (c == '\'') {
            return 26;
        }
        if (isupper(c)) {
            c = tolower(c);
        }


        return c - 'a';
    }
};

class Trie {
public:
    unique_ptr<TrieNode> root;
    int wordCount;

    Trie() : root(make_unique<TrieNode>()), wordCount(0) {}

    void insert(const string& word) {
        TrieNode* current = root.get();
        for (char c : word) {
            int index = current->getIndex(c);

            if (!current->children[index]) {
                current->children[index] = make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        if (!current->isEndOfWord) {
            current->isEndOfWord = true;
            wordCount++;
        }
    }

    int getCount() {
        return wordCount;
    }

    /*vector<string> getSuggestions(const string& input) {
        vector<string> suggestions;
        TrieNode* current = root.get();
        for (char c : input) {
            int index = current->getIndex(c);
            if (!current->children[index]) {
                return suggestions;
            }
            current = current->children[index].get();
        }
        findSuggestions(current, input, suggestions);
        return suggestions;
    }
*/
/*void findSuggestions(TrieNode* node, string prefix, vector<string>& suggestions) {
    if (suggestions.size() == 5) {
        return;
    }

    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            findSuggestions(node->children[i].get(), prefix + char('a' + i), suggestions);
        }
    }
}*/

    bool search(const string& word) {
        TrieNode* current = root.get();
        for (char c : word) {
            int index = current->getIndex(c);
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index].get();
        }
        return current && current->isEndOfWord;
    }

    vector<string> suggestCorrections(const string& word) {
        vector<string> suggestions;
        for (size_t i = 0; i <= word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string newWord = word;
                newWord.insert(i, 1, c);
                if (search(newWord)) {
                    suggestions.push_back(newWord);
                }
            }
        }
        return suggestions;
    }
};
#endif
