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

template <typename T>
void ShowArray(T *arr, int size, string name="")
{
	cout << "Ёлементы массива " << name << ": ";
	for (int i = 0; i < size; i++)
	{
		if (size - i != 1)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i] << endl;
		}
	}

}
void FillArray(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			arr[i] = 65 + rand() % 26;
			continue;
		}
		if (size - i != 1)
		{
			arr[i] = 97 + rand() % 26;
		}
		else
		{
			arr[i] = '\0';
		}
	}
}

void FillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

int main()
{
	system("chcp 1251");
	srand(time(0));

	const int rows = 3;
	int cols = 7;
	const char* arr[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = "Pooooo";
		cout << arr[i] << endl;
	}

	cin.get();
	return 0;
}