#include <QCoreApplication>
#include <ctime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <cstdlib>
#include <cstdint>
#include <fstream>

#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
srand(static_cast<unsigned int>(time(nullptr)));
QFile file("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/random_numbers_3.txt");
    if (!file.open(QFile::WriteOnly | QFile::Truncate)) {
        qWarning() << "Failed to open file";
        return 1;
    }

    QTextStream out(&file);

    for (int i = 0; i < 10105; ++i) {
        uint64_t num = (uint64_t)rand() * (uint64_t)RAND_MAX + rand();
        out << num << endl;
    }

    file.close();
std::cout << "Сгенерировано." << std::endl;
    return a.exec();
}
