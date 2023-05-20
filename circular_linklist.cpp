#include<iostream>
using namespace std;


class node{
public:
    int data;
    node* next;
    
    node(int val){
          data = val;
          next=NULL;
          }

    ~node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memeory deleted for element: "<<val<<endl;
    }
};

void insertNode(int element, node* &tail, int d){
    if(tail == NULL){
        node* newNode = new node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        node* curr =tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* temp = new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}


void deleteNode(node* &tail, int element){
    if(tail == NULL){
        cout<<"Empty list, insert some element first "<<endl;
        return;
    }
    else{
        node *prev =tail;
        node *curr =prev->next;
        while(curr->data != element){
                prev=curr;
                curr=curr->next;
        }
        //1 node linklist
        if(curr==prev){
            tail=NULL;
        }

        // 2 or more than two node linklist
        if(tail==curr){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}


void print(node* tail){
    if(tail==NULL){
        cout<<"Empty list------List not found**************check again"<<endl;
        return;
    }  
    node* temp =tail;

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}


int main(){

node * tail = NULL;
insertNode(2,tail,10);
print(tail);


insertNode(10,tail,20);
print(tail);

insertNode(10,tail,30);
print(tail);

insertNode(20,tail,50);
print(tail);

deleteNode(tail,10);
print(tail);

deleteNode(tail,30);
print(tail);
return 0;
}