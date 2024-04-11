#ifndef DEANERY_MY_GROUP_H
#define DEANERY_MY_GROUP_H

#include "student.h"
#include <iostream>
#include <string>
#include <vector>

class Student; // Forward declaration

class Group {
 public:
  // Constructor with only title
  explicit Group(const std::string &title);

  // Default constructor
  Group();

  // Destructor
  ~Group();

  // Get group's speciality
  std::string GetSpec() const;

  // Add a student to the group
  void AddStudent(Student &st);

  // Choose the head of the group
  void ChooseHead(Student &starosta);

  // Find a student by name in the group
  Student *FindStudent(const std::string &f);

  // Find a student by ID in the group
  Student *FindStudent(int f);

  // Get the average mark of all students in the group
  float GetAverageMark() const;

  // Remove a student from the group by ID
  void RemoveStudent(int ind);

  // Check if student with a specific name is in the group
  bool ContainsStudent(const std::string &f);

  // Check if the group is empty (has 0 students)
  bool IsEmpty() const;

  // Get the name of the head of the group
  std::string GetHeadFio() const;

  // Get vector of students in the group
  std::vector<Student *> &GetStudentUrls();

  // Get the title of the group
  std::string GetTitle() const;

 private:
  std::string title; // Title of the group
  std::string spec; // Group's speciality
  std::vector<Student *> studentsUrls; // Vector of student pointers
  Student *head; // Group's head
};

#endif //DEANERY_MY_GROUP_H
