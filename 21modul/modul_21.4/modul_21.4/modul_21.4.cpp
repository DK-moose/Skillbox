#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <conio.h>
#define SIZE_AREA 40

using namespace std;
enum orientation { l = 1, r, t, b };
struct Point
{
	int x;
	int y;
};

struct Character
{
	string name;
	int health;
	int armor;
	int damage;
	int step;
	char sign;
	Point position;
};

void DoStep(Character &character, char **area)
{
	if (character.step == l && character.position.x > 0)
	{
		area[character.position.x][character.position.y] = '.';
		character.position.x--;
		area[character.position.x][character.position.y] = character.sign;
	}
	else if (character.step == r && character.position.x < SIZE_AREA - 1)
	{
		area[character.position.x][character.position.y] = '.';
		character.position.x++;
		area[character.position.x][character.position.y] = character.sign;
	}
	else if (character.step == t && character.position.y > 0)
	{
		area[character.position.x][character.position.y] = '.';
		character.position.y--;
		area[character.position.x][character.position.y] = character.sign;
	}
	else if (character.step == b && character.position.y < SIZE_AREA - 1)
	{
		area[character.position.x][character.position.y] = '.';
		character.position.y++;
		area[character.position.x][character.position.y] = character.sign;
	}
}

bool EnemiesLives(vector<Character> &enemies)
{
	for (int i = 0; i < enemies.size(); i++)
		if (enemies[i].health > 0)
			return true;
	return false;
}

void TakeDamage(Character &character, int damage)
{
	character.armor -= damage;
	if (character.armor < 0)
	{
		character.health += character.armor;
		character.armor = 0;
	}
}

void PrintCharacter(Character &character)
{
	if (character.health <= 0) cout << character.name << " : DEAD!" << endl;
	else cout << character.name << " : " << character.armor << " A, " << character.health << " H, (" << character.damage << " D)" << endl;
}

void InitArea(char **area)
{
	for (int i = 0; i < SIZE_AREA; i++)
		for (int j = 0; j < SIZE_AREA; j++)
			area[i][j] = '.';
}

void ReadCharacter(Character &character, ifstream &file)
{
	int len;
	file.read((char*)&len, sizeof(len));
	file.read((char*)character.name.c_str(), len);
	file.read((char*)&character.health, sizeof(character.health));
	file.read((char*)&character.armor, sizeof(character.armor));
	file.read((char*)&character.damage, sizeof(character.damage));
	file.read((char*)&character.step, sizeof(character.step));
	file.read((char*)&character.sign, sizeof(character.sign));
	file.read((char*)&character.position.x, sizeof(character.position.x));
	file.read((char*)&character.position.y, sizeof(character.position.y));
}

void WriteCharacter(Character &character, ofstream &file)
{
	int len = character.name.length() + 1;
	file.write((char*)&len, sizeof(len));
	file.write((char*)character.name.c_str(), len);
	file.write((char*)&character.health, sizeof(character.health));
	file.write((char*)&character.armor, sizeof(character.armor));
	file.write((char*)&character.damage, sizeof(character.damage));
	file.write((char*)&character.step, sizeof(character.step));
	file.write((char*)&character.sign, sizeof(character.sign));
	file.write((char*)&character.position.x, sizeof(character.position.x));
	file.write((char*)&character.position.y, sizeof(character.position.y));
}

void LoadFromFile(Character &player, vector<Character> &enemies, char ** area)
{
	ifstream file("saving.bin", ios::binary);
	if (file.is_open())
	{
		InitArea(area);
		ReadCharacter(player, file);
		area[player.position.x][player.position.y] = 'P';
		for (int i = 0; i < enemies.size(); i++)
		{
			ReadCharacter(enemies[i], file);
			area[enemies[i].position.x][enemies[i].position.y] = 'E';
		}
	}
}

void SaveToFile(Character &player, vector<Character> &enemies)
{
	ofstream file("saving.bin", ios::binary);
	if (file.is_open())
	{
		WriteCharacter(player, file);
		for (int i = 0; i < enemies.size(); i++)
			WriteCharacter(enemies[i], file);
	}
}

