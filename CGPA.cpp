#include <iostream>
#include <string>
#include <vector>

using std::string;
using namespace std;
using std::vector;

class Course {
private:
	string courseName;
	int courseCredits;
	string courseLetterGrade;

public:
	Course(const string& coursename, int coursecredits, string coursegrade) {
		courseName = coursename;
		courseCredits = coursecredits;
		courseLetterGrade = coursegrade;
	}

	string getcourseName() const {
		return courseName;
	}
	int getcourseCredits() const {
		return courseCredits;
	}
	
	string getcourseLetterGrade() const {
		return courseLetterGrade;
	}
	friend ostream& operator<<(ostream& os, const Course& course);
};

// Implementation of the << operator for Course
ostream& operator<<(ostream& os, const Course& course) {
	os << "Course Name: " << course.courseName
		<< ", Credits: " << course.courseCredits
		<< ", Grade: " << course.courseLetterGrade;
	return os;
};

class Student {
private:
	string Name;
	vector<Course> courses;// here I am using a vector to store courses

public:
	int totalCredits;
	float StudentCGPA;
	Student(const string& name, const vector<Course>& coursesList) : Name(name), courses(coursesList) {}
	void getName()
		const {
		std::cout << "Name:" << Name << std::endl;
	}
	void getnumCourses()
		const {
		cout << "Number of Courses:" << courses.size() << endl;
	}
	void addCourse(const Course& course) {
		courses.push_back(course);// This will add a course to the vector
	}
	void displayCourses() {
		cout << "Courses: " << endl;

		for (const auto& course : courses) {
			totalCredits = course.getcourseCredits() + totalCredits;
			cout << "Course Name: " << course.getcourseName()
				<< " Course Credits: " << course.getcourseCredits()
				<< " Course Grade: " << course.getcourseLetterGrade()
				<< endl;
		}
	}
	int calculateStudentTotalCredits() {
		return totalCredits;
	}
};
int main() {
	string courseName;
	int courseCredits;
	int courseGrade;

	string courseLetterGrade;

	vector<Course> courseList;
	int numCourses;
	string name;

	cout << "Enter the student name: ";
	getline(std::cin, name);

	cout << "Enter the number of courses: ";
	cin >> numCourses;
	std::cin.ignore();

	for (int i = 0; i < numCourses; ++i) {

		std::cout << "Enter course name: ";
		std::getline(std::cin, courseName);

		std::cout << "Enter course credits: ";
		std::cin >> courseCredits;

		std::cout << "Enter course grade: ";
		std::cin >> courseGrade;
		std::cin.ignore();

		if (70 <= courseGrade && courseGrade <= 72) {
			courseLetterGrade = "C-";
		}
		else if (73 <= courseGrade && courseGrade <= 76) {
			courseLetterGrade = "C";
		}
		else if (77 <= courseGrade && courseGrade <= 79) {
			courseLetterGrade = "C+";
		}
		else if (80 <= courseGrade && courseGrade <= 82) {
			courseLetterGrade = "B-";
		}
		else if (83 <= courseGrade && courseGrade <= 86) {
			courseLetterGrade = "B";
		}
		else if (87 <= courseGrade && courseGrade <= 89) {
			courseLetterGrade = "B+";
		}
		else if (90 <= courseGrade && courseGrade <= 92) {
			courseLetterGrade = "A-";
		}
		else if (93 <= courseGrade && courseGrade <= 96) {
			courseLetterGrade = "A";
		}
		else if (97 <= courseGrade && courseGrade <= 99) {
			courseLetterGrade = "A+";
		}
		courseList.emplace_back(courseName, courseCredits, courseLetterGrade);
	}
	int totalCredits = 0;
	Student student(name, courseList);

	student.getName();
	student.getnumCourses();
	student.displayCourses();
	cout<< student.calculateStudentTotalCredits()<< endl;
	return 0;
}
}
