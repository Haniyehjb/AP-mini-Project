#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <rpc.h>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <random>
#include <thread>
#include <cassert>
#include <ctime>

#pragma comment(lib, "rpcrt4.lib")
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


using namespace std;

string generate_id() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    const char* hex_chars = "0123456789abcdef";
    string uuid;
    for (int i = 0; i < 32; ++i) {
        uuid += hex_chars[dis(gen)];
    }
    return uuid;
}

string hashPassword(const string& password) {
    return to_string(hash<string>{}(password));
}

int setting_before_start = 0;

// Forward declarations
class player;
class terrorist;
class ct;
class gun;
class game_map;
class game_manager;
class users;
class node;

class player {
private:
    string id;
    string name;
    string using_gun_id;
    Guns using_gun_name;
    int health;
    int armor;
    bool AI;
    int money;
    int score;
    node* phead;

public:
    player(string playerName, int initialScore = 0);
    void set_id(string);
    void set_name(string);
    void set_using_gun_id(string);
    void set_using_gun_name(Guns);
    void set_health(int);
    void set_armor(int);
    void set_AI(bool);
    void set_money(int);

    string get_id();
    string get_name();
    string get_using_gun_id();
    Guns get_using_gun_name();
    int get_health();
    int get_armor();
    bool get_AI();
    int get_money();
    int get_score();

    player();
    player(const player& obj);
    player(string _id, string _name, string _using_gun_id, Guns _using_gun_name, int _health, int _armor, bool _AI, int _money);
    player& operator=(const player& obj);
    bool operator!=(const player& obj);
    bool operator==(const player& obj);

    node* add_node(const player& p);
    void delete_node(Guns _guns);
};

class node {
public:
    node* pprv;
    node* pnxt;
    player data;
};

node* phead = nullptr;


class gun {
private:
    int num_shot;
    int price;
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
    gun(const gun& obj);
    gun(int _num_shot, int _price, string _gun_id, Guns _gun_name, int _power_shot, int _num_gun);
    ~gun();
    gun& operator=(const gun& obj);
    bool operator!=(const gun& obj);
    bool operator==(const gun& obj);
    string getGunName(Guns gun);
};



class terrorist : public player {
private:
    bool bomb;
    bool using_bomb;
public:
    void set_bomb(bool);
    void set_using_bomb(bool);
    bool get_bomb();
    bool get_using_bomb();
    terrorist();
    terrorist(const terrorist& obj);
    terrorist(bool _bomb, bool _using_bomb);
    terrorist& operator=(const terrorist& obj);
    bool operator!=(const terrorist& obj);
    bool operator==(const terrorist& obj);
};

class ct : public player {
private:
    bool kit;
    bool cooling_bomb;
public:
    void set_kit(bool);
    void set_cooling_bomb(bool);
    bool get_kit();
    bool get_cooling_bomb();
    ct();
    ct(const ct& obj);
    ct(bool _kit, bool _cooling_bomb);
    ct& operator=(const ct& obj);
    bool operator!=(const ct& obj);
    bool operator==(const ct& obj);
};

class game_map {
private:
    string map_name;
    string maker_map;
    bool am_pm;
public:
    void set_map_name(string);
    void set_maker_map(string);
    void set_am_pm(bool);
    string get_map_name();
    string get_maker_map();
    bool get_am_pm();
    game_map();
    game_map(const game_map& obj);
    game_map(string _map_name, string _maker_map, bool _am_pm);
    game_map& operator=(const game_map& obj);
    bool operator!=(const game_map& obj);
    bool operator==(const game_map& obj);
};

class game_manager {
private:
    vector<player> team_ct;
    vector<player> team_terrorist;
    string map_name;
    int game_result;
    static game_manager* _instance;

    game_manager() : map_name(""), game_result(0) {}

public:
    static game_manager* instance();
    void set_map_name(string);
    void set_game_result(int);

