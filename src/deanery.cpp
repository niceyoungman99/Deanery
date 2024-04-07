#include "deanery.h"

using namespace std;

void Deanery::createGroups(const string &file2) {
    std::locale::global(std::locale("C"));
    std::ifstream our_file(file2);
    if (!our_file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    } else {
        our_file.imbue(std::locale(our_file.getloc(), new std::codecvt_utf8<wchar_t>));
        string gr_name;
        while (our_file >> gr_name) {
            Group *group = new Group(gr_name);
            groups.push_back(group);
            cout <<"Создана группа: " <<group->GetTitle() << endl;
        }
    }
    our_file.close();
}

void Deanery::hireStudents(const string &file1) {
    std::locale::global(std::locale("C"));
    std::ifstream our_file(file1);
    if (!our_file.is_open()) {
        cout << "Ошибка открытия файла" << endl;

    } else {
        our_file.imbue(std::locale(our_file.getloc(), new std::codecvt_utf8<wchar_t>));
        string surname, im, father_im, name, term, data;
        int id;
        while (getline(our_file, data)) {
            std::vector<std::string> info;
            if(!data.empty()){
                std::istringstream type(data);
                while (type >> term) {
                    info.push_back(term);
                }
                id = stoi(info[0]);
                surname = info[1];
                im = info[2];
                father_im = info[3];
                name = info[4];
                std::string fs = surname + " " + im + " " + father_im;
                Student *st = new Student(id, fs);
                bool quantity = false;
                for (int i = 0; i < groups.size(); i++) {
                    if (name == groups[i]->GetTitle()) {
                        for (int g = 5; g < info.size(); g++) {
                            int grade = stoi(info[g]);
                            if (grade >= 0 && grade <= 10) {
                                st->addmark(grade);
                            }

                        }
                        st->addToGroup(groups[i]);
                        groups[i]->addStudent(*st);
                        quantity= true;break;
                    }
                }
                if(quantity== false){
                    cout<<"Группы данного студента нет в файле"<<endl;
                }
            }
            }


    }
    our_file.close();
}

void Deanery::addMarksToAll() {
    srand(time(NULL));
    for (Group* group : this->groups) {
        for (Student* student : group->Get_Dostup_St_urls()) {
            int x = rand() % (rand()% 11+1);
            student->addmark(rand() % 11);
        }
    }

}
void Deanery::moveStudents(Group &new2, vector<Student *>& moving_sts) {
    for (int i = 0; i < moving_sts.size(); i++) {
        if (new2.Find_student(moving_sts[i]->Get_ID()) == nullptr && moving_sts[i]->RetGr()->GetTitle() != new2.GetTitle()) {
            new2.addStudent(*moving_sts[i]);
            moving_sts[i]->RetGr()->removeStudent(moving_sts[i]->Get_ID());
            moving_sts[i]->addToGroup(&new2);
        } else {
            //cout << "Студент " << moving_sts[i]->Get_fio() << " уже находится в этой группе" << endl;
        }
    }
}


void Deanery::Delete_St_Low_Mark(Student &st) {
    if (st.getAveragemark() < 3.5) {
        st.RetGr()->removeStudent(st.Get_ID());
        //cout<<"Студент: "<<st.Get_fio()<<" был отчислен за неуспеваемость"<<endl;
    } else {
        //cout << "Студент"<<st.Get_fio()<< " имеет удовлетворительный средний балл" << endl;
    }
}

void Deanery::initHeads(Student &st) {//what is this goal?
    st.RetGr()->chooseHead(st);
}

void Deanery::saveStaff(const std::string &newstfile) {
    std::ofstream file(newstfile);
    if (file.fail()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    } else {
        for (int i = 0; i < groups.size(); i++) {
            for (int j = 0; j < groups[i]->Get_Dostup_St_urls().size(); j++) {
                file << groups[i]->Get_Dostup_St_urls()[j]->Get_ID() << " "
                     << groups[i]->Get_Dostup_St_urls()[j]->Get_fio() << " " << groups[i]->GetTitle() << " "
                     << groups[i]->Get_Dostup_St_urls()[j]->Get_list_of_marks() << endl;
            }
        }
    }
    file.close();
    //cout << "Информация успешно занесена в файл" << endl;//файл находится в папке cmake-build-debug

}

void Deanery::getStatistics() {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->isEmpty()) {
            cout << "Группа " << groups[i]->GetTitle() << " не представляет никакой информационной ценности по причине пустоты" << endl;
            return;
        }
        cout << "Название группы: " << groups[i]->GetTitle() << endl;
        cout << "Специальность данной группы: " <<groups[i]->getSpec()<<endl;
        cout << "Количество студентов в данной группе: " << groups[i]->Get_Dostup_St_urls().size() << endl;
        cout << "Староста группы: " << groups[i]->Get_Fio_Head() << endl;
        cout << "Средняя оценка группы: " << groups[i]->getAveragemark() << endl;
        for (int j = 0; j < groups[i]->Get_Dostup_St_urls().size(); j++) {
            cout << "Id: " << groups[i]->Get_Dostup_St_urls()[j]->Get_ID() << " ФИО: "
                 << groups[i]->Get_Dostup_St_urls()[j]->Get_fio() << " Название группы: " << groups[i]->GetTitle()
                 << endl;
            cout << " Средняя оценка данного студента: " << groups[i]->Get_Dostup_St_urls()[j]->getAveragemark()
                 << " Список оценок: " << groups[i]->Get_Dostup_St_urls()[j]->Get_list_of_marks() << endl;
        }


    }
}

Deanery::~Deanery() {
    this->groups.clear();
}

string Deanery::fireStudents() {
    stringstream output;

    for (int i = 0; i < groups.size(); i++) {
        for (int j = groups[i]->Get_Dostup_St_urls().size() - 1; j >= 0; j--) {
            if (groups[i]->Get_Dostup_St_urls()[j]->getAveragemark() < 3.5) {
                cout<<"Студент: " << groups[i]->Get_Dostup_St_urls()[j]->Get_fio() << " был отчислен из группы "<<groups[i]->Get_Dostup_St_urls()[j]->RetGr()->GetTitle() <<" за плохую успеваемость со средним баллом: "
                       << groups[i]->Get_Dostup_St_urls()[j]->getAveragemark() << endl;
                groups[i]->removeStudent(groups[i]->Get_Dostup_St_urls()[j]->Get_ID());
            }
        }
    }

    return output.str(); // Возвращаем строку с уведомлениями об исключенных студентах
}


Group *Deanery::GetGroup(const string &ttl) {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->GetTitle() == ttl) {
            return groups[i];
        }
    }
    return nullptr;

}

bool Deanery::FindGroup(const string f) {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->GetTitle() == f) {
            return true;
        }
    }
    return false;
}