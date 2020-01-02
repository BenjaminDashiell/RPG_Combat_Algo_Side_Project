#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct information{
    string id = "";
    string name = "";
    int baseHP = 0;
    int baseMP = 0;
    string attackOne = "";
    int attackOneDamage = 0;
    int attackOneMP = 0;
    string attackTwo = "";
    int attackTwoDamage = 0;
    int attackTwoMP = 0;
    string attackThree = "";
    int attackThreeDamage = 0;
    int attackThreeMP = 0;
    string attackFour = "";
    int attackFourDamage = 0;
    int attackFourMP = 0;
};
//
class game{
    private:
      information monster_database[10];
      information hero_database[4];
      int MPpotions = 20;
      int HPpotions = 50;
      int party_member_one_index = 0;
      int party_member_one_health = 0;
      int party_member_one_mp = 0;
      //
      int party_member_two_index = 0;
      int party_member_two_health = 0;
      int party_member_two_mp = 0;
      //
      int party_member_three_index = 0;
      int party_member_three_health = 0;
      int party_member_three_mp = 0;
      //
      int monster_one_index = 0;
      int monster_one_health = 0;
      int monster_one_mp = 0;
      //
      int monster_two_index = 0;
      int monster_two_health = 0;
      int monster_two_mp = 0;
      //
      int monster_three_index = 0;
      int monster_three_health = 0;
      int monster_three_mp = 0;
      //
      bool quitter = false;
    public:
      void readDatabase(string filename);
      //void printDatabase();
      void displayMoveset(int index);
      void displayItems();
      void displayFightMenu();
      bool stoicheck(string input);
      void playerCombat(int heroturn, int index);
      int enemyEncounterProb();
      void battle();
      void heroSelection();
      void printBattleStats();
      bool CriticalHit();
      void dealDamage(string id, int index, int heroturn, int move, int target);
      void useItems(int index, int move, int target);
      bool monstersSlain();
      bool partyActive();
};
//
void game::readDatabase(string filename){
    ifstream readfile;
    readfile.open(filename);
    if(readfile.is_open()){
        string whole_line = "";
        int i = 0;
        while(getline(readfile, whole_line)){
          stringstream line(whole_line);
          string id = "";
          getline(line,whole_line,',');
          id = whole_line;
          if(id == "monster"){
            monster_database[i].id = whole_line;
          }
          else if(id == "hero"){
            hero_database[i].id = whole_line;
          }
          id = whole_line;
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].name = whole_line;
          }
          else if(id == "hero"){
            hero_database[i].name = whole_line;
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].baseHP = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].baseHP = stoi(whole_line);
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].baseMP = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].baseMP = stoi(whole_line);
          }
          //
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackOne = whole_line;
          }
          else if(id == "hero"){
            hero_database[i].attackOne = whole_line;
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackOneDamage = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackOneDamage = stoi(whole_line);
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackOneMP = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackOneMP = stoi(whole_line);
          }
          //
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackTwo = whole_line;
          }
          else if(id == "hero"){
            hero_database[i].attackTwo = whole_line;
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackTwoDamage = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackTwoDamage = stoi(whole_line);
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackTwoMP = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackTwoMP = stoi(whole_line);
          }
          //
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackThree = whole_line;
          }
          else if(id == "hero"){
            hero_database[i].attackThree = whole_line;
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackThreeDamage = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackThreeDamage = stoi(whole_line);
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackThreeMP = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackThreeMP = stoi(whole_line);
          }
          //
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackFour = whole_line;
          }
          else if(id == "hero"){
            hero_database[i].attackFour = whole_line;
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackFourDamage = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackFourDamage = stoi(whole_line);
          }
          //
          getline(line,whole_line,',');
          if(id == "monster"){
            monster_database[i].attackFourMP = stoi(whole_line);
          }
          else if(id == "hero"){
            hero_database[i].attackFourMP = stoi(whole_line);
          }
          //
          i++;
        }
    }
    else{
        cout << "The file needed can not be found" << endl;
    }
    readfile.close();
};
//
void game::displayMoveset(int index){
    cout << "Moveset:" << endl;
    if(hero_database[index].attackOne != "None"){
      cout << "1. " << hero_database[index].attackOne << endl;
    }
    if(hero_database[index].attackTwo != "None"){
      cout << "2. " << hero_database[index].attackTwo << endl;
    }
    if(hero_database[index].attackThree != "None"){
      cout << "3. " << hero_database[index].attackThree << endl;
    }
    if(hero_database[index].attackFour != "None"){
      cout << "4. " << hero_database[index].attackFour << endl;
    }
};
//
void game::displayItems(){
  cout << "1. HP Potions (Restore 20 HP): " << HPpotions << " Remaining." << endl;
  cout << "2. MP Potions (Restore 25 MP): " << MPpotions << " Remaining." << endl;
};
//
void game::displayFightMenu(){
    cout << "1. Fight" << endl;
    cout << "2. Items" << endl;
    cout << "3. Run" << endl;
};
//
bool game::stoicheck(string input){
    //check for empty string
    if (input == ""){
        cout << "Input is empty. Please enter something else" << endl;
        return false;
    }
    //traverse the string
    for(int i = 0; i < input.length(); i++){
        if (input[i] != '0' && input[i] != '1' && input[i] != '2' && input[i] != '3' && input[i] != '4' && input[i] != '5' && input[i] != '6' && input[i] != '7' && input[i] != '8' && input[i] != '9'){
            //Does it contain non integer 0-9
            //cout << "false " << false << endl;
            cout << "Invalid input. Please stop trying to break my game!"  << endl;
            return false;
        }
    }
    //cout << "true " << true << endl;
    return true;
};
//
void game::useItems(int index, int move, int target){
    int restore;
    if(move == 1){
      cout << hero_database[index].name << " used a HP Potion on ";
      if(target == 1){
        cout << hero_database[party_member_one_index].name << endl;
        restore = party_member_one_health + 20;
        if(restore > 100){
          party_member_one_health = 100;
        }
        else{
          party_member_one_health += 20;
        }
      }
      else if(target == 2){
        cout << hero_database[party_member_two_index].name << endl;
        restore = party_member_two_health + 20;
        if(restore > 100){
          party_member_two_health = 100;
        }
        else{
          party_member_two_health += 20;
        }
      }
      else if(target == 3){
        cout << hero_database[party_member_three_index].name << endl;
        restore = party_member_three_health + 20;
        if(restore > 100){
          party_member_three_health = 100;
        }
        else{
          party_member_three_health += 20;
        }
      }
    }
    else if(move == 2){
      cout << hero_database[index].name << " used a MP Potion on ";
      if(target == 1){
        cout << hero_database[party_member_one_index].name << endl;
        restore = party_member_one_mp + 25;
        if(restore > 100){
          party_member_one_mp = 100;
        }
        else{
          party_member_one_mp += 25;
        }
      }
      else if(target == 2){
        cout << hero_database[party_member_two_index].name << endl;
        restore = party_member_two_mp + 25;
        if(restore > 100){
          party_member_two_mp = 100;
        }
        else{
          party_member_two_mp += 25;
        }
      }
      else if(target == 3){
        cout << hero_database[party_member_three_index].name << endl;
        restore = party_member_three_index + 25;
        if(restore > 100){
          party_member_three_mp = 100;
        }
        else{
          party_member_three_mp += 25;
        }
      }
    }
};
//
void game::dealDamage(string id, int index, int heroturn, int move, int target){
    bool ch = CriticalHit();
    bool enoughMP = true;
    if(id == "monster"){
        bool selectMove = false;
        while(selectMove == false){
          move = rand() % 4 + 1;
          if(move == 2){
            if(monster_database[index].attackTwo != "None"){
                selectMove = true;
            }
          }
          else if(move == 3){
            if(monster_database[index].attackThree != "None"){
                selectMove = true;
            }
          }
          else if(move == 4){
            if(monster_database[index].attackFour != "None"){
                selectMove = true;
            }
          }
          else{
            selectMove = true;
          }
        }
        //
        target = rand() % 3 + 1;
        //
        if(heroturn == 1){
          if(monster_one_mp <= 0){
            enoughMP = false;
          }
          if(move == 1)
          {
            if(monster_one_mp < monster_database[index].attackOneMP){
              enoughMP = false;
            }
          }
          if(move == 2)
          {
            if(monster_one_mp < monster_database[index].attackTwoMP){
              enoughMP = false;
            }
          }
          if(move == 3)
          {
            if(monster_one_mp < monster_database[index].attackThreeMP){
              enoughMP = false;
            }
          }
          if(move == 4)
          {
            if(monster_one_mp < monster_database[index].attackFourMP){
              enoughMP = false;
            }
          }
        }
        else if(heroturn == 2){
          if(monster_two_mp <= 0){
            enoughMP = false;
          }
          if(move == 1)
          {
            if(monster_two_mp < monster_database[index].attackOneMP){
              enoughMP = false;
            }
          }
          if(move == 2)
          {
            if(monster_two_mp < monster_database[index].attackTwoMP){
              enoughMP = false;
            }
          }
          if(move == 3)
          {
            if(monster_two_mp < monster_database[index].attackThreeMP){
              enoughMP = false;
            }
          }
          if(move == 4)
          {
            if(monster_two_mp < monster_database[index].attackFourMP){
              enoughMP = false;
            }
          }
        }
        else if(heroturn == 3){
          if(monster_three_mp <= 0){
            enoughMP = false;
          }
          if(move == 1)
          {
            if(monster_three_mp < monster_database[index].attackOneMP){
              enoughMP = false;
            }
          }
          if(move == 2)
          {
            if(monster_three_mp < monster_database[index].attackTwoMP){
              enoughMP = false;
            }
          }
          if(move == 3)
          {
            if(monster_three_mp < monster_database[index].attackThreeMP){
              enoughMP = false;
            }
          }
          if(move == 4)
          {
            if(monster_three_mp < monster_database[index].attackFourMP){
              enoughMP = false;
            }
          }
        }
        //
        if(enoughMP == true){
        if(move == 1){
          cout << monster_database[index].name << " used " << monster_database[index].attackOne << " to deal ";
          if(ch == false){
            cout << monster_database[index].attackOneDamage << " damage to ";
          }
          else{
            cout << "a critical " << (monster_database[index].attackOneDamage + (monster_database[index].attackOneDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << hero_database[party_member_one_index].name << endl;
              party_member_one_health = party_member_one_health - monster_database[index].attackOneDamage;
          }
          else if(target == 2){
              cout << hero_database[party_member_two_index].name << endl;
              party_member_two_health = party_member_two_health - monster_database[index].attackOneDamage;
          }
          else if(target == 3){
              cout << hero_database[party_member_three_index].name << endl;
              party_member_three_health = party_member_three_health - monster_database[index].attackOneDamage;
          }
          //
          if(heroturn == 1){
            monster_one_mp = monster_one_mp - monster_database[index].attackOneMP;
          }
          else if(heroturn == 2){
            monster_two_mp = monster_two_mp - monster_database[index].attackOneMP;
          }
          else if(heroturn == 3){
            monster_three_mp = monster_three_mp - monster_database[index].attackOneMP;
          }
        }
        if(move == 2){
          cout << monster_database[index].name << " used " << monster_database[index].attackTwo << " to deal ";
          if(ch == false){
            cout << monster_database[index].attackTwoDamage << " damage to ";
          }
          else{
            cout << "a critical " << (monster_database[index].attackTwoDamage + (monster_database[index].attackTwoDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << hero_database[party_member_one_index].name << endl;
              party_member_one_health = party_member_one_health - monster_database[index].attackTwoDamage;
          }
          else if(target == 2){
              cout << hero_database[party_member_two_index].name << endl;
              party_member_two_health = party_member_two_health - monster_database[index].attackTwoDamage;
          }
          else if(target == 3){
              cout << hero_database[party_member_three_index].name << endl;
              party_member_three_health = party_member_three_health - monster_database[index].attackTwoDamage;
          }
          //
          if(heroturn == 1){
            monster_one_mp = monster_one_mp - monster_database[index].attackTwoMP;
          }
          else if(heroturn == 2){
            monster_two_mp = monster_two_mp - monster_database[index].attackTwoMP;
          }
          else if(heroturn == 3){
            monster_three_mp = monster_three_mp - monster_database[index].attackTwoMP;
          }
        }
        if(move == 3){
          cout << monster_database[index].name << " used " << monster_database[index].attackThree << " to deal ";
          if(ch == false){
            cout << monster_database[index].attackThreeDamage << " damage to ";
          }
          else{
            cout << "a critical " << (monster_database[index].attackThreeDamage + (monster_database[index].attackThreeDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << hero_database[party_member_one_index].name << endl;
              party_member_one_health = party_member_one_health - monster_database[index].attackThreeDamage;
          }
          else if(target == 2){
              cout << hero_database[party_member_two_index].name << endl;
              party_member_two_health = party_member_two_health - monster_database[index].attackThreeDamage;
          }
          else if(target == 3){
              cout << hero_database[party_member_three_index].name << endl;
              party_member_three_health = party_member_three_health - monster_database[index].attackThreeDamage;
          }
          //
          if(heroturn == 1){
            monster_one_mp = monster_one_mp - monster_database[index].attackThreeMP;
          }
          else if(heroturn == 2){
            monster_two_mp = monster_two_mp - monster_database[index].attackThreeMP;
          }
          else if(heroturn == 3){
            monster_three_mp = monster_three_mp - monster_database[index].attackThreeMP;
          }
        }
        if(move == 4){
          cout << monster_database[index].name << " used " << monster_database[index].attackFour << " to deal ";
          if(ch == false){
            cout << monster_database[index].attackFourDamage << " damage to ";
          }
          else{
            cout << "a critical " << (monster_database[index].attackFourDamage + (monster_database[index].attackFourDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << hero_database[party_member_one_index].name << endl;
              party_member_one_health = party_member_one_health - monster_database[index].attackFourDamage;
          }
          else if(target == 2){
              cout << hero_database[party_member_two_index].name << endl;
              party_member_two_health = party_member_two_health - monster_database[index].attackFourDamage;
          }
          else if(target == 3){
              cout << hero_database[party_member_three_index].name << endl;
              party_member_three_health = party_member_three_health - monster_database[index].attackFourDamage;
          }
          //
          if(heroturn == 1){
            monster_one_mp = monster_one_mp - monster_database[index].attackFourMP;
          }
          else if(heroturn == 2){
            monster_two_mp = monster_two_mp - monster_database[index].attackFourMP;
          }
          else if(heroturn == 3){
            monster_three_mp = monster_three_mp - monster_database[index].attackFourMP;
          }
        }
      }
        else{
            cout << "There is not enough MP for the monster to use its desired move. You take no damage." << endl;
        }
    }
    else if(id == "hero"){
        if(heroturn == 1){
          if(party_member_one_mp <= 0){
            enoughMP = false;
          }
          if(move == 1)
          {
            if(party_member_one_mp < hero_database[index].attackOneMP){
              enoughMP = false;
            }
          }
          if(move == 2)
          {
            if(party_member_one_mp < hero_database[index].attackTwoMP){
              enoughMP = false;
            }
          }
          if(move == 3)
          {
            if(party_member_one_mp < hero_database[index].attackThreeMP){
              enoughMP = false;
            }
          }
          if(move == 4)
          {
            if(party_member_one_mp < hero_database[index].attackFourMP){
              enoughMP = false;
            }
          }
        }
        else if(heroturn == 2){
          if(party_member_two_mp <= 0){
            enoughMP = false;
          }
          if(move == 1)
          {
            if(party_member_two_mp < hero_database[index].attackOneMP){
              enoughMP = false;
            }
          }
          if(move == 2)
          {
            if(party_member_two_mp < hero_database[index].attackTwoMP){
              enoughMP = false;
            }
          }
          if(move == 3)
          {
            if(party_member_two_mp < hero_database[index].attackThreeMP){
              enoughMP = false;
            }
          }
          if(move == 4)
          {
            if(party_member_two_mp < hero_database[index].attackFourMP){
              enoughMP = false;
            }
          }
        }
        else if(heroturn == 3){
          if(party_member_three_mp <= 0){
            enoughMP = false;
          }
          if(move == 1)
          {
            if(party_member_three_mp < hero_database[index].attackOneMP){
              enoughMP = false;
            }
          }
          if(move == 2)
          {
            if(party_member_three_mp < hero_database[index].attackTwoMP){
              enoughMP = false;
            }
          }
          if(move == 3)
          {
            if(party_member_three_mp < hero_database[index].attackThreeMP){
              enoughMP = false;
            }
          }
          if(move == 4)
          {
            if(party_member_three_mp < hero_database[index].attackFourMP){
              enoughMP = false;
            }
          }
        }
        //
        if(enoughMP == true){
        if(move == 1){
          cout << hero_database[index].name << " used " << hero_database[index].attackOne << " to deal ";
          if(ch == false){
            cout << hero_database[index].attackOneDamage << " damage to ";
          }
          else{
            cout << "a critical " << (hero_database[index].attackOneDamage + (hero_database[index].attackOneDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << monster_database[monster_one_index].name << endl;
              monster_one_health = monster_one_health - hero_database[index].attackOneDamage;
          }
          else if(target == 2){
              cout << monster_database[monster_two_index].name << endl;
              monster_two_health = monster_two_health - hero_database[index].attackOneDamage;
          }
          else if(target == 3){
              cout << monster_database[monster_three_index].name << endl;
              monster_three_health = monster_three_health - hero_database[index].attackOneDamage;
          }
          //
          if(heroturn == 1){
            party_member_one_mp = party_member_one_mp - hero_database[index].attackOneMP;
          }
          else if(heroturn == 2){
            party_member_two_mp = party_member_two_mp - hero_database[index].attackOneMP;
          }
          else if(heroturn == 3){
            party_member_three_mp = party_member_three_mp - hero_database[index].attackOneMP;
          }
        }
        else if(move == 2){
          cout << hero_database[index].name << " used " << hero_database[index].attackTwo << " to deal ";
          if(ch == false){
            cout << hero_database[index].attackTwoDamage << " damage to ";
          }
          else{
            cout << "a critical " << (hero_database[index].attackTwoDamage + (hero_database[index].attackTwoDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << monster_database[monster_one_index].name << endl;
              monster_one_health = monster_one_health - hero_database[index].attackTwoDamage;
          }
          else if(target == 2){
              cout << monster_database[monster_two_index].name << endl;
              monster_two_health = monster_two_health - hero_database[index].attackTwoDamage;
          }
          else if(target == 3){
              cout << monster_database[monster_three_index].name << endl;
              monster_three_health = monster_three_health - hero_database[index].attackTwoDamage;
          }
          //
          if(heroturn == 1){
            party_member_one_mp = party_member_one_mp - hero_database[index].attackTwoMP;
          }
          else if(heroturn == 2){
            party_member_two_mp = party_member_two_mp - hero_database[index].attackTwoMP;
          }
          else if(heroturn == 3){
            party_member_three_mp = party_member_three_mp - hero_database[index].attackTwoMP;
          }
        }
        else if(move == 3){
          cout << hero_database[index].name << " used " << hero_database[index].attackThree << " to deal ";
          if(ch == false){
            cout << hero_database[index].attackThreeDamage << " damage to ";
          }
          else{
            cout << "a critical " << (hero_database[index].attackThreeDamage + (hero_database[index].attackThreeDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << monster_database[monster_one_index].name << endl;
              monster_one_health = monster_one_health - hero_database[index].attackThreeDamage;
          }
          else if(target == 2){
              cout << monster_database[monster_two_index].name << endl;
              monster_two_health = monster_two_health - hero_database[index].attackThreeDamage;
          }
          else if(target == 3){
              cout << monster_database[monster_three_index].name << endl;
              monster_three_health = monster_three_health - hero_database[index].attackThreeDamage;
          }
          //
          if(heroturn == 1){
            party_member_one_mp = party_member_one_mp - hero_database[index].attackThreeMP;
          }
          else if(heroturn == 2){
            party_member_two_mp = party_member_two_mp - hero_database[index].attackThreeMP;
          }
          else if(heroturn == 3){
            party_member_three_mp = party_member_three_mp - hero_database[index].attackThreeMP;
          }
        }
        else if(move == 4){
          cout << hero_database[index].name << " used " << hero_database[index].attackFour << " to deal ";
          if(ch == false){
            cout << hero_database[index].attackFourDamage << " damage to ";
          }
          else{
            cout << "a critical " << (hero_database[index].attackFourDamage + (hero_database[index].attackFourDamage)*10) << "damage to ";
          }
          //
          if(target == 1){
              cout << monster_database[monster_one_index].name << endl;
              monster_one_health = monster_one_health - hero_database[index].attackFourDamage;
          }
          else if(target == 2){
              cout << monster_database[monster_two_index].name << endl;
              monster_two_health = monster_two_health - hero_database[index].attackFourDamage;
          }
          else if(target == 3){
              cout << monster_database[monster_three_index].name << endl;
              monster_three_health = monster_three_health - hero_database[index].attackFourDamage;
          }
          //
          if(heroturn == 1){
            party_member_one_mp = party_member_one_mp - hero_database[index].attackFourMP;
          }
          else if(heroturn == 2){
            party_member_two_mp = party_member_two_mp - hero_database[index].attackFourMP;
          }
          else if(heroturn == 3){
            party_member_three_mp = party_member_three_mp - hero_database[index].attackFourMP;
          }
        }
      }
        else{
            cout << "There is not enough MP for you to use your desired move. Enemy takes no damage." << endl;
        }
    }
    enoughMP = true;
};
//
void game::playerCombat(int heroturn, int index){
    string choice;
    int target;
    int move;
    bool input = false;
    bool finished = false;
    bool enoughMP = true;
    while (choice != "3" && finished == false){
      cout << "What would " << hero_database[index].name << " like to do?" << endl;
      displayFightMenu();
      bool integer_check = false;
      while (integer_check == false){
          cin >> choice;
          integer_check = stoicheck(choice);
          //cout << "integer_check " << integer_check << endl;
          if (integer_check == true){
              integer_check =  true;
          }
      }
      integer_check = false;
      switch(stoi(choice)) {
          case 1:
            {
                if(heroturn == 1){
                  if(party_member_one_mp <= 0){
                    move = 1;
                    enoughMP = false;
                  }
                }
                else if(heroturn == 2){
                  if(party_member_two_mp <= 0){
                    move = 1;
                    enoughMP = false;
                  }
                }
                else if(heroturn == 3){
                  if(party_member_three_mp <= 0){
                    move = 1;
                    enoughMP = false;
                  }
                }
                if(enoughMP == true){
                  cout << "Which move would you like to use?" << endl;
                  displayMoveset(index);
                  while (input == false){
                    while (integer_check == false){
                        cin >> choice;
                        integer_check = stoicheck(choice);
                        //cout << "integer_check " << integer_check << endl;
                        if (integer_check == true){
                            integer_check =  true;
                        }
                    }
                    move = stoi(choice);
                    input = true;
                  }
                  integer_check = false;
                  input = false;
                }
                //
                cout << "Who would you like to target?" << endl;
                if(monster_one_index != -1 && monster_one_health > 0){
                  cout << "1. " << monster_database[monster_one_index].name << endl;
                }
                if(monster_two_index != -1 && monster_two_health > 0){
                  cout << "2. " << monster_database[monster_two_index].name << endl;
                }
                if(monster_three_index != -1 && monster_three_health > 0){
                  cout << "3. " << monster_database[monster_three_index].name << endl;
                }
                while(input == false){
                  while (integer_check == false){
                      cin >> choice;
                      integer_check = stoicheck(choice);
                      //cout << "integer_check " << integer_check << endl;
                      if (integer_check == true){
                          integer_check =  true;
                      }
                  }
                  target = stoi(choice);
                  input = true;
                }
                integer_check = false;
                input = false;
                dealDamage("hero", index, heroturn, move, target);
                finished = true;
                break;
            }
          case 2:
            {
                displayItems();
                cout << "Which would you like to use?" << endl;
                while (input == false){
                  while (integer_check == false){
                      cin >> choice;
                      integer_check = stoicheck(choice);
                      //cout << "integer_check " << integer_check << endl;
                      if (integer_check == true){
                          integer_check =  true;
                      }
                  }
                  integer_check = false;
                  move = stoi(choice);
                  if(choice == "1"){
                      move = stoi(choice);
                      HPpotions--;
                      cout << "Who would you like to use it on?" << endl;
                      if(party_member_one_health > 0){
                        cout << "1. " << hero_database[party_member_one_index].name << endl;
                      }
                      if(party_member_two_health > 0){
                        cout << "2. " << hero_database[party_member_two_index].name << endl;
                      }
                      if(party_member_three_health > 0){
                        cout << "3. " << hero_database[party_member_three_index].name << endl;
                      }
                      while (integer_check == false){
                          cin >> choice;
                          integer_check = stoicheck(choice);
                          //cout << "integer_check " << integer_check << endl;
                          if (integer_check == true){
                              integer_check =  true;
                          }
                      }
                      target = stoi(choice);
                      integer_check = false;
                      useItems(index, move, target);
                      input = true;
                  }
                  else if(choice == "2"){
                      MPpotions--;
                      cout << "Who would you like to use it on?" << endl;
                      if(party_member_one_health > 0){
                        cout << "1. " << hero_database[party_member_one_index].name << endl;
                      }
                      if(party_member_two_health > 0){
                        cout << "2. " << hero_database[party_member_two_index].name << endl;
                      }
                      if(party_member_three_health > 0){
                        cout << "3. " << hero_database[party_member_three_index].name << endl;
                      }
                      while (integer_check == false){
                          cin >> choice;
                          integer_check = stoicheck(choice);
                          //cout << "integer_check " << integer_check << endl;
                          if (integer_check == true){
                              integer_check =  true;
                          }
                      }
                      target = stoi(choice);
                      integer_check = false;
                      useItems(index, move, target);
                      input = true;
                  }
                  else{
                    cout << "Invalid input." << endl;
                  }
                }
                input = false;
                finished = true;
                break;
            }
          case 3:
            {
                cout << "Really?? Alright then." << endl;
                quitter = true;
                break;
            }
      }
    }
    cout << endl;
    //cout << "End Turn" << endl;
};
//
int game::enemyEncounterProb(){
    int random = 0;
    random = rand() % 100;
    //cout << "Random: " << random << endl;
    if(random < 60){
      int enemy = rand() % 10;
      //cout << "Enemy: " << enemy << endl;
      return enemy;
    }
    return -1;
};
//
bool game::CriticalHit(){
    int random = 0;
    random = rand() % 100;
    //cout << "Random: " << random << endl;
    if(random > 90){
      return true;
    }
    return false;
};
//
void game::heroSelection(){
  string input;
  cout << "Your party leader was already selected for the purposes of this demo." << endl;
  party_member_one_index = 0;
  party_member_one_health = hero_database[0].baseHP;
  party_member_one_mp = hero_database[0].baseMP;
  cout << "Please choose the other two members you would like to have in your party." << endl;
  for(int i = 1; i < 4; i++){
    cout << i << ". " << hero_database[i].name << endl;
  }
  int choose_one;
  int choose_two;
  bool integer_check = false;
  while (integer_check == false){
      cin >> input;
      integer_check = stoicheck(input);
      //cout << "integer_check " << integer_check << endl;
      if(stoi(input) < 4){
          integer_check = true;
          choose_one = stoi(input);
      }
      else{
          integer_check =  false;
      }
  }
  integer_check = false;
  while (integer_check == false){
      cin >> input;
      integer_check = stoicheck(input);
      //cout << "integer_check " << integer_check << endl;
      if(stoi(input) < 4){
          integer_check = true;
          choose_two = stoi(input);
      }
      else{
          integer_check =  false;
      }
  }
  integer_check = false;
  party_member_two_index = choose_one;
  party_member_two_health = hero_database[choose_one].baseHP;
  party_member_two_mp = hero_database[choose_one].baseMP;
  party_member_three_index = choose_two;
  party_member_three_health = hero_database[choose_two].baseHP;
  party_member_three_mp = hero_database[choose_two].baseMP;
};
//
void game::printBattleStats(){
    if(monster_one_index != -1 && monster_one_health > 0){
      cout << "Enemy 1: " << monster_database[monster_one_index].name << endl;
      cout << "HP: " << monster_one_health << " | MP: " << monster_one_mp << endl;
    }
    if(monster_two_index != -1 && monster_two_health > 0){
      cout << "Enemy 2: "  << monster_database[monster_two_index].name << endl;
      cout << "HP: " << monster_two_health << " | MP: " << monster_two_mp << endl;
    }
    if(monster_three_index != -1 && monster_three_health > 0){
      cout << "Enemy 3: " << monster_database[monster_three_index].name << endl;
      cout << "HP: " << monster_three_health << " | MP: " << monster_three_mp << endl;
    }
    if(party_member_one_index != -1 && party_member_one_health > 0){
      cout << "Hero 1: " << hero_database[party_member_one_index].name << endl;
      cout << "HP: " << party_member_one_health << " | MP: " << party_member_one_mp << endl;
    }
    if(party_member_two_index != -1 && party_member_two_health > 0){
      cout << "Hero 2: " << hero_database[party_member_two_index].name << endl;
      cout << "HP: " << party_member_two_health << " | MP: " << party_member_two_mp << endl;
    }
    if(party_member_three_index != -1 && party_member_three_health > 0){
      cout << "Hero 3: " << hero_database[party_member_three_index].name << endl;
      cout << "HP: " << party_member_three_health << " | MP: " << party_member_three_mp << endl;
    }
    cout << endl;
};
//
bool game::monstersSlain(){
    if(monster_one_health <= 0){
      monster_one_health = 0;
    }
    if(monster_two_health <= 0){
      monster_two_health = 0;
    }
    if(monster_three_health <= 0){
      monster_three_health = 0;
    }
    if(monster_one_health <= 0 && monster_two_health <= 0 && monster_three_health <= 0){
      return true;
    }
    return false;
};
//
bool game::partyActive(){
    if(party_member_one_health <= 0){
      party_member_one_health = 0;
    }
    if(party_member_two_health <= 0){
      party_member_two_health = 0;
    }
    if(party_member_three_health <= 0){
      party_member_three_health = 0;
    }
    if(party_member_one_health >= 0 || party_member_two_health >= 0 || party_member_three_health >= 0){
      return true;
    }
    return false;
};
//
void game::battle(){
    /* initialize random seed: */
    srand (time(NULL));
    int enemyCounter = 0;
    int enemyEncounter = 0;
    int i = 0;
    //for the demo, it'll go to a max of 5 battle per run
    while(i < 5 && quitter == false){
      cout << "Battle: " << (i + 1) << "/5" << endl;
      //select enemy index
      monster_one_index = enemyEncounterProb();
      monster_two_index = enemyEncounterProb();
      monster_three_index = enemyEncounterProb();
      if(monster_one_index != -1){
        enemyCounter++;
        monster_one_health = monster_database[monster_one_index].baseHP;
        monster_one_mp = monster_database[monster_one_index].baseMP;
      }
      if(monster_two_index != -1){
        enemyCounter++;
        monster_two_health = monster_database[monster_two_index].baseHP;
        monster_two_mp = monster_database[monster_two_index].baseMP;
      }
      if(monster_three_index != -1){
        enemyCounter++;
        monster_three_health = monster_database[monster_three_index].baseHP;
        monster_three_mp = monster_database[monster_three_index].baseMP;
      }
      if(monster_one_index == -1 && monster_two_index == -1 && monster_three_index == -1){
          cout << "No Enemys Spawned. Lucky You." << endl << endl;
      }
      else{
          //while loop until either all the enemies or heros are dead
          bool dead_monsters = monstersSlain();
          bool alive = partyActive();
          while((dead_monsters == false) && (alive == true) && quitter == false){
            printBattleStats();
            cout << "The Heros Turn" << endl;
            if(party_member_one_health != 0){
              playerCombat(1, party_member_one_index);
              printBattleStats();
            }
            dead_monsters = monstersSlain();
            alive = partyActive();
            if(quitter != true && party_member_two_health != 0 && dead_monsters == false){
              playerCombat(2, party_member_two_index);
              printBattleStats();
            }
            dead_monsters = monstersSlain();
            alive = partyActive();
            if(quitter != true && party_member_three_health != 0 && dead_monsters == false){
              playerCombat(3, party_member_three_index);
              printBattleStats();
            }
            dead_monsters = monstersSlain();
            alive = partyActive();
            if(quitter != true && dead_monsters == false){
              cout << "The Monsters Turn" << endl;
              if(monster_one_index != -1 && monster_one_health != 0){
                dealDamage("monster", monster_one_index, 1, 0, 0);
              }
              if(monster_two_index != -1 && monster_two_health != 0){
                dealDamage("monster", monster_two_index, 2, 0, 0);
              }
              if(monster_three_index != -1 && monster_three_health != 0){
                dealDamage("monster", monster_three_index, 3, 0, 0);
              }
            }
            dead_monsters = monstersSlain();
            alive = partyActive();
            printBattleStats();
          }
      }
      i++;
      enemyCounter = 0;
    }
};
//
int main(){
    //read in monster and hero database
    game rungame;
    rungame.readDatabase("monster_database.txt");
    rungame.readDatabase("hero_database.txt");
    //print the "battlefield"
    rungame.heroSelection();
    rungame.battle();
};
