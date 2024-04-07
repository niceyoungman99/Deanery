#include "student.h"

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
    this->group = nullptr;
}

int Student::Get_ID() const {
    return id;

}

string Student::Get_fio() const {
    return this->fio;
}

void Student::addmark(int mark) {
    this->marks.push_back(mark);
}

void Student::addToGroup(Group *g) {
    this->group = g;
    //cout << "Группа установлена студенту" << endl;
}

float Student::getAveragemark() {
    float sum = 0;
    float res;
    for (int i = 0; i < this->marks.size(); i++) {
        sum += this->marks[i];
    }
    res = sum / this->marks.size();
    return res;
}

bool Student::isHeadOfGroup() {
    if (this->group->Get_Fio_Head() == this->fio) {
        return true;
    } else {
        return false;
    }
}

Group *Student::RetGr() const {
    return this->group;
}

string Student::Get_list_of_marks() {
    string list;
    for (int i = 0; i < this->marks.size(); i++) {
        list = list + to_string(marks[i]) + " ";
    }
    return list;
}

Student::~Student() {
    this->marks.clear();
}