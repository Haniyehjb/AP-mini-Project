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
public:
    void set_num_shot(int);
    void set_price(int);
    void set_gun_id(string);
    void set_gun_name(enum);
    void set_power_shot(int);
    void set_num_gun(int);

    int get_num_shot();
    int get_price();
    string get_gun_id();
    enum get_gun_name();
    int get_power_shot();
    int get_num_gun();
    gun();
    gun(gun obj);
    gun(int _num_shot,int _price ,string _gun_id,enum _gun_name,int _power_shot,int _num_gun);
    gun& operator=(const gun& obj);
    bool operator!=(const gun& obj);
    bool operator==(const gun& obj);

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
void set_id(string);
void set_name(string);
void set_using_gun_id(string);
void set_using_gun_name(enum);
void set_health(int);
void set_armor(int);
void set_AI(bool);

string get_id();
string get_name();
string get_using_gun_id();
enum get_using_gun_name();
int get_health();
int get_armor();
bool get_AI();

player();
player(playr obj);
player(string _id,string _name,string _using_gun_id,enum _using_gun_name,int _health,int _armor,bool _AI);


};
class trorist:public player{
private :
    bool bomb;
    bool using_bomb;
public:
    void set_bomb(bool);
    void set_using_bomb(bool);
    bool get_bomb();
    bool get_using_bomb();
    terorist();
    terorist(terorist obj);
    terorist(bool _bomb,bool _using_bomb);

};
class ct:public player{
private:
    bool kit;
    bool cooling_bomb;
public:
    void set_kit(bool);
    void set_cooling_bomb(bool);
    bool get_kit();
    bool get_cooling_bomb();
    ct();
    ct(ct obj);
    ct(bool _kit,bool _cooling_bomb);

};
class game_map{
private:
    string map_name;
    string maker_map;
    bool am_pm;
public:
    void set_map_name(string);
    void set_maker_map(string);
    void set_am_pm(bool);
    string set_map_name();
    string set_maker_map();
    bool set_am_pm();
    game_map();
    game_map(game_map obj);
    game_map(string _map_name,string _maker_map,bool _am_pm);


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
    void set_map_name(string);
    void set_game_result(int);

    string set_map_name();
    int set_game_result();
    game_manager();
    game_manager(game_manager obj);
    game_manager(string _map_name; ,int _game_result);


};
game_manager* game_manager::_instance = 0 ;
game_manager* game_manager::inctance(){
    if(_instance == 0 )
        _instance = new game_manager;
    return _instance;
}

////////////////////////////////////////////////////////////////////gun
void gun::set_num_shot(int _num_shot){
    num_shot = _num_shot;
}
void gun::set_price(int _price){
    price = _prise;
}
void gun::set_gun_id(string _gun_id){
    gun_id = _gun_id;
}
void gun::set_gun_name(enum _gun_name){
    get_name = _gun_name;
}
void gun::set_power_shot(int _power_shot){
    power_shot = _power_shot;
}
void gun::set_num_gun(int _num_gun){
    num_gun = _num_gun;
}

int gun::get_num_shot(){
    return num_shot;
}
int gun::get_price(){
    return price;
}
string gun::get_gun_id(){
    return gun_id;
}
enum gun::get_gun_name(){
    return gun_name;
}
int gun::get_power_shot(){
    return power_shot;
}
int gun::get_num_gun(){
    return num_gun;
}
gun::gun(){
    num_shot = 0 ;
    price  = 0 ;
    gun_id = "";
    gun_name = 0 ;
    power_shot = 0;
    num_gun = 0 ;
}
gun::gun(gun obj){
    num_shot = obj.num_shot ;
    price  = obj.price;
    gun_id = obj.gun_id;
    gun_name = obj.gun_name;
    power_shot = obj.power_shot;
    num_gun = obj.num_gun ;
}
gun::gun(int _num_shot,int _price ,string _gun_id,enum _gun_name,int _power_shot,int _num_gun){
     num_shot = _num_shot;
     price = _price ;
     gun_id = _gun_id;
     gun_name = _gun_name;
     power_shot = _power_shot;
     num_gun = _num_gun;
}
gun& gun::operator=(const gun& obj){
    num_shot = obj.num_shot ;
    price  = obj.price;
    gun_id = obj.gun_id;
    gun_name = obj.gun_name;
    power_shot = obj.power_shot;
    num_gun = obj.num_gun ;
    return *this;
}
bool gun::operator!=(const gun& obj){
    if(num_shot != obj.num_shot&&price != obj.price&&gun_id != obj.gun_id&&gun_name != obj.gun_name&&power_shot != obj.power_shot&&num_gun != obj.num_gun)
        return false;
}
bool gun::operator==(const gun& obj){
    if(num_shot == obj.num_shot&&price == obj.price&&gun_id == obj.gun_id&&gun_name == obj.gun_name&&power_shot == obj.power_shot&&num_gun == obj.num_gun)
        return true;

}



