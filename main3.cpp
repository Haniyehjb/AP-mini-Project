#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <rpc.h>
#include <cstdlib>
#include <fstream>
int setting_before_start = 0;
using namespace std;
//classes
class node{
    node* pprv;
    node* pnxt;
};
enum Guns {
    AK47 = 1,
    M4A1,
    AWP,
    P90,
    UMP45,
    FAMAS,
    DESERT_EAGLE,
    GLOCK,
    MP5,
    SHOTGUN
};

class gun{
private:
    int num_shot;
    int price ;
    string gun_id;
    Guns gun_name;
    int power_shot;
    int num_gun;
public:
    void set_num_shot(int);
    void set_price(int);
    void set_gun_id(string);
    void set_gun_name(Guns);
    void set_power_shot(int);
    void set_num_gun(int);

    int get_num_shot();
    int get_price();
    string get_gun_id();
    Guns get_gun_name();
    int get_power_shot();
    int get_num_gun();
    gun();
    gun(gun obj);
    gun(int _num_shot,int _price ,string _gun_id,enum _gun_name,int _power_shot,int _num_gun);
    ~gun();
    gun& operator=(const gun& obj);
    bool operator!=(const gun& obj);
    bool operator==(const gun& obj);
    string getGunName(Guns gun);

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
    player *phead = nullptr;


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
    void set_money(int);

    string get_id();
    string get_name();
    string get_using_gun_id();
    enum get_using_gun_name();
    int get_health();
    int get_armor();
    bool get_AI();
    int get_money();

    player();
    player(player obj);
    player(string _id,string _name,string _using_gun_id,enum _using_gun_name,int _health,int _armor,bool _AI);
    player& operator=(const player& obj);
    bool operator!=(const player& obj);
    bool operator==(const player& obj);

    player& add_node();
    void delete_node();


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
    trorist& operator=(const trorist& obj);
    bool operator!=(const trorist& obj);
    bool operator==(const trorist& obj);

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
    ct& operator=(const ct& obj);
    bool operator!=(const ct& obj);
    bool operator==(const ct& obj);

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
    game_map& operator=(const game_map& obj);
    bool operator!=(const game_map& obj);
    bool operator==(const game_map& obj);


};
class game_manager{
private:
    vector<player>team_ct;
    vector<player>team_terorist;
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
    game_manager(string _map_name ,int _game_result);
    game_manager& operator=(const game_manager& obj);
    bool operator!=(const game_manager& obj);
    bool operator==(const game_manager& obj);
    int display_history(const string& filename , const string& userid);
    void setting_manu();
    void start_game();





};
game_manager* game_manager::_instance = 0 ;
game_manager* game_manager::inctance(){
    if(_instance == 0 )
        _instance = new game_manager;
    return _instance;
}
class users{
private:
    string username;
    string nick_name;
    string passwordHashed;
    int wins;
    string hashPassword(const std::string& password);
public:
    users();
    users(const User& other);
    users(string _username, string _nickname, string _passwordHash, int _wins);


    bool registerusers ();
    bool loginusers (const string& password);
    void updateWins();
    void saveToFile();
    static User loadFromFile(const string& username);

    string getusername() const;
    string getnickname() const;
    int getWins() const;



};









