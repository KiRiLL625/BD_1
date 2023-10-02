#include <sstream>
#include <iostream>
#include <fstream>
#include "BD_Handler.h"

BD_Handler::BD_Handler() {
    this->filename = "BD.csv";
}

BD_Handler::BD_Handler(std::string filename) {
    this->filename = filename;
}

void BD_Handler::addDataFromFile(int id, Data &data){
    auto it = this->data.find(id);
    if (it == this->data.end()){
        this->data.insert(std::pair<int, Data>(id, data));
    }
    else{
        std::cout << "ERROR: The data with this id already exists" << std::endl;
    }
}

void BD_Handler::addDataFromConsole(int id) {
    auto it = this->data.find(id);
    if(it == this->data.end()){
        Data new_data;
        std::cout << "Enter name: ";
        std::cin >> new_data.name;
        std::cout << std::endl;
        std::cout << "Enter age: ";
        std::cin >> new_data.age;
        std::cout << std::endl;
        std::cout << "Enter sex: ";
        std::cin >> new_data.sex;
        std::cout << std::endl;
        std::cout << "Enter occupation: ";
        std::cin >> new_data.occupation;
        std::cout << std::endl;
        this->data.insert(std::pair<int, Data>(id, new_data));
    }
}

bool BD_Handler::deleteData(int id) {
    auto it = this->data.find(id);
    if (it != this->data.end()){
        this->data.erase(it);
        return true;
    }
    else{
        std::cout << "ERROR: The data with this id does not exist" << std::endl;
    }
    return false;
}

void BD_Handler::deleteAllData() {
    this->data.clear();
}

bool BD_Handler::updateData(int id) {
    auto it = this->data.find(id);
    if (it != this->data.end()){
        Data new_data;
        std::cout << "Enter name: ";
        std::cin >> new_data.name;
        std::cout << std::endl;
        std::cout << "Enter age: ";
        std::cin >> new_data.age;
        std::cout << std::endl;
        std::cout << "Enter sex: ";
        std::cin >> new_data.sex;
        std::cout << std::endl;
        std::cout << "Enter occupation: ";
        std::cin >> new_data.occupation;
        std::cout << std::endl;
        this->data[id] = new_data;
        return true;
    }
    else{
        std::cout << "ERROR: The data with this id does not exist" << std::endl;
    }
    return false;
}

Data& BD_Handler::getDataById(int id) {
    auto it = this->data.find(id);
    if(it == this->data.end()){
        throw std::runtime_error("ERROR: The data with this id does not exist");
    }
    return it->second;
}

void BD_Handler::writeDataToFile(const std::string& other_filename) {
    if(other_filename.empty()){
        std::cout << "ERROR: The filename is empty" << std::endl;
        return;
    }
    if(this->data.empty()){
        std::cout << "ERROR: The data is empty" << std::endl;
        return;
    }
    std::ofstream file(other_filename, std::ios::in);
    if(!file.is_open()){
        std::cout << "ERROR: The file is not open" << std::endl;
        return;
    }
    for(const auto& pair: this->data){
        const Data& data = pair.second;
        file << pair.first << ' ' << data.name << ' '
        << data.age << ' ' << data.sex << ' ' << data.occupation << '\n';
    }
    file.close();
}

void BD_Handler::printData() {
    if(this->data.empty()){
        std::cout << "ERROR: The data is empty" << std::endl;
        return;
    }
    for(const auto& pair: this->data){
        const Data& data = pair.second;
        std::cout << pair.first << ' ' << data.name
        << ' ' << data.age << ' ' << data.sex << ' ' << data.occupation << '\n';
    }
}

void menu(){
    std::cout << "1. Add data from file" << std::endl;
    std::cout << "2. Add data from console" << std::endl;
    std::cout << "3. Delete data by id" << std::endl;
    std::cout << "4. Delete all data" << std::endl;
    std::cout << "5. Update data by id" << std::endl;
    std::cout << "6. Get data by id" << std::endl;
    std::cout << "7. Write data to file" << std::endl;
    std::cout << "8. Print data" << std::endl;
    std::cout << "9. Exit" << std::endl;
}


