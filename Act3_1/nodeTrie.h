#ifndef NODETRIE_H
#define NODETRIE_H

#include <iostream>
#include <vector>

using namespace std;

class nodeTrie {
private:
  char letter;
  bool isLeaf;
  nodeTrie *parent;
  std::vector<nodeTrie *> child;

public:
  nodeTrie();
  nodeTrie(char c, nodeTrie *p);
  nodeTrie *getChild(char c);
  vector<nodeTrie *> getChildren(); 
  void setChild(nodeTrie *ptrChild);  
  bool getIsLeaf();
  void setIsLeaf(bool value);
  char getLetter();
};


#endif // _NODETRIE_H