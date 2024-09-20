/*
  Aditya Chandrashekaran
  9/20/2024
  This program allows you to add and delete students to a list.
  You can also print out all the students in the list.
*/

// Import needed libraries
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

// Create struct that stores all properties of students
struct Student {
  char firstName[100];
  char lastName[100];
  int studentID;
  float GPA;
};


// Initialize functions
void addStudent(vector<Student*> &list);
void printStudentList(vector<Student*> list);
void deleteStudent(vector<Student*> &list);

int main() {

  // Initalize veriables and student list
  bool running = true;
  char input[8];
  vector<Student*> studentList;

  // loop that keeps program running
  while (running == true) {

    // Get user input of which function they want to run
    cout << "Pick a command to run on student list: \'ADD\', \'DELETE\', \'PRINT\', or \'QUIT\'" << endl;
    cin >> input;

    // Call the correct function based on user input
    if (strcmp(input, "ADD") == 0) {
      addStudent(studentList);
    }
    else if (strcmp(input, "PRINT") == 0) {
      printStudentList(studentList);
    }
    else if (strcmp(input, "DELETE") == 0) {
      deleteStudent(studentList);
    }
    else if (strcmp(input, "QUIT") == 0) {
      //stop the loop is the user want to quit the program
      running = false;
    }
  }
  return 0;
}

// Function to add a student
void addStudent(vector<Student*> &list) {
  Student* newStudent = new Student();

  // Get input for each of the students attributes and then store it in a new student variable
  cout << "Enter the students first name: " << endl;
  cin >> newStudent->firstName;
  cout << "Enter the students last name: " << endl;
  cin >> newStudent->lastName;
  cout << "Enter the students ID: " << endl;
  cin >> newStudent->studentID;
  cout << "Enter the students gpa: " << endl;
  cin >> newStudent->GPA;
  // Add the new student variable to the vector
  list.push_back(newStudent);
  // Lets the user know that the student was successfully added
  cout << "Succesfully added a student with the id of " << newStudent->studentID << endl;
}

// Function to print out all students in the list
void printStudentList(vector<Student*> list) {
  // Runs a for loop through the vector and prints out each attribute of each student
  for (int i = 0; i < list.size(); i++) {
    cout << list[i]->firstName << "\t\t" << list[i]->lastName << "\t\t" << list[i]->studentID << "\t\t" << std::fixed <<std::setprecision(2) <<list[i]->GPA << endl;
  }
}

// Function to delete a student from the list
void deleteStudent(vector<Student*> &list) {
  // Variables to keep track of id and index
  int index = -1;
  int id = -1;
  // get the user input for the student id of the student they want to delete
  cout << "Enter the student id of the student you would like to delete" << endl;
  cin >> id;

  // Runs a through student list and sets the index to the student that has this id
  for (int i = 0; i < list.size(); i++) {
    if (list[i]->studentID == id) {
      index = i;
    }
  }
  // If the index is not the preset index then we delete the student and inform the user
  if (index != -1) {
    list.erase(std::next(list.begin(), index));
    cout << "Successfully deleted a student with an ID of " << id << endl;
  }
  // Else the user is informed that no student with the inputted id exists
  else {
    cout << "A student with the inputted student ID does not exist" << endl;
  }
}
