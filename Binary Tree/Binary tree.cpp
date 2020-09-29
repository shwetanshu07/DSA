#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

// global variable for leftView Function
int max_level = 0;

struct Node{
    int key;
    Node *left, *right;
    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        std::cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root!=NULL){
        std::cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        std::cout<<root->key<<" ";
    }
}

int height(Node *root){
    if(root==NULL) return 0;
    else{
        return std::max(height(root->left), height(root->right))+1;
    }
}

void getKthLevel(Node *root, int k){
    // prints the nodes at kth level of tree
    if(root == NULL) return;
    else if(k==0) std::cout<<root->key<<" ";
    else{
        getKthLevel(root->left, k-1);
        getKthLevel(root->right, k-1);
    }
}

void breadthFirstTraversal(Node *root){
  if(root == NULL) return;
  std::queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node *temp = q.front();
    q.pop();
    std::cout<<temp->key<<" ";
    if(temp->left != NULL) q.push(temp->left);
    if(temp->right != NULL) q.push(temp->right);  
  }
}

void lineByLineTraversal(Node *root){
  // In Level Order Traversal Line by Line,
  // we print the nodes at each level separately in a new line.
  if(root==NULL) return;
  std::queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(q.size()>1){
    Node *temp = q.front();
    q.pop();
    if(temp == NULL){
      std::cout<<"\n";
      q.push(NULL);
    }
    else{
      std::cout<<temp->key<<" ";
      if(temp->left!=NULL) q.push(temp->left);
      if(temp->right!=NULL) q.push(temp->right);
    }
  }
}

int getSize(Node *root){
  if(root==NULL) return 0;
  return getSize(root->left)+getSize(root->right)+1;
}

int getMax(Node *root){
  if(root == NULL) return INT_MIN;
  int a = getMax(root->left);
  int b = getMax(root->right);
  return std::max(std::max(a, b), root->key);
}

void leftView(Node *root, int level){
// in the main leftView is called with parameters root, 1
// prints the leftmost node at every level of the Binary Tree.
  if(root==NULL) return;
  if(max_level<level){
    std::cout<<root->key<<" ";
    max_level = level;
  }
  leftView(root->left, level+1);
  leftView(root->right, level+1);
}

bool isChildSum(Node *root){
  if(root == NULL) return true;
  if(root->left == NULL && root->right == NULL) return true;
  int sum = 0;
  if(root->left != NULL) sum = sum + root->left->key;
  if(root->right != NULL) sum = sum + root->right->key;
  return (sum==root->key && isChildSum(root->left) && isChildSum(root->right));
}

void widthOfBinaryTree(Node *root){
  // corner case
  if (root== NULL) return;

  std::queue<Node*> q;
  q.push(root);
  q.push(NULL);
  int max_width = 0;
  int width = 0;
  while(q.size()>1){
    Node *temp = q.front();
    q.pop();
    // either it is null or an valid address
    if(temp==NULL){
      // we know that the level is over and new one is starting
      max_width = std::max(max_width, width);
      width = 0;
      q.push(NULL);
    }
    else{
      width++;
      if(temp->left!=NULL) q.push(temp->left);
      if(temp->right!=NULL) q.push(temp->right);
    }
  }
  std::cout<<std::max(max_width, width);
}

void spiralTraversal(Node *root){
  if(root==NULL) return; // corner case

  std::deque<Node*> deque;
  bool reverse = false;
  deque.push_back(root);
  while(!deque.empty()){
    int count = deque.size();
    for(int i=0; i<count; i++){
      if(reverse == true){
        Node *temp = deque.back();
        deque.pop_back();
        std::cout<<temp->key<<" ";
        if(temp->right != NULL) deque.push_front(temp->right);
        if(temp->left != NULL) deque.push_front(temp->left);

      }else{
        Node *temp = deque.front();
        deque.pop_front();
        std::cout<<temp->key<<" ";
        if(temp->left != NULL) deque.push_back(temp->left);
        if(temp->right != NULL) deque.push_back(temp->right);
      }
    }
    reverse = !reverse;
  }
}

int main(){
    /*     10
          /  \
         20  30
        /  \   \
       40  50   60
    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);

    // traversing the tree
    std::cout<<"Inorder Traversal: ";
    inorder(root);
    std::cout<<"\nPreorder Traversal: ";
    preorder(root);
    std::cout<<"\nPostorder Traversal: ";
    postorder(root);

    // finding the height of the tree
    std::cout<<std::endl;
    std::cout<<"Height of tree: "<<height(root)<<std::endl;

    return 0;
}
