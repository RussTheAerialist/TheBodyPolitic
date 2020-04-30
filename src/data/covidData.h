#pragma once

#include "ofxTime.h"

#include <iostream>
#include <string>

using namespace std;

struct CovidData {
	enum class CaseType { confirmed, deaths };

	enum FieldLabel {
		Case_Type,
		Cases,
		Difference,
		Date,
		Country_Region,
		Province_State,
		Admin2,
		Combined_Key,
		FIPS,
		Lat,
		Long,
		Table_Names,
		Prep_Flow_Runtime
	};

	CaseType caseType;
	int cases;
	int difference;
	Poco::DateTime date; // TODO: Convert to unix timestamp for sorting
	string countryRegion;
	string provinceState;
	string admin2;
	string combinedKey;
	int fips;
	float latitude;
	float longitude;

	bool operator<(const CovidData &rhs) const { return date < rhs.date; }
};