#include "person.h"

    person::person(){
        first_name = first_name;
        last_name = last_name;
        classification = classification;
        phone = phone;
        mail = mail;
        favorate = favorate;

    }

 person::person(string fn,string ln,string p,string cla,string m,bool f,addrese a )
  {
first_name=fn;
last_name=ln;
phone=p;
classification=cla;
mail=m;
favorate=f;
Addrese=a;

  }

string person::get_first_name()const{
return first_name;
}

string person::get_last_name()const{
return last_name;
}

string person::get_classification()const{
return classification;
}

string person::get_phone()const{

   char c;
   for(int i=0;i<phone.length();i++)
   {
         c=phone[i];
   }
    if (c >= '0' && c <= '9') return "";
	if (c >= 'a' && c <= 'z') return "";
	if (c >= 'A' && c <= 'Z') return "";

return phone;
}

string person::get_mail()const{
return mail;
}
bool person::get_favorate()const{
return favorate;
}

void person::print_cin_add(){
cout<<"Fn: ";
cin>>first_name;
cout<<endl<<"Ln: ";
cin>>last_name;
cout<<endl;
cout<<"class (freind,work,family,other): ";
cin>>classification;
cout<<endl;

cout<<"Set as Fav: (press 1(fav) or 0 (Not) ) : ";
cin>>favorate;
cout<<endl;

string temp_phone;
phone=" ";
size_t n;
cout<<"How many number: ";
cin>>n;
int temp=1;
while(n--){
    cout<<"phone #"<<temp<<":";
   cin>>temp_phone;
    if(temp==1)
    {
        phone+=temp_phone;
         cout<<endl;
    }
    else
    {
        phone+=","+temp_phone;
        cout<<endl;
    }
++temp;
}

size_t m;
cout<<"How many mails: ";
cin>>m;
int mtemp=1;
while(m--){
    cout<<"mail #"<<mtemp<<":";
    cin>>mail;
    cout<<endl;
    ++mtemp;

}

display(); //addrese

}

size_t person::getid(){
return id++;
}

void person::showdata(size_t id){

if(id==1){
    cout<< setw(20) << left << "ID"
         << setw(20)  << "FName"
         << setw(20)  << "LName"
         << setw(20)  << "Classification"
         << setw(10)  << "Fav"
         << setw(40)  << "Address"
         << setw(80)  << "Phone Number" << endl;
          cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" ;
          }


    string full_addrese=street_number+" "+street_name+" "+city+" "+country;

        cout << setw(20)  << id
         << setw(20)  << first_name
         << setw(20)  << last_name
         << setw(20)  << classification
         << setw(10)  << favorate
         << setw(40)  << full_addrese
         << setw(80) << phone
         <<endl;
          cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------";



}


void person::showfav (size_t id){
  static bool ch=0;
if(!ch){
    cout<< setw(20) << left << "ID"
         << setw(20)  << "FName"
         << setw(20)  << "LName"
         << setw(20)  << "Classification"
         << setw(10)  << "Fav"
         << setw(30)  << "Address"
         << setw(80)  << "Phone Number" << endl;
          cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
     ch=1;
}


    string full_addrese=street_number+" "+street_name+" "+city+" "+country;

        cout << setw(20)  << id
         << setw(20)  << first_name
         << setw(20)  << last_name
         << setw(20)  << classification
         << setw(10)  << favorate
         << setw(30)  << full_addrese
         << setw(80) << phone
         <<endl;
          cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------";



}

void person::load(){


 ifstream file_load("load.txt");

    if(!file_load.is_open()){
      cout<<"  "<<endl;
     return;
    }

cout<<"Fn: ";
file_load>>first_name;
cout<<endl<<"Ln: ";
file_load>>last_name;
cout<<endl;
cout<<"class (freind,work,family,other): ";
file_load>>classification;
cout<<endl;

cout<<"Set as Fav: (press 1(fav) or 0 (Not) ) : ";
file_load>>favorate;
cout<<endl;

string temp_phone;
phone=" ";
size_t n;
cout<<"How many number: ";
file_load>>n;
int temp=1;
while(n--){
    cout<<"phone #"<<temp<<":";
    file_load>>temp_phone;
    if(temp==1)
    {
        phone+=temp_phone;
         cout<<endl;
    }
    else
    {
        phone+=","+temp_phone;
        cout<<endl;
    }
++temp;
}

size_t m;
mail=" ";
cout<<"How many mails: ";
file_load>>m;
int newtemp=1;
while(m--){
    cout<<"mail #"<<newtemp<<":";
    file_load>>mail;
    cout<<endl;
    ++newtemp;

}

 cout<<"          ::Enter Addrese details::"<<endl;
    cout<<"streetnum:";
    file_load>>street_number;
    cout<<endl;
    cout<<"streetname:";
    file_load>>street_name;
    cout<<endl;
    cout<<"town:";
    file_load>>city;
    cout<<endl;
    cout<<"state:";
    file_load>>country;
    cout<<endl;

file_load.close();
}

