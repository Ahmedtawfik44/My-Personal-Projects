#include <iostream>
using namespace std;
template<typename T>
struct Node{
T data;
Node *next;
Node *prev;
Node():next(nullptr){}
};

template<typename T>
class dll{
private:
    Node<T> *head;
public:
sll():head(nullptr){}

bool is_Empty(){
    return(head==nullptr);
}

bool is_found(T x){
bool ch=false;
Node<T> *temp=head;
while(temp!=nullptr){
    if(temp->data==x)
        ch=true;
    temp=temp->next;
}
return ch;
}

void insert_first(T x){
   Node<T> *newnode=new Node<T>();
    newnode->data=x;

if(is_Empty()){
  head=newnode;
  newnode->next=newnode->prev=nullptr;
}

else{
    newnode->next=head;
    newnode->prev=nullptr;
    head->prev=newnode;
     head=newnode;
}
}

void insert_pos(T x){
if(is_Empty()){
insert_first(x);
}
if(is_found(x)){
     Node<T> *newnode=new Node<T>();
     Node<T> *temp=head;
    newnode->data=x;
while(temp!=nullptr && temp->next->data==x){
    temp=temp->next;
}

newnode->next=temp->next;
temp->next->prev=newnode;
newnode->prev=temp;
temp->next=newnode;

}
else{
    cout<<" Item Not Found ";
}
}

void insert_End(T x){
if(is_Empty())
    insert_first(x);
else{
    Node<T> *newnode=new Node<T>();
    Node<T> *temp=head;
    newnode->data=x;
while(temp->next!=nullptr){
    temp=temp->next;
}
temp->next=newnode;
newnode->next=nullptr;
newnode->prev=temp;
}
}

void delete_first(){
if(is_Empty())
    cout<<"linked List is Empty "<<endl;
if(head->next==nullptr){
    delete head;
    head=nullptr;
}
else{
    Node<T> *temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
}

}

void delete_pos(T x){
if(is_Empty()){
  cout<<"Linked List Is Empty "<<endl;
  return;
}
if(head->next==nullptr){
        if(head->data==x)
          {
               delete head;
            head=nullptr;
          }
          else cout<<"not found item "<<endl;
          return;
}
if(head->data==x)
    {
        delete_first();
        return;
    }
if(is_found(x)){
    Node<T> *prv=nullptr;
    Node<T> *curr=head;
while( curr!=nullptr&& curr->data!=x){
prv=curr;
curr=curr->next;
}
if(curr==nullptr)
    {
        cout<<"Not found item "<<endl;
        return;
    }
prv->next=curr->next;
 if (curr->next != nullptr) {
            curr->next->prev = prv;
        }
delete curr;
}
else
    cout<<"item not found "<<endl;
}

void delete_End(){
if(is_Empty())
    cout<<"Linked List Is Empty "<<endl;
if(head->next==nullptr){
    delete head;
    head=nullptr;
}
else{
    Node<T> *temp=head;
while(temp->next->next!=nullptr){
    temp=temp->next;
}
delete temp->next;
temp->next=nullptr;
}

}

size_t counter(){
size_t c=0;
Node<T> *temp=head;
while(temp!=nullptr){
        c++;
    temp=temp->next;
}
return c;
}

void print(){
Node<T> *temp=head;
while(temp!=nullptr){
    cout<<temp->data;
    if(temp->next!=nullptr)
                cout<<" -> ";
    temp=temp->next;
}
}

};


