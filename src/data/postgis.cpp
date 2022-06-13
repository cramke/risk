#include "postgis.hpp"

void example() {
    pqxx::connection c("dbname=postgres user=postgres password=postgis host=172.17.0.2 port=5432");
    if (c.is_open())
        std::cout << "Opened database successfully: " << c.dbname() << std::endl;
    else
        std::cout << "Can't open database. Is container running?" << std::endl;

    pqxx::work w(c);
    pqxx::row r = w.exec1("SELECT risk, wkb_geometry FROM some_points WHERE id=1");
    w.commit();
    std::cout << r[0].as<int>() << std::endl;
    std::cout << r[1].as<std::string>() << std::endl;

    std::cout << "Hello Risk!" << std::endl;
}