////////////////////////////////////////////////////////////////////gun
void gun::set_num_shot(int _num_shot){
    num_shot = _num_shot;
}
void gun::set_price(int _price){
    price = _price;
}
void gun::set_gun_id(string _gun_id){
    gun_id = _gun_id;
}
void gun::set_gun_name(Guns _gun_name){
    gun_name = _gun_name;
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
Guns gun::get_gun_name(){
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
gun::gun(int _num_shot,int _price ,string _gun_id,Guns _gun_name,int _power_shot,int _num_gun){
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
gun::~gun(){
    num_gun--;
}


/////////////////////////////////////////////////////////////////player

void Player::generate_id() {
    uuid_t binuuid;
    uuid_generate(binuuid);
    char uuid[37];
    uuid_unparse(binuuid, uuid);
    uuid = string(uuid); // Convert UUID to string
}

void player::set_id(string _id){
    id = _id;
}
void player::set_name(string _name){
    name = _name;
}
void player::set_using_gun_id(string _using_gun_id){
    using_gun_id = _using_gun_id;
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
void player::set_money(int _money){
    money = _money;
}


string player::get_id(){return id;}
string player::get_name(){return name;}
string player::get_using_gun_id(){return using_gun_id;}
enum player::get_using_gun_name(){return using_gun_name;}
int player::get_health(){return health;}
int player::get_armor(){return armor;}
bool player::get_AI(){return AI;}
int player::get_money(){return money;}

player::player(){
    id = "";
    name = "";
    using_gun_id = "";
    using_gun_id = 0;
    health = 0;
    armor = 0;
    money = 0 ;
    AI = false;
}
player::player(player obj){
    id = obj.id;
    name = obj.name;
    using_gun_id = obj.using_gun_id;
    using_gun_name = obj.using_gun_name;
    health = obj.health;
    armor = obj.armor;
    AI = obj.AI;

}
player::player(string _id,string _name,string _using_gun_id,enum _using_gun_name,int _health,int _armor,bool _AI int _money){
    id = _id;
    name = _name;
    using_gun_id = _using_gun_id;
    using_gun_name = _using_gun_name;
    health = _health;
    armor = _armorf;
    AI = _AI;
    money = _money;

}
player& player::operator=(const player& obj){
    id = obj.id;
    name = obj.name;
    using_gun_id = obj.using_gun_id;
    using_gun_name = obj.using_gun_name;
    health = obj.health;
    armor = obj.armor;
    AI = obj.AI;
    money = obj.money;
    return *this;

}
bool player::operator!=(const player& obj){
    if(id != obj.id&&name != obj.name&&using_gun_id != obj.using_gun_id&&using_gun_name != obj.using_gun_name&&health != obj.health,armor != obj.armor&&AI != obj.AI && money != obj.money)
        return false;

}
bool player::operator==(const player& obj){
    if(id == obj.id&&name == obj.name&&using_gun_id == obj.using_gun_id&&using_gun_name == obj.using_gun_name&&health == obj.health,armor == obj.armor&&AI == obj.AI&& money == obj.money)
        retun true;
}

player::player& add_node() {
    node* pnew = new player;
    pnew->pnxt = nullptr;
    pnew->pper = nullptr;

    if (phead == nullptr) {
        phead = pnew;
        pnew->pnxt = pnew;
        pnew->pper = pnew;
    } else {
        node* ptmp = phead;
        while (ptmp->pnxt != phead) {
            ptmp = ptmp->pnxt;
        }
        ptmp->pnxt = pnew;
        pnew->pper = ptmp;
        pnew->pnxt = phead;
    }
    return *pnew;
}
void player::delete_node(Guns _guns) {
    if (phead == nullptr) {
        cout << "Error: No member to delete." << endl;
        return;
    }

    node* ptmp = phead;
    do {
        if (ptmp->get_gun_id() == _guns) {

            if (ptmp == phead) {

                if (ptmp->pnxt == phead) {
                    delete ptmp;
                    phead = nullptr;
                } else {

                    node* last = phead->pper;
                    phead = ptmp->pnxt;
                    last->pnxt = phead;
                    phead->pper = last;
                    delete ptmp;
                }
            } else {

                node* before = ptmp->pper;
                node* after = ptmp->pnxt;

                before->pnxt = after;
                after->pper = before;

                delete ptmp;
            }
            return;
        }
        ptmp = ptmp->pnxt;
    } while (ptmp != phead);

    cout << "Not found." << endl;
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

terorist& terorist::operator=(const trorist& obj){
    bomb = obj.bomb;
    using_bomb = obj.using_bomb;
}
bool terorist::operator!=(const terorist& obj){
    if(bomb != obj.bomb&&using_bomb != obj.using_bomb)
        return false;
}
bool terorist::operator==(const terorist& obj){
    if(bomb != obj.bomb&&using_bomb != obj.using_bomb)
        return true;

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
ct& ct::operator=(const ct& obj){
    kit = obj.kit;
    cooling_bomb = obj.cooling_bomb;
    return *this;
}
bool ct::operator!=(const ct& obj){
    if(kit != obj.kit&&cooling_bomb != obj.cooling_bomb)
        return false;
}
bool ct::operator==(const ct& obj){
    if(kit == obj.kit&&cooling_bomb == obj.cooling_bomb)
        return true;
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
game_map& game_map::operator=(const game_map& obj){
    map_name = obj.map.name;
    maker_map = obj.maker_map;
    am_pm = obj.am_pm;
}
bool game_map::operator!=(const game_map& obj){
    if(map_name != obj.map.name&&maker_map != obj.maker_map&&am_pm != obj.am_pm)
        return false;
}
bool game_map::operator==(const game_map& obj){
    if(map_name == obj.map.name&&maker_map == obj.maker_map&&am_pm == obj.am_pm)
        return true;

}
//////////////////////////////////////////////////////
void game_manager::set_map_name(string _map_name){map_name = _map_name;}
void game_manager::set_game_result(int _game_result){game_result = _game_result;}

string game_manager::set_map_name(){return map_name;}
int game_manager::set_game_result(){return game_result;}
game_manager::game_manager(){
    map_name = "";
    game_result = 0;
}
game_manager::game_manager(game_manager obj){
    map_name = obj.map_name;
    game_result = obj.game_result;
}
game_manager::game_manager(string _map_name; ,int _game_result){
map_name = _map_name;
game_result = _game_result;
}
game_manager::game_manager& operator=(const game_manager& obj){
    map_name = obj.map_name;
    game_result = obj.game_result;
}
bool game_manager::operator!=(const game_manager& obj){
    if(map_name != obj.map_name&&game_result != obj.game_result)
        return false;
}
bool game_manager::operator==(const game_manager& obj){
    if(map_name == obj.map_name&&game_result == obj.game_result)
        return true;

}

void menu(){
    int cmd;
    cout<<"1⚪ START GAME"<<endl;
    cout<<"2⚪ GAME SETTING"<<endl;
    cout<<"3⚪ HISTORY"<<endl;
    cout<<"4⚪ INFORMATION"<<endl;
    cout<<"5⚪ EXIT"<<endl;
    cin>>cmd;
    switch_menu(int cmd);

}
void switch_menu(int cmd) {
    switch (cmd) {

        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            exit(0);
    }

}
int display_history(const string& filename , const string& userid){
    string line , winner;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: can not open file!" << endl;
    }

    int round_game = 1;
    int user_wins = 0;
    while(getline(file , line)){
        for(char c : line){
            if(c == '0'){
                winner = "Terorist";
                for(int i = 0 ; i < team_Terorist.size() ; i++){
                    if(team_Terorist[i].get_id() == userid){
                        user_wins ++;
                    }
                    round_game ++;
                }
            }
            else if(c == '1'){
                winner = "CT";
                for(int i = 0 ; i < team_ct.size() ; ++i){
                    if(team_ct[i] == userid){
                        user_wins++;
                    }
                    round_game++;

                }
            }
            else{
                cout<<"invalid result"<<endl;
                continue;
            }


        }
    }
    cout<<"Round "<<round_game<<": "<<"winner :"<<winner<<endl;


}
void game_manager::setting_menu(){
    int a ;
    int c;
    int t;
    cout <<"please choose one map";
    cout<<"1.map1"<<endl<<"2.map2"<<endl<<"3.map3"<<endl<<"4.map4"<<endl<<"5.map5"<<endl;
    cin >> a;
    system("cls");
    do{
        cout<<"please enter the number of player of each team"<<endl;
        cout<<"CT team"<<endl;

        cout<<"Terorist team" <<endl;
        cin >>c;
        cin >>t;

    }while(!((c / (float)t >= 0.95 && c / (float)t <= 1.05) || (t / (float)c >= 0.95 && t / (float)c <= 1.05)))

    system("cls");
    cout<<"please enter money of each CT player "<<endl;
    vector<int>ct_money(c);
    for(int i = 0 ; i < c ; ++i)
        cin>>ct_money[i];
    cout<<"please enter money of each terorist player "<<endl;
    vector<int>terorist_money(t);
    for(int i = 0 ; i < t ; ++i)
        cin >> terorist_money[i];
    setting_before_start = 1;
}
//void game_manager::setting_menu() {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    int a;
//    int ct_count;
//    int terrorist_count;
//
//    // انتخاب نقشه
//    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//    cout << "Please choose one map:" << endl;
//    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//    cout << "1. Dust2" << endl
//         << "2. Inferno" << endl
//         << "3. Nuke" << endl
//         << "4. Mirage" << endl
//         << "5. Overpass" << endl;
//    cin >> a;
//
//    string map_names[] = {"Dust2", "Inferno", "Nuke", "Mirage", "Overpass"};
//    if (a >= 1 && a <= 5) {
//        this->map_name = map_names[a - 1];
//    } else {
//        cout << "Invalid map selected. Default map set to Dust2." << endl;
//        this->map_name = "Dust2";
//    }
//
//    system("cls");
//
//    // گرفتن تعداد بازیکنان
//    do {
//        cout << "Please enter the number of players for each team:" << endl;
//
//        cout << "CT team: ";
//        cin >> ct_count;
//
//        cout << "Terrorist team: ";
//        cin >> terrorist_count;
//
//        // بررسی بالانس تیم‌ها (نسبت باید بین 0.95 تا 1.05 باشه)
//        float ratio1 = ct_count / (float)terrorist_count;
//        float ratio2 = terrorist_count / (float)ct_count;
//        if (!((ratio1 >= 0.95f && ratio1 <= 1.05f) || (ratio2 >= 0.95f && ratio2 <= 1.05f))) {
//            cout << "⚠️ Teams are not balanced! Try again." << endl;
//            system("pause");
//            system("cls");
//        }
//    } while (!((ct_count / (float)terrorist_count >= 0.95f && ct_count / (float)terrorist_count <= 1.05f) ||
//               (terrorist_count / (float)ct_count >= 0.95f && terrorist_count / (float)ct_count <= 1.05f)));
//
//    system("cls");
//
//    // گرفتن پول اولیه بازیکنان CT
//    cout << "Please enter the initial money for each CT player:" << endl;
//    vector<int> ct_money(ct_count);
//    for (int i = 0; i < ct_count; ++i) {
//        cout << "CT Player " << i + 1 << ": ";
//        cin >> ct_money[i];
//    }
//
//    system("cls");
//
//    // گرفتن پول اولیه بازیکنان Terrorist
//    cout << "Please enter the initial money for each Terrorist player:" << endl;
//    vector<int> terrorist_money(terrorist_count);
//    for (int i = 0; i < terrorist_count; ++i) {
//        cout << "Terrorist Player " << i + 1 << ": ";
//        cin >> terrorist_money[i];
//    }
//
//    system("cls");
//
//    // 📌 ذخیره تنظیمات در Singleton
//    this->player_count_ct = ct_count;
//    this->player_count_ter = terrorist_count;
//    this->initial_money_ct = ct_money;
//    this->initial_money_ter = terrorist_money;
//
//    // می‌توانید اکنون تیم‌ها را بسازید:
//    // create_teams(ct_money, terrorist_money);
//}

string gun::getGunName(Guns gun) {
    switch (gun) {
        case AK47: return "AK-47";
        case M4A1: return "M4A1";
        case AWP: return "AWP";
        case P90: return "P90";
        case UMP45: return "UMP-45";
        case FAMAS: return "FAMAS";
        case DESERT_EAGLE: return "Desert Eagle";
        case GLOCK: return "Glock";
        case MP5: return "MP5";
        case SHOTGUN: return "Shotgun";
        default: return "Unknown Gun";
    }
}
//void game_manager::setting_menu() {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    int a;
//    int ct_count;
//    int terrorist_count;
//
//    // انتخاب نقشه
//    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//    cout << "Please choose one map:" << endl;
//    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//    cout << "1. Dust2" << endl
//         << "2. Inferno" << endl
//         << "3. Nuke" << endl
//         << "4. Mirage" << endl
//         << "5. Overpass" << endl;
//    cin >> a;
//
//    string map_names[] = {"Dust2", "Inferno", "Nuke", "Mirage", "Overpass"};
//    if (a >= 1 && a <= 5) {
//        this->map_name = map_names[a - 1];
//    } else {
//        cout << "Invalid map selected. Default map set to Dust2." << endl;
//        this->map_name = "Dust2";
//    }
//
//    system("cls");
//
//    // گرفتن تعداد بازیکنان
//    do {
//        cout << "Please enter the number of players for each team:" << endl;
//
//        cout << "CT team: ";
//        cin >> ct_count;
//
//        cout << "Terrorist team: ";
//        cin >> terrorist_count;
//
//        float ratio1 = ct_count / (float)terrorist_count;
//        float ratio2 = terrorist_count / (float)ct_count;
//
//        if (!((ratio1 >= 0.95f && ratio1 <= 1.05f) || (ratio2 >= 0.95f && ratio2 <= 1.05f))) {
//            cout << "⚠️ Teams are not balanced! Try again." << endl;
//            system("pause");
//            system("cls");
//        }
//    } while (!((ct_count / (float)terrorist_count >= 0.95f && ct_count / (float)terrorist_count <= 1.05f) ||
//               (terrorist_count / (float)ct_count >= 0.95f && terrorist_count / (float)ct_count <= 1.05f)));
//
//    system("cls");
//
//    // گرفتن پول اولیه بازیکنان CT
//    cout << "Please enter the initial money for each CT player:" << endl;
//    vector<int> ct_money(ct_count);
//    for (int i = 0; i < ct_count; ++i) {
//        cout << "CT Player " << i + 1 << ": ";
//        cin >> ct_money[i];
//    }
//
//    system("cls");
//
//    // گرفتن پول اولیه بازیکنان Terrorist
//    cout << "Please enter the initial money for each Terrorist player:" << endl;
//    vector<int> terrorist_money(terrorist_count);
//    for (int i = 0; i < terrorist_count; ++i) {
//        cout << "Terrorist Player " << i + 1 << ": ";
//        cin >> terrorist_money[i];
//    }
//
//    system("cls");
//
//    // ذخیره اطلاعات تیم‌ها
//    for (int i = 0; i < ct_count; ++i) {
//        player p;
//        p.set_name("CT_Player_" + to_string(i + 1));
//        p.set_money(ct_money[i]);
//        p.set_health(100);
//        p.set_armor(50);
//        p.set_AI(true);
//        team_ct.push_back(p);
//    }
//
//    for (int i = 0; i < terrorist_count; ++i) {
//        player p;
//        p.set_name("Terrorist_Player_" + to_string(i + 1));
//        p.set_money(terrorist_money[i]);
//        p.set_health(100);
//        p.set_armor(50);
//        p.set_AI(true);
//        team_terorist.push_back(p);
//    }
//
//    setting_before_start = 1;
//}
void game_manager::start_game(){
    int teroristindex = 0 ;
    int ctindex = 0 ;
    while(terorisrindex < terorist.size() && ctindex < ct.size())
        player* terrorist = team_terorist[teroristindex];
    player* ct = team_ct[ctindex];


    double terroristPower = terorist->getMoney();
    double ctPower = ct->getMoney();


    for (int gunId : terorist->getWeaponIds()) {
        Gun gun = getGunById(gunId); // فرض کنید تابعی برای دریافت تفنگ بر اساس ID وجود دارد
        terroristPower += gun.getBulletCount() * gun.getBulletPower();
    }

    for (int gunId : ct->getWeaponIds()) {
        Gun gun = getGunById(gunId);
        ctPower += gun.getBulletCount() * gun.getBulletPower();
    }


    if (terroristPower > ctPower) {

        ct->reduceHealth(terroristPower - ctPower);
        std::cout << "Terrorist " << terrorist->getName() << " defeated CT " << ct->getName() << std::endl;
        if (ct->getHealth() <= 0) {
            ctIndex++;
        }
    } else if (ctPower > terroristPower) {

        terrorist->reduceHealth(ctPower - terroristPower);
        std::cout << "CT " << ct->getName() << " defeated Terrorist " << terrorist->getName() << std::endl;
        if (terrorist->getHealth() <= 0) {
            terroristIndex++;
        }
    } else {

        terrorist->reduceHealth(1);
        ct->reduceHealth(1);
        std::cout << "Both " << terrorist->getName() << " and " << ct->getName() << " took damage!" << std::endl;
        if (terrorist->getHealth() <= 0) {
            terroristIndex++;
        }
        if (ct->getHealth() <= 0) {
            ctIndex++;
        }
    }


    checkWinner();


    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
}

void GameManager::checkWinner() {
    bool terroristAlive = false;
    bool ctAlive = false;

    for (Player* player : terrorists) {
        if (player->getHealth() > 0) {
            terroristAlive = true;
            break;
        }
    }

    for (Player* player : cts) {
        if (player->getHealth() > 0) {
            ctAlive = true;
            break;
        }
    }

    if (!terroristAlive) {
        std::cout << "CT team wins!" << std::endl;

    } else if (!ctAlive) {
        std::cout << "Terrorist team wins!" << std::endl;

    }
}

}

//void game_manager::start_game() {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    int terroristIndex = 0;
//    int ctIndex = 0;
//
//    while (terroristIndex < team_terorist.size() && ctIndex < team_ct.size()) {
//        player& terrorist = team_terorist[terroristIndex];
//        player& ct = team_ct[ctIndex];
//
//        double terroristPower = terrorist.get_money();
//        double ctPower = ct.get_money();
//
//        // جمع قدرت سلاح (فرض کن هر بازیکن یک تفنگ داره)
//        // این قسمت باید بهتر با سیستم سلاح نوشته بشه
//        // فعلاً ساده فرض میکنیم فقط پول لحاظ میشه.
//
//        if (terroristPower > ctPower) {
//            double damage = terroristPower - ctPower;
//            ct.set_health(ct.get_health() - damage);
//
//            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//            cout << "Terrorist " << terrorist.get_name() << " defeated ";
//            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//            cout << "CT " << ct.get_name() << endl;
//
//            if (ct.get_health() <= 0) {
//                ctIndex++;
//            }
//        }
//        else if (ctPower > terroristPower) {
//            double damage = ctPower - terroristPower;
//            terrorist.set_health(terrorist.get_health() - damage);
//
//            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//            cout << "CT " << ct.get_name() << " defeated ";
//            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//            cout << "Terrorist " << terrorist.get_name() << endl;
//
//            if (terrorist.get_health() <= 0) {
//                terroristIndex++;
//            }
//        }
//        else {
//            // مساوی
//            terrorist.set_health(terrorist.get_health() - 10);
//            ct.set_health(ct.get_health() - 10);
//
//            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
//            cout << "CT " << ct.get_name() << " damaged ";
//            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//            cout << "Terrorist " << terrorist.get_name() << endl;
//
//            if (ct.get_health() <= 0) ctIndex++;
//            if (terrorist.get_health() <= 0) terroristIndex++;
//        }
//
//        // نیم ثانیه مکث
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    }
//
//    // بررسی برنده بعد از اتمام کامل بازی
//    checkWinner();
//}
//
//void game_manager::checkWinner() {
//    bool terroristAlive = false;
//    bool ctAlive = false;
//
//    for (player& p : team_terorist) {
//        if (p.get_health() > 0) {
//            terroristAlive = true;
//            break;
//        }
//    }
//
//    for (player& p : team_ct) {
//        if (p.get_health() > 0) {
//            ctAlive = true;
//            break;
//        }
//    }
//
//    if (terroristAlive && !ctAlive) {
//        cout << "\nTerrorist team wins!" << endl;
//        game_result = 0;
//    }
//    else if (ctAlive && !terroristAlive) {
//        cout << "\nCT team wins!" << endl;
//        game_result = 1;
//    }
//    else {
//        cout << "\nDraw! Both teams are down!" << endl;
//        game_result = -1;
//    }
//}
string User::hashPassword(const string& password){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

    string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashedPassword += sprintf("%02x", hash[i]);
    }
    return hashedPassword;
}

users::users(){
    username = "";
    nickname = "";
    passwordHash = "";
    wins = 0;
}
users::users(const User& other){
    username = other->username;
    nickname = other->nickname;
    passwordHash = other->passwordHash;
    wins = other->wins;
}
users::users(string _username, string _nickname, string _passwordHash, int _wins){
    username = _username;
    nickname = _nickname;
    passwordHash = _passwordHash;
    wins = _wins;
}


bool users::registerUser (){
    cout<<"please enter your username"<<endl;
    cin>>username;
    cout<<"please enter your nickname"<<endl;
    cin >> nickname;
    cout<<"enter your password"<<endl;
    cin>>password;
    passwordhssh = hashpassword(password);
    saveToFile();
    return true;
}
bool users::loginUser (const string& password){
    return passwordHash == hashpassword(password);
}
void users::updateWins(){
    wins++;
}
void users::saveToFile(){
    ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << username << " " << nickname << " " << passwordHash << " " << wins << endl;
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}
}
static users::User loadFromFile(const string& username){
    std::ifstream file("users.txt");
    std::string user, nickname, passwordHash;
    int wins;

    while (file >> user >> nickname >> passwordHash >> wins) {
        if (user == username) {
            return User(user, alias, passwordHash, wins);
        }
    }
    return User();
}

string users::getusername() const{
    return username;
}
string users::getnickname() const{
    return nickname;
}
int users::getWins() const{
    return wins;
}