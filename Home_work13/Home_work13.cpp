#include <iostream>

struct Student {
	char name[20];
	static const int markAmount = 4;
	double mark[markAmount]{};
};
int averageMark(Student student) {
	int sumMark{};
	for (int i = 0; i < student.markAmount; ++i) {
		sumMark += student.mark[i];
	}
	return sumMark / student.markAmount;
}
void sortByMark(Student students[], int size) {
	int minIndex = 0;
	for (int i = 0; i < (size-1); ++i) {
		minIndex = i;
		for (int j = (i + 1); j < size; ++j) {
			if (averageMark(students[j]) > averageMark(students[minIndex])) minIndex = j;
		}
		if (minIndex != i) std::swap(students[minIndex], students[i]);
	}

}
Student* bestStudent( Student students[], const int size) {
	int studentNumber{};
	int biggestMark{};
	for (int i = 0; i < size; ++i)
	{
		if (averageMark(students[i]) > biggestMark) {
			biggestMark = averageMark(students[i]);
			studentNumber = i;
		}
	}
	return &students[studentNumber];
}

int successfulStudents(Student students[], const int size) {
	int counter = 0;
	int requiredAssessment = 75;
	for (int i = 0; i < size; ++i) {
		if (averageMark(students[i]) >= requiredAssessment) counter++;
	}
	return counter;
};
int main() {
	const int size = 4;
	Student students[size] = { {"Gregory",12,23,13,4}, {"Valentine", 65,55,89,100}, {"Sergy", 44,67,55,43}, {"Anton",34,54,64,76} };
	std::cout << "Students and their average mark: \n";
	for (int i = 0; i < size; ++i) {
		std::cout << students[i].name << ' ' << averageMark(students[i]) << ' ';
	}
	sortByMark(students, size);
	std::cout << "\nStudents sorted by average mark: \n";
	for (int i = 0; i < size; ++i) {
		std::cout << students[i].name << ' ';
	}
	std::cout << "\nBest student: " << bestStudent(students, size)->name;
	std::cout << "\nNumber of successful students;" << successfulStudents(students, size);
}