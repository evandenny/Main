#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <chrono>
#include <cstdio>
using namespace std;

string character = "Evan Denny";
int health = 10;

enum Player_modifier {
	NONE,
	SPEED,
	HEALTH,
	DAMAGE,
	RANGE,
	CRITICAL_CHANCE,
	ARMOR,
	EVASION,
	LUCK
};



enum weapon {
	RPG,
	Greatsword,
	Sniper_Rifle,
	Katana,
	Full_Auto_Shotgun,
	Machine_gun,
	Mace,
	Long_rifle,
	Mp5,
	Fire_axe,
	Tec_9,
	Semi_Auto_Shotgun,
	Baseball_bat,
	Machete,
	Pump_Shotgun,
	Glock_17,
	Long_Sword,
	Dagger,
	Revolver
};

class Player {
public:
	Player(string name, string role, int health, int pNumber, enum weapon main_weapon, enum weapon secondary_weapon, double id_code, string description, enum Player_modifier modifier, int modifier_value, double gold, int level, int xp) {
		this->name = name;
		this->role = role;
		this->health = health;
		this->pNumber = pNumber;
		this->main_weapon = main_weapon;
		this->secondary_weapon = secondary_weapon;
		this->id_code = id_code;
		this->description = description;
		this->modifier = modifier;
		this->modifier_value = modifier_value;
		this->gold = gold;
		this->level = level;
		this->xp = xp;
	};
	string getNameRole() {
		string *x;
		x = &name;
		cout << "Player name: " << *x << endl;
		x = &role;
		cout << "Player role: " << *x << endl;
		return name;
	}
	//getters
	string getName() {
		return name;
	}
	string getRole() {
		return role;
	}
	int getHealth() {
		return health;
	}
	int getpNumber() {
		return pNumber;
	}
	enum weapon getMainWeapon() {
		return main_weapon;
	}
	enum weapon getSecondaryWeapon() {
		return secondary_weapon;
	}
	double getIdCode() {
		return id_code;
	}
	string getDescription() {
		return description;
	}
	enum Player_modifier getModifier() {
		return modifier;
	}
	int getModifierValue() {
		return modifier_value;
	}
	double getGold() {
		return gold;
	}
	int getLevel() {
		return level;
	}
	int getXP() {
		return xp;
	}
	//setters
	void setName(string name) {
		this->name = name;
	}
	void setRole(string role) {
		this->role = role;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setpNumber(int pNumber) {
		this->pNumber = pNumber;
	}
	void setMainWeapon(enum weapon main_weapon) {
		this->main_weapon = main_weapon;
	}
	void setSecondaryWeapon(enum weapon secondary_weapon) {
		this->secondary_weapon = secondary_weapon;
	}
	void setDescription(string description) {
		this->description = description;
	}
	void setModifier(enum Player_modifier modifier) {
		this->modifier = modifier;
	}
	void setModifierValue(int modifier_value) {
		this->modifier_value = modifier_value;
	}
	void setGold(double gold) {
		this->gold = gold;
	}
	void setXP(int xp) {
		this->xp = xp;
	}
	void setLevel(int level) {
		this->level = level;
	}

	void print_player_modifier(Player_modifier modifier) {
	switch (modifier) {
	case SPEED:
		cout << "Speed";
		break;
	case HEALTH:
		cout << "Health";
		break;
	case DAMAGE:
		cout << "Damage";
		break;
	case RANGE:
		cout << "Range";
		break;
	case CRITICAL_CHANCE:
		cout << "Critical chance";
		break;
	case ARMOR:
		cout << "Armor";
		break;
	case EVASION:
		cout << "Evasion";
		break;
	case LUCK:
		cout << "Luck";
		break;
	default:
		cout << "None";
		break;
	}
}
	void print_player() {
		cout << "Player: " << getName() << endl;
		cout << "Role: " << getRole() << endl;
		cout << "Level: " << getLevel() << endl;
		cout << "-" << getDescription() << endl;
	}
	
	void takeDamage(int damage);
	void dealDamage(int damage);
	void heal(int health);
	void changeWeapon(enum weapon weapon);
	void swapWeapon();

	void goToSleep();
	void loot();
	void inventory();
	
	void levelUp();
	void gainXP(int xp);
	void gainLevel(int level);
	
	void activateModifier();
	
	void talk(string message);
	void yell(string message);
	void whisper(string message);

private:
	string name;
	string role;
	int level;
	int xp;
	bool isSleeping;
	int energy;
	int pNumber;
	int health;
	enum weapon main_weapon;
	enum weapon secondary_weapon;
	double id_code;
	string description;
	enum Player_modifier modifier;
	int modifier_value;
	double gold;
};

int main() {
	Player Evan("Evan", "Warrior", 100, 1, Greatsword, Long_Sword, 1.0, "A strong and powerful warrior from a place only he knows.", SPEED, 10, 100, 1, 0);
	Evan.print_player();
}
