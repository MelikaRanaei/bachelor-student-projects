
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


//part 1


struct TrieNode{

    TrieNode* children[2];
    TrieNode() {
       children[0] = NULL;
       children[1] = NULL;
    }

};


//part 2


struct SegmentNode{

    TrieNode* trie;
    SegmentNode* left;
    SegmentNode* right;
    SegmentNode* root;
    int start;
    int end;


    SegmentNode(int start, int end){
       this->start = start;
       this->end = end;
       this->right = NULL;
       this->left = NULL;
       this->trie = NULL;
       
    }

};
struct segmenttree{


    int getmid(int s, int e) {
       return (e+s)/2;
    }
    int Binary(int number,int i){
       return (bool)((number >> i) & 1);
    }

    void insert_trietree( TrieNode *root,int x){
       TrieNode* temp = new TrieNode();
       temp=root;

       for (int i = 19; i >= 0; i--)
       {
          int bit =  Binary(x,i);
          if(bit==1){
             if (! temp->children[1])
                temp->children[1] = new TrieNode();
             temp = temp->children[1];

          }
          if(bit==0){
             if (! temp->children[0])
                temp->children[0] = new TrieNode();
             temp = temp->children[0];
          }

       }

    }
    int max_Xor(TrieNode *root, int x)
    {

       TrieNode* temp = root;
       int ans = 0;
       for (int i = 19; i >= 0; i--) {
          int bit = Binary(x,i);
          if (bit == 0) {
             if (temp->children[1] != NULL) {
                ans += 1 << i;
                temp = temp->children[1];

             } else if (temp->children[0] !=NULL) {
                temp = temp->children[0];
             }
          } else {
             if (temp->children[0] != NULL) {
                ans += 1 << i; // same as pow(2, i)
                temp = temp->children[0];
             } else if (temp->children[1] !=NULL) {

                temp = temp->children[1];
             }
          }
       }
       return ans;



    }



    void removeNode_trietree(TrieNode *root,int new_data){
       stack <TrieNode*> s;
       bool isleftorright;
       s.push(root);
       TrieNode* curr ;
       TrieNode* parent ;

       for (int i = 19; i >= 0; i--){
          int bit=Binary(new_data,i);
          if(bit){
             root = root->children[1];
          }else {
             root = root->children[0];
          }
          s.push(root);
       }


       for (int i = 0; i <= 19; i++) {
          curr = s.top();
          s.pop();
          parent = s.top();
          s.push(curr);
          isleftorright = (parent->children[0] == curr);

          if (curr->children[0] == NULL && curr->children[1] == NULL)
          {
             delete curr;
             if (isleftorright==true)
                parent->children[0] = NULL;
             else
                parent->children[1] = NULL;
             s.pop();
          }
          else
             break;

       }
    }




    SegmentNode *insert_Segment(int s, int e,int *arr)
    {
       SegmentNode *node = new SegmentNode(s,e);
       if (s == e) {
          TrieNode *root = new TrieNode();
          insert_trietree(root, arr[s]);
          node->trie = root;
       } else {
          int mid = getmid(s,e);
          node->left = insert_Segment( s, mid,arr);
          node->right = insert_Segment( mid + 1, e,arr);
          auto *root = new TrieNode();
          for (int i = s; i <= e; i++) {
             insert_trietree(root, arr[i]);
          }
          node->trie = root;
       }
       return node;
    }


    void update(SegmentNode* root, int index, int new_data, int prev_data) {
      if(root->start == root->end){
         removeNode_trietree(root->trie, prev_data);
         insert_trietree(root->trie, new_data);
      } else {
         removeNode_trietree(root->trie, prev_data);
         insert_trietree(root->trie, new_data);

         int mid = getmid(root->end , root->start);
         if(index <= mid){
            update(root->left, index, new_data, prev_data);
         } else {
            update(root->right, index, new_data, prev_data);
         }
      }
    }

    int maxxor(int l, int r, int x,SegmentNode* root ) {

       int mid = getmid(root->end , root->start);
       if (l == root->start && r == root->end) {
          return (max_Xor(root->trie,x));
       }
       else {
          if (l <= mid && r <= mid)
             return (maxxor(l, r, x,root->left));

          else if (l > mid && r > mid)
             return (maxxor( l, r, x,root->right));

          else if (l <= mid && r > mid)
             return (max(maxxor( l, mid, x,root->left), maxxor( mid + 1, r, x,root->right)));

       }
       return -1;

    }

};
int main(){
   //n is size of array
   //m is the number of request

   int n,m;
   cin >> n >> m;
   int* arr = new int[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   segmenttree* tree = new segmenttree();
   SegmentNode *s=tree->insert_Segment(0, n - 1,arr);
   int feln = 0;
   for (int i = 0; i < m; i++){

      int choose;
      cin >> choose;
      if (choose == 1){
         int index,x;
         cin>>index>>x;
         tree->update(s,index - 1, x, arr[index - 1]);
         index--;
         arr[index] = x;
      }
      if (choose == 2){
         int l,r,x;
         cin>>l>>r>>x;
         int ans =tree->maxxor( l - 1, r - 1, x,s);
         cout << ans << endl;
      }

   }
   return 0;
}
