#ifndef AUDIO_H
#define AUDIO_H
#include <windows.h>
#include<string>
#include<mmsystem.h>
//#pragma comment(lib, "Winmm.lib")
#pragma comment
#include<iostream>
#include<string>

using namespace std;
class audio
{
    public:

        string  get_name_file() const;
        string  get_path_file() const;
        string  get_type_file() const;
        void set_name_file(string );
        void set_path_file(string );
        void set_type_file(string );
        void sound_play(const char* p);
         friend ostream& operator<<(ostream& os, const audio& a);
        void cin_add_surah();
        void cin_name();
      void cin_insert_name();
        bool operator==(const audio& other) const {
        return (name_surah == other.name_surah);
    }

      bool operator!=(const audio& other) const {
        return !(*this == other);  // ÅÐÇ ßÇäÊ ÇáßÇÆäÇÊ ÛíÑ ãÊÓÇæíÉ¡ ÓíÊã ÅÑÌÇÚ true
    }
    private:
        string name_surah;
        string path_surah;
        string type_surah;

};

#endif // AUDIO_H
