#include "phone.h"

using namespace std;

int main()
{
	Phone* phone = new Phone();
	Record* rec_1 = new Record();
	Record* rec_2 = new Record();
	Record* rec_3 = new Record();
	rec_1->SetName("Mom");
	rec_1->SetNumber("+71234567890");
	rec_2->SetName("Dad");
	rec_2->SetNumber("+79876543210");
	rec_3->SetName("Friend");
	rec_3->SetNumber("+78912345678");
	map<string, string> contacts;
	pair<string, string> newRec1(rec_1->GetNumber(), rec_1->GetName());
	contacts.insert(newRec1);
	pair<string, string> newRec2(rec_2->GetNumber(), rec_2->GetName());
	contacts.insert(newRec2);
	pair<string, string> newRec3(rec_3->GetNumber(), rec_3->GetName());
	contacts.insert(newRec3);
	phone->SetDirectory(contacts);

	string command;
	while (true)
	{
		cout << "Please, input command (add, call, sms) or \"exit\": ";
		cin >> command;
		if (command == "add")
		{
			Record* newRecord = new Record();
			string number, name;
			do
			{
				cout << "Input number: ";
				cin >> number;
			} while (!Phone::IsNumber(number));
			cout << "Input name: ";
			cin >> name;
			newRecord->SetName(name);
			newRecord->SetNumber(number);
			phone->Add(*newRecord);
			delete newRecord;
		}
		else if (command == "call")
		{
			string str;
			cout << "Input number or name of contact: ";
			cin >> str;
			phone->Call(str);
		}
		else if (command == "sms")
		{
			string str;
			cout << "Input number or name of contact: ";
			cin >> str;
			phone->Sms(str);
		}
		else if (command == "exit")
			break;
		else cout << ERROR_INPUT << endl;
	}
	delete rec_1;
	delete rec_2;
	delete rec_3;
	delete phone;
	return 0;
}
