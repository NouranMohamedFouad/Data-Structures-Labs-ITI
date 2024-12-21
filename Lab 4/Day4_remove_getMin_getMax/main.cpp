#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * Right;
    Node * Left;
    Node(int _data){
        data=_data;
        Right=Left=NULL;
    }
};
class Tree{
    private:
    Node * root;
    Node * getNodeByData(int data){
        Node * current =root;
        while(current != NULL ){
            if(data == current->data){
                return current;
            }else if(data > current->data){
                current=current->Right;
            }else{
                current=current->Left;
            }
        }
        return NULL;

    }
    Node * getParent(Node * node){
        Node * parent=root;
        while(parent != NULL){
            if(node == parent->Right ||node == parent->Left  ){
                return parent;
            }else if(node->data > parent->data){
                parent=parent->Right;
            }else{
                parent=parent->Left;
            }
        }
        return NULL;

    }
    Node * getMaxRight(Node * node)
    {
        Node * current=node;
        while(current->Right != NULL){
            current=current->Right;
        }
        return current;
    }

    void display(Node *node){
        if(node == NULL){
            return ;
        }
        display(node->Left);
        cout<<node->data<<" : ";
        display(node->Right);
    }
    ////////////////////////////////////////
     Node* getMin(Node* node)
    {
        Node * current=node;
        while(current->Left != NULL){
            current=current->Left;
        }
        return current;
    }
    //////////////////////////////////////////


    public:
    Tree(){
        root=NULL;
    }
    void add(int data){
        //Create Node
        Node * newNode=new Node(data);
        if(root == NULL){
            root=newNode;
        }
        else{
            Node * current = root;
            Node * parent = NULL;
            while(current != NULL){
                parent=current;
                if(data > current->data){
                    current=current->Right;
                }else{
                    current=current->Left;
                }
            }
            if(data>parent->data){
               parent->Right=newNode;
            }else{
                parent->Left=newNode;
            }

        }
    }
    int findDataInTree(int data){
        if(getNodeByData(data)== NULL){
            return 0;
        }
            return 1;
    }
    int getParentBydata(int data){
        Node * node = getNodeByData(data);
        if(node == root){
            throw "The Node is Root Not Have Parent";
        }
        if(node != NULL ){
            Node * parent=getParent(node);
            if(parent != NULL){
                return parent->data;
            }
        }else{
            throw " Node Not Found , Not Have Parent";
        }

    }
    int getMaxRightByData(int data){
        Node * node=getNodeByData(data);
        if(node == NULL){
            throw " Node Not Found";
        }
        Node * maxR= getMaxRight(node);
        return maxR->data;
    }
    //////////////////////////////////////////////
    int getMaxOfTree()
    {
        if(root==NULL)
        {
            throw "tree is empty";
        }
        Node * maxR= getMaxRight(root);
        return maxR->data;
    }
    //////////////////////////////////////////////
    int getMinOfTree(){

        if(root==NULL)
        {
            throw "tree is empty";
        }
        Node * min= getMin(root);
        return min->data;
    }
    //////////////////////////////////////////////

    void displayAll(){
        cout<<endl;
        display(root);
    }
    ////////////////////////////////////////////
    void Remove(int data)
    {
        Node* node=getNodeByData(data);
        if(node==NULL){
            throw "error,the node is not exist";
        }
        if(node==root){

            throw "error,the root node can not be deleted";
        }
        else
        {
            Node* parent=getParent(node);
            Node* newChild;
            if(node->Left==NULL && node->Right==NULL)
            {
                newChild=NULL;
            }
            else if(node->Left==NULL)
            {
                newChild=node->Right;

            }
            else if(node->Right==NULL)
            {
                newChild=node->Left;

            }
            else
            {
                Node* newParent=node->Left;
                Node* maxRight=getMaxRight(newParent);
                maxRight->Right=node->Right;
                newChild=newParent;
            }

            if(parent->Right==node)
            {
                parent->Right=newChild;
            }
            else
            {
                parent->Left=newChild;
            }

        }
        delete node;
    }
};

int main()
{
    Tree t;
    t.add(50);
    t.add(40);
    t.add(70);
    t.add(30);
    t.add(65);
    t.add(60);
    t.add(35);
    t.add(42);
    t.add(45);
    t.add(48);
    t.add(25);
    t.add(22);
    t.findDataInTree(70)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(35)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(40)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(50)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(30)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(80)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    t.findDataInTree(90)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    try
    {
        t.displayAll();
        cout<<endl;
        cout<<"Parent of node 35: "<<t.getParentBydata(35)<<endl;
        cout<<"Max node of the tree : "<<t.getMaxOfTree()<<endl;
        cout<<"Min node of the tree : "<<t.getMinOfTree()<<endl;

        t.Remove(48);
        cout<<"node deleted successfully"<<endl;
        t.Remove(50);
        cout<<"node deleted successfully"<<endl;
        t.displayAll();


    }
    catch(const char * msg)
    {
        cout<<msg;
    }







    return 0;
}
