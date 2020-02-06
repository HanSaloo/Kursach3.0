#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QRegExpValidator>

#define DATABASE_HOSTNAME "ExampleDataBase"
#define DATABASE_NAME "DataBase.db" // ім'я файлу для SQLite

#define TABLE "`List`" // назва бази данних
#define TABLE_NAMES "`Names`" // П.І.П
#define TABLE_DATES "`Dates`" // Дата штрафу
#define TABLE_SUMA "`Suma`" // Сума штрафу

#define DEVICE                  "`List`"
#define DEVICE_NAMES             "`Names`"
#define DEVICE_DATES               "`Dates`"
#define DEVICE_SUMA              "`Suma`"


class DataBase : public QObject {
    Q_OBJECT
public:
    explicit DataBase(QObject *patern = 0);
    ~DataBase();
    void connectToDataBase();
    bool insertIntoTable(const QVariantList &data);

private:
    QSqlDatabase db;
private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
};
#endif
