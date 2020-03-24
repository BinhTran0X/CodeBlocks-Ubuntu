#include <iostream>
using namespace std;

int main() {
	int taxableIncomes, numberOfDependants;
	int taxedIncomes;
	cin >> taxableIncomes;
	cin >> numberOfDependants;
	taxedIncomes = taxableIncomes - 9000000 - 3600000*numberOfDependants;

	int fax = 0;
	int calc = taxedIncomes;
	if (taxedIncomes <= 0) fax = 0;
	else if (taxedIncomes <= 5000000) fax = calc/20;
	else {
	    fax += 250000;
	    calc -= 5000000;
	    if (taxedIncomes <= 10000000) fax += calc/10;
	    else {
	        fax += 500000;
	        calc -= 5000000;
	        if (taxedIncomes <= 18000000) fax += calc*3/20;
	        else {
	            calc -= 8000000;
	            fax += 1200000;
	            if (taxedIncomes <= 32000000) fax += calc/5;
	            else {
	                calc -= 14000000;
	                fax += 2800000;
	                if (taxedIncomes <= 52000000) fax += calc/4;
	                else {
	                    calc -= 20000000;
	                    fax += 5000000;
	                    if (taxedIncomes <= 80000000) fax += calc*3/10;
	                    else {
	                        calc -= 28000000;
	                        fax += 8400000;
	                        fax += calc*7/20;
	                    }
	                }
	            }
	        }
	    }
	}
	cout << fax;
}
