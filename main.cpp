#include <iostream>
#include <fstream>
#include <sstream>
#include "BD_Handler.h"

int main() {
    BD_Handler bd_handler;
    Data data;
    menu();
    int choice;
    std::cin >> choice;
    while (choice != 9){
        switch (choice) {
            case 1:{
                std::cout << "Enter file name: ";
                std::string filename;
                std::cin >> filename;
                std::cout << std::endl;
                std::fstream file(filename, std::fstream::in);
                if(!file.is_open()){
                    std::cout << "ERROR: File is not open" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                else{
                    std::string line;
                    std::getline(file, line);
                    while(std::getline(file, line)){
                        std::stringstream ss(line);
                        std::string id;
                        std::getline(ss, id, ',');
                        std::string name;
                        std::getline(ss, name, ',');
                        std::string age;
                        std::getline(ss, age, ',');
                        std::string sex;
                        std::getline(ss, sex, ',');
                        std::string occupation;
                        std::getline(ss, occupation, ',');
                        data.name = name;
                        data.age = std::stoi(age);
                        data.sex = sex;
                        data.occupation = occupation;
                        bd_handler.addDataFromFile(std::stoi(id), data);
                    }
                }
                file.close();
                break;
            }
            case 2:{
                std::cout << "Enter number of rows: ";
                int count;
                std::cin >> count;
                std::cout << std::endl;
                for(int i = 0; i < count; i++){
                    int id;
                    std::cout << "Enter id: ";
                    std::cin >> id;
                    std::cout << std::endl;
                    bd_handler.addDataFromConsole(id);
                }
                break;
            }
            case 3:{
                int id;
                std::cout << "Enter id: ";
                std::cin >> id;
                if(bd_handler.deleteData(id)){
                    std::cout << "Row was deleted" << std::endl;
                }
                break;
            }
            case 4:{
                bd_handler.deleteAllData();
                std::cout << "Data was deleted" << std::endl;
                break;
            }
            case 5:{
                int id;
                std::cout << "Enter id: ";
                std::cin >> id;
                if(bd_handler.updateData(id)) {
                    std::cout << "Row was updated" << std::endl;
                }
                break;
            }
            case 6:{
                int id;
                std::cout << "Enter id: ";
                std::cin >> id;
                Data temp_data = bd_handler.getDataById(id);
                std::cout << temp_data.name << ' ' << temp_data.age
                << ' ' << temp_data.sex << ' ' << temp_data.occupation << std::endl;
                break;
            }
            case 7:{
                std::string filename;
                std::cout << "Enter file name: ";
                std::cin >> filename;
                std::cout << std::endl;
                bd_handler.writeDataToFile(filename);
                break;
            }
            case 8:{
                bd_handler.printData();
                break;
            }
            default:{
                std::cout << "ERROR: Wrong choice" << std::endl;
                break;
            }
        }
        menu();
        std::cin >> choice;
    }
    return 0;
}