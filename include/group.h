#ifndef DEANERY_MY_GROUP_H
#define DEANERY_MY_GROUP_H

#include "student.h"
#include "iostream"
#include "string"
#include "vector"

class Student;

using namespace std;

class Group {
private:
    string title;//title of group
    string spec;//group`s speciality
    std::vector<Student *> students_urls;//vector ссылок на студентов
    Student *head;//group`s head
public:
    Group(string &name);//initialization of group with only title
    Group();//
    ~Group();//destructor
    void addStudent(Student &st);//adding student into group
    void chooseHead(Student &starosta);//choosing head of group
    Student *Find_student(string &f);//finding student in the group of his or her fio
    Student *Find_student(int f);//finding student in the group of his or her id
    float getAveragemark();//giving average value of all student`s vectors of marks(getter of average group`s mark)
    void removeStudent(int ind);//deleting student from the group of his or her id
    bool Contains_Student(basic_string<char> f);//checkin is student in the group(FIXED TO BASIC STRING CHAR????)
    bool isEmpty();//checking if the group is empty(0 students in the group)
    string Get_Fio_Head() const;//giving fio of head of group(getter of head)
    vector<Student *>
    Get_Dostup_St_urls();//giving vector of students of the group(getter of vector of students urls objects)
    string GetTitle();//giving title of the group (getter title of the group)
};

#endif //DEANERY_MY_GROUP_H