    string get_map_name();
    int get_game_result();
    game_manager(const game_manager& obj);
    game_manager(string _map_name, int _game_result);
    game_manager& operator=(const game_manager& obj);
    bool operator!=(const game_manager& obj);
    bool operator==(const game_manager& obj);
    int display_history(const string& filename, const string& userid);
    void setting_menu();
    void start_game();
    void checkWinner();
    void add_ct_player(const player& p) { team_ct.push_back(p); }
    void add_terrorist_player(const player& p) { team_terrorist.push_back(p); }
};

game_manager* game_manager::_instance = nullptr;

game_manager* game_manager::instance() {
    if (_instance == nullptr) {
        _instance = new game_manager();
    }
    return _instance;
}

class users {
private:
    string username;
    string nickname;
    string passwordHash;
    int wins;
public:
    users();
    users(const users& other);
    users(string _username, string _nickname, string _passwordHash, int _wins);

    bool registerUser();
    bool loginUser(const string& password);
    void updateWins();
    void saveToFile();
    static users loadFromFile(const string& username);

    string getusername() const;
    string getnickname() const;
    int getWins() const;
};

// Implementations of gun class
void gun::set_num_shot(int _num_shot) { num_shot = _num_shot; }
void gun::set_price(int _price) { price = _price; }
void gun::set_gun_id(string _gun_id) { gun_id = _gun_id; }
void gun::set_gun_name(Guns _gun_name) { gun_name = _gun_name; }
void gun::set_power_shot(int _power_shot) { power_shot = _power_shot; }
void gun::set_num_gun(int _num_gun) { num_gun = _num_gun; }

int gun::get_num_shot() { return num_shot; }
int gun::get_price() { return price; }
string gun::get_gun_id() { return gun_id; }
Guns gun::get_gun_name() { return gun_name; }
int gun::get_power_shot() { return power_shot; }
int gun::get_num_gun() { return num_gun; }

gun::gun() : num_shot(0), price(0), gun_id(""), gun_name(AK47), power_shot(0), num_gun(0) {}
gun::gun(const gun& obj) : num_shot(obj.num_shot), price(obj.price), gun_id(obj.gun_id),
                           gun_name(obj.gun_name), power_shot(obj.power_shot), num_gun(obj.num_gun) {}
gun::gun(int _num_shot, int _price, string _gun_id, Guns _gun_name, int _power_shot, int _num_gun) :
        num_shot(_num_shot), price(_price), gun_id(_gun_id), gun_name(_gun_name),
        power_shot(_power_shot), num_gun(_num_gun) {}

gun& gun::operator=(const gun& obj) {
    num_shot = obj.num_shot;
    price = obj.price;
    gun_id = obj.gun_id;
    gun_name = obj.gun_name;
    power_shot = obj.power_shot;
    num_gun = obj.num_gun;
    return *this;
}

bool gun::operator!=(const gun& obj) { return !(*this == obj); }
bool gun::operator==(const gun& obj) {
    return num_shot == obj.num_shot &&
           price == obj.price &&
           gun_id == obj.gun_id &&
           gun_name == obj.gun_name &&
           power_shot == obj.power_shot &&
           num_gun == obj.num_gun;
}

gun::~gun() { num_gun--; }

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

// Implementations of player class
player::player(string playerName, int initialScore) : name(playerName), score(initialScore) {
    // استفاده از تابع generate_id به جای UUID برای سادگی
    id = "P" + generate_id();
}

void player::set_id(string _id) { id = _id; }
void player::set_name(string _name) { name = _name; }
void player::set_using_gun_id(string _using_gun_id) { using_gun_id = _using_gun_id; }
void player::set_using_gun_name(Guns _using_gun_name) { using_gun_name = _using_gun_name; }
void player::set_health(int _health) { health = _health; }
void player::set_armor(int _armor) { armor = _armor; }
void player::set_AI(bool _ai) { AI = _ai; }
void player::set_money(int _money) { money = _money; }

