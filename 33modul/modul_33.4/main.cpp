#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;
enum vectorType {_int = 1, _ulong, _llong, _ullong, _float, _double };

template<typename T>
T GetSumVector(vector<T>* vec)
{
	T sum = 0;
	for (int i = 0; i < vec->size(); i++)
		sum += vec->at(i);
	return sum;
}

template<typename T>
double GetArithmeticMean(vector<T>* vec)
{
	T sum = GetSumVector<T>(vec);
	return (double)sum / vec->size();
}

int InputSizeOfVector()
{
	string str_size;
	int _size;
	try
	{
		cout << "Input size of vector: ";
		cin >> str_size;
		_size = stoi(str_size);
		if (_size <= 0)
			throw underflow_error("Size must be > 0!");
	}
	catch (invalid_argument err)
	{
		cout << "Invalid argument: " <<  err.what() << endl;
		return 0;
	}
	catch (underflow_error err)
	{
		cout << "Underflow error: " << err.what() << endl;
		return 0;
	}
	return _size;
}

template<typename T>
bool InputElement(T* el, int index)
{
	string str_el, type_el;
	cout << "Input vec[" << index << "]: ";
	cin >> str_el;
	type_el = typeid(*el).name();
	try
	{
		if (type_el == "int")
			*el = stoi(str_el);
		else if (type_el == "unsigned long")
			*el = stoul(str_el);
		else if (type_el == "__int64")
			*el = stoll(str_el);
		else if (type_el == "unsigned __int64")
			*el = stoull(str_el);
		else if (type_el == "float")
			*el = stof(str_el);
		else if (type_el == "double")
			*el = stod(str_el);
		else
			throw invalid_argument("invalid type of input!");
	}
	catch (invalid_argument err) 
	{
		cout << "Invalid argument: " << err.what() << endl;
		return false;
	}
	catch (out_of_range err) 
	{
		cout << "Out of range: " << err.what();
		return false;
	}
	return true;
}

template<typename T>
void CreateVector(vector<T>* vec)
{
	if (vec->size() > 0)
		vec->clear();
	
	int _size = 0;
	while (_size == 0)
		_size = InputSizeOfVector();
	
	for (int i = 0; i < _size; i++)
	{
		T tmp;
		while (!InputElement<T>(&tmp, i))
			continue;
		vec->push_back(tmp);
	}
}

template<typename T>
void PrintVector(vector<T>* vec)
{
	for (int i = 0; i < vec->size(); i++)
		cout << vec->at(i) << " ";
}

int SelectVectorType()
{
	string str_type;
	int ind_type;
	cout << "Select type of vector:" << endl;
	cout << "\t1. int" << endl;
	cout << "\t2. unsigned long" << endl;
	cout << "\t3. long long" << endl;
	cout << "\t4. unsigned long long" << endl;
	cout << "\t5. float" << endl;
	cout << "\t6. double" << endl;
	try
	{
		cout << "Input: ";
		cin >> str_type;
		ind_type = stoi(str_type);
		if (ind_type < 1 || ind_type > 6)
			throw out_of_range("Input must be from 1 to 6!");
	}
	catch (invalid_argument err)
	{
		cout << "Invalid argument: " << err.what() << endl;
		return 0;
	}
	catch (out_of_range err)
	{
		cout << "Out of range: " << err.what() << endl;
		return 0;
	}
	return ind_type;
}

int main()
{
	int indexVectorType = 0;
	while (indexVectorType == 0)
		indexVectorType = SelectVectorType();
	switch (indexVectorType)
	{
	case _int:
	{
		vector<int> vec;
		CreateVector<int>(&vec);
		PrintVector<int>(&vec);
		cout << "Result: " << GetArithmeticMean<int>(&vec);
		break;
	}
	case _ulong:
	{
		vector<unsigned long> vec;
		CreateVector<unsigned long>(&vec);
		PrintVector<unsigned long>(&vec);
		cout << "Result: " << GetArithmeticMean<unsigned long>(&vec);
		break;
	}
	case _llong:
	{
		vector<long long> vec;
		CreateVector<long long>(&vec);
		PrintVector<long long>(&vec);
		cout << "Result: " << GetArithmeticMean<long long>(&vec);
		break;
	}
	case _ullong:
	{
		vector<unsigned long long> vec;
		CreateVector<unsigned long long>(&vec);
		PrintVector<unsigned long long>(&vec);
		cout << "Result: " << GetArithmeticMean<unsigned long long>(&vec);
		break;
	}
	case _float:
	{
		vector<float> vec;
		CreateVector<float>(&vec);
		PrintVector<float>(&vec);
		cout << "Result: " << GetArithmeticMean<float>(&vec);
		break;
	}
	case _double:
	{
		vector<double> vec;
		CreateVector<double>(&vec);
		PrintVector<double>(&vec);
		cout << "Result: " << GetArithmeticMean<double>(&vec);
		break;
	}
	}
	return 0;
}
