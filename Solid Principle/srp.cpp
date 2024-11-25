// SSSSSSSS - Single Responsibility Principle (SRP) - A class should have one, and only one, reason to change. This means that a class should have a single responsibility or job.


#include <iostream>
#include <string>

class GenerateReport {
public:
    void GenerateReport() {
        // Generate report content
        std::cout << "Report content generated." << std::endl;
    }

    void printReport() {
        // Print report
        std::cout << "Printing report..." << std::endl;
    }
};

int main() {
    Report report;
    report.generateReport();
    report.printReport();

    return 0;
}

// Explanation - The Report class handles both generating and printing reports, which violates the SRP. If printing logic needs to change, it will affect the Report class, making maintenance harder.


// After SRP:

#include <iostream>
#include <string>

class Report {
public:
    std::string generateReport() {
        return "Report content generated.";
    }
}; 


class ReportPrinter {
public:
    void print(const std::string& content) {
        std::cout << "Printing: " << content << std::endl;
    }
};

int main() {
    Report report;
    ReportPrinter printer;

    std::string content = report.generateReport();
    printer.print(content);

    return 0;
}


// Explanation: Now, Report is only responsible for generating the report, and ReportPrinter is responsible for printing. This separation makes the code easier to maintain, as changes to printing won’t affect report generation.

