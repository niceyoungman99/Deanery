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
      cout << "Создана группа: " << group->GetTitle() << endl;
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
      if (!data.empty()) {
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
                st->AddMark(grade);
              }

            }
            st->AddToGroup(groups[i]);
            groups[i]->AddStudent(*st);
            quantity = true;
            break;
          }
        }
        if (quantity == false) {
          cout << "Группы данного студента нет в файле" << endl;
        }
      }
    }

  }
  our_file.close();
}

void Deanery::addMarksToAll() {

  for (Group *group : this->groups) {
    for (Student *student : group->GetStudentUrls()) {
      int x = rand() % (rand() % 11 + 1);
      student->AddMark(rand() % 11);
    }
  }

}
void Deanery::moveStudents(Group &new2, vector<Student *> &moving_sts) {
  for (int i = 0; i < moving_sts.size(); i++) {
    if (new2.FindStudent(moving_sts[i]->GetID()) == nullptr
        && moving_sts[i]->GetGroup()->GetTitle() != new2.GetTitle()) {
      new2.AddStudent(*moving_sts[i]);
      moving_sts[i]->GetGroup()->RemoveStudent(moving_sts[i]->GetID());
      moving_sts[i]->AddToGroup(&new2);
    } else {
      //cout << "Студент " << moving_sts[i]->Get_fio() << " уже находится в этой группе" << endl;
    }
  }
}

void Deanery::Delete_St_Low_Mark(Student &st) {
  if (st.GetAverageMark() < 3.5) {
    st.GetGroup()->RemoveStudent(st.GetID());
    //cout<<"Студент: "<<st.Get_fio()<<" был отчислен за неуспеваемость"<<endl;
  } else {
    //cout << "Студент"<<st.Get_fio()<< " имеет удовлетворительный средний балл" << endl;
  }
}

void Deanery::initHeads(vector<int> ids) {//what is this goal?
  for (int i = 0; i < ids.size(); i++) {
    for (int j = 0; j < groups.size(); j++) {
      for (int k = 0; k < groups[j]->GetStudentUrls().size(); k++) {
        if (ids[i] == groups[j]->GetStudentUrls()[k]->GetID()) {
          groups[j]->ChooseHead(*groups[j]->GetStudentUrls()[k]);
        }
      }
    }
  }
}

void Deanery::saveStaff(const std::string &newstfile) {
  std::ofstream file(newstfile);
  if (file.fail()) {
    cout << "Ошибка открытия файла" << endl;
    return;
  } else {
    for (int i = 0; i < groups.size(); i++) {
      for (int j = 0; j < groups[i]->GetStudentUrls().size(); j++) {
        file << groups[i]->GetStudentUrls()[j]->GetID() << " "
             << groups[i]->GetStudentUrls()[j]->GetFIO() << " " << groups[i]->GetTitle() << " "
             << groups[i]->GetStudentUrls()[j]->GetListOfMarks() << endl;
      }
    }
  }
  file.close();
  //cout << "Информация успешно занесена в файл" << endl;//файл находится в папке cmake-build-debug

}

void Deanery::getStatistics() {
  for (int i = 0; i < groups.size(); i++) {
    if (groups[i]->IsEmpty()) {
      cout << "Группа " << groups[i]->GetTitle()
           << " не представляет никакой информационной ценности по причине пустоты" << endl;
      return;
    }
    cout << "Название группы: " << groups[i]->GetTitle() << endl;
    cout << "Специальность данной группы: " << groups[i]->GetSpec() << endl;
    cout << "Количество студентов в данной группе: " << groups[i]->GetStudentUrls().size() << endl;
    cout << "Староста группы: " << groups[i]->GetHeadFio() << endl;
    cout << "Средняя оценка группы: " << groups[i]->GetAverageMark() << endl;
    for (int j = 0; j < groups[i]->GetStudentUrls().size(); j++) {
      cout << "Id: " << groups[i]->GetStudentUrls()[j]->GetID() << " ФИО: "
           << groups[i]->GetStudentUrls()[j]->GetFIO() << " Название группы: " << groups[i]->GetTitle()
           << endl;
      cout << " Средняя оценка данного студента: " << groups[i]->GetStudentUrls()[j]->GetAverageMark()
           << " Список оценок: " << groups[i]->GetStudentUrls()[j]->GetListOfMarks() << endl;
    }

  }
}

Deanery::~Deanery() {
  this->groups.clear();
}

string Deanery::fireStudents() {
  stringstream output;

  for (int i = 0; i < groups.size(); i++) {
    for (int j = groups[i]->GetStudentUrls().size() - 1; j >= 0; j--) {
      if (groups[i]->GetStudentUrls()[j]->GetAverageMark() < 3.5) {
        cout << "Студент: " << groups[i]->GetStudentUrls()[j]->GetFIO() << " был отчислен из группы "
             << groups[i]->GetStudentUrls()[j]->GetGroup()->GetTitle() << " за плохую успеваемость со средним баллом: "
             << groups[i]->GetStudentUrls()[j]->GetAverageMark() << endl;
        groups[i]->RemoveStudent(groups[i]->GetStudentUrls()[j]->GetID());
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