#ifndef CONTACT_H
#define CONTACT_H
#include"person.h"
#include<iostream>
#include"../ADT.h"
using namespace std;
class contact:public person
{
    public:
        contact();
       void add_new_contact();
       void search_by_last_name();
       void search_by_classific();
       void print_all_contact();
       void print_fav_contacts();
       void reverse_contacts();
       void delete_contact();
       void save_file_contact();
       void share_contact();
       void  update_contact();
       void load_from_file();
       void show_consol();

    private:
        person p;
       ADT_dynamic<person> operation;
};

#endif // CONTACT_H
