#include "phone.h"

using namespace std;

int main()
{
	Phone* phone = new Phone();
	phone->Add(new Record("+71234567890", "Mom"));
	phone->Add(new Record("+79876543210", "Dad"));
	phone->Add(new Record("+78912345678", "Friend"));

	string command;
	while (true)
	{
		cout << "Please, input command (add, call, sms) or \"exit\": ";
		cin >> command;
		if (command == "add")
		{
			string number, name;
			do
			{
				cout << "Input number: ";
				cin >> number;
			} while (!Phone::IsNumber(number));
			cout << "Input name: ";
			cin >> name;
			phone->Add(new Record(number, name));
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
	phone->RemoveDir();
	delete phone;
	return 0;
}
