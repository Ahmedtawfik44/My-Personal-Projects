#include "playlist.h"

playlist::playlist(){
h=nullptr;
}

void playlist::add_playlist(){
    string x;
 cout << "Enter playlist name: ";
 cin>>x;

 if(find_playlist(x)){
    cout<<"You Entered this name before, do not enter it again"<<endl;

 }
 else{
 playlistnode *newnode=new playlistnode();
 newnode->playlistname=x;
 if(h==nullptr){
     h=newnode;
     newnode->next=nullptr;
      newnode->prev = nullptr;
 }


 else{
    playlistnode *temp=h;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=nullptr;
    newnode->prev=temp;

 }

 }

}

playlistnode* playlist::find_playlist(string &x){
    playlistnode *temp=h;
    while(temp!=nullptr){
        if(temp->playlistname==x)
        {
          return temp;
        }
            temp=temp->next;
    }
    return nullptr;
}

 void playlist::display_playlist(){
 size_t c=1;
 playlistnode* temp = h;
   if (temp == nullptr) {
        cout << "No playlists available" << endl;
        return;
   }

    cout << "The current Playlist are: " <<endl
          <<left<<setw(5)<<"ID"<< setw(10)<<"playlist"<<endl
         << "--------------------" << endl;

        while (temp!=nullptr) {

          cout <<left<<setw(5)<<c<<setw(20)<<temp->playlistname<<endl;
            temp = temp->next;
            c++;
        }
 }


void playlist::delete_playlist_first(){
if(h==nullptr)
    cout<<"linked List is Empty "<<endl;
if(h->next==nullptr){
    delete h;
    h=nullptr;
}
else{
   playlistnode *temp=h;
    h=h->next;
    h->prev=nullptr;
    delete temp;
}

}


void playlist::delete_playlist_pos(string x){
if(h==nullptr){
  cout<<"Linked List Is Empty "<<endl;
  return;
}
if(h->next==nullptr){
        if(h->playlistname==x)
          {
               delete h;
            h=nullptr;
          }
          else cout<<"not found item "<<endl;
          return;
}
if(h->playlistname==x)
    {
        delete_playlist_first();
        return;
    }
if(find_playlist(x)){
    playlistnode *prv=nullptr;
     playlistnode *curr=h;
while( curr!=nullptr&& curr->playlistname!=x){
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

 void playlist::remove_playlist(){
 string x;
 cout << "Enter playlist name: ";
 cin>>x;

 delete_playlist_pos(x);
 }

 void playlist::load_playlist(ifstream &f){
   string x;
 cout << "Enter playlist name: ";
 f>>x;

 if(find_playlist(x)){
    cout<<"You Entered this name before, do not enter it again"<<endl;

 }
 else{
 playlistnode *newnode=new playlistnode();
 newnode->playlistname=x;
 if(h==nullptr){
     h=newnode;
     newnode->next=nullptr;
      newnode->prev = nullptr;
 }


 else{
    playlistnode *temp=h;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=nullptr;
    newnode->prev=temp;

 }

 }

}