int main()
{
	srand(time(NULL));
	string command;
	bool winner;
	char **gameArea = new char *[SIZE_AREA];
	for (int i = 0; i < SIZE_AREA; i++)
	{
		gameArea[i] = new char[SIZE_AREA];
	}

	InitArea(gameArea);

	// Initial player
	Character player;
	cout << "Please, enter name of your character: ";
	cin >> player.name;
	while (true)
	{
		cout << "Pease, enter number of lives: ";
		cin >> player.health;
		if (player.health < 50 || player.health > 150)
			cout << "Error: number of lives should be from 50 to 150!" << endl;
		else break;
	}
	while (true)
	{
		cout << "Please, enter armor: ";
		cin >> player.armor;
		if (player.armor < 0 || player.armor > 50)
			cout << "Error: armor should be from 0 to 50!" << endl;
		else break;
	}
	while (true)
	{
		cout << "Please, enter damage: ";
		cin >> player.damage;
		if (player.damage < 15 || player.damage > 30)
			cout << "Error: damage should be from 15 to 30!" << endl;
		else break;
	}
	player.position.x = rand() % SIZE_AREA;
	player.position.y = rand() % SIZE_AREA;
	player.sign = 'P';
	gameArea[player.position.x][player.position.y] = player.sign;


	// Initial enemies
	vector<Character> enemies;
	for (int i = 0; i < 5; i++)
	{
		Character enemy;
		enemy.position.x = rand() % SIZE_AREA;
		enemy.position.y = rand() % SIZE_AREA;
		if (gameArea[enemy.position.x][enemy.position.y] != '.')
		{
			i--;
			continue;
		}

		enemy.name = "Enemy #" + to_string(i);
		enemy.health = rand() % 100 + 51;
		enemy.armor = rand() % 50 + 1;
		enemy.damage = rand() % 15 + 16;
		enemy.sign = 'E';
		enemies.push_back(enemy);
		gameArea[enemy.position.x][enemy.position.y] = enemy.sign;
	}
	system("cls"); //'clear' for linux

	while (true)
	{
		command = "";
		for (int i = 0; i < SIZE_AREA; i++)
		{
			for (int j = 0; j < SIZE_AREA; j++)
				cout << gameArea[j][i] << ' ';
			cout << endl;
		}
		cout << endl;
		PrintCharacter(player);
		for (int i = 0; i < enemies.size(); i++)
		{
			PrintCharacter(enemies[i]);
		}

		while (command == "")
		{
			cout << "Please, enter your step (left, right, top, bottom): ";
			cin >> command;
			if (command == "left")
				player.step = l;
			else if (command == "right")
				player.step = r;
			else if (command == "top")
				player.step = t;
			else if (command == "bottom")
				player.step = b;
			else if (command == "load")
				LoadFromFile(player, enemies, gameArea);
			else if (command == "save")
				SaveToFile(player, enemies);
			else
			{
				command = "";
				cout << "Error: Invalid command! Try again." << endl;
			}
		}
		if (command == "load" || command == "save")
		{
			system("cls");
			continue;
		}

		DoStep(player, gameArea);
		for (int i = 0; i < enemies.size(); i++)
		{
			if (player.position.x == enemies[i].position.x &&
				player.position.y == enemies[i].position.y)
			{
				TakeDamage(enemies[i], player.damage);
			}
		}
		if (!EnemiesLives(enemies))
		{
			winner = true;
			break;
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].health > 0)
			{
				enemies[i].step = rand() % 4 + 1;
				DoStep(enemies[i], gameArea);
				if (player.position.x == enemies[i].position.x &&
					player.position.y == enemies[i].position.y)
				{
					TakeDamage(player, enemies[i].damage);
				}
			}
		}
		if (player.health < 0)
		{
			winner = false;
			break;
		}
		system("cls"); //'clear' for linux
	}

	if (winner) cout << "You won!" << endl;
	else cout << "You lose!" << endl;
	return 0;
}