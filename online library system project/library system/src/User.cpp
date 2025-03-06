#include "User.h"

int User::count=0;
User::User()
{
    name=" ";
    age=0;
    password=" ";
    email=" ";
    count++;
    id=count;
}
User::User(string name, int age, string password, string email )
{
    this-> name=name;
    this-> age=age;
    this-> password=password;
    this-> email=email;
    count++;
    id=count;

}
    User::User(const User&u )
    {
        name=u.name;
        age=u.age;
        password=u.password;
        email=u.email;
        id=u.id;
    }
    bool User::operator==(const User& u )
    {
         if(id!=u.id || name!=u.name || age!=u.age ||password!=u.password|| email!=u.email)
             return false;
         return true;
    }
    void User::setName(string n)
    {
        name=n;
    }
    string User::getName() const
    {
        return name;
    }
    void User::setPassword(string p)
    {
        password=p;
    }
    string User::getPassword()const
    {
        return password;
    }
    void User::setEmail(string e)
    {
        email=e;
    }
    string User::getEmail()const
    {
        return email;
    }
    void User::setAge(int a )
    {
        age=a;
    }
    int User::getAge() const
    {
        return age;
    }
    void User::setId(int i)
    {
        id=i;
    }
    int User::getId() const
    {
        return id;
    }
    void User::Display ()
    {
        cout<<"_________________________";
        cout<<"Name : "<<name<<endl;
        cout<<"Email : "<<email<<endl;
        cout<<"password : "<<password<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"__________________________";
    }
    /*
    void User::operator=(const User &u)
    {
        name=u.name;
        age=u.age;
        passwors=u.password;
        email=u.email;
    }
    */
     istream &operator>>(istream &i, User &u)
    {
        cout<<" Enter the user Information in this order"<<endl;
        cout<<" Enter Name : "<<endl;
        i>>u.name;
        cout<<"Enter age : "<<endl;
        i>>u.age;
        cout<<"Enter email : "<<endl;
        i>>u.email;
        cout<<"Enter password : "<<endl;
        i>>u.password;

        return i;
    }
     ostream &operator<<( ostream &o, const User &u)
    {
        o<<endl<<"     User "<<u.id<<endl<<"information ... "<<endl;
        cout<<"=================================="<<endl;
        o<<"->"<<"Name : "<<u.name<<endl<<"->";
        o<<"Email : "<<u.email<<endl<<"->";
        o<<"password : "<<u.password<<endl<<"->";
        o<<"age : "<<u.age<<endl<<"->";
        o<<"ID : "<<u.id<<endl;
        cout<<"==================================="<<endl;
        return o;
    }
