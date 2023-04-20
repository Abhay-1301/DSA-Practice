#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;

    }
    Node(){
        next = NULL;
    }
};

class linkedlist{
    public:
    Node* head;

    linkedlist(){
        head = NULL;
    }

    Node* insertAtFront(int value){
        Node* New = new Node(value);
        if(head==NULL){
            head=New;
            return head;
        }
        else {
            New->next=head;
            head=New;
            return head;
        }
    }

    Node* reverse(){
        if(head==NULL){
            return NULL;
        }
        else{
            Node* prev = NULL;
            Node* curr = head;
            Node* nxt = NULL;
            while(curr!=NULL){
                nxt=curr->next;
                curr->next=prev;
                prev = curr;
                curr=nxt;
            }
            head=prev;
            return head;
        }
    }
};

int main()
{
    linkedlist * num1 = new linkedlist();
    linkedlist * num2 = new linkedlist();
    linkedlist * ans = new linkedlist();
    int carry = 0;
    int n,m;
    cin>>n;
    cin>>m;
    for(int i = 0 ; i < n ;i++){
        int x;
        cin >> x;
        num1->insertAtFront(x);
    }
    for(int i = 0 ; i < m ;i++){
        int x;
        cin >> x;
        num2->insertAtFront(x);
    }
    Node* head1 = num1->reverse();
    Node* head2 = num2->reverse();
    stack<int>st1;
    Node* ptr1=head1;
    while(ptr1!=NULL){
        st1.push(ptr1->data);
    }
    stack<int>st2;
    Node* ptr2=head2;
    while(ptr2!=NULL){
        st2.push(ptr2->data);
    }
    while(!st1.empty() && !st2.empty()){
        int x = st1.top() * st2.top() + carry;
        
    }
    return 0;
}