string player::get_id() { return id; }
string player::get_name() { return name; }
string player::get_using_gun_id() { return using_gun_id; }
Guns player::get_using_gun_name() { return using_gun_name; }
int player::get_health() { return health; }
int player::get_armor() { return armor; }
bool player::get_AI() { return AI; }
int player::get_money() { return money; }
int player::get_score() { return score; }

player::player() : id(""), name(""), using_gun_id(""), using_gun_name(AK47),
                   health(0), armor(0), money(0), AI(false), score(0), phead(nullptr) {}

player::player(const player& obj) : id(obj.id), name(obj.name), using_gun_id(obj.using_gun_id),
                                    using_gun_name(obj.using_gun_name), health(obj.health), armor(obj.armor),
                                    AI(obj.AI), money(obj.money), score(obj.score), phead(nullptr) {}

player::player(string _id, string _name, string _using_gun_id, Guns _using_gun_name,
               int _health, int _armor, bool _AI, int _money) :
        id(_id), name(_name), using_gun_id(_using_gun_id), using_gun_name(_using_gun_name),
        health(_health), armor(_armor), AI(_AI), money(_money), score(0), phead(nullptr) {}

player& player::operator=(const player& obj) {
    id = obj.id;
    name = obj.name;
    using_gun_id = obj.using_gun_id;
    using_gun_name = obj.using_gun_name;
    health = obj.health;
    armor = obj.armor;
    AI = obj.AI;
    money = obj.money;
    score = obj.score;
    return *this;
}

bool player::operator!=(const player& obj) { return !(*this == obj); }
bool player::operator==(const player& obj) {
    return id == obj.id &&
           name == obj.name &&
           using_gun_id == obj.using_gun_id &&
           using_gun_name == obj.using_gun_name &&
           health == obj.health &&
           armor == obj.armor &&
           AI == obj.AI &&
           money == obj.money &&
           score == obj.score;
}

node* player::add_node(const player& p) {
    node* pnew = new node;
    pnew->data = p;
    pnew->pnxt = nullptr;
    pnew->pprv = nullptr;

    if (!phead) {
        phead = pnew;
        pnew->pnxt = pnew;
        pnew->pprv = pnew;
    } else {
        node* last = phead->pprv;
        last->pnxt = pnew;
        pnew->pprv = last;
        pnew->pnxt = phead;
        phead->pprv = pnew;
    }
    return pnew;
}

void player::delete_node(Guns _guns) {
    if (phead == nullptr) {
        cout << "Error: No member to delete." << endl;
        return;
    }

    node* ptmp = phead;
    do {
        if (ptmp->data.get_using_gun_name() == _guns) {
            if (ptmp == phead) {
                if (ptmp->pnxt == phead) {
                    delete ptmp;
                    phead = nullptr;
                } else {
                    node* last = phead->pprv;
                    phead = ptmp->pnxt;
                    last->pnxt = phead;
                    phead->pprv = last;
                    delete ptmp;
                }
            } else {
                node* before = ptmp->pprv;
                node* after = ptmp->pnxt;
                before->pnxt = after;
                after->pprv = before;
                delete ptmp;
            }
            return;
        }
        ptmp = ptmp->pnxt;
    } while (ptmp != phead);

    cout << "Not found." << endl;
}

// Implementations of terrorist class
void terrorist::set_bomb(bool _bomb) { bomb = _bomb; }
void terrorist::set_using_bomb(bool _using_bomb) { using_bomb = _using_bomb; }
bool terrorist::get_bomb() { return bomb; }
bool terrorist::get_using_bomb() { return using_bomb; }

terrorist::terrorist() : bomb(true), using_bomb(false) {}
terrorist::terrorist(const terrorist& obj) : player(obj), bomb(obj.bomb), using_bomb(obj.using_bomb) {}
terrorist::terrorist(bool _bomb, bool _using_bomb) : bomb(_bomb), using_bomb(_using_bomb) {}

