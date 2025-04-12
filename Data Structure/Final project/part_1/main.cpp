
#include <iostream>
using namespace std;



class TrieNode{

public:

    TrieNode* children[2];
    bool isLeaf;
    
    
};

 
// This checks if the ith position in
// binary of N is a 1 or a 0

bool check(int N, int i)
{
    return (bool)(N & (1<<i));
}
  
// Create a new node
TrieNode* newNode()

{
    TrieNode* temp = new TrieNode;
    temp->isLeaf = false;
    temp->children[0] = NULL;
    temp->children[1] = NULL;
    return temp;
}
  
// Inserts x into the Trie
void insert(TrieNode* root, int x)
{
    TrieNode* temp = root;
  
    // padding upto 20 bits
    for (int i = 20; i >= 0; i--)
    {
        int bit = check(x, i);
        if (! temp->children[bit]) //==null
            temp->children[bit] = newNode();
        temp = temp->children[bit];
    }
   
}
  
// Finds maximum XOR of x with stream of elements so far.
int max_xor(TrieNode *root, int x)
{
    TrieNode* temp = root;
  
    int ans = 0;
    for (int i = 20; i >= 0; i--)
    {
        int bit = check(x, i);
  
        // Move to the child whose XOR with f is 1.
        if ((temp->children[bit ^ 1])) //!=null
        {
            ans = ans + (1 << i); // update answer
            temp = temp->children[bit ^ 1];
        }
  
        // If child with XOR 1 doesn't exist
        else
            temp = temp->children[bit];
    }
  
    return ans;
}


   

int main()

{
    TrieNode* root = newNode();
   insert(root,0);
 
    
    int q; // the number of request
    cin>>q;

    for(int i=0;i<q;i++){
        int choose;
        cin>>choose;
        if(choose==1){
            int x;
            cin>>x;
            insert(root,x);
        }
        
        if(choose==2){
            int x;
            cin>>x;
            cout<<max_xor(root,x)<<endl;
            
        }
    }
    return 0;
}

