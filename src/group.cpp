#include "group.h"
#include "deanery.h"

#include <iostream>

Group::Group(const std::string &name) : title(name), head(nullptr) {
}

void Group::AddStudent(Student &st) {
  studentsUrls.push_back(&st);
  std::cout << "Студент " << st.GetFIO() << " добавлен в группу: " << title << std::endl;
}

void Group::ChooseHead(Student &starosta) {
  if (!ContainsStudent(starosta.GetFIO())) {
    std::cout << "Студент из другой группы. Нельзя назначить старостой!" << std::endl;
  }
  else {
    head = &starosta;
    std::cout << "Студент: "<<starosta.GetFIO()<<" успешно назначен на роль старосты группы" << this->GetTitle() << std::endl;
  }

}

Student *Group::FindStudent(int i) {
  for (Student *student : studentsUrls) {
    if (student->GetID() == i) {
      return student;
    }
  }
  return nullptr;
}

float Group::GetAverageMark() const {
  if (this == nullptr) {
    return -1;//if no this group object
  }
  if (studentsUrls.empty()) {
    return 0;
  }
  float sum = 0;
  for (Student *student : studentsUrls) {
    sum += student->GetAverageMark();
  }
  return studentsUrls.size() > 0 ? sum / studentsUrls.size() : 0;
}

bool Group::ContainsStudent(const std::string &f) {
  for (Student *student : studentsUrls) {
    if (student->GetFIO() == f) {
      return true;
    }
  }
  return false;
}

Group::Group() {
}

void Group::RemoveStudent(int ind) {
  bool found = false;
  for (size_t i = 0; i < studentsUrls.size(); i++) {
    if (studentsUrls[i]->GetID() == ind) {
      studentsUrls[i]->AddToGroup(nullptr);
      if (head != nullptr && head->GetID() == ind) {
        head = nullptr;
      }
      studentsUrls.erase(studentsUrls.begin() + i);
      found = true;
    }
  }
  if (!found) {
    std::cout << "Студента с данным id: " << ind << " нет в группе" << std::endl;
  }
}

bool Group::IsEmpty() const {
  return studentsUrls.empty();
}

std::string Group::GetHeadFio() const {
  if (head != nullptr) {
    return head->GetFIO();
  } else {
    return "Староста не выбран";
  }
}

std::vector<Student *> &Group::GetStudentUrls() {
  return studentsUrls;
}

std::string Group::GetTitle() const {
  if (this == nullptr) {
    return "Нет такого студента в группе";
  }
  return title;
}

Group::~Group() {
  studentsUrls.clear();
}

std::string Group::GetSpec() const {
  if (this == nullptr) {
    return "Нет такой группы";
  }
  std::string spec;
  for (char ch : title) {
    if (!isdigit(ch)) {
      spec += ch;
    }
  }
  return spec;
}
