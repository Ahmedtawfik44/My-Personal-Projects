#include "contact.h"
contact::contact() : operation(10) { }

 void contact::add_new_contact(){ //1
 cout<< "                        --- Add a New Contant ---                                            "<<endl;
  p.print_cin_add();
  operation.Append(p);
 }

  void contact::search_by_last_name(){  //2
      cout<<"Enter LName in Coreect Form : ";
      string ln;
      cin>>ln;
      cout<<endl;
     operation.Binairy_search_last_name(ln);

  }


void contact::search_by_classific(){  //3
  cout<<"Enter Class in Coreect Form (freind,work,family,other) : ";
      string x;
      cin>>x;
      cout<<endl;
      operation.Binairy_search_classification(x);

}


void contact::print_all_contact(){ //4
operation.print_all();
}

void contact::print_fav_contacts(){  //5
    if(favorate==1)
        operation.print_fav();
}


void contact::reverse_contacts(){  //11
operation.Reverse();
operation.print_all();
}


 void contact::delete_contact(){  //8
     cout<<"Enter index : ";
     size_t i;
     cin>>i;
     cout<<endl;
     operation.Delete(i);
     operation.print_all();

 }

  void contact::save_file_contact(){ //6
    operation.save_to_file();
  }

 void contact::share_contact(){
string l;
cout<<"Enter Last Name : ";
cin>>l;
operation.Binairy_search_last_name(l);
 }

void  contact::update_contact(){ //9
    size_t x;
    cout<<"Enter Index: ";
    cin>>x;
    cout<<endl;
operation.Delete(x);
p.print_cin_add();
operation.Insert(p,x);
operation.print_all();
}

void contact::load_from_file() {

   p.load();
operation.Append(p);

  cout<<"Data Loaded "<<endl;
}

void contact::show_consol()
{
    cout<<endl;
    cout<<"                    =========================================================================                                  "<<endl;
    cout<<"                     Contacts Book Menue:                                                                                      "<<endl;
    cout<<"                     ------------------------                                                                                  "<<endl;
    cout<<"                     1-Add a new contact                                                                                        "<<endl;
    cout<<"                     2-Search by Last Name (Enter Last Name Correctly )                                                         "<<endl;
    cout<<"                     3-Search by cllassification (freind,work,family,other)?                                                    "<<endl;
    cout<<"                     4-Print All Contacts                                                                                       "<<endl;
    cout<<"                     5-Print Fav Contact                                                                                        "<<endl;
    cout<<"                     6-Save to file                                                                                             "<<endl;
    cout<<"                     7-Load From file                                                                                           "<<endl;
    cout<<"                     8-Delete Contact                                                                                           "<<endl;
    cout<<"                     9-Update Contact Information                                                                               "<<endl;
    cout<<"                     10-Share Contact With Other                                                                                "<<endl;
    cout<<"                     11-Reverse Contacts Book                                                                                   "<<endl;
    cout<<"                     12-Exit                                                                                                    "<<endl;
    cout<<"                    =========================================================================                                   "<<endl<<endl;


}
