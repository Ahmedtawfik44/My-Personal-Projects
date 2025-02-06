#include <iostream>
#include"person.h"
#include"container.h"
#include"contact.h"
using namespace std;

int main()
{
contact c;

while(true){
int n;

c.show_consol();

cout<<"Enter Your Choise : ";
cin>>n;
cout<<endl;

switch(n){
case 1 :
     c.add_new_contact();
     break;

case 2 :
    c.search_by_last_name();
    break;

case 3 :
    c.search_by_classific();
    break;

case 4 :
    cout<<"                           ---- Contacts Information ----                                                 "<<endl;
    cout<<"                ======================================================                                    " <<endl<<endl;
    c.print_all_contact();
    break;

case 5:
    c.print_fav_contacts();
    break;

case 6 :
    c.save_file_contact();
    break;

case 7 :
c.load_from_file();
break;

case 8 :
    c.delete_contact();
    break;

case 9 :
    c.update_contact();
    break;

case 10 :
    c.share_contact();
    break;

case 11 :
    c.reverse_contacts();
    break;

case 12 :
    return 0;
}

}


    return 0;
}
