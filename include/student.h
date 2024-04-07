#ifndef DEANERY_MY_STUDENT_H
#define DEANERY_MY_STUDENT_H

#include "iostream"
#include "string"
#include "group.h"
#include "vector"

using namespace std;

class Group;

class Student {
private:
    int id;//id of student
    Group *group;//students`s group
    string fio;//fio of student
    vector<int> marks;//student`s marks
public:
    Student(int id, std::string fio);//initialization of student with 2 params
    ~Student();//destructor
    void addToGroup(Group *g);//todo: maybe it is not good(useful)  function
    void addmark(int mark);//adding marks to student`s vector marks
    float getAveragemark();//giving average value of student`s  marks(getter of average value of mark)
    int Get_ID() const;//giving student`s id(getter of id)
    string Get_fio() const;//giving student`s fio(getter of fio)
    bool isHeadOfGroup();//checking if this student is the head of group
    Group *RetGr() const;//giving ссылку on student`s group
    string Get_list_of_marks();//giving student`s vector of marks in string format

};

#endif //DEANERY_MY_STUDENT_H