terrorist& terrorist::operator=(const terrorist& obj) {
    player::operator=(obj);
    bomb = obj.bomb;
    using_bomb = obj.using_bomb;
    return *this;
}

bool terrorist::operator!=(const terrorist& obj) { return !(*this == obj); }
bool terrorist::operator==(const terrorist& obj) {
    return bomb == obj.bomb && using_bomb == obj.using_bomb;
}

// Implementations of ct class
void ct::set_kit(bool _kit) { kit = _kit; }
void ct::set_cooling_bomb(bool _cooling_bomb) { cooling_bomb = _cooling_bomb; }
bool ct::get_kit() { return kit; }
bool ct::get_cooling_bomb() { return cooling_bomb; }

ct::ct() : kit(true), cooling_bomb(false) {}
ct::ct(const ct& obj) : player(obj), kit(obj.kit), cooling_bomb(obj.cooling_bomb) {}
ct::ct(bool _kit, bool _cooling_bomb) : kit(_kit), cooling_bomb(_cooling_bomb) {}

ct& ct::operator=(const ct& obj) {
    player::operator=(obj);
    kit = obj.kit;
    cooling_bomb = obj.cooling_bomb;
    return *this;
}

bool ct::operator!=(const ct& obj) { return !(*this == obj); }
bool ct::operator==(const ct& obj) {
    return kit == obj.kit && cooling_bomb == obj.cooling_bomb;
}

// Implementations of game_map class
void game_map::set_map_name(string _map_name) { map_name = _map_name; }
void game_map::set_maker_map(string _maker_map) { maker_map = _maker_map; }
void game_map::set_am_pm(bool _am_pm) { am_pm = _am_pm; }

string game_map::get_map_name() { return map_name; }
string game_map::get_maker_map() { return maker_map; }
bool game_map::get_am_pm() { return am_pm; }

game_map::game_map() : map_name(""), maker_map(""), am_pm(true) {}
game_map::game_map(const game_map& obj) : map_name(obj.map_name), maker_map(obj.maker_map), am_pm(obj.am_pm) {}
game_map::game_map(string _map_name, string _maker_map, bool _am_pm) :
        map_name(_map_name), maker_map(_maker_map), am_pm(_am_pm) {}

game_map& game_map::operator=(const game_map& obj) {
    map_name = obj.map_name;
    maker_map = obj.maker_map;
    am_pm = obj.am_pm;
    return *this;
}

bool game_map::operator!=(const game_map& obj) { return !(*this == obj); }
bool game_map::operator==(const game_map& obj) {
    return map_name == obj.map_name &&
           maker_map == obj.maker_map &&
           am_pm == obj.am_pm;
}

// Implementations of game_manager class
void game_manager::set_map_name(string _map_name) { map_name = _map_name; }
void game_manager::set_game_result(int _game_result) { game_result = _game_result; }

string game_manager::get_map_name() { return map_name; }
int game_manager::get_game_result() { return game_result; }

game_manager::game_manager(const game_manager& obj) : map_name(obj.map_name), game_result(obj.game_result) {}
game_manager::game_manager(string _map_name, int _game_result) : map_name(_map_name), game_result(_game_result) {}

game_manager& game_manager::operator=(const game_manager& obj) {
    map_name = obj.map_name;
    game_result = obj.game_result;
    return *this;
}

bool game_manager::operator!=(const game_manager& obj) { return !(*this == obj); }
bool game_manager::operator==(const game_manager& obj) {
    return map_name == obj.map_name && game_result == obj.game_result;
}

