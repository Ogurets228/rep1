/*#include <iostream>

using namespace std;

void Foo(int* a, int* size)
{
	*size = 10;

	delete[] a;
	a = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		a[i] = i * i;
	}
}

int* addElement(int* arr, int* size, int element)
{
	int* newArr = new int[*size + 1];
	for (int i = 0; i < *size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[*size] = element;
	delete[] arr;
	arr = new int[*size + 1];
	for (int i = 0; i < *size + 1; i++)
	{
		arr[i] = newArr[i];
	}
	*size += 1;

	return arr;
}

void ShowArray(int arr[], int size)
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

int main()
{
	int* arr = new int[3];
	*arr = 1;
	*(arr + 1) = 2;
	*(arr + 2) = 3;
	ShowArray(arr, 3);

	int*& h = arr;
	cout << "h = " << h << endl;
	cout << "&h = " << &h << endl;
	cout << "&arr = " << &arr << endl;
	cout << "arr = " << arr << endl;


	delete[] arr;

	system("pause");
	return 0;
}
*/

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
	int size = 3;
	string* p = new string[size];
	FillArray(p, size);
	ShowArray(p, size);

	cout << "Adding 1 element...\n";
	AddElement(p, size, "noooo");
	ShowArray(p, size);

	delete[] p;

	system("pause");
	return 0;
}