#include <iostream>

using namespace std;

string to_string(int n)
{
	char buf[40];
	sprintf_s(buf, "%d", n);
	return buf;
}

template <typename T>
void ShowArray(T arr[], int size)
{
	cout << "arr's elements: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void FillArray(int arr[], int size, int max = 10)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % max + 1;
	}
}
void FillArray(string arr[], int size, int max = 10)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = "Element " + to_string(i);
	}
}
void FillArray(char arr[], int size, int max = 10)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = 97 + i;
	}
	cout << endl;
}

void AddElement(string*& arr, int &size, string element)
{
	string* new_arr = new string[size+1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[size] = element;

	delete[] arr;
	arr = new_arr;
	size += 1;
}

int main()
{
	/*
	char arr[5];
	FillArray(arr, 5);
	cout << arr << endl;
	cout << arr[4] << endl;
	*/
	srand(time(0));
	char arr[] = { 'g', 'o', 'o', 'g', '\0' };
	cout << strlen(arr) << endl;

	system("pause");
	return 0;
}