int game_manager::display_history(const string& filename, const string& userid) {
    string line, winner;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: can not open file!" << endl;
        return -1;
    }

    int round_game = 1;
    int user_wins = 0;
    while (getline(file, line)) {
        for (char c : line) {
            if (c == '0') {
                winner = "Terrorist";
                for (size_t i = 0; i < team_terrorist.size(); i++) {
                    if (team_terrorist[i].get_id() == userid) {
                        user_wins++;
                    }
                    round_game++;
                }
            }
            else if (c == '1') {
                winner = "CT";
                for (size_t i = 0; i < team_ct.size(); ++i) {
                    if (team_ct[i].get_id() == userid) {
                        user_wins++;
                    }
                    round_game++;
                }
            }
            else {
                cout << "invalid result" << endl;
                continue;
            }
        }
    }
    cout << "Round " << round_game << ": " << "winner :" << winner << endl;
    return user_wins;
}

void game_manager::setting_menu() {
    int a;
    int c;
    int t;

    cout << "please choose one map" << endl;
    cout << "1.map1" << endl << "2.map2" << endl << "3.map3" << endl
         << "4.map4" << endl << "5.map5" << endl;
    cin >> a;
    system("cls");

    do {
        cout << "please enter the number of player of each team" << endl;
        cout << "CT team" << endl;
        cin >> c;
        cout << "Terrorist team" << endl;
        cin >> t;

    } while (!((c / (float)t >= 0.95 && c / (float)t <= 1.05) ||
               (t / (float)c >= 0.95 && t / (float)c <= 1.05)));
    system("cls");
    cout << "please enter money of each CT player " << endl;
    vector<int> ct_money(c);
    for (int i = 0; i < c; ++i)
        cin >> ct_money[i];
    cout << "please enter money of each terrorist player " << endl;
    vector<int> terrorist_money(t);
    for (int i = 0; i < t; ++i)
        cin >> terrorist_money[i];
    setting_before_start = 1;
}

