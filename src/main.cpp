#include <windows.h>

#include "deanery.h"
#include "student.h"
#include "group.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"ru");
    Deanery deanary;
    deanary.createGroups("C:\\Users\\maxim\\CLionProjects\\deanery_my\\groups.txt");
    deanary.hireStudents("C:\\Users\\maxim\\CLionProjects\\deanery_my\\students.txt");
    deanary.getStatistics();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после добавления оценок"<<endl;
    deanary.getStatistics();
    deanary.saveStaff("save.txt");
    Student st1(31,"Терентьев Борис Григорьевич");
    //cout<<deanary.FindGroup("23КНТ6")<<endl;//проверка на наличие группы в векторе групп
    deanary.GetGroup("23КНТ6")->addStudent(st1);
    st1.addToGroup(deanary.GetGroup("23КНТ6"));
    deanary.GetGroup("23КНТ6")->chooseHead(st1);
    st1.addmark(6);
    st1.addmark(3);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после добавления студента"<<endl;
    deanary.getStatistics();
    deanary.saveStaff("save.txt");
    //cout<<deanary.GetGroup("23КНТ6")->isEmpty()<<endl;//проверка на пустоту группы
    //cout<<deanary.GetGroup("23КНТ6")->Contains_Student(st1.Get_fio())<<endl;//проверка на наличие студента в группе
    Student st2(32,"Долгов Олег Васильевич");
    deanary.GetGroup("23КНТ4")->addStudent(st2);
    st2.addToGroup(deanary.GetGroup("23КНТ4"));
    deanary.initHeads(st2);
    st2.addmark(3);
    st2.addmark(7);
    st2.addmark(10);
    //cout<<st2.isHeadOfGroup()<<endl;//проверка является ли студент
    //cout<<deanary.GetGroup("23КНТ6")->Get_Fio_Head()<<endl;//вывод ФИО старосты
    //cout<<deanary.GetGroup("23КНТ4")->Get_Fio_Head()<<endl;//вывод ФИО старосты
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после добавления студента"<<endl;
    deanary.getStatistics();
    deanary.saveStaff("save.txt");//this file is placed in cmake-build-debug
    Student st3(33,"Елесеева Ольга Романовна");
    deanary.GetGroup("23КНТ6")->addStudent(st3);
    st3.addToGroup(deanary.GetGroup("23КНТ6"));
    deanary.addMarksToAll();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после добавления студента"<<endl;
    deanary.getStatistics();
    vector<Student*>movsts;
    movsts.push_back(&st1);
    movsts.push_back(&st3);
    deanary.moveStudents(*(deanary.GetGroup("23КНТ4")),movsts);//Dright
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после перемещения студентов"<<endl;
    deanary.getStatistics();
    //cout<<deanary.GetGroup("23КНТ4")->Find_student(st1.Get_ID())->Get_fio()<<endl;//проверка функции нахождения студента в группе
    deanary.GetGroup("23КНТ4")->removeStudent(st1.Get_ID());//right
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после удаления студента"<<endl;
    deanary.getStatistics();
    deanary.saveStaff("save.txt");
    Student st4(34,"Телегин Георгий Михайлович");
    deanary.GetGroup("23КНТ6")->addStudent(st4);
    st4.addToGroup(deanary.GetGroup("23КНТ6"));
    st4.addmark(3);
    st4.addmark(1);
    st4.addmark(2);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после добавления студента"<<endl;
    deanary.getStatistics();
    deanary.fireStudents();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после удаления неуспешных студентов"<<endl;
    deanary.getStatistics();
    Student st5(35,"Полов Клим Павлович");
    deanary.GetGroup("23КНТ2")->addStudent(st5);
    st5.addToGroup(deanary.GetGroup("23КНТ2"));
    st5.addmark(4);
    st5.addmark(5);
    st5.addmark(0);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после добавления студента"<<endl;
    deanary.getStatistics();
    deanary.Delete_St_Low_Mark(st5);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Проверка информации о студентах после удаления студента за неуспеваемость"<<endl;
    deanary.getStatistics();
    deanary.saveStaff("save.txt");

}
