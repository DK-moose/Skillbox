#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <Windows.h>
#include <algorithm>

#define DIR_FILMS "films"
#define DB_FILMS "dbFilms"

using namespace std;

struct RoleAndActor
{
	string role;
	string actor;
};

struct Film
{
	string name;							//название фильма
	vector<string> countries;				//страны
	string dateOfCreation;					//дата создания
	vector<string> studios;					//студии
	vector<string> screenwriters;			//авторы сценария
	vector<string> directors;				//режиссёры
	vector<string> producers;				//продюссеры
	vector<RoleAndActor*> mainPersons;		//главные действующие лица и актёры
};

void StringToVector(string str, vector<string>* vec)
{
	int start = 0, len = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (i == str.size() - 1 || str[i + 1] == ',')
		{
			len = i - start + 1;
			vec->push_back(str.substr(start, len));
			start = i + 3;
		}
	}
}

void CreateFilm() // создать JSON с информацией о  фильме с кинопортала (modul_32.1)
{
	Film film;
	cout << "Write down information about the movie:" << endl;
	cout << "\tName -> ";
	getline(cin, film.name);

	cout << "\tCountries -> ";
	string _countries;
	getline(cin, _countries);
	StringToVector(_countries, &film.countries);

	cout << "\tDate of creation -> ";
	getline(cin, film.dateOfCreation);

	cout << "\tStudios -> ";
	string _studios;
	getline(cin, _studios);
	StringToVector(_studios, &film.studios);

	cout << "\tScreenwriters -> ";
	string _screenwriters;
	getline(cin, _screenwriters);
	StringToVector(_screenwriters, &film.screenwriters);

	cout << "\tDirectors -> ";
	string _directors;
	getline(cin, _directors);
	StringToVector(_directors, &film.directors);

	cout << "\tProducers -> ";
	string _producers;
	getline(cin, _producers);
	StringToVector(_producers, &film.producers);

	while (true)
	{
		RoleAndActor* ar = new RoleAndActor;
		cout << "\tRole -> ";
		getline(cin, ar->role);
		if (ar->role == "")
		{
			delete ar;
			break;
		}
		cout << "\tActor -> ";
		getline(cin, ar->actor);;
		film.mainPersons.push_back(ar);
	}

	ofstream file(DIR_FILMS "/" + film.name + ".json");
	nlohmann::json obj;

	for (int i = 0; i < film.countries.size(); i++)
		obj["countries"][i] = film.countries[i];

	obj["dateOfCreation"] = film.dateOfCreation;

	for (int i = 0; i < film.studios.size(); i++)
		obj["studios"][i] = film.studios[i];

	for (int i = 0; i < film.screenwriters.size(); i++)
		obj["screenwriters"][i] = film.screenwriters[i];

	for (int i = 0; i < film.directors.size(); i++)
		obj["directors"][i] = film.directors[i];

	for (int i = 0; i < film.producers.size(); i++)
		obj["producers"][i] = film.producers[i];

	for (int i = 0; i < film.mainPersons.size(); i++)
	{
		obj["mainPerson"][i]["actor"] = film.mainPersons[i]->actor;
		obj["mainPerson"][i]["role"] = film.mainPersons[i]->role;
	}

	file << obj;
	file.close();
}

void GetFileNames(vector<string>* fileNames) // получить список JSON файлов каталога films
{
	if (fileNames->size() > 0)
		fileNames->clear();
	WIN32_FIND_DATAW wfd;
	HANDLE const hFind = FindFirstFileW(L"" DIR_FILMS "\\*", &wfd);
	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			wstring wstr = &wfd.cFileName[0];
			string str(wstr.begin(), wstr.end());
			if (str.size() <= 5)
				continue;
			for (int i = 0; i < str.size(); i++)
				if (str[i] == '.' && str.substr(i + 1) == "json")
					fileNames->push_back(str.substr(0, str.size() - 5));
		} while (NULL != FindNextFileW(hFind, &wfd));
		FindClose(hFind);
	}
}

void CreateFilmsDictionary(vector<string>* fileNames) // создать JSON-словарь (modul_32.2)
{
	ofstream dbFilms(DB_FILMS ".json");
	nlohmann::json dbObj;
	
	for (int i = 0; i < fileNames->size(); i++)
	{
		ifstream film(DIR_FILMS "/" + fileNames->at(i) + ".json");
		if (film.is_open())
		{
			nlohmann::json objFilm;
			film >> objFilm;
			dbObj[fileNames->at(i)] = objFilm;
			film.close();
		}
	}

	dbFilms << dbObj;
	dbFilms.close();
}

void SearchByActor(vector<string>* fileNames)
{
	string str;
	cout << "Input actor's Name or Surname: ";
	cin >> str;

	ifstream dbFilms(DB_FILMS ".json");
	if (dbFilms.is_open())
	{
		nlohmann::json dbObj;
		nlohmann::json actors;
		vector<string> actorsKeys;
		dbFilms >> dbObj;

		for (int i = 0; i < fileNames->size(); i++)
		{
			for (int j = 0; j < dbObj[fileNames->at(i)]["mainPerson"].size(); j++)
			{
				string _actor = dbObj[fileNames->at(i)]["mainPerson"][j]["actor"];
				int index = _actor.find(" ");
				string name;
				string surname;
				if (index == -1)
				{
					name = _actor;
					surname = "";
				}
				else
				{
					name = _actor.substr(0, index);
					surname = _actor.substr(name.size() + 1);
				}

				if (str == name || str == surname)
				{
					nlohmann::json raf;	
					raf["role"] = dbObj[fileNames->at(i)]["mainPerson"][j]["role"];
					raf["film"] = fileNames->at(i);
					actors[_actor].push_back(raf);
					
					bool flAddKey = 1;
					for (int k = 0; k < actorsKeys.size(); k++)
						if (actorsKeys[k] == _actor)
						{
							flAddKey = 0;
							break;
						}
					if (flAddKey)
						actorsKeys.push_back(_actor);
				}
			}
		}

		cout << "Result of searching:" << endl;
		for (int i = 0; i < actors.size(); i++)
		{
			cout << actorsKeys[i] << endl;
			for (int j = 0; j < actors[actorsKeys[i]].size(); j++)
			{
				cout << "Film - " << actors[actorsKeys[i]][j]["film"] << ", role - " << actors[actorsKeys[i]][j]["role"] << endl;
			}
			cout << endl;
		}
		dbFilms.close();
	}
}

int main()
{
	vector<string> films;
	GetFileNames(&films);
	CreateFilmsDictionary(&films);

	int action = 0;
	while (action != 3)
	{
		cout << "\t1. ADD or UPDATE film to the database" << endl;
		cout << "\t2. Search for information by actor's NAME or SURNAME" << endl;
		cout << "\t3. Exit" << endl;
		cout << "Select an action: ";
		cin >> action;
		cout << endl;
		cin.seekg(cin.eof());

		switch (action)
		{
			case 1:
			{
				CreateFilm();
				GetFileNames(&films);
				CreateFilmsDictionary(&films);
				break;
			}
			case 2:
			{
				SearchByActor(&films);
				break;
			}
			case 3:
				break;
			default:
			{
				cout << "Error: input '1', '2', or '3'" << endl;
				break;
			}
		}
	}
	return 0;
}
