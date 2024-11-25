/**
Assignment Task 2: Logging System with Chain of Responsibility Pattern
Objective:
Implement a Logging System that supports multiple levels of logging (e.g., Info, Warning, Error). Use the Chain of Responsibility pattern to pass log messages through different loggers that handle specific log levels.

Chain of Responsibility Pattern should be used to create a chain of loggers, each responsible for a specific log level.

Use advanced C++ features like smart pointers, lambdas, and modern STL.

Requirements:
Create a Logger class with different logging levels (Info, Warning, Error).
Implement a Chain of Responsibility where each logger (InfoLogger, WarningLogger, ErrorLogger) will either process or forward the log message to the next logger in the chain.
Use std::shared_ptr for memory management, std::function for flexible callback functionality, and enum class for type safety.
Demonstrate logging at different levels (Info, Warning, Error) and ensure that each message is passed along the chain appropriately.
 */



#include <iostream>
#include <memory>
#include <string>
#include <functional>

// Step 1: Define Log Levels (enum class)
enum class LogLevel {
    Info,
    Warning,
    Error
};

// Step 2: Define Abstract Logger Interface
class Logger {
protected:
    std::shared_ptr<Logger> nextLogger;  // Next logger in the chain
    LogLevel level;  // Log level for this logger

public:
    virtual ~Logger() = default;

    // Set the next logger in the chain
    void setNext(std::shared_ptr<Logger> next) {
        nextLogger = next;
    }

    // Handle logging or pass it to the next logger in the chain
    virtual void log(LogLevel level, const std::string& message) = 0;
};

// Step 3: Define Concrete Loggers for Each Level

class InfoLogger : public Logger {
public:
    InfoLogger() {
        level = LogLevel::Info;
    }

    void log(LogLevel logLevel, const std::string& message) override {
        if (logLevel == LogLevel::Info) {
            std::cout << "[INFO]: " << message << std::endl;
        } else if (nextLogger) {
            nextLogger->log(logLevel, message);
        }
    }
};

class WarningLogger : public Logger {
public:
    WarningLogger() {
        level = LogLevel::Warning;
    }

    void log(LogLevel logLevel, const std::string& message) override {
        if (logLevel == LogLevel::Warning) {
            std::cout << "[WARNING]: " << message << std::endl;
        } else if (nextLogger) {
            nextLogger->log(logLevel, message);
        }
    }
};

class ErrorLogger : public Logger {
public:
    ErrorLogger() {
        level = LogLevel::Error;
    }

    void log(LogLevel logLevel, const std::string& message) override {
        if (logLevel == LogLevel::Error) {
            std::cout << "[ERROR]: " << message << std::endl;
        } else if (nextLogger) {
            nextLogger->log(logLevel, message);
        }
    }
};

// Step 4: Main function to test the Chain of Responsibility

int main() {
    // Create instances of different loggers
    auto infoLogger = std::make_shared<InfoLogger>();
    auto warningLogger = std::make_shared<WarningLogger>();
    auto errorLogger = std::make_shared<ErrorLogger>();

    // Set up the chain of responsibility
    infoLogger->setNext(warningLogger);
    warningLogger->setNext(errorLogger);

    // Log messages at different levels
    std::cout << "Logging Info Message:" << std::endl;
    infoLogger->log(LogLevel::Info, "This is an informational message.");

    std::cout << "\nLogging Warning Message:" << std::endl;
    infoLogger->log(LogLevel::Warning, "This is a warning message.");

    std::cout << "\nLogging Error Message:" << std::endl;
    infoLogger->log(LogLevel::Error, "This is an error message.");

    return 0;
}
