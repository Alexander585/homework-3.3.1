#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct Address {
    std::string city;
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;
};

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return 1;
    }

    int n;
    inputFile >> n; 
    inputFile.ignore(); 

    std::vector<Address> address(n);

    
    for (int i = 0; i < n; ++i) {
        std::getline(inputFile, address[i].city);
        std::getline(inputFile, address[i].street);

        std::getline(inputFile, address[i].houseNumber);
        std::getline(inputFile, address[i].apartmentNumber);
    }

    
    outputFile << n << std::endl;

    
    for (int i = n - 1; i >= 0; --i) {
        outputFile 
            << address[i].city << ", "

            << address[i].street << ", "
            << address[i].houseNumber << ", "
            << address[i].apartmentNumber << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}