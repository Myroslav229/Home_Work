#include <iostream>

struct Student {
	char name[20];
	double mark[4]{};

};
double averageMark(Student student) {
	int sumMark{};
	for (int i = 0; i < 4; ++i) {
		sumMark += student.mark[i];
	}
	return sumMark / 4;
}
void sortByMark(Student students[]) {
	int minIndex = 0;
	for (int i = 0; i < 3; ++i) {
		minIndex = i;
		for (int j = (i + 1); j < 4; ++j) {
			if (averageMark(students[j]) > averageMark(students[minIndex])) minIndex = j;
		}
		if (minIndex != i) std::swap(students[minIndex], students[i]);
	}

}
const char* bestStudent(Student students[]) {
	int studentNumber{};
	int biggestMark{};
	for (int i = 0; i < 4; ++i)
	{
		if (averageMark(students[i]) > biggestMark) {
			biggestMark = averageMark(students[i]);
			studentNumber = i;
		}
	}
	return students[studentNumber].name;
}

int successfulStudents(Student students[]) {
	int counter = 0;
	for (int i = 0; i < 4; ++i) {
		if (averageMark(students[i]) >= 75) counter++;
	}
	return counter;
};
int main() {

	Student students[4] = { {"Gregory",12,23,13,4}, {"Valentine", 65,55,89,100}, {"Sergy", 44,67,55,43}, {"Anton",34,54,64,76} };
	std::cout << "Students and their average mark: \n";
	for (int i = 0; i < 4; ++i) {
		std::cout << students[i].name << ' ' << averageMark(students[i]) << ' ';
	}
	sortByMark(students);
	std::cout << "Students sorted by average mark: \n";
	for (int i = 0; i < 4; ++i) {
		std::cout << students[i].name << ' ';
	}
	std::cout << "\nBest student" << bestStudent(students);
	std::cout << "\nNumber of successful students;" << successfulStudents(students);
}