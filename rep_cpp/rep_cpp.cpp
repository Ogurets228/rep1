#include <iostream>

using namespace std;

void Foo(int* a, int *size)
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
	for (int i = 0; i<*size+1; i++)
	{
		arr[i] = newArr[i];
	}
	*size += 1;

	return arr;
}

int main()
{
	int *size = new int;
	*size = 5;
	int* pArr = new int[*size];
	pArr[0] = 12;
	pArr[1] = 15642;
	pArr[2] = 3412;
	pArr[3] = 152;
	pArr[4] = 125;

	pArr = addElement(pArr, size, 111);

	for (int i = 0; i < *size; i++)
	{
		cout << *(pArr + i) << endl;
	}
	delete[] pArr;

	system("pause");
	return 0;
}