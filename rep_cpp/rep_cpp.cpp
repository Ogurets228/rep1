#include <iostream>

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
	int size = 2;
	int* pInt = new int[size];
	*pInt = 0;
	*(pInt + 1) = 1;
	Insert(pInt, 5, size, &size);
	for (int i = 0; i < size; i++)
	{
		cout << pInt[i] << endl;
	}
	
	delete[] pInt;

	system("pause");
	return 0;
}