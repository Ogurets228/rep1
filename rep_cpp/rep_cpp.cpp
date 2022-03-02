#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string hopa[7] = { "Gay string: ", "Oh no! It's ", "Let's read: ", "Prankkkkkkkkk ", "Poopa ", "jdfhjsdcvf", "Reshka " };

    int size;
    cin >> size;
    string *arr = new string[size];

    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = hopa[rand()%7] + to_string(rand() % 10 + 1);
        cout << "Element " << i << ":" << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}
