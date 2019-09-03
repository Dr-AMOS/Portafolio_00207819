using namespace std;
#include <iostream>

struct Country {
	string Name[5];
	string Capital[5];
	int Population[5];
	int AgeAvg[5];
};

int main() {
	struct Country Continent[5];
	Continent[0].Name[0] = "USA";
	Continent[0].Capital[0] = "Washington";
	Continent[0].Population[0] = 100000;
	Continent[0].AgeAvg[0] = 40;

	Continent[0].Name[1] = "Canada";
	Continent[0].Capital[1] = "Ontario";
	Continent[0].Population[1] = 100000;
	Continent[0].AgeAvg[1] = 30;

	Continent[0].Name[2] = "Brazil";
	Continent[0].Capital[2] = "	Brasília";
	Continent[0].Population[2] = 100000;
	Continent[0].AgeAvg[2] = 30;

	Continent[0].Name[3] = "Jamaica";
	Continent[0].Capital[3] = "Kingston";
	Continent[0].Population[3] = 100000;
	Continent[0].AgeAvg[3] = 25;

	Continent[0].Name[4] = "Chile";
	Continent[0].Capital[4] = "Santiago";
	Continent[0].Population[4] = 100000;
	Continent[0].AgeAvg[4] = 40;

	Continent[1].Name[0] = "China";
	Continent[1].Capital[0] = "Beijing";
	Continent[1].Population[0] = 1000000;
	Continent[1].AgeAvg[0] = 30;

	Continent[1].Name[1] = "Japan";
	Continent[1].Capital[1] = "Tokyo";
	Continent[1].Population[1] = 100000;
	Continent[1].AgeAvg[1] = 30;

	Continent[1].Name[2] = "Russia";
	Continent[1].Capital[2] = "Moscow";
	Continent[1].Population[2] = 100000;
	Continent[1].AgeAvg[2] = 45;

	Continent[1].Name[3] = "S-Korea";
	Continent[1].Capital[3] = "Seoul";
	Continent[1].Population[3] = 100000;
	Continent[1].AgeAvg[3] = 30;

	Continent[1].Name[4] = "India";
	Continent[1].Capital[4] = "New Delhi";
	Continent[1].Population[4] = 100000;
	Continent[1].AgeAvg[4] = 25;

	Continent[2].Name[0] = "Nigeria";
	Continent[2].Capital[0] = "Abuja";
	Continent[2].Population[0] = 100000;
	Continent[2].AgeAvg[0] = 30;

	Continent[2].Name[1] = "Morocco";
	Continent[2].Capital[1] = "	Rabat";
	Continent[2].Population[1] = 100000;
	Continent[2].AgeAvg[1] = 40;

	Continent[2].Name[2] = "Egypt";
	Continent[2].Capital[2] = "	Cairo";
	Continent[2].Population[2] = 100000;
	Continent[2].AgeAvg[2] = 30;

	Continent[2].Name[3] = "Algeria";
	Continent[2].Capital[3] = "Algiers";
	Continent[2].Population[3] = 100000;
	Continent[2].AgeAvg[3] = 40;

	Continent[2].Name[4] = "Angola";
	Continent[2].Capital[4] = "Luanda";
	Continent[2].Population[4] = 1000000;
	Continent[2].AgeAvg[4] = 35;

	Continent[3].Name[0] = "Albania";
	Continent[3].Capital[0] = "Tirana";
	Continent[3].Population[0] = 10000;
	Continent[3].AgeAvg[0] = 30;

	Continent[3].Name[1] = "Andorra";
	Continent[3].Capital[1] = "Andorra la Vella";
	Continent[3].Population[1] = 1000000;
	Continent[3].AgeAvg[1] = 40;

	Continent[3].Name[2] = "Belgium";
	Continent[3].Capital[2] = "Brussels";
	Continent[3].Population[2] = 1000000;
	Continent[3].AgeAvg[2] = 40;

	Continent[3].Name[3] = "Germany";
	Continent[3].Capital[3] = "Berlin";
	Continent[3].Population[3] = 100000;
	Continent[3].AgeAvg[3] = 45;

	Continent[3].Name[4] = "Greece";
	Continent[3].Capital[4] = "Athens";
	Continent[3].Population[4] = 100000;
	Continent[3].AgeAvg[4] = 35;

	Continent[4].Name[0] = "Australia";
	Continent[4].Capital[0] = "Canberra";
	Continent[4].Population[0] = 100000;
	Continent[4].AgeAvg[0] = 35;

	Continent[4].Name[1] = "Fiji";
	Continent[4].Capital[1] = "Suva";
	Continent[4].Population[1] = 100000;
	Continent[4].AgeAvg[1] = 30;

	Continent[4].Name[2] = "Vanuatu";
	Continent[4].Capital[2] = "Port Vila";
	Continent[4].Population[2] = 1000000;
	Continent[4].AgeAvg[2] = 40;

	Continent[4].Name[3] = "Nauru";
	Continent[4].Capital[3] = "None";
	Continent[4].Population[3] = 100000;
	Continent[4].AgeAvg[3] = 35;

	Continent[4].Name[4] = "Palau";
	Continent[4].Capital[4] = "Ngerulmud";
	Continent[4].Population[4] = 40;
	Continent[4].AgeAvg[4] = 100000;

	cout << Continent[2].Name[4] << endl;
	cout << Continent[2].Capital[4] << endl;
	cout << Continent[2].Population[4] << endl;
	cout << Continent[2].AgeAvg[4] << endl;

	getchar();
	return 0;
}


