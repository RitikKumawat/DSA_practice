#include<iostream>
#include<map>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data=val;
            next=NULL;
        }
};

void print(node* head){
    node* temp=head->next;
    cout<<head->data<<"->";
    while(temp!=head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<endl;
}


bool detectCycle(node* head){
    if(head==NULL)
        return false;
    map<node*,bool> visited;
    node* temp=  head;
    while(temp!=NULL){
        if(visited[temp]){
            cout<<"Present on element:"<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp=temp->next;
    }
    return false;
}

node* floydDetectCycle(node* head){
    if(head==NULL)
        return NULL;

    node* slow = head;
    node* fast = head;

    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;

        if(slow==fast){
            
            return slow;
        }
    }
    return NULL;
}

node* getStartingNode(node* head){
    if(head==NULL)
        return NULL;

    node* intersection = floydDetectCycle(head);
    node* slow = head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(node* head){
    if(head==NULL)
        return ;
    node* startOfLoop = getStartingNode(head);
    node* temp=startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}


int main(){

node* node1 = new node(1);
node* node2 = new node(2);
node* node3 = new node(3);
node* node4 = new node(4);
node* node5 = new node(5);
node* node6 = new node(6);
node* head=node1;

node1->next = node2;
node2->next = node3;
node3->next = node4;
node4->next = node5;
node5->next = node6;
node6->next = node3;


// Step 1 detecting Cycle 
// if(detectCycle(head)){
//     cout<<"Cycle present in linked list"<<endl;

// }
// else{
//     cout<<"Cycle not present"<<endl;

// Optimized approach to detect cycle 
if(floydDetectCycle(head)!=NULL){
    cout<<"CYcle Present"<<endl;
}
else{
    cout<<"Cycle not present "<<endl;
}


// Finding Starting node of LOOP 
node* ans = getStartingNode(head);
cout<<"Cycle Present at: "<<ans->data<<endl;


// Removing LOOP from linklist
cout<<"Removing LOOP"<<endl;
removeLoop(head);
print(head);

return 0;
}