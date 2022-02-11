#include "test.h"
#include <cpr/cpr.h>

using namespace std;

int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
	cout << r.text << endl;
	return 0;
}
