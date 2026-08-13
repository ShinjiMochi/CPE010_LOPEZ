#include "Job & Printer.h"

int main() {

    Printer printer;

    printer.addJob(Job(101, "John", 5));
    printer.addJob(Job(102, "Jimmy", 12));
    printer.addJob(Job(103, "James", 8));
    printer.addJob(Job(104, "Jorge", 20));

    printer.displayPendingJobs();

    std::cout << "\nProcessing Jobs...\n";

    printer.processAllJobs();

    return 0;
}

