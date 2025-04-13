#include <iostream>
#include <math.h>


using namespace std;
int  fullSegmentSize, n, segment;


class Node {

public:

    int value;
    Node* next;

};

class LinkedList {

public:

    Node* head = NULL;
    void insertlast(int);
    void insertFirst(int);
    void insertAt(int, int);
    void remove(int);
    Node* get(int );
    Node* getTail();
    void removeTail();
};


void LinkedList::insertlast(int data) {

    Node* node = new Node;
    node->value = data;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    }

    else {

        Node* temp = head;

        while (temp->next != NULL) {

            temp = temp->next;
        }
        temp->next = node;
    }
}


void LinkedList::insertFirst(int data) {

    Node* node = new Node;
    node->value = data;
    node->next = head;
    head = node;
}


void LinkedList::insertAt(int s, int data) {

    Node* node = new Node;
    node->value = data;
    node->next = NULL;

    if (s == 1) {
        insertFirst(data);
    }
    else {
        Node* temp = head;
        for (int i = 0; i < s - 2; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
}


void LinkedList::remove(int index) {

    if (index == 1) {
        head = head->next;
    }
    else {
        Node* temp = head;
        Node* temp1 = NULL;
        for (int i = 0; i < index - 2; i++) {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
    }
}


Node* LinkedList::get(int index) {

    Node* c = head;
    for (int i = 0; i < index; i++)
        c = c->next;
    return c;
}


Node* LinkedList::getTail() {

    Node* c = head;
    while (c->next != NULL) {
        c = c->next;
    }
    return c;
}


void LinkedList::removeTail() {

    Node* c = head;
    while (c->next->next != NULL) {
        c = c->next;
    }
    c->next = NULL;
}


int main() {
    
    int n, m;
    cin >> n >> m;


    double sq = sqrt(n);
    fullSegmentSize = ceil(n / sq);
    int remainSegmentSize = n % fullSegmentSize;
    int segment;
    if (remainSegmentSize != 0) {
        segment = (int)(n / fullSegmentSize) + 1;
    }
    else {
        segment = (int)(n / fullSegmentSize);
    }


    LinkedList* fullList = new LinkedList;
    int inputValue = 0;
    for (int i = 0; i < n; i++) {
        cin >> inputValue;
        fullList->insertlast(inputValue);
    }


    LinkedList** lists = new LinkedList * [segment];
    for (int i = 0; i < segment; i++)
        lists[i] = new LinkedList;

    for (int i = 0; i < (int)(n / fullSegmentSize); i++) {
        int startPos = i * fullSegmentSize;
        int endPos = (i + 1) * fullSegmentSize;
        for (int j = startPos; j < endPos; j++) {
            lists[i]->insertlast(fullList->get(j)->value);
        }
    }
    if (remainSegmentSize != 0) {
        for (int j = n - remainSegmentSize; j < n; j++) {
            lists[segment - 1]->insertlast(fullList->get(j)->value);
        }
    }

    for (int k = 0; k < m; k++) {
        int choose, s, e;
        cin >> choose;
        if (choose == 1)
        {
            cin >> s >> e;
            int whichList, finalIndex;

            if (e <= (segment - 1) * fullSegmentSize)
                whichList = (int)((e - 1) / fullSegmentSize);
            else
                whichList = segment - 1;
            finalIndex = (e - (fullSegmentSize * whichList)) - 1;

            Node* eTemp = lists[whichList]->get(finalIndex);
            lists[whichList]->remove(finalIndex + 1);

            int eWhichList = whichList;

            if (s <= (segment - 1) * fullSegmentSize)
                whichList = (int)((s - 1) / fullSegmentSize);
            else
                whichList = segment - 1;
            finalIndex = (s - (fullSegmentSize * whichList)) - 1;

            lists[whichList]->insertAt(finalIndex + 1, eTemp->value);

            for (int i = whichList; i < eWhichList; i++) {
                lists[i + 1]->insertFirst(lists[i]->getTail()->value);
                lists[i]->removeTail();
            }
        }
        else if (choose == 2) {
            cin >> s;
            int whichList, finalIndex;
            if (s <= (segment - 1) * fullSegmentSize)
                whichList = (int)((s - 1) / fullSegmentSize);
            else
                whichList = segment - 1;
            finalIndex = (s - (fullSegmentSize * whichList)) - 1;
            // this query is O(sqrt(n))
            cout << lists[whichList]->get(finalIndex)->value << endl;
        }
    }
    return 0;
}
