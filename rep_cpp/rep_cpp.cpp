#include <iostream>
#include <string>

using namespace std;

void reMake(int* pInt)
{
    *pInt = 8888;
}

int main()
{
    int lol = 5;
    reMake(&lol);
    cout << lol;
    return 0;
}