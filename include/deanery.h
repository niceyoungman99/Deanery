
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
  std::vector<Group *> groups;//вектор ссылок на группы
 public:
  void hireStudents(const std::string &file1);//считывание студентов из файла

  void createGroups(const std::string &file2);//считывание групп из файлов

  void moveStudents(Group &new2, std::vector<Student *> &moving_sts);//перемещение студентов

  void addMarksToAll();//добавление рандомных оценок всем студентам

  void Delete_St_Low_Mark(Student &st);//удаление студентов со средней оценкой меньше 3,5

  void initHeads(std::vector<int> ids);//инициализация старосты?? такая же функция есть у группы

  void saveStaff(const std::string &newstfile);//сохранение информации в файл

  void getStatistics();//вывод всей информации

  Group *GetGroup(const std::string &ttl);//выдача объекта группы по тайтлу

  ~Deanery();//destructor
  std::string fireStudents();//giving info and deleting students with low marks(<3.5)
  bool FindGroup(const std::string f);//проверка есть ли функция в векторе групп
};

#endif //DEANERY_MY_DEANERY_H
