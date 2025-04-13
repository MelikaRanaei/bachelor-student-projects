
#include <iostream>
using namespace std;

struct Node{

    float data;
    Node *left;
    Node *right;
};


Node* newnode(float data){ //creat a node

    Node* node=new Node;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
    
}

//________________________________________________

void insert(Node* &root,float data){ //this function is for store new data
    if(root==NULL)
        root=newnode(data);
    else if(root->data>data) //if data less than root data must be for left subtree
        insert(root->left,data);
    else insert(root->right,data);//if data greater than root data must be for right subtree
}
//_________________________________________________
void display(Node* root,int choose){  //this function is for display in order and pre order
    if(choose ==1){//in order
       if(root!=NULL){
       //L root R   inorder
        display(root->left,1);
        cout<<root->data<<" ";
           display(root->right,1);
           
       }
    }
    if (choose==2){//pre order
        if(root!=NULL){
              //root L R  pre order
           cout<<root->data<<" ";
            display(root->left,2);
            display(root->right,2);
               
            
           }
    }
}

//________________________________________________
int countnodes(Node* root,int choose){
    
//    int count=0;
    if(choose==1){  //This part is for return the number of leaf
        if(root==NULL) return 0;
        else
            if(root->left==NULL && root->right==NULL)
                return 1;
            else
                return countnodes(root->left,1)+ countnodes(root->right,1);
    }
            
    
   else if (choose==2){ //This part is for return the number of non-leaf
        if(root==NULL || (root->left==NULL && root->right==NULL)) return 0;
        else
        return 1+countnodes(root->left,2)+ countnodes(root->right,2);
    
    }
   else return -1;//means invalid choose
}

//_______________________________________________
//when we call  deletenode() function we need this function for find mimimum in a subtree
Node* findmin(Node* root){
    Node* temp=root;
    //find the leftmost element
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

//_______________________________________________
//for deletea node we have 3 part :1 the node has no child .2 the node has one child. 3the node has two child
Node* deletenode(Node* root,float data){
    if(root==NULL) return root;
     // if data less than root call leftsubtree
    else if(data<root->data) root->left=deletenode(root->left,data);
    // if root less than data call rightsubtree
    else if(data>root->data) root->right=deletenode(root->right,data);
    else{
        
        //no child
        if(root->left==NULL && root->right==NULL){//this means has nochild and leaf
            root=NULL;
        }
        // one child
    else if(root->left==NULL){ //has no left subtree
        Node* temp=root->right;
        return temp;
    }
    else if(root->right==NULL){//has no right subtree
        Node* temp=root->left;
        return temp;
       
    }
    //two child
    else{
        Node* temp=findmin(root->right);//smallest in the right subtree(successor)
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);//delete successor
        
        }
    }
    return root;
    
}



//______________________________________________
Node* remove_Duplicate(Node* root){
    if (root==NULL)
        return 0;
  //while data equal to parent's data to be in right subtree
   if(root->right!=NULL)
        root->right = deletenode(root->right,root->data);
    remove_Duplicate(root->left);
    remove_Duplicate(root->right);

    root->right = deletenode(root->right,root->data);// data equal to root-> data to be in the tree or no
    return root;
}

//_______________________________________________
float lowerbound(Node* root,float input){
    if(root==NULL)
        return -1;
//    if(root->data==input) return root->data;
    if(root->left==NULL && root->right==NULL && root->data<input)
         return -1;
    if((root->data>=input && root->left==NULL) || (root->data>=input && root->left->data<input))
           return root->data;

    if(root->data<=input) return lowerbound(root->right,input);

    else return lowerbound(root->left,input);


}
//_______________________________________________
int main() {
     Node *root=NULL;
    int n ,choose;
    float x,y,z;
    cin>>n;
    
//    cout<<"please choose:"<<endl;
//    cout<<"1 x-> "<<endl;      //insert x
//    cout<<"2 -> "<<endl;      //print inorder & pre order
//    cout<<"3 -> "<<endl;     //the number of leaf
//    cout<<"4 -> "<<endl;    //the number of non-leaf
//    cout<<"5 y-> "<<endl;  //delete
//    cout<<"6 -> "<<endl;  //remove_Duplicate
//    cout<<"7 z-> "<<endl;//lowerBound
    for(int i=0;i<n;i++){
    cin>>choose;
    if(choose==1){
        cout<<"please enter a key for insert:";
        cin>>x;
        insert(root,x);
//         insert(root,12.3);
//         insert(root,-7);
//         insert(root,0.56);
//         insert(root,-11.2);
//         insert(root,17);
//         insert(root,-7);
//         insert(root,31);
//         insert(root,0.56);
//         insert(root,21);
//         insert(root,-1);
//

    }
    if(choose==2){
        cout<<"in order:";
       display(root,1);
       cout<<endl;
        cout<<"pre order:";
       display(root,2);
    }
    if(choose==3){
        cout<<"The numbet of leaf:";
        cout<<countnodes(root,1);
        

    }
    if(choose==4){
        cout<<"The numbet of non-leaf:";
       cout<<countnodes(root,2);
    }
    if(choose==5){
        cout<<"please enter a key for delete:";
        cin>>y;
        deletenode(root,y);
        display(root,1);
        
    }
    if(choose==6){
        cout<<"remove duplicate: ";
        remove_Duplicate(root);
        display(root,1);
    }
    if(choose==7){
        cout<<"please enter a number:";
        cin>>z;
        cout<<"the lowerbound is:";
        cout<<lowerbound(root,z);

        
         
    }
   
    }
    return 0;
}
