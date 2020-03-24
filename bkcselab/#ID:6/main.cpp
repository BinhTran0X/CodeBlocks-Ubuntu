#include <iostream>

using namespace std;

int main()
{
    float temperature;
	int option, isRound;
	cin >> temperature;
	cin >> option;
	cin >> isRound;

	if (option == 1) temperature = (temperature - 32)*5/9;
	else if (option == 2) temperature = temperature*1.8 + 32;

	if (isRound == 1) temperature = round(temperature*100)/100;

	cout << temperature;
	return 0;
}
