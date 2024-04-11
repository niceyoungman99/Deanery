#include "student.h"

Student::Student(int id, const std::string &fio) {
  this->id = id;
  this->fio = fio;
  this->group = nullptr;
}

int Student::GetID() const {
  if (this == nullptr) {
    return -1;//if no this student object
  }
  return id;
}

std::string Student::GetFIO() const {
  if (this == nullptr) {
    return "Нет такого студента в группе";
  }
  return fio;
}

void Student::AddMark(int mark) {
  marks.push_back(mark);
}

void Student::AddToGroup(Group *g) {
  group = g;
}

float Student::GetAverageMark() const {
  if (this == nullptr) {
    return -1;//if no this student object
  }
  float sum = 0.0;
  for (int mark : marks) {
    sum += mark;
  }
  return marks.size() > 0 ? sum / marks.size() : 0;
}

bool Student::IsHeadOfGroup() const {
  if (this->group->GetHeadFio() == this->fio) {
    return true;
  } else {
    return false;
  }

}

Group *Student::GetGroup() const {
  if (this == nullptr) {
    return nullptr;//if no this student object
  }
  return group;
}

std::string Student::GetListOfMarks() const {
  if (this == nullptr) {
    return "no such student";//if no this student object
  }
  std::string list;
  for (int mark : marks) {
    list += std::to_string(mark) + " ";
  }
  return list;
}

Student::~Student() {
  marks.clear();
}
