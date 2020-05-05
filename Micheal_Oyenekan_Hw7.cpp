
#include <iostream>
#include <string>
#include <fstream>
#include "CityFile.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#define M_PI    3.1415926535897932384626433832795

using namespace std;

bool compareCity(CityFile a, CityFile b) {
	return a.getCityDist() < b.getCityDist();
}

long double toRadians(const long double degree)
{
	// cmath library in C++  
	// defines the constant 
	// M_PI as the value of 
	// pi accurate to 1e-30 
	long double one_deg = (M_PI) / 180;
	return (one_deg * degree);
}

long double formula(long double lat1, long double long1,
	long double lat2, long double long2)
{
	// Convert the latitudes  
	// and longitudes 
	// from degree to radians. 
	lat1 = toRadians(lat1);
	long1 = toRadians(long1);
	lat2 = toRadians(lat2);
	long2 = toRadians(long2);

	// Haversine Formula 
	long double dlong = long2 - long1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
		cos(lat1) * cos(lat2) *
		pow(sin(dlong / 2), 2);

	ans = 2 * asin(sqrt(ans));

	// Radius of Earth in  
	// Kilometers, R = 6371 
	// Use R = 3956 for miles 
	long double R = 3956;

	// Calculate the result 
	ans = ans * R;

	return ans;
}
vector<CityFile> list;
void doit();
int main()
{
	string line;


	ifstream file;
	file.open("worldcities.csv");

	if (!file.is_open()) {
		cout << "file didnt open " << endl;
	}
	else {
		getline(file, line);
		while (!file.eof()) {


			getline(file, line);
			if (line.size() == 0) {
				break;
			}
			int pos1 = 0;
			int pos2 = line.find(',', pos1);
			CityFile cityObject;
			cityObject.setCity(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
			pos2 = line.find(',', pos1);
			cityObject.setCountry(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
			pos2 = line.find(',', pos1);
			cityObject.setLat(stod(line.substr(pos1, pos2 - pos1)));
			pos1 = pos2 + 1;
			pos2 = line.find(',', pos1);
			cityObject.setLon(stod(line.substr(pos1, pos2 - pos1)));
			pos1 = pos2 + 1;

			list.push_back(cityObject);
		}
		cout << "Print city names and index from file" << endl;
		for (unsigned int index = 0; index < list.size(); index++) {

			cout << index << "    " << list[index].getCity();
			cout << endl;
		}
		
}
		doit();
		int choice;
		cout << "do you wanna continue" << endl;
		cout << "enter 1 to continue " << endl;
		cout << "enter 2 to quit" << endl;
		cin >> choice;
		do {
			switch (choice) {
			case 1:
				doit();
				break;
			case 2:
				cout << "bye!" << endl;
				exit(0);
				break;
			default:
					cout << "invalid number" << endl;
			}
		}while(choice = 1);
file.close();
		return 0;

	
}


void doit() 
{
	int userSelec;
		string input;
		cout << "do you want to use a city name or and index number? " << endl;


	cin >> input;

		bool foundit = false;
		for (unsigned int index = 0; list.size() > index; index++) {
			if (list[index].getCity() == input) {
				foundit = true;

				int saved = index;
				for (unsigned int j = 0; j < list.size(); j++) {
					double dist = formula(list[saved].getLat(), list[saved].getLon(), list[j].getLat(), list[j].getLon());
					list[j].setCityDist(dist);
				}
				sort(list.begin(), list.end(), compareCity);
			}
		}

		if (foundit == false) {
			if (stoi(input) < 0 || stoi(input) > list.size() - 1)
			{
				std::cout << "Index out of bound!" << endl;
				return;
			}
			userSelec = stoi(input);
				for (unsigned int w = 0; w < list.size(); w++) {
					double dist = formula(list[userSelec].getLat(), list[userSelec].getLon(), list[w].getLat(), list[w].getLon());
					list[w].setCityDist(dist);
				}
				sort(list.begin(), list.end(), compareCity);
			}
		
			cout << "The five closest city to " << input << endl;
			cout << "******************************************************************" << endl;
			cout << list[1].getCity() << "    " << list[1].getCountry() << "    " << list[1].getCityDist() << " miles" << endl;
			cout << list[2].getCity() << "    " << list[2].getCountry() << "    " << list[2].getCityDist() << " miles" << endl;
			cout << list[3].getCity() << "    " << list[3].getCountry() << "    " << list[3].getCityDist() << " miles" << endl;
			cout << list[4].getCity() << "    " << list[4].getCountry() << "    " << list[4].getCityDist() << " miles" << endl;
			cout << list[5].getCity() << "    " << list[5].getCountry() << "    " << list[5].getCityDist() << " miles" << endl;
			cout << "The five farthest city to " << input << endl;
			cout << "******************************************************************" << endl;
			cout << list[114].getCity() << "    " << list[114].getCountry() << "    " << list[114].getCityDist() << " miles" << endl;
			cout << list[115].getCity() << "    " << list[115].getCountry() << "    " << list[115].getCityDist() << " miles" << endl;
			cout << list[116].getCity() << "    " << list[116].getCountry() << "    " << list[116].getCityDist() << " miles" << endl;
			cout << list[117].getCity() << "    " << list[117].getCountry() << "    " << list[117].getCityDist() << " miles" << endl;
			cout << list[118].getCity() << "    " << list[118].getCountry() << "    " << list[118].getCityDist() << " miles" << endl;
	
	
}

