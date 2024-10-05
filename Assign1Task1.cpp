#include <iostream>
#include <string>
using namespace std;

class Process {
public:
    int process_id;
    int execution_time;
    int remaining_time;
    Process* next;

    Process(int id, int ex_time) {
        process_id = id;
        execution_time = ex_time;
        remaining_time = ex_time;
        next = nullptr;
    }
};

class ProcessScheduler {
private:
    Process* head;
    int CPUtime;
    int cycle;
    int countProcess;

public:

    ProcessScheduler(int time) {
        head = nullptr;
        CPUtime = time;
        cycle = 0;
        countProcess = 0;
    }

    int get_CPUtime() const {
        return CPUtime;
    }

    void add_process(int process_id, int execution_time) {
        Process* newProcess = new Process(process_id, execution_time);
        countProcess++;

        if (head == nullptr) {
            head = newProcess;
            newProcess->next = head; //circular linked list
        }
        else {
            Process* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newProcess;
            newProcess->next = head;
        }

        cout << "New process arrives: P" << process_id << " (Remaining: " << execution_time << ")" << endl;
    }

    void remove_Process(Process* process) {
        if (head == head->next) {
            head = nullptr;
        }
        else {
            Process* temp = head;
            while (temp->next != process) {
                temp = temp->next;
            }

            temp->next = process->next;
            if (process == head) {
                head = process->next;
            }
        }

        countProcess--;
        delete process;
    }

    

    void schedule() {
        if (!head) return; //if there's no process, exit
        Process* current = head;

        while (current && countProcess > 0) {
            cycle++;
            cout << "\nCycle " << cycle << ": " << endl;

            string cycleOutput;
            Process* start = current;

            //first, print the remaining times of all processes in the cycle
            do {
                int remaining = max(0, current->remaining_time - CPUtime);
                cycleOutput += "P" + to_string(current->process_id) + "(Remaining: " + to_string(remaining) + ")";

                //reduce remaining time by CPU time 
                if (current->remaining_time > CPUtime) {
                    current->remaining_time -= CPUtime;
                }
                else {
                    current->remaining_time = 0;
                }

                current = current->next;

                if (current != start) {
                    cycleOutput += ", ";
                }

            } while (current != start);

            cout << cycleOutput;

            //check for completed processes after printing remaining times
            current = start;  //reset current to the start of the cycle

            do {
                if (current->remaining_time == 0) {
                    cout << "\nProcess P" << current->process_id << " completed.";
                    Process* remProcess = current;
                    current = current->next;
                    remove_Process(remProcess);
                    if (countProcess == 0) {
                        break;
                    }
                    if (remProcess == head) {
                        head = current;
                    }
                }
                else {
                    current = current->next;
                }

            } while (current != start);
        }
    }
};

int main() {
    ProcessScheduler scheduler(3);  //CPU time = 3 
    cout << "Initial Processes: [(P1, 10), (P2, 5), (P3, 8)]\n";
    cout << "CPU Time per Process per Cycle: " << scheduler.get_CPUtime() << endl << endl;

    //adding initial processes
    scheduler.add_process(1, 10);
    scheduler.add_process(2, 5);
    scheduler.add_process(3, 8);

    //start scheduling
    scheduler.schedule();

    //simulating a new process arriving in cycle 2
    scheduler.add_process(4, 9);

    //continue scheduling after new process arrives
    scheduler.schedule();

    return 0;
}
