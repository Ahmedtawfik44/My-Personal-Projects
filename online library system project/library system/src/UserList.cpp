#include "UserList.h"

UserList::UserList()
{
    capacity=0;
    usersCount=0;
}
UserList::UserList(int capacity )
{
    this->capacity=capacity;
    users=new User[capacity];
    usersCount=0;
}
void UserList::addUser(User &u)
{
    if(usersCount<capacity)
    {
       users[usersCount]=u;
       users[usersCount].setId(usersCount+1);
        usersCount++;
    }
    else
        cout<<"the array full"<<endl;
}
User* UserList::searchUser(string name )
{
    for(int i=0; i<usersCount; i++)
        if(users[i].getName()==name)
            return &users[i];
    return nullptr;
}
User* UserList::searchUser(int id )
{
    for(int i=0; i<usersCount; i++)
        if(users[i].getId()==id)
            return &users[i];
    return nullptr;
}
void UserList::deleteUser(int id )
{
    for(int i=0; i<usersCount ; i++)
        if(users[i].getId()==id)
        {
            while(i<usersCount-1)
            {
                users[i]=users[i+1];
                users[i].setId(i+1);
                i++;
            }
            usersCount--;
            capacity--;
            break;
        }
}
ostream &operator<<( ostream& o,const UserList& u)
{
    for(int i=0; i<u.usersCount; i++)
        o<<u.users[i];
    return o;
}
UserList::~UserList()
{
    delete []users;
}