void game_manager::start_game() {
    int terroristIndex = 0;
    int ctIndex = 0;

    while (terroristIndex < team_terrorist.size() && ctIndex < team_ct.size()) {
        player& terroristPlayer = team_terrorist[terroristIndex];
        player& ctPlayer = team_ct[ctIndex];

        double terroristPower = terroristPlayer.get_money();
        double ctPower = ctPlayer.get_money();

        if (terroristPower > ctPower) {
            ctPlayer.set_health(ctPlayer.get_health() - (terroristPower - ctPower));
            cout << "Terrorist " << terroristPlayer.get_name() << " defeated CT " << ctPlayer.get_name() << endl;
            if (ctPlayer.get_health() <= 0) {
                ctIndex++;
            }
        }
        else if (ctPower > terroristPower) {
            terroristPlayer.set_health(terroristPlayer.get_health() - (ctPower - terroristPower));
            cout << "CT " << ctPlayer.get_name() << " defeated Terrorist " << terroristPlayer.get_name() << endl;
            if (terroristPlayer.get_health() <= 0) {
                terroristIndex++;
            }
        }
        else {
            terroristPlayer.set_health(terroristPlayer.get_health() - 1);
            ctPlayer.set_health(ctPlayer.get_health() - 1);
            cout << "Both " << terroristPlayer.get_name() << " and " << ctPlayer.get_name() << " took damage!" << endl;
            if (terroristPlayer.get_health() <= 0) {
                terroristIndex++;
            }
            if (ctPlayer.get_health() <= 0) {
                ctIndex++;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }

    checkWinner();
}

void game_manager::checkWinner() {
    bool terroristAlive = false;
    bool ctAlive = false;

    for (player& p : team_terrorist) {
        if (p.get_health() > 0) {
            terroristAlive = true;
            break;
        }
    }

    for (player& p : team_ct) {
        if (p.get_health() > 0) {
            ctAlive = true;
            break;
        }
    }

    if (terroristAlive && !ctAlive) {
        cout << "\nTerrorist team wins!" << endl;
        game_result = 0;
    }
    else if (ctAlive && !terroristAlive) {
        cout << "\nCT team wins!" << endl;
        game_result = 1;
    }
    else {
        cout << "\nDraw! Both teams are down!" << endl;
        game_result = -1;
    }
}

// Implementations of users class
users::users() : username(""), nickname(""), passwordHash(""), wins(0) {}
users::users(const users& other) : username(other.username), nickname(other.nickname),
                                   passwordHash(other.passwordHash), wins(other.wins) {}
users::users(string _username, string _nickname, string _passwordHash, int _wins) :
        username(_username), nickname(_nickname), passwordHash(_passwordHash), wins(_wins) {}

bool users::registerUser() {
    cout << "please enter your username" << endl;
    cin >> username;
    cout << "please enter your nickname" << endl;
    cin >> nickname;
    cout << "enter your password" << endl;
    string password;
    cin >> password;
    passwordHash = hashPassword(password);
    saveToFile();
    return true;
}

bool users::loginUser(const string& password) {
    return passwordHash == hashPassword(password);
}

void users::updateWins() {
    wins++;
}

void users::saveToFile() {
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << nickname << " " << passwordHash << " " << wins << endl;
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

users users::loadFromFile(const string& username) {
    ifstream file("users.txt");
    string user, nickname, passwordHash;
    int wins;

    while (file >> user >> nickname >> passwordHash >> wins) {
        if (user == username) {
            return users(user, nickname, passwordHash, wins);
        }
    }

    return users();
}

string users::getusername() const { return username; }
string users::getnickname() const { return nickname; }
int users::getWins() const { return wins; }

// Test functions
void test_gun_normal() {
    gun g(30, 1500, "GUN123", AK47, 50, 1);
    if (g.get_num_shot() == 30 && g.get_price() == 1500)
        cout << "✅ test_gun_normal passed\n";
    else
        cout << "❌ test_gun_normal failed\n";
}

void test_gun_edge_case() {
    gun g(0, 0, "NONE", P90, 0, 1);
    if (g.get_num_shot() == 0 && g.get_power_shot() == 0)
        cout << "✅ test_gun_edge_case passed\n";
    else
        cout << "❌ test_gun_edge_case failed\n";
}

void test_gun_invalid() {
    gun g(-10, -500, "BADGUN", AK47, -20, 1);
    if (g.get_num_shot() < 0 || g.get_price() < 0)
        cout << "⚠️ Warning: Invalid gun created! Needs validation.\n";
    else
        cout << "✅ test_gun_invalid passed\n";
}

void test_player_normal() {
    player p("Player1", 100);
    p.set_health(100);
    if (p.get_name() == "Player1" && p.get_health() == 100)
        cout << "✅ test_player_normal passed\n";
    else
        cout << "❌ test_player_normal failed\n";
}

void test_player_edge_case() {
    player p("Player2", 0);
    p.set_health(0);
    if (p.get_health() == 0)
        cout << "✅ test_player_edge_case passed\n";
    else
        cout << "❌ test_player_edge_case failed\n";
}

void test_player_invalid() {
    player p("Player3", -50);
    p.set_health(-50);
    if (p.get_health() < 0)
        cout << "⚠️ Warning: Negative health detected! Should validate.\n";
    else
        cout << "✅ test_player_invalid passed\n";
}

void test_map_creation() {
    game_map m("Dust2", "Valve", true);
    if (m.get_map_name() == "Dust2")
        cout << "✅ test_map_creation passed\n";
    else
        cout << "❌ test_map_creation failed\n";
}

void test_combat_system() {
    game_manager* gm = game_manager::instance();
    player p1("p1", 100);
    player p2("p2", 100);
    p1.set_money(50);
    p2.set_money(30);

    gm->add_terrorist_player(p1);
    gm->add_ct_player(p2);

    gm->start_game();

    if (p2.get_health() < 100)
        cout << "✅ test_combat_system passed\n";
    else
        cout << "❌ test_combat_system failed\n";
}

int main() {
    cout << "🚀 Running Unit Tests:" << endl;

    test_gun_normal();
    test_gun_edge_case();
    test_gun_invalid();

    test_player_normal();
    test_player_edge_case();
    test_player_invalid();

    test_map_creation();
    test_combat_system();

    return 0;
}