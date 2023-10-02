//
// Created by Admin on 30.09.2023.
//

#ifndef BD_1_BD_HANDLER_H
#define BD_1_BD_HANDLER_H

#include <string>
#include <map>

struct Data{
    std::string name;
    int age;
    std::string sex;
    std::string occupation;
};

void menu();

class BD_Handler {
private:
    std::string filename;
    std::map<int, Data> data;
public:
    BD_Handler();
    BD_Handler(std::string filename);
    void addDataFromFile(int id, Data& data);
    void addDataFromConsole(int id);
    bool deleteData(int id);
    void deleteAllData();
    bool updateData(int id);
    Data& getDataById(int id);
    void writeDataToFile(const std::string& other_filename);
    void printData();
};

#endif //BD_1_BD_HANDLER_H
