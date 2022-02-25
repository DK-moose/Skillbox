#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

int main()
{
	string arg, val;
	vector<string> arguments;
	vector<string> values;
	while (true)
	{
		cout << "Input name argument: ";
		cin >> arg;
		if (arg == "post" || arg == "get")
			break;
		cout << "Input value of the argument \"" << arg << "\": ";
		cin >> val;
		arguments.push_back(arg);
		values.push_back(val);
	}
	cpr::Response r;
	if (arg == "get")
	{
		string request = "http://httpbin.org/get?";
		for (int i = 0; i < arguments.size(); i++)
			request += arguments[i] + '=' + values[i] + '&';
		request.pop_back();
		r = cpr::Get(cpr::Url(request));
	}
	else
	{
		initializer_list<cpr::Pair> bodyRequest;
		cpr::Payload _payload(bodyRequest);
		for (int i = 0; i < arguments.size(); i++)
		{
			_payload.Add(cpr::Pair(arguments[i], values[i]));
		}

		r = cpr::Post(cpr::Url("http://httpbin.org/post"), _payload);
	}
	cout << r.text << endl;
	return 0;
}
