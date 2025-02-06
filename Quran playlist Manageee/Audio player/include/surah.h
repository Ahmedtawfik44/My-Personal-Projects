#ifndef SURAH_H
#define SURAH_H
#include<iostream>
#include<string>
#include"audio.h"
#include"playlist.h"


#include <thread>
#include <atomic>

class surah:public playlist
{
    public:
        surah(playlist& playlist_ref) : playlist_object(playlist_ref) {}
        void add_surah();
        void save_playlist();
        void remove_surah();
        void update_surah();
        void display_surah();
        void display_specific();
        void play_specific();
        void load_all();
        void show_consol();


   private:
     playlist &playlist_object;
     audio audio_object;

};

#endif // SURAH_H
