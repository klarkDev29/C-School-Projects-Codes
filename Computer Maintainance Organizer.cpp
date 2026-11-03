
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

struct RepairRecord
{
    string ticketNumber;
    string computerID;
    string laboratory;
    string problem;
    string reportDate;
    string status;
};

const string FILE_NAME = "repairs.txt";
vector<RepairRecord> repairs;

string cleanField(string value)
{

    for (int i = 0; i < (int)value.length(); i++)
    {
        if (value[i] == '|')
        {
            value[i] = '/';
        }
    }
    return value;
}

void saveRecords()
{
    ofstream file(FILE_NAME.c_str());

    for (int i = 0; i < (int)repairs.size(); i++)
    {
        file << cleanField(repairs[i].ticketNumber) << "|"
             << cleanField(repairs[i].computerID) << "|"
             << cleanField(repairs[i].laboratory) << "|"
             << cleanField(repairs[i].problem) << "|"
             << cleanField(repairs[i].reportDate) << "|"
             << cleanField(repairs[i].status) << "\n";
    }

    file.close();
}


void wipeAllData()
{
    repairs.clear();
    remove(FILE_NAME.c_str());
}

string getInput(string prompt)
{
    string value;
    cout << prompt;
    getline(cin, value);

    while (value.empty())
    {
        cout << "This field cannot be empty. Please enter again: ";
        getline(cin, value);
    }

    return cleanField(value);
}


bool repeatOrReturn(string repeatText)
{
    cout << "\n--------------------------------------------\n";
    cout << "1. " << repeatText << "\n";
    cout << "2. Return to Main Menu\n";
    string choice = getInput("Enter choice (1-2): ");

    while (choice != "1" && choice != "2")
    {
        choice = getInput("Invalid choice. Please enter 1 or 2: ");
    }

    return choice == "1";
}


void waitForMainMenu()
{
    string choice;
    cout << "\n--------------------------------------------\n";
    cout << "Enter 0 to return to the Main Menu: ";
    getline(cin, choice);

    while (choice != "0")
    {
        cout << "Invalid input. Enter 0 to return to the Main Menu: ";
        getline(cin, choice);
    }
}

string makeTicketNumber()
{
    int highestNumber = 0;

    for (int i = 0; i < (int)repairs.size(); i++)
    {
        string ticket = repairs[i].ticketNumber;
        if (ticket.length() > 1 && ticket[0] == 'R')
        {
            try
            {
                int number = stoi(ticket.substr(1));
                if (number > highestNumber)
                {
                    highestNumber = number;
                }
            }
            catch (...)
            {

            }
        }
    }

    stringstream ss;
    ss << "R" << setw(3) << setfill('0') << highestNumber + 1;
    return ss.str();
}

void showRecord(const RepairRecord &record)
{
    cout << "\nTicket Number : " << record.ticketNumber
         << "\nComputer ID   : " << record.computerID
         << "\nLaboratory    : " << record.laboratory
         << "\nProblem       : " << record.problem
         << "\nReport Date   : " << record.reportDate
         << "\nStatus        : " << record.status << "\n";
}



void reportProblem()
{
    RepairRecord record;
    record.ticketNumber = makeTicketNumber();

    cout << "\n--- Report a Computer Problem ---\n";
    cout << "New Ticket Number: " << record.ticketNumber << "\n";
    record.computerID = getInput("Computer ID (example PC-05): ");
    record.laboratory = getInput("Specific Location : ");
    record.problem = getInput("Problem description: ");
    record.reportDate = getInput("Report date (example 2026-11-02): ");
    record.status = "Pending";

    repairs.push_back(record);
    saveRecords();

    cout << "\nProblem reported successfully. The status is Pending.\n";
}

void viewAllRecords()
{
    cout << "\n--- All Repair Records ---\n";

    if (repairs.empty())
    {
        cout << "No repair records found.\n";
        return;
    }

    for (int i = 0; i < (int)repairs.size(); i++)
    {
        cout << "\nRecord " << i + 1;
        showRecord(repairs[i]);
    }
}

