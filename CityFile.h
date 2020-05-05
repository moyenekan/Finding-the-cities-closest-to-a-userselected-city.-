#pragma once
#include <string>
#include <iostream>

using namespace std;
class CityFile
{
private:
	string ci;
	string country;
	double lat;
	double lon;
	double cDist;

public:
	CityFile();
	~CityFile();

	void setCity(string _city);
	string getCity();
	void setCityDist(double _cDist);
	double getCityDist();
	void setCountry(string _country);
	string getCountry();
	void setLat(double _lat);
	double getLat();
	void setLon(double _lon);
	double getLon();
};


