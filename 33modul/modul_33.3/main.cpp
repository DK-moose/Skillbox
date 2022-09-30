#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T1, typename T2>
class KeyVal
{
private:
	T1 key;
	T2 val;

public:
	KeyVal() {};
	
	KeyVal(T1 _key, T2 _val) : key(_key), val(_val) {};

	T1 GetKey()
	{
		return key;
	};

	void Print()
	{
		cout << "Key: " << key << ", Value: " << val << endl;
	};
};

template<typename TKey, typename TVal>
class Registry
{
private:
	vector<KeyVal<TKey, TVal>*> vec;

public:
	void Add(TKey key, TVal val)
	{
		vec.push_back(new KeyVal<TKey, TVal>(key, val));
	};

	void Remove(TKey key)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]->GetKey() == key)
				vec.erase(vec.begin() + i);
			i--;
		}
	};

	void Print()
	{
		for (int i = 0; i < vec.size(); i++)
			vec[i]->Print();
	};

	void Find(TKey key)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]->GetKey() == key)
				vec[i]->Print();
		}
	};
};

void PrintCommandsList()
{
	cout << "\t'add' - add an element with a key;" << endl;
	cout << "\t'remove' - remove all elements with the specified key;" << endl;
	cout << "\t'print' - print all the elements with their keys on the screen;" << endl;
	cout << "\t'find' - find all the elements by their key." << endl;
}

void CheckCommand(string str)
{
	if (str != "add" && str != "remove" && str != "print" && str != "find" && str != "exit")
		throw invalid_argument("Invalid input command!");
}

string SelectDataType(string var)
{
	string dataType;
	cout << "Input data type for " + var + " (int, duoble, string): ";
	cin >> dataType;
	if (dataType != "int" && dataType != "double" && dataType != "string")
		throw invalid_argument("Invalid data type! Try again");
	return dataType;
}

string InputVar(string type_var, int* var_i, double* var_d, string* var_s)
{
	string data_type;
	try
	{
		data_type = SelectDataType(type_var);
	}
	catch (invalid_argument err)
	{
		cout << err.what() << endl;
		return "";
	}

	string val;
	try
	{
		cout << "Input " + type_var + ": ";
		cin.ignore(100000, '\n');
		getline(cin, val);
		if (data_type == "int")
			*var_i = stoi(val);
		else if (data_type == "double")
			*var_d = stod(val);
		else
			*var_s = val;
		return data_type;
	}
	catch (invalid_argument err)
	{
		cout << err.what() << ". Try again" << endl;
		return "";
	}
}


int main()
{
	string command;
	string dtKey, dtVal;
	int key_i, val_i;
	double key_d, val_d;
	string key_s, val_s;

	Registry<int, int> reg_ii;
	Registry<int, double> reg_id;
	Registry<int, string> reg_is;
	Registry<double, int> reg_di;
	Registry<double, double> reg_dd;
	Registry<double, string> reg_ds;
	Registry<string, int> reg_si;
	Registry<string, double> reg_sd;
	Registry<string, string> reg_ss;

	cout << "Enter one of the command or 'exit':" << endl;
	PrintCommandsList();
	while (true)
	{
		try
		{
			cout << endl << "Input: ";
			cin >> command;
			CheckCommand(command);
		}
		catch (invalid_argument err)
		{
			cout << err.what() << endl;
			continue;
		}

		if (command == "add")
		{
			while (true)
			{
				dtKey = InputVar("KEY", &key_i, &key_d, &key_s);
				if (dtKey != "")
					break;
			}
			while (true)
			{
				dtVal = InputVar("VALUE", &val_i, &val_d, &val_s);
				if (dtVal != "")
					break;
			}
			
			if (dtKey == "int")
			{
				if (dtVal == "int")
					reg_ii.Add(key_i, val_i);
				else if (dtVal == "double")
					reg_id.Add(key_i, val_d);
				else 
					reg_is.Add(key_i, val_s);
			}
			else if (dtKey == "double")
			{
				if (dtVal == "int")
					reg_di.Add(key_d, val_i);
				else if (dtVal == "double")
					reg_dd.Add(key_d, val_d);
				else
					reg_ds.Add(key_d, val_s);
			}
			else 
			{
				if (dtVal == "int")
					reg_si.Add(key_s, val_i);
				else if (dtVal == "double")
					reg_sd.Add(key_s, val_d);
				else
					reg_ss.Add(key_s, val_s);
			}
		}
		else if (command == "remove")
		{
			while (true)
			{
				dtKey = InputVar("KEY", &key_i, &key_d, &key_s);
				if (dtKey != "")
					break;
			}

			if (dtKey == "int")
			{
				reg_ii.Remove(key_i);
				reg_id.Remove(key_i);
				reg_is.Remove(key_i);
			}
			else if (dtKey == "double")
			{
				reg_di.Remove(key_d);
				reg_dd.Remove(key_d);
				reg_ds.Remove(key_d);
			}
			else
			{
				reg_si.Remove(key_s);
				reg_sd.Remove(key_s);
				reg_ss.Remove(key_s);
			}
		}
		else if (command == "print")
		{
			reg_ii.Print();
			reg_id.Print();
			reg_is.Print();
			reg_di.Print();
			reg_dd.Print();
			reg_ds.Print();
			reg_si.Print();
			reg_sd.Print();
			reg_ss.Print();
		}
		else if (command == "find")
		{
			while (true)
			{
				dtKey = InputVar("KEY", &key_i, &key_d, &key_s);
				if (dtKey != "")
					break;
			}

			if (dtKey == "int")
			{
				reg_ii.Find(key_i);
				reg_id.Find(key_i);
				reg_is.Find(key_i);
			}
			else if (dtKey == "double")
			{
				reg_di.Find(key_d);
				reg_dd.Find(key_d);
				reg_ds.Find(key_d);
			}
			else
			{
				reg_si.Find(key_s);
				reg_sd.Find(key_s);
				reg_ss.Find(key_s);
			}
		}
		else break;
	}
	return 0;
}