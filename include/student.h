#ifndef DEANERY_MY_STUDENT_H
#define DEANERY_MY_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "group.h"
class Group; // Forward declaration

class Student {
 public:
  // Constructor
  Student(int id, const std::string &fio);

  // Destructor
  ~Student();

  // Add student to a group
  void AddToGroup(Group *g);

  // Add a mark to the student's list of marks
  void AddMark(int mark);

  // Get the average mark of the student
  float GetAverageMark() const;

  // Get student's ID
  int GetID() const;

  // Get student's full name (FIO)
  std::string GetFIO() const;

  // Check if this student is the head of the group
  bool IsHeadOfGroup() const;

  // Get a reference to the student's group
  Group *GetGroup() const;

  // Get the list of student's marks as a string
  std::string GetListOfMarks() const;

 private:
  int id; // ID of the student
  Group *group; // Student's group
  std::string fio; // Full name (FIO) of the student
  std::vector<int> marks; // Student's marks
};

#endif //DEANERY_MY_STUDENT_H
