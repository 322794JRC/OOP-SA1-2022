#pragma once
//Jonathan Cunliffe 14/12/2022
//SA01
#include <string>
#include <vector>
#include <map>

struct classifiedAssessmentGrade {
	int grade;
	int maxGrade;
};

struct weightedAssessmentGrade {
	double grade;
	double weighting;
};

// Class specification

class Grade
{
private:

protected:

public:
	// Sample 
	double add(double dataItem1, double dataItem2);
	double subtract(double dataItem1, double dataItem2);


	// 3rd Methods
	//Methods for Sum
	long double sum(const std::vector<double>&);
	long double sum(const std::vector<int>&);
	//Methods for Mean
	double mean(const std::vector<double>&);
	double mean(const std::vector<int>&);
	//Method for Population Variance
	double populationVariance(const std::vector<double>&, double mean);

	// 2.2 Methods


	// 2.1 Methods


	// 1st Methods

};

// Class Implementation
//Finding the sum for a Vector of doubles.
long double Grade::sum(const std::vector<double>& data) {
	if (data.empty()) {
		throw std::invalid_argument("Your vector is empty!");
	}
	else {
		long double addedSum = 0;
		for (int Counter = 0; Counter < data.size(); Counter++) {
			addedSum += data[Counter];
		}
		return addedSum;
	}
	return 0;
}
//Finding the sum for a Vector of integers.
long double Grade::sum(const std::vector<int>& data) {
	if (data.empty()) {
		throw std::invalid_argument("Your vector is empty!");
	}
	else {
		long double addedSum = 0;
		for (int Counter = 0; Counter < data.size(); Counter++) {
			addedSum += data[Counter];
		}
		return addedSum;
	}
	return 0;
}
//Finding the mean for a vector of doubles
double Grade::mean(const std::vector<double>& data) {
	//Throws an error if the vector is empty
	if (data.empty()) {
		throw std::invalid_argument("Your vector is empty!");
	}
	else {
		double mean = 0;
		long double addedSum = 0;
		for (int Counter = 0; Counter < data.size(); Counter++) {
			addedSum += data[Counter];
		}
		mean = addedSum / data.size();
		return mean;
	}
	return 0;
}
//Finding the mean for a vector of integers
	double Grade::mean(const std::vector<int>& data) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!");
		}
		else {
			double mean = 0;
			long double addedSum = 0;
			for (int Counter = 0; Counter < data.size(); Counter++) {
				addedSum += data[Counter];
			}
			mean = addedSum / data.size();
			return mean;
		}
		return 0;
	}
//Finding the Population Variance from a vector.
	double Grade::populationVariance(const std::vector<double>& data, double mean) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!");
		}
		else {
			double finalValue = 0;
			double populationVariance = 0;
			double mean = 0;
			long double addedSum = 0;
			for (int Counter = 0; Counter < data.size(); Counter++) {
				addedSum += data[Counter];
			}
			mean = addedSum / data.size();
			for (int Counter = 0; Counter < data.size(); Counter++) {
				double tempValue = data[Counter] - mean;
				double squaredValue = tempValue * tempValue;
				finalValue += squaredValue;
			}
			populationVariance = finalValue / data.size();
			return populationVariance;
		}
		return 0;
	}
// Sample code passed test
double Grade::add(double dataItem1, double dataItem2) {
	return dataItem1 + dataItem2;
}

// Sample code failed test (error in the code)
double Grade::subtract(double dataItem1, double dataItem2) {
	// Uncomment the line below to fix the failed test
	// return dataItem1 - dataItem2;
	return dataItem1 - dataItem1;
	
}
