#include "main.h"

int main() {
    pqxx::connection c("dbname=postgres user=postgres password=postgis host=172.17.0.2 port=5432");
    std::cout << "Something worked.";
    if (c.is_open())
        std::cout << "Opened database successfully: " << c.dbname() << std::endl;
    else
        std::cout << "Can't open database" << std::endl;

    std::cout << "Hello Risk!" << std::endl;
}