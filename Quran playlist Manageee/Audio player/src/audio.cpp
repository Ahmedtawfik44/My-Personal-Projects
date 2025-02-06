   #include "audio.h"

string audio::get_name_file () const
{
    return name_surah;
}
string audio::get_path_file () const
{
    return path_surah;
}
string audio::get_type_file () const
{
    return type_surah;
}

void audio::set_name_file(string n)
{
    name_surah=n;
}
void audio::set_path_file(string p)
{
    path_surah=p;
}
void audio::set_type_file(string t)
{
    type_surah=t;
}
 void audio::sound_play(const char* p){


PlaySound(p, NULL, SND_FILENAME | SND_SYNC);



 }

 void audio::cin_name(){
 cout<<"Enter Surah name : ";
 cin>>name_surah;

 }

 void audio::cin_insert_name(){
 cout<<"Enter the name of the surah you want to add before it: ";
 cin>>name_surah;

 }

  ostream& operator<<(ostream& os, const audio& a) {
        os << "Audio Name: " << a.name_surah << "path: " << a.path_surah<<"type: "<<a.type_surah;
        return os;
    }



 void audio::cin_add_surah(){
 cout<<"Enter Surah Name : ";
 cin>>name_surah;
 cout<<"Enter Surah type : ";
 cin>>type_surah;
 cout<<"Enter Surah path : ";
 cin>>path_surah;
 }
