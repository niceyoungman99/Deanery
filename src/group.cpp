#include "group.h"
#include "deanery.h"

Group::Group(std::string &name) {
    this->title = name;
    this->head = nullptr;
}

void Group::addStudent(Student &st) {
    this->students_urls.push_back(&st);
    cout << "Студент "<<st.Get_fio()<<" добавлен в группу: "<< this->title<< endl;
}

void Group::chooseHead(Student &starosta) {// destroyed
    this->head = &starosta;
    //cout << "head was chosen" << endl;
}



Student *Group::Find_student(int i) {
    for (int j = 0; j < students_urls.size(); j++) {
        if (students_urls[j]->Get_ID() == i) {
            return students_urls[j];
        }
    }
    return nullptr;
}

float Group::getAveragemark() {
    if (students_urls.size() == 0) {
        return 0;
    }
    float sum = 0;
    for (int i = 0; i < this->students_urls.size(); i++) {
        sum += students_urls[i]->getAveragemark();
    }
    float res = sum / students_urls.size();
    return res;
}

bool Group::Contains_Student(basic_string<char> f) {
    for (int i = 0; i < students_urls.size(); i++) {
        if (students_urls[i]->Get_fio() == f) {
            return true;
        }
    }
    return false;
}

Group::Group() {}

void Group::removeStudent(int ind) {
    bool flag = false;
    for (int i = 0; i < students_urls.size(); i++) {
        if (students_urls[i]->Get_ID() == ind) {
            students_urls[i]->addToGroup(nullptr);
            if (head!= NULL&&head->Get_ID() == ind) {
                head = NULL;
            }
            students_urls.erase(students_urls.begin() + i);

            flag = true;
            //cout << "this student was removed" << endl;
        }
    }
    if (flag == false) {
        cout << "Данного студента нет в группе";

    }
}

bool Group::isEmpty() {
    if (students_urls.size() == 0) {
        return true;
    }
    return false;
}

string Group::Get_Fio_Head() const {
    if (head != nullptr) return head->Get_fio();
    else return "Староста не выбран";
}

vector<Student *> Group::Get_Dostup_St_urls() {
    return students_urls;
}

string Group::GetTitle() {
    return this->title;
}

Group::~Group() {
    this->students_urls.clear();
}