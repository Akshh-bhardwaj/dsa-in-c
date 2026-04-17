#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode) {
        int i;
        pNode->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!pCrawl->children[index]) return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    struct TrieNode *root = getNode();
    int i;
    for (i = 0; i < 8; i++) insert(root, keys[i]);
    printf("%s --- %s\n", "the", search(root, "the") ? "Present" : "Not present");
    printf("%s --- %s\n", "these", search(root, "these") ? "Present" : "Not present");
    return 0;
}
