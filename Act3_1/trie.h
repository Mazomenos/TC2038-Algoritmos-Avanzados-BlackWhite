#ifndef TRIE_H
#define TRIE_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include "nodeTrie.h"

class trie {
private:
  nodeTrie *root;

public:
  trie();
  ~trie(); // To-do
  void destroy(nodeTrie* node);
  void autoComplete(std::string prefix);
  void insert(std::string word);
  bool search(std::string word);
  void dfs(nodeTrie *node, std::string prefix); // To-do (parametros puede variar)
  
};

#endif // _TRIE_H