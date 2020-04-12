#include <iostream>
using namespace std;

struct BSTnode {
    int data;
    BSTnode *left;
    BSTnode *right;
};

BSTnode *create_node(int);
BSTnode *insert(BSTnode*, int);
bool search(BSTnode*, int);

BSTnode* create_node(int data)
{
    BSTnode *node = new BSTnode();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BSTnode* insert(BSTnode *node, int data)
{
    if (node == NULL) {
        node = create_node(data);
        return node;
    }
    else if (data <= node->data) {
        node->left = insert(node->left, data);
    }
    else {
        node->right = insert(node->right, data);
    }
    
    return node;
}

bool search(BSTnode *node, int data)
{
    if (node == NULL) return false;
    else if (node->data == data) return true;
    else if (data <= node->data) return search(node->left, data);
    else return search(node->right, data);
}

int main()
{
    int data[10];
    cout << "Enter 10 integers: ";
    for (int i=0; i<10; i++)
        cin >> data[i];

    BSTnode *root_node = NULL;
    for (int i=0; i<sizeof(data); i++)
        root_node = insert(root_node, data[i]);
    
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if (search(root_node, number) == true) {
        cout << "Found number in tree!" << endl;
    }
    else {
        cout << "Could not find number in tree!" << endl;
    }
    
    return 0;
}
