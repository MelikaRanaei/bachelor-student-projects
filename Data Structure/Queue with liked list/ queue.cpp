#include <iostream>

using namespace std;


class Node {

public:

     int data;
     Node *next;

};


class queue{

public:

    Node *rear = NULL;
    Node *front = NULL;
    void push(int);
     void pop();
    int printfront();
    int printrear();
    bool isEmpty();
    
    
    
};


bool queue::isEmpty(){

    return (front==NULL && rear==NULL);
    
}

void queue::push(int value) {

    Node *newnode=new Node;

    newnode->data=value;

    newnode->next=NULL;

    if(isEmpty()){

        front=newnode;
        rear=newnode;
        
    }else{

    rear->next=newnode;
        rear=newnode;
        
    }
}

void queue::pop() {

     Node *newnode=front;

    if(front==NULL)

        cout<<"queue is empty";

    if(front==rear){

        front=NULL;
        rear=NULL;

    }else{

        front=front->next;
    }

    free(newnode);
}

int queue::printfront(){

    if(isEmpty()){
        return -1;

    }else{

        return front->data;
    }
    
}

int queue::printrear(){

    if(isEmpty()){

        return -1;
    }else{

        return rear->data;
    }
}


int main() {

    int n;

    cin>>n;

    queue queue;

    for(int i=0;i<n;i++){

        int choose;
        cin>>choose;

        if(choose==1){
            
            int x;
            cin>>x;
            queue.push(x);
            
        }
        if(choose==2){
            queue.pop();
            
        }
        if(choose==3){
            cout<< queue.printfront()<<endl;
                   
        }
        if(choose==4){
            cout<<queue.printrear()<<endl;
        }
    }
    return 0;
}
