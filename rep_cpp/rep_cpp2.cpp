#include <iostream>
#include <locale.h>

using namespace std;

string to_string(int n)
{
	char buf[40];
	sprintf_s(buf, "%d", n);
	return buf;
}

void Insert(int*& arr, int element, int index, int *size)
{
	int* new_arr = new int[*size + 1];
	for (int i = 0; i < index; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[index] = element;
	for (int i = index+1; i < *size + 1; i++)
	{
		new_arr[i] = arr[i - 1];
	}
	delete[] arr;
	arr = new_arr;
	*size += 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool a = true;
	for (int i = 0; i < 256; i++)
	{
		cout << i << " - " << (char)i << endl;
	}
	cout << "Рус\n";

	system("pause");
	return 0;
}