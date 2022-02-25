#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header({ { "Accept", "text/html" } }));
	string text = r.text;
	text = text.substr(text.find("<h1>") + 4, text.find("</h1>") - text.find("<h1>") - 4);
	cout << text << endl;
	return 0;
}
