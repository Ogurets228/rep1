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

void ShowArray(int arr[], int size)
{
	cout << "arr's elements: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void FillArray(int arr[], int size, int max=10)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % max + 1;
	}
}

int main()
{
	int b[] = {3, 654, 543, 89};
	int* pArr = new int[3];
	pArr[0] = 90;
    pArr[1] = 95;
	pArr[2] = 100;
	ShowArray(pArr, 3);
	cout << "Changing size of arr...\n";
	
	//cout << "array first element's address: " << pArr << endl;
	//cout << "should be array first element's address: " << *&pArr << endl;
	int*& pRef = *&pArr;
	delete[] pArr;
	pRef = new int[5];
	FillArray(pArr, 5);
	ShowArray(pArr, 5);

	delete[] pArr;
	system("pause");
	return 0;
}