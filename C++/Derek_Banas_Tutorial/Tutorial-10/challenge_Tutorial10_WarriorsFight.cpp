// ---------- PROBLEM : WARRIORS BATTLE TILL DEATH ----------
// EXAMPLE BELOW
/*
Thor attacks Hulk and deals 12 damage
Hulk is down to 28 health
Hulk attacks Thor and deals 3 damage
Thor is down to 37 health
Thor attacks Hulk and deals 14 damage
Hulk is down to 14 health
Hulk attacks Thor and deals 0 damage
Thor is down to 37 health
Thor attacks Hulk and deals 14 damage
Hulk is down to 0 health
Hulk has Died and Thor is Victorious
Game Over
*/

#include <iostream>
#include <ctime>
#include <string>


class Warrior {
private:
	unsigned attack; // Warrior attack stat
	unsigned defense; // Warrior defense stat

public:
	std::string name; // Warrior name
	unsigned health; // Warrior health stat

	// Default constructor
	Warrior();

	Warrior(std::string, unsigned, unsigned, unsigned);

	// Deconstructor
	~Warrior() 
	{ 
		std::cout << "Warrior object "
			<< this->name << " destroyed\n"; 
	}

	// Return attack amount for round
	unsigned Attack() 
	{
		return std::rand() % this->attack;
	}
	
	// Return defense amount for round
	unsigned Defend() {
		return std::rand() % this->defense;
	}
};

Warrior::Warrior()
{
	this->name = "";
	this->health = 0;
	this->attack = 0;
	this->defense = 0;
}

Warrior::Warrior(std::string name, unsigned health, unsigned attack, unsigned defense)
{
	this->name = name;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
}


class Battle : public Warrior {
public:
	// We pass warriors into the function by reference so we can
	// track continued damage to each

	// We continue to loop having each warrior take turns attacking
	// until a warriors health < 0

	static void StartFight(Warrior& warrior1, Warrior& warrior2) 
	{
		while (true)
		{
			if (Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0)
			{
				std::cout << "Game Over\n\n\n";
				break;
			}
			if (Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0)
			{
				std::cout << "Game Over\n\n\n";
				break;
			}
		}
	}

	static std::string GetAttackResult(Warrior& warriorA, Warrior& warriorB)
	{
		// Get random attack & defense amounts and calculate damage
		int warriorAAttackAmt = warriorA.Attack();
		int warriorBDefenseAmt = warriorB.Defend();
		int damageToWarriorB = 
			(warriorAAttackAmt - warriorBDefenseAmt) < 0 ?
			0 : warriorAAttackAmt - warriorBDefenseAmt;

		// Change health and output changes
		warriorB.health -= damageToWarriorB > warriorB.health ?
			warriorB.health : damageToWarriorB;
		std::cout << warriorA.name
			<< " attacks " << warriorB.name
			<< " and deals " << damageToWarriorB << " damage\n";
		std::cout << warriorB.name << " is down to "
			<< warriorB.health << " health\n";

		// Once health = 0 end game by passing back Game over
		if (warriorB.health == 0) 
		{
			std::cout << "\n\n" << warriorB.name << " has died and "
				<< warriorB.name << " is VICTORIOUS\n";
			return "Game Over";
		}
		else { return "Fight Again"; }
	}
};



int main() {
	// Create Warriors
	Warrior Hulk("Hulk", 200, 40, 35);
	Warrior Superman("Superman", 300, 50, 75);

	// Seed random number generator
	srand(time(NULL));

	// Create battle and have it run on its own until completion
	Battle::StartFight(Hulk, Superman);

	return 0;
}

// ---------- END PROBLEM : WARRIORS BATTLE TILL DEATH ----------