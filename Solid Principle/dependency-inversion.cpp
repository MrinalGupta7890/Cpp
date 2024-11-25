// DDDDDD - Dependency Inversion Principle (DIP) - High-level modules should not depend on low-level modules. Both should depend on abstractions.

// Before DIP:

#include <iostream>

class MySQLDatabase {
public:
    void connect() {
        std::cout << "Connected to MySQL database." << std::endl;
    }
};

class Application {  //Application class is tightly coupled to the MySQLDatabase
private:
    MySQLDatabase db; // Direct dependency on a low-level module
public:
    void run() {
        db.connect(); // Tightly coupled to MySQL
    }
};

int main() {
    Application app;
    app.run(); // Connects to MySQL directly

    return 0;
}


// Explanation: - In this example, the Application class directly depends on the MySQLDatabase class. This tight coupling makes it difficult to switch to another database (e.g., PostgreSQL) without modifying the Application code. If we want to use a different database, we need to change the implementation of Application, which violates the Dependency Inversion Principle. The principle states that high-level modules should not depend on low-level modules; both should depend on abstractions.





// After DIP:

#include <iostream>

class IDataSource {
public:
    virtual void connect() = 0; // High-level interface
};

class MySQLDataSource : public IDataSource {
public:
    void connect() override {
        std::cout << "Connected to MySQL database." << std::endl;
    }
};

class PostgreSQLDataSource : public IDataSource {
public:
    void connect() override {
        std::cout << "Connected to PostgreSQL database." << std::endl;
    }
};

class Application {
private:
    IDataSource* db; // Dependency on an abstraction
public:
    Application(IDataSource* dataSource) : db(dataSource) {} // Dependency injection

    void run() {
        db->connect(); // Uses the abstraction
    }
};

int main() {
    MySQLDataSource mysqlDb;
    Application app(&mysqlDb); // Can easily switch to another data source
    app.run();

    return 0;
}

// Explanation: -  Here, we introduce an interface IDataSource, which acts as an abstraction layer for any data source. The Application class now depends on this interface rather than a concrete implementation. This allows us to inject any data source (e.g., MySQLDataSource, PostgreSQLDataSource) at runtime, adhering to the DIP.