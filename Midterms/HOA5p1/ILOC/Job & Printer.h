#ifndef JOB_PRINTER_H
#define JOB_PRINTER_H

#include "Queue.h"

// ------- Job Class ------- //
class Job {
private:
    int id;
    std::string user;
    int pages;

public:
    Job(int id, std::string user, int pages) {
        this->id = id;
        this->user = user;
        this->pages = pages;
    }

    int getID() const {
        return id;
    }

    std::string getUser() const {
        return user;
    }

    int getPages() const {
        return pages;
    }

    void display() const {
        std::cout << "Job ID: " << id << std::endl;
        std::cout << "User: " << user << std::endl;
        std::cout << "Pages: " << pages << std::endl;
        std::cout << "---------------------" << std::endl;
    }
};

// ------- Printer Class ------- //
class Printer {
private:

    qNode<Job>* front;
    qNode<Job>* back;

public:
    Printer() {

        front = nullptr;
        back = nullptr;
    }

    void addJob(const Job& job) {

        enqueue(job, &front, &back);


        std::cout << "Added Job "
                  << job.getID()
                  << " from "
                  << job.getUser()
                  << std::endl;
    }

    void processJob() {

        if (isEmpty(&front, &back)) {

            std::cout << "No jobs to process."
                      << std::endl;

            return;
        }

        std::cout << "\nPrinting Job..."
                  << std::endl;

        front->data.display();

        dequeue(&front, &back);
    }

    void processAllJobs() {

        while (!isEmpty(&front, &back)) {

            processJob();
        }

        std::cout << "All jobs completed."
                  << std::endl;
    }

    void displayPendingJobs() {

        if (isEmpty(&front, &back)) {

            std::cout << "No pending jobs."
                      << std::endl;

            return;
        }

        qNode<Job>* current = front;

        std::cout << "\nPending Jobs"
                  << std::endl;

        while (current != nullptr) {

            current->data.display();

            current = current->next;
        }
    }
};


#endif 