/////////////////////////////////////////////////////////////////player

void player::set_id(string _id){
    id = _id;
}
void player::set_name(string _name){
    name = _name;
}
void player::set_using_gun_id(string _using_gun_id){
    using_gun_id = _using_gun-id;
}
void player::set_using_gun_name(enum _using_gun_name){
    using_gun_id = _using_gun_id;
}
void player::set_health(int _health){
   health = _health;
}
void player::set_armor(int _armor){
    armor = _armor;
}
void player::set_AI(bool _ai){
    AI = _ai;
}

string player::get_id(){return id;}
string player::get_name(){return name;}
string player::get_using_gun_id(){return using_gun_id;}
enum player::get_using_gun_name(){return using_gun_name;}
int player::get_health(){return health;}
int player::get_armor(){return armor;}
bool player::get_AI(){return AI;}

player::player(){
     id = "";
     name = "";
     using_gun_id = "";
     using_gun_name = 0;
     health = 0;
     armor = 0;
     AI = false;
}
player::player(playr obj){
    id = obj.id;
    name = obj.name;
    using_gun_id = obj.using_gun_id;
    using_gun_name = obj.using_gun_name;
    health = obj.health;
    armor = obj.armor;
    AI = obj.AI;

}
player::player(string _id,string _name,string _using_gun_id,enum _using_gun_name,int _health,int _armor,bool _AI){
    id = _id;
    name = _name;
    using_gun_id = _using_gun_id;
    using_gun_name = _using_gun_name;
    health = _health;
    armor = _armorf;
    AI = _AI;

}
////////////////////////////////////////////
void trorist::set_bomb(bool _bomb){ bomb = _bomb;}
void trorist::set_using_bomb(bool _using_bomb){bomb = _using_bomb;}
bool trorist::get_bomb(){ return bomb;}
bool trorist::get_using_bomb(){return using_bomb;}
terorist::terorist(){
     bomb = true;
     using_bomb = true;

}
terorist::terorist(terorist obj){
    bomb = obj.bomb;
    using_bomb = obj.using_bomb;
}
terorist::terorist(bool _bomb,bool _using_bomb){
    bomb = _bomb;
    using_bomb = _using_bomb;
}
////////////////////////
void ct::set_kit(bool _kit){kit = _kit;}
void ct::set_cooling_bomb(bool _cooling_bomb){cooling_bomb = _cooling_bomb;}
bool ct::get_kit(){return kit;}
bool ct::get_cooling_bomb(){return cooling_kit;}
ct::ct(){
     kit = true;
     cooling_bomb = true;
}
ct::ct(ct obj){
     kit = obj.kit;
     cooling_bomb = obj.cooling_bomb;
}
ct::ct(bool _kit,bool _cooling_bomb){
     kit = _kit;
     cooling_bomb = _cooling_bomb;
}
//////////////////////////////////////////////////////////////
void game_map::set_map_name(string _map_name){map_name = _map_name;}
void game_map::set_maker_map(string _maker_map){maker_map = _maker_map;}
void game_map::set_am_pm(bool _am_pm){am_pm = _am_pm;}
string game_map::set_map_name(){return map_name;}
string game_map::set_maker_map(){return maker_name;}
bool game_map::set_am_pm(){ return am_pm;}
game_map::game_map(){
     map_name = "";
     maker_map = "";
     am_pm = true;
}
game_map::game_map(game_map obj){
    map_name = obj.map.name;
    maker_map = obj.maker_map;
    am_pm = obj.am_pm;
}
game_map::game_map(string _map_name,string _maker_map,bool _am_pm){
    map_name = _map_name;
    maker_map = _maker_map;
    am_pm = _am_pm;
}
//////////////////////////////////////////////////////
void game_manager::set_map_name(string _map_name){map_name = _map_name;}
void game_manager::set_game_result(int _game_result){game_result = _game_result;}

string game_manager::set_map_name(){return map_name;}
int game_manager::set_game_result(){return game_result;}
game_manager(){
    map_name = "";
    game_result = 0;
}
game_manager(game_manager obj){
    map_name = obj.map_name;
    game_result = obj.game_result;
}
game_manager(string _map_name; ,int _game_result){
    map_name = _map_name;
    game_result = _game_result;
}