#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <rpc.h>


using namespace std;
//classes
class gun{
private:
    int num_shot;
    int price ;
    string gun_id;
    enum gun_name;
    int power_shot;
    int num_gun;

};
class player{
private:
    string id;
    string name;
    string using_gun_id;
    enum using_gun_name;
    int health;
    int armor;
    bool AI;

public:
    // سازنده کلاس
    player(string& playerName, int initialScore = 0)
            : name(playerName), score(initialScore) {
        // تولید GUID برای بازیکن
        UUID uuid;
        UuidCreate(&uuid); // تولید یک UUID جدید

        unsigned char* uuid_str;
        UuidToStringA(&uuid, &uuid_str); // تبدیل UUID به رشته

        id = reinterpret_cast<char*>(uuid_str);
        RpcStringFreeA(&uuid_str); // آزاد کردن حافظه اختصاص داده شده به رشته
    }



};
class trorist:public player{
private :
    bool bomb;
    bool using_bomb;

};
class ct:public player{
private:
    bool kit;
    bool cooling_bomb;

};
class game_map{
private:
    string map_name;
    string maker_map;
    bool am_pm;

};
class game_manager{
private:
    vector<player>team1;
    vector<player>team2;
    string map_name;
    int game_result;
    static game_manager* _instance;
    game_manager(){}

public:
    static game_manager* instance();


};
game_manager* game_manager::_instance = 0 ;
game_manager* game_manager::inctance(){
    if(_instance == 0 )
        _instance = new game_manager;
    return _instance;
}

