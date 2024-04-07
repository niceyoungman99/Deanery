
#ifndef DEANERY_MY_DEANERY_H
#define DEANERY_MY_DEANERY_H
//как то наверно заинклюдить файл и сделать работу с ним
#include "iostream"
#include "string"
#include "vector"
#include "group.h"
#include "random"
#include <sstream>
#include "ctime"
#include "deanery.h"
#include "fstream"
#include "cmath"
#include <locale>
#include "codecvt"
#include "student.h"
#include "cstdlib"
#include "cstring"

class Deanery {

private:
    vector<Group *> groups;//вектор ссылок на группы
public:
    void hireStudents(const string &file1);

    void createGroups(const string &file2);

    void moveStudents(Group &new2, vector<Student *>& moving_sts);

    void addMarksToAll();

    void Delete_St_Low_Mark(Student &st);

    void initHeads(Student &st);

    void saveStaff(const std::string &newstfile);

    void getStatistics();

    Group *GetGroup(const string &ttl);

    ~Deanery();//destructor
    string fireStudents();//giving info and deleting students with low marks(<3.5)
    bool FindGroup(const string f);
};

#endif //DEANERY_MY_DEANERY_H
