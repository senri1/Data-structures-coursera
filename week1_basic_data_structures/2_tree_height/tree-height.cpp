#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::queue<Node*> queue;
  std::vector<Node> nodes(n);
  Node* root;
  int parent_index;
  for (int child_index = 0; child_index < n; child_index++) {
    std::cin >> parent_index;
    if (parent_index >= 0) {
      nodes[child_index].setParent(&nodes[parent_index]);
    }
    else if(parent_index == -1) {
      root = &nodes[child_index];
    }
    nodes[child_index].key = child_index;
  }
  Node* parent;
  int maxHeight = 0;
  queue.push(root);

  while(!queue.empty()) {
    int size = queue.size();
    while(size--){
      parent = queue.front();
      queue.pop();
      for(auto child: parent->children){
        queue.push(child);
        }
      }  
    maxHeight++;
    }
  
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
return main_with_large_stack_space();
}
