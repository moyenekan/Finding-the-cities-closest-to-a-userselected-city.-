#include "CityFile.h"
#include <string>
#include <iostream>

using namespace std;

CityFile::CityFile()
{
}


CityFile::~CityFile()
{
}

void CityFile::setCity(string _city) {
	ci = _city;
}
string CityFile::getCity() {
	return ci;
}
void CityFile::setCityDist(double _cDist) {
	cDist = _cDist;
}
double CityFile::getCityDist() {
	return cDist;
}
void CityFile::setCountry(string _country) {
	country = _country;
}
string CityFile::getCountry() {
	return country;
}
void CityFile::setLat(double _lat) {
	lat = _lat;
}
double CityFile::getLat() {
	return lat;
}
void CityFile::setLon(double _lon) {
	lon = _lon;
}
double CityFile::getLon() {
	return lon;
}





