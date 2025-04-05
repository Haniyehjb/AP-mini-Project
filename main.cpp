#include <iostream>
#include <vector>

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

};
class trorist{
private :
    int bomb;
    int using_bomb;

};
class ct{
private:
    int kit;
    int cooling_bomb;

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

};
