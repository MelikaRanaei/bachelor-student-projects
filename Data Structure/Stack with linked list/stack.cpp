#include <iostream>
using namespace std;



class Node {

public:

     int data;
     Node *next;

};


class stack{

public:

     Node* top = NULL;
    void push(int);
    int isEmpty();
    void pop();
    int peek();
    

};


void stack::push(int value) {

    Node* newnode = new Node;
   newnode->data = value;
   newnode->next = top;
   top = newnode;

}


int stack::isEmpty()

{
    return top == NULL;
}


void stack::pop() {

    
   if(isEmpty())
   cout<<"Stack is empty"<<endl;

   else {
      top = top->next;

   }
}


int stack::peek()

{
    if (!isEmpty())
        return top->data;
    else
        return -1;
}



int main() {

    int n;
    cin>>n;
    stack stack;

    for(int i=0;i<n;i++){

        int choose;
        cin>>choose;

        if(choose==1){

            int x;
            cin>>x;
            stack.push(x);

        }

        if(choose==2){

            stack.pop();
            
        }

        if(choose==3){
            cout<<"\n"<<stack.peek();
            
        }
    }
    return 0;
}
