#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <memory>
#include <filesystem>

using namespace std;

auto myVector = [](vector<int>* vec)
{
	unordered_set<int> us_vec;
	for (auto el : *vec)
		us_vec.insert(el);
	vec->clear();
	for (auto el : us_vec)
		vec->push_back(el);
	return make_unique<vector<int>>(*vec);
};

auto recursiveGetFileNameByExtension = [](filesystem::path path, const string extension)
{
	vector<string>* vec = new vector<string>();
	for (auto& p : filesystem::recursive_directory_iterator(path))
	{
		if (p.is_regular_file() && p.path().extension().compare(extension) == 0)
			vec->push_back(p.path().filename().string());
	}
	return vec;
};

int main()
{
	cout << "Task 1" << endl;
	initializer_list<int> arr = { 1, 2, 3, 4, 5 };
	for (auto val : arr)
		cout << val << " ";
	cout << "\n\n";

	cout << "Task 2" << endl;
	vector<int> vec = { 1,1,2,4,5,4,5,3,6 };
	cout << "Input: ";
	for (auto el : vec)
		cout << el << " ";
	cout << endl;
	cout << "Result: ";
	unique_ptr<vector<int>> result = myVector(&vec);
	for (auto el : *result)
		cout << el << " ";
	cout << "\n\n";

	cout << "Task 3" << endl;
	vector<string> files = *recursiveGetFileNameByExtension("test", ".txt");
	for (auto path : files)
		cout << path << endl;
	return 0;
}
