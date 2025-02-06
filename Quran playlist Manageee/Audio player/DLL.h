#include <iostream>
#include "audio.h"
#include"playlist.h"
#include<iomanip>
#include <fstream>


using namespace std;
template<class T>
struct Node{
T data;
Node *next;
Node *prev;
Node():next(nullptr){}
};

template<class T>
class sll{
private:
    Node<T> *head;
public:
sll():head(nullptr){}

bool is_Empty(){
    return(head==nullptr);
}

Node<T> *return_head(){
return head;
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


void insert_pos(T x, T pos)
    {
        if (is_Empty())
        {
            insert_first(x);
            return;
        }

        if (is_found(pos))
        {
            Node<T> *newnode = new Node<T>();
            Node<T> *temp = head;
            newnode->data = x;


            while (temp != nullptr && temp->data != pos)
            {
                temp = temp->next;
            }

            if (temp == nullptr)
            {
                cout << "Item Not Found" << endl;
                return;
            }


            if (temp->next == nullptr)
            {
                temp->next = newnode;
                newnode->prev = temp;
                newnode->next = nullptr;
            }
            else
            {

                newnode->next = temp->next;
                temp->next->prev = newnode;
                newnode->prev = temp;
                temp->next = newnode;
            }
        }
        else
        {
            cout << "Item Not Found" << endl;
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
    int c=1;
    if (is_Empty()){
        cout<<"NO playlist avalibale "<<endl;
        return;
        }
Node<T> *temp=head;
 cout<<"------------------------------------------------------------------------------------------------------"<<endl
  <<left<<setw(5)<<"ID"
  <<setw(40)<<"Surah"
  <<setw(40)<<"Type"
  <<setw(40)<<"Path"<<endl;
 cout<<"------------------------------------------------------------------------------------------------------"<<endl;
while(temp!=nullptr){
    const audio& content_audio = temp->data;

 cout <<left<<setw(5)<<c
 <<setw(40)<<content_audio.get_name_file()
 <<setw(40)<<content_audio.get_type_file ()
 <<setw(40)<<content_audio.get_path_file ()<<endl;
 c++;
 temp=temp->next;
}
cout<<endl<<endl;
}

void update(){
     if (is_Empty()){
        cout<<"NO playlist avalibale "<<endl;
        return;
        }
        Node<T> *temp=head;

        string s;
cout<<"Enter Name Surah : ";
cin>>s;

string t;
cout<<"Enter new position (Do you want the surah to remain after what?): ";
cin>>t;

while(temp!=nullptr){
       audio& content_audio = temp->data;
    if(content_audio.get_name_file()==s){

            audio o1=temp->data;
        audio o2=temp->data;
        o1.set_name_file(s);
        o2.set_name_file(t);

        delete_pos(content_audio);
        insert_pos(o1,o2);
        cout<<"surah "<<"'"<<s<<"'"<<"Moved to After "<<t<<endl;
        return;
    }
temp=temp->next;
}
cout<<" surah not found "<<endl;
}

void Remove(){
      if (is_Empty()){
        cout<<"NO playlist avalibale "<<endl;
        return;
        }
        Node<T> *temp=head;

       string s;
cout<<"Enter Name Surah : ";
cin>>s;


while(temp!=nullptr){
       audio& content_audio = temp->data;
    if(content_audio.get_name_file()==s){
        delete_pos(content_audio);
        cout<<"surah "<<"'"<<s<<"'"<<"Removed from playlist "<<endl;
        return;
    }
temp=temp->next;
}
cout<<" surah not found "<<endl;

}


void print_file(ofstream &f){
 int c=1;
    if (is_Empty()){
        cout<<"NO playlist avalibale "<<endl;
        return;
        }
Node<T> *temp=head;
 f<<"------------------------------------------------------------------------------------------------------"<<endl
  <<left<<setw(5)<<"ID"
  <<setw(40)<<"Surah"
  <<setw(40)<<"Type"
  <<setw(40)<<"Path"<<endl;
 f<<"------------------------------------------------------------------------------------------------------"<<endl;
while(temp!=nullptr){
    const audio& content_audio = temp->data;

 f <<left<<setw(5)<<c
 <<setw(40)<<content_audio.get_name_file()
 <<setw(40)<<content_audio.get_type_file ()
 <<setw(40)<<content_audio.get_path_file ()<<endl;
 c++;
 temp=temp->next;
}
cout<<endl<<endl;
}



};
