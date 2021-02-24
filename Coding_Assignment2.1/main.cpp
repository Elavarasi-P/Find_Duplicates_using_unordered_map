#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string find_duplicates(int size,int array[]) 
{
	unordered_map<int, int> occurrence;
	string result = "";
	for (int i = 0; i < size; i++)
		occurrence[array[i]]++;
	bool duplicate = false;
	unordered_map<int, int>::iterator itr;
	for (itr = occurrence.begin(); itr != occurrence.end(); itr++) {
		if (itr->second > 1) {
			duplicate = true;
			result += to_string(itr->first)+":"+to_string(itr->second)+"\n";
		}
	}
	if (duplicate == false)
		return "";
	return result;
}

string TestallPositive()
{
	int array[] = { 3,2,7,8,2,3,1,6,8 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "\nArrray:";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
	string result = find_duplicates(size, array);
	return result;
}

string TestallNegative()
{
	int array[] = { -5,-3,-2,-9,-5 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "\nArrray:";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	string result = find_duplicates(size, array);
	return result;
}

string TestMixed()
{
	int array[] = { -9,8,-7,-5,-7,2,3,1,6,8 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "\nArrray:";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	string result = find_duplicates(size, array);
	return result;
}

string TestZeroCase()
{
	int array[] = { -9,0,8,0,0,0,3,1,0,-9 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "\nArrray:";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	string result = find_duplicates(size, array);
	return result;
}

string TestSameNum()
{
	int array[] = { 5,5,5,5,5,5,5 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "\nArrray:";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	string result = find_duplicates(size, array);
	return result;
}

string TestDynamicIp()
{
	int size = 0;
	cout << "\nEnter the size for dynamic array:";
	cin >> size;
	int* array{ new int[size] {} };
	cout << "\nEnter the elements of the dynamic array:";
	for (int i = 0; i < size; i++)
		cin >> array[i];
	cout << "\nArrray:";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	string result = find_duplicates(size, array);
	return result;
}

int main()
{
	string results[6]{};
	cout << "\n--------------------INPUT TEST CASES-------------------\n";
	results[0] = TestallPositive();
	results[1] = TestallNegative();
	results[2] = TestMixed();
	results[3] = TestZeroCase();
	results[4] = TestSameNum();
	results[5] = TestDynamicIp();
	cout << "\n----------------------RESULTS---------------------\n";
	string display[6] = { "all positive numbers","all negative numbers", "mixed numbers",
		"multiple zeros", "all same numbers", "dynamic input array" };
	for (int i = 0; i < 6; i++)
	{
		if (results[i] != "")
			cout << "Repeating elements in the array for the case of " << display[i] << ":\n" << "Number:Frequency\n"<<results[i] << endl;
		else
			cout << "No repeating elements" << "in case of " << display[i] << "\n";
	}
	return 0;
}
