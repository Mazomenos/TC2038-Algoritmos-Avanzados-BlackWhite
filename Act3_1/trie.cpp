#include "trie.h"

//Default Constructor
trie::trie() { 
  root = new nodeTrie(); 
}

//Deconstructor
trie::~trie() {
  nodeTrie *current = root;
  destroy(root);

}

//Aux function for Deconstructor
//Has a time complexity of O(N) since it needs to go to and
//delete every node
void trie::destroy(nodeTrie* node) {
  int aV = 'a';
  if (node) {
        for (int i = 0; i < 26; i++) {
          
            if (node ->getChild(aV + i) != nullptr) {
              destroy(node->getChild(i+aV));
            }
        }
        
        delete node; // Deallocate the current node
}
}

//Inserts word to Trie
//Has a time complexity of O(word_length) since it needs to
//go down or create nodes until it can store the whole word
void trie::insert(std::string word) {
  nodeTrie *current = root;
  for (int i = 0; i < (int)word.length(); i++) {
    if (current->getChild(word[i]) == nullptr) {
      nodeTrie *newNode = new nodeTrie(word[i], current);
      current->setChild(newNode);
    }
    current = current->getChild(word[i]);
  }
  current->setIsLeaf(true);
}

//Searches a given word and returns a bool if its found or not
//Has a time complexity of O(word_length) because it needs to
//go down all the way to the end of the word, passing through all its nodes
bool trie::search(std::string word) {
  nodeTrie *current = root;
  if (current == nullptr)

    return false;
  for (int i = 0; i < (int)word.length(); i++) {
    current = current->getChild(word[i]);
    if (current == nullptr)
      return false;
  }
  return current->getIsLeaf();
}

/*
 * Receives the function and a prefix to then return the
 * words in the trie in lexicographic order.
 * Has a time complexity of O(N) since it needs to go
 * through all the nodes to print the words
 */
void trie::dfs(nodeTrie *node, std::string prefix) {
  nodeTrie *current = (node == nullptr) ? root : node;
  if (current->getIsLeaf()) {
    cout << prefix + current->getLetter() << endl;
  }
  std::vector<nodeTrie *> lista = current->getChildren();
  for (int i = 0; i < 26; i++) {
    if (lista[i] != nullptr) {
      dfs(current->getChild(lista[i]->getLetter()),
          prefix + current->getLetter());
    }
  }
}

/*
 * Receives a prefix and first searches if it's in the trie
 * In case its there, it proceeds to run a dfs search with the last
 * letter of the prefix as its root
 * Has a time complexity of O(N_after_Prefix + Prefix_length) since it
 * first has to traverse the prefix and set it as the root, and after this
 * it runs the dfs with the new root, so instead of being the total number of nodes,
 * it's just the number of nodes after the new prefix root
 */
void trie::autoComplete(std::string prefix) {
    //Search prefix
    nodeTrie *current = root;
    for (char c : prefix){
      
      if (current->getChild(c) == nullptr){
        //cout << "xdxd" << endl;
        return;
      } else{

        //cout << c << endl;
        current = current->getChild(c);
      }

    }
    
    //cout << prefix << endl;

    //Print words

    prefix.pop_back();

    dfs(current,prefix);


}
