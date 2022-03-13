#include <iostream>
#include <string>


using namespace std;

template <typename T>
void ShowArray(T arr[], int size, string name="Array")
{
	cout << name << "'s elements: {";
	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i] << ".\n";
		}
	}
}

class Number
{
public:

	string num;

	Number(string num)
	{
		this->num = num;
	}

	Number operator+(Number num2_in)
	{
		char num1_str[255]{};
		int max;
		strlen(&this->num[0]) > 9 ? max = 9 : max = strlen(&this->num[0]);
		for (int i = 0; i < max; i++)
		{
			num1_str[i] = this->num[i];
		}

		char num2_str[255]{};
		strlen(&num2_in.num[0]) > 9 ? max = 9 : max = strlen(&num2_in.num[0]);
		for (int i = 0; i < max; i++)
		{
			num2_str[i] = num2_in.num[i];
		}

		double num1 = (double)stoi(num1_str);
		double num2 = (double)stoi(num2_str);
		double num3 = num2 + num1;
		cout << num1_str << endl;
		cout << num2_str << endl;
		cout << to_string(num1) << endl;
		cout << to_string(num2) << endl;
		cout << to_string(num3) << endl;

		char num3_str[255]{};
		sprintf_s(num3_str, "%f", num3);

		Number res = Number(num3_str);
		return res;
	}

};

int pow(int num, int where)
{
	int res = 1;
	for (int i = 0; i < where; i++)
	{
		res *= num;
	}

	return res;
}

int main(int argc, char *argv[])
{
	system("chcp 1251");

	Number num("2374893023495874832343454345434");
	Number num2("2345445456678765445689876545678");
	Number lol = num + num2;
	cout << lol.num << endl;

	cin.get();
	return 0;
}