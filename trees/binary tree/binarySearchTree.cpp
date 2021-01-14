#include<iostream>
#define SPACE 10

using namespace std;

class TreeNode {
  public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
      value = 0;
      left = NULL;
      right = NULL;
    }

    TreeNode(int v){
      value = v;
      left = NULL;
      right = NULL; 
    }
};

class BST{
  public:
    TreeNode* root;
    BST(){
      root = NULL;
    }
    bool isEmpty(){
      return (root == NULL)? true : false;
    }

    void insertNode(TreeNode* new_node){
      if(root==NULL){
        root = new_node;
        cout << "Value Inserted as root node!"<<endl;
      }
      else{
        TreeNode* temp=root;
        while(temp!=NULL){
          if(new_node->value==temp->value){
            cout<<"Value Already exist, Insert another Value!"<<endl;
            return;
          }
          else if((new_node->value<temp->value) && (temp->left==NULL)){
            temp->left = new_node;
            cout<<"Value Inserted to the left!"<<endl;
            break;
          }
          else if(new_node->value<temp->value){
            temp= temp->left;
          }
          else if((new_node->value>temp->value) && (temp->right==NULL)){
            temp->right = new_node;
            cout<<"Value Inserted to the right!"<<endl;
            break;
          }
          else{
            temp= temp->right;
          }
        }
      }
    }

    void printPreorder(TreeNode* r){ // (root, left, right)
      if(r==NULL) return;
      // first print the data
      cout << r->value << " ";
      // then recursive call to left subtree
      printPreorder(r->left);
      // then recursive call to right subtree
      printPreorder(r->right);
    }

    void printInorder(TreeNode* r){// (left, root, right)
      if(r==NULL) return;
      printInorder(r->left);
      cout << r->value << " ";
      printInorder(r->right);
    }

    void printPostorder(TreeNode* r){// (left, right, root)
      if(r==NULL) return;
      printPostorder(r->left);
      printPostorder(r->right);
      cout << r->value << " ";
    }
    void print2D(TreeNode* r, int space){
      if(r==NULL)
        return;
      space += SPACE;
      print2D(r->right, space);
      cout<<endl;
      for(int i=SPACE;i<space;i++)
        cout<<' ';
      cout<<r->value<<endl;
      print2D(r->left, space);
    }
};

int main() {
  BST obj;
  int option, val;
  do{
    cout << "What operation do you want to perform? "
    << " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print BST values" << endl;
    cout << "5. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;
    cin >> option;
    TreeNode* new_node = new TreeNode();
    switch(option){
      case 0:
        break;
      case 1:
        cout << "INSERT" << endl;
        cout << "Enter VALUE of the tree NODE to INSERT in BST: ";
        cin >> val;
        new_node->value = val;
        obj.insertNode(new_node);
        cout << endl;
        break;
      case 2:
        cout << "Search" << endl;
        break;
      case 3:
        cout << "Delete" << endl;
        break;
      case 4:
        cout << "Print" << endl;
        obj.print2D(obj.root, 5);
        cout << "PreOrder" << endl;
        obj.printPreorder(obj.root);
        cout << endl;
        cout << "InOrder" << endl;
        obj.printInorder(obj.root);
        cout << endl;
        cout << "PostOrder" << endl;
        obj.printPostorder(obj.root);
        cout << endl;
        break;
      case 5:
        system("cls");
        break;
      default:
        cout << "Enter a valid option";
        break;
    }
  }while(option!=0);
  return 0;
}