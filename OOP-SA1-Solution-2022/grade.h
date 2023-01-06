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
	// 3rd Methods
	//Methods for sum.
	long double sum(const std::vector<double>&);
	long double sum(const std::vector<int>&);
	//Methods for Mean.
	double mean(const std::vector<double>&);
	double mean(const std::vector<int>&);
	//Method for Population Variance.
	double populationVariance(const std::vector<double>&, double mean);

	// 2.2 Methods
	//Method for standard deviation.
	long double standardDeviation(const std::vector<double>&, double populationVariance);
	//Method for high performing learners.
	std::vector<std::string> highPerformingLearners(const std::map<std::string, double>& data);
	//Method for low performing learners.
	std::vector<std::string> lowPerformingLearners(const std::map<std::string, double>& data);
};

// Class Implementation
//Finding the sum for a Vector of doubles.
	long double Grade::sum(const std::vector<double>& data) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the vector is empty
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
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the vector is empty
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
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the vector is empty
		}
		else {
			long double addedSum = 0;
			for (int Counter = 0; Counter < data.size(); Counter++) {
				addedSum += data[Counter];
			}
			return addedSum / data.size();
		}
		return 0;
	}
//Finding the mean for a vector of integers
	double Grade::mean(const std::vector<int>& data) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the vector is empty
		}
		else {
			long double addedSum = 0;
			for (int Counter = 0; Counter < data.size(); Counter++) {
				addedSum += data[Counter];
			}
			return addedSum / data.size();
		}
		return 0;
	}
//Finding the Population Variance from a vector.
	double Grade::populationVariance(const std::vector<double>& data, double mean) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the vector is empty
		}
		else {
			double finalValue = 0;
			double vectorMean = Grade::mean(data);
			for (int Counter = 0; Counter < data.size(); Counter++) {
				finalValue += (data[Counter] - vectorMean) * (data[Counter] - vectorMean);
			}
			return finalValue / data.size();
		}
		return 0;
	}

//Code for the 2.2 Methods
//Finding the Standard Deviation from a vector.
	long double Grade::standardDeviation(const std::vector<double>& data, double populationVariance) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the vector is empty
		}
		else {
			double mean = Grade::mean(data); //Brings in the previously defined mean method to be used in the next step.
			double popVariance = Grade::populationVariance(data, mean); //Uses the previously defined population variance method to avoid a repeat of code.
			return sqrt(popVariance);
		}
		return 0;
	}
//Finding the high performing learners from a map using standard deviation.
	std::vector<std::string> Grade::highPerformingLearners(const std::map<std::string, double>& data) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!"); //Throws an error if the map is empty
		}
		else {
			long double sum = 0;
			long double stepTwo = 0;
			std::map<std::string, double> learnerGrades = data;
			for (std::pair<std::string, double> grade : learnerGrades) {
				sum += grade.second;
			}
			double mean = sum / data.size();
			for (std::pair<std::string, double> grade : learnerGrades) {
				stepTwo += (grade.second - mean) * (grade.second - mean);
			}
			double popVariance = stepTwo / data.size();
			double stdDeviation = sqrt(popVariance);
			std::vector<std::string> highPerformers;
			for (std::pair<std::string, double> grade : learnerGrades) {
				if (grade.second > mean + stdDeviation) {
					highPerformers.push_back(grade.first);
				}
			}
			/* 
			//Code I wrote to try optimise highPerformingLearners/lowPerformingLearners. Unfortunately struggled to get it functional
			//So I am sticking with the functional code that already passes tests.
			std::map<std::string, double> learnerGrades = data;
			std::vector<double> scores;
			for (std::pair<std::string, double> grade : learnerGrades) {
				scores.push_back(grade.second);
			}
			double mean = Grade::mean(scores);
			double popVariance = Grade::populationVariance(scores, mean);
			long double standardDev = sqrt(popVariance);
			std::vector<std::string> highPerformers;
			for (std::pair<std::string, double> grade : learnerGrades) {
				if (grade.second > mean + standardDev) {
					highPerformers.push_back(grade.first);
				}
			}
			*/
			return highPerformers;
		}
		std::vector<std::string> highPerformers;
		return highPerformers;
	}
	
//Finding the low performing learners from a map using standard deviation.
	std::vector<std::string> Grade::lowPerformingLearners(const std::map<std::string, double>& data) {
		if (data.empty()) {
			throw std::invalid_argument("Your vector is empty!");
		}
		else {
			long double sum = 0;
			long double stepTwo = 0;
			std::map<std::string, double> learnerGrades = data;
			for (std::pair<std::string, double> grade : learnerGrades) {
				sum += grade.second;
			}
			double mean = sum / data.size();
			for (std::pair<std::string, double> grade : learnerGrades) {
				stepTwo += (grade.second - mean) * (grade.second - mean);
			}
			double popVariance = stepTwo / data.size();
			double stdDeviation = sqrt(popVariance);
			std::vector<std::string> lowPerformers;
			for (std::pair<std::string, double> grade : learnerGrades) {
				if (grade.second < mean - stdDeviation) {
					lowPerformers.push_back(grade.first);
				}
			}
			return lowPerformers;
		}
		std::vector<std::string> lowPerformers;
		return lowPerformers;
	}
