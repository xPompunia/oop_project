#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        conn = driver->connect("tcp://127.0.0.1:3306", "root", "Krzysiu13");

        conn->setSchema("library");

        // Execute a simple query
        sql::Statement *stmt = conn->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * from books");

        // Display results
        while (res->next()) {
            std::cout << "Book ID: " << res->getInt("id") << ", Title: " << res->getString("title") << std::endl;
        }

        // Clean up
        delete res;
        delete stmt;
        delete conn;
    }
    catch (sql::SQLException &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
