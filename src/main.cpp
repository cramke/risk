#include "main.h"

int main() {
    pqxx::connection c("dbname=some_postgis user=postgres password=postgis port=5432");
    std::cout << "Something worked.";
    if (c.is_open())
        std::cout << "Opened database successfully: " << c.dbname() << std::endl;
    else
        std::cout << "Can't open database" << std::endl;

    std::cout << "Hello Risk!" << std::endl;
}