void searchRecord()
{
    cout << "\n--- Search Repair Record ---\n";
    string key = getInput("Enter ticket number or computer ID: ");
    bool found = false;

    for (int i = 0; i < (int)repairs.size(); i++)
    {
        if (repairs[i].ticketNumber == key || repairs[i].computerID == key)
        {
            showRecord(repairs[i]);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching repair record found.\n";
    }
}

void updateStatus()
{
    cout << "\n--- Update Repair Status ---\n";
    string ticket = getInput("Enter ticket number: ");
    int index = -1;

    for (int i = 0; i < (int)repairs.size(); i++)
    {
        if (repairs[i].ticketNumber == ticket)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Ticket number not found.\n";
        return;
    }

    cout << "\nCurrent status: " << repairs[index].status << "\n";
    cout << "Choose new status:\n";
    cout << "1. Pending\n";
    cout << "2. In Progress\n";
    cout << "3. Completed\n";
    string choice = getInput("Enter choice (1-3): ");

    // Keep asking until the choice is valid.
    while (choice != "1" && choice != "2" && choice != "3")
    {
        choice = getInput("Invalid status choice. Enter 1, 2, or 3: ");
    }

    if (choice == "1")
    {
        repairs[index].status = "Pending";
    }
    else if (choice == "2")
    {
        repairs[index].status = "In Progress";
    }
    else
    {
        repairs[index].status = "Completed";
    }

    saveRecords();
    cout << "Repair status updated successfully.\n";
}

void viewByStatus(string wantedStatus, string heading)
{
    cout << "\n--- " << heading << " ---\n";
    bool found = false;

    for (int i = 0; i < (int)repairs.size(); i++)
    {
        if (repairs[i].status == wantedStatus)
        {
            showRecord(repairs[i]);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No records with this status were found.\n";
    }
}

// Asks for confirmation before exiting because exiting erases all data.
bool confirmExit()
{
    cout << "\nWARNING: Exiting will permanently erase all repair records.\n";
    string answer = getInput("Are you sure you want to exit? (Y/N): ");

    while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
    {
        answer = getInput("Invalid input. Enter Y or N: ");
    }

    return answer == "Y" || answer == "y";
}

int main()
{
    wipeAllData();
    string choice;
    bool running = true;

    while (running)
    {
        cout << "\n============================================\n";
        cout << " COMPUTER LAB MAINTENANCE AND REPAIR TRACKER\n";
        cout << "============================================\n";
        cout << "1. Report a Computer Problem\n";
        cout << "2. View All Repair Records\n";
        cout << "3. Search Repair Record\n";
        cout << "4. Update Repair Status\n";
        cout << "5. View Pending Repairs\n";
        cout << "6. View Completed Repairs\n";
        cout << "7. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice (1-7): ";
        getline(cin, choice);

        if (choice == "1")
        {
            do
            {
                reportProblem();
            } while (repeatOrReturn("Report another problem"));
        }
        else if (choice == "2")
        {
            viewAllRecords();
            waitForMainMenu();
        }
        else if (choice == "3")
        {
            do
            {
                searchRecord();
            } while (repeatOrReturn("Search again"));
        }
        else if (choice == "4")
        {
            do
            {
                updateStatus();
            } while (repeatOrReturn("Update another ticket"));
        }
        else if (choice == "5")
        {
            viewByStatus("Pending", "Pending Repairs");
            waitForMainMenu();
        }
        else if (choice == "6")
        {
            viewByStatus("Completed", "Completed Repairs");
            waitForMainMenu();
        }
        else if (choice == "7")
        {
            if (confirmExit())
            {
                wipeAllData();
                cout << "\nAll data has been erased. Thank you for using the system.\n";
                running = false;
            }
        }
        else
        {
            cout << "Invalid menu choice. Please enter a number from 1 to 7.\n";
        }
    }

    return 0;
}
