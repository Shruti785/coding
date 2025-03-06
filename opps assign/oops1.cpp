#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
//#include<bits/stdc++.h>
using namespace std;

// Structure to represent an expense
struct Expense {
    string category;
    double amount;
};

class PersonalFinanceManager {
private:
    vector<Expense> expenses;
    double budget;
    string expenseFilePath;

public:
    PersonalFinanceManager(double initialBudget, const string& filePath) : budget(initialBudget), expenseFilePath(filePath) {}

    // Add an expense to the list
    void addExpense(const string& category, double amount) {
        expenses.push_back({category, amount});
        saveExpensesToFile();
    }

    // Calculate total expenses
    double getTotalExpenses() const {
        double total = 0.0;
        for (const Expense& expense : expenses) {
            total += expense.amount;
        }
        return total;
    }

    // Display expenses
    void displayExpenses() {
        loadExpensesFromFile(); // Load expenses from file
        cout << "Expense Summary:" << endl;
        for (const Expense& expense : expenses) {
            cout << setw(15) << left << expense.category << ": Rs." << expense.amount << endl;
        }
        cout << "---------------------" << endl;
        cout << "Total Expenses: Rs." << getTotalExpenses() << endl;
        cout << "Remaining Budget: Rs." << budget - getTotalExpenses() << endl;
    }

    // Set budget
    void setBudget(double newBudget) {
        budget = newBudget;
    }

    // Save expenses to file
    void saveExpensesToFile() const {
        ofstream file(expenseFilePath);
        if (file.is_open()) {
            for (const Expense& expense : expenses) {
                file << expense.category << "," << expense.amount << endl;
            }
            file.close();
        } else {
            cout << "Error: Unable to save expenses to file." << endl;
        }
    }

    // Load expenses from file
    void loadExpensesFromFile() {
        ifstream file(expenseFilePath);
        if (file.is_open()) {
            expenses.clear(); // Clear existing expenses
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                if (pos != string::npos) {
                    string category = line.substr(0, pos);
                    double amount = stod(line.substr(pos + 1));
                    expenses.push_back({category, amount});
                }
            }
            file.close();
        } else {
            cout << "Error: Unable to open expense file." << endl;
        }
    }

    // Get expense file path
    string getExpenseFilePath() const {
        return expenseFilePath;
    }
};

class VirtualAssistant {
private:
    char password[20];
    PersonalFinanceManager financeManager;
    string bookPath;

    void datetime() {
        time_t now = time(0);
        char *dt = ctime(&now);
        cout << "The date and time is " << endl << dt << endl;
    }

    void saveReminder(string reminder) {
        ofstream file("reminders.txt", ios::app);
        if (file.is_open()) {
            file << reminder << endl;
            file.close();
            cout << "Reminder saved successfully!" << endl;
        } else {
            cout << "Error: Unable to save reminder." << endl;
        }
    }

    void listReminders() {
        ifstream file("reminders.txt");
        if (file.is_open()) {
            string line;
            cout << "Your reminders:" << endl;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "You have no reminders." << endl;
        }
    }

public:
    VirtualAssistant(double initialBudget, const string& book, const string& expenseFile) : financeManager(initialBudget, expenseFile), bookPath(book) {}

    void welcome() {
        cout << "<============================================= W E L C O M E ==========================================>" << endl;
        cout << "<============================================= I'M A VIRTUAL ASSISTANT ==========================================>" << endl;
        cout << "<============================================= MY NAME IS ROXY ==========================================>" << endl;
        cout << "<============================================= I'M HERE TO HELP YOU ==========================================>" << endl
             << endl;
    }

    void setPassword() {
        cout << "========================" << endl;
        cout << "| ENTER YOUR PASSWORD  |" << endl;
        cout << "========================" << endl
             << endl;
        cout << "Enter your password: ";
        cin.getline(password, sizeof(password));
    }

    void speak(string phrase) {
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }

    bool authenticate() {
        return strcmp(password, "donkey") == 0;
    }

    void greet() {
        time_t now = time(0);
        tm *time = localtime(&now);

        if (time->tm_hour < 12)
            speak("Good Morning Sir");
        else if (time->tm_hour >= 12 && time->tm_hour <= 16)
            speak("Good Afternoon Sir");
        else
            speak("Good Evening Sir");
    }

    void processCommand() {
        char ch[100];

        do {
            cout << "\n<==================================================================================================>\n\n";
            cout << endl
                 << "How can I help you Sir...." << endl
                 << endl;
            speak("How can I help you Sir");

            cout << "Your query ===> ";
            cin.getline(ch, sizeof(ch));
            cout << endl;
            cout << "Here is the result for your query ===> ";

            if (strcmp(ch, "hi") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0) {
                cout << "Hello Sir....." << endl;
                speak("Hello Sir");
            } else if (strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0) {
                cout << "Good Bye sir, have a nice day!!!!" << endl;
                speak("Good Bye sir, have a nice day");
                exit(0);
            } else if (strcmp(ch, "who are you") == 0 || strcmp(ch, "tell me about yourself") == 0 || strcmp(ch, "about") == 0) {
                cout << "I'm a virtual assistant !!!" << endl;
                speak("I am a virtual assistant !!!");
            } else if (strcmp(ch, "how are you") == 0 || strcmp(ch, "whatsup") == 0 || strcmp(ch, "how is your day") == 0) {
                cout << "I'm good sir, tell me how can I help you.." << endl;
                speak("I'm good sir, tell me how can I help you");
            } else if (strcmp(ch, "time") == 0 || strcmp(ch, "date") == 0) {
                datetime();
            } else if (strcmp(ch, "open notepad") == 0) {
                cout << "opening notepad....." << endl;
                speak("opening notepad");
                system("start notepad.exe");
            } else if (strcmp(ch, "open google") == 0) {
                cout << "opening google....." << endl;
                speak("opening google");
                system("start https://www.google.com");
            } else if (strcmp(ch, "open youtube") == 0) {
                cout << "opening YouTube....." << endl;
                speak("opening youtube");
                system("start https://www.youtube.com");
            } else if (strcmp(ch, "open instagram") == 0) {
                cout << "opening instagram....." << endl;
                speak("opening instagram");
                system("start https://www.instagram.com");
            } else if (strcmp(ch, "set reminder") == 0) {
                string reminder;
                cout << "Enter your reminder: ";
                getline(cin, reminder);
                saveReminder(reminder);
            } else if (strcmp(ch, "list reminders") == 0) {
                listReminders();
            } else if (strcmp(ch, "manage finances") == 0) {
                manageFinances();
            } else if (strcmp(ch, "open book") == 0) {
                openBook();
            } else {
                cout << "Sorry could not understand your query please try again !!!" << endl;
                speak("Sorry could not understand your query please try again");
            }
        } while (true);
    }

    void openBook() {
        cout << "Opening the specified book..." << endl;
        speak("opening the specified book");
        system(("start " + bookPath).c_str());
    }

    void manageFinances() {
        char choice;
        do {
            cout << "\nFinances Management:" << endl;
            cout << "1. Add Expense" << endl;
            cout << "2. View Expenses" << endl;
            cout << "3. Set Budget" << endl;
            cout << "4. Open Expense File" << endl;
            cout << "5. Back to main menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // Clear input buffer

            switch (choice) {
                case '1': {
                    string category;
                    double amount;
                    cout << "Enter expense category: ";
                    getline(cin, category);
                    cout << "Enter expense amount: ";
                    cin >> amount;
                    financeManager.addExpense(category, amount);
                    break;
                }
                case '2':
                    financeManager.displayExpenses();
                    break;
                case '3': {
                    double budget;
                    cout << "Enter new budget amount: ";
                    cin >> budget;
                    financeManager.setBudget(budget);
                    break;
                }
                case '4':
                    openExpenseFile();
                    break;
                case '5':
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (true);
    }

    void openExpenseFile() {
        cout << "Opening expense file..." << endl;
        speak("opening expense file");
        system(("start " + financeManager.getExpenseFilePath()).c_str());
    }
};

int main() {
    VirtualAssistant roxy(1000.0, "C:\\Users\\Dell\\Downloads\\Balaguruswamy.pdf", "expenses.txt");
    roxy.welcome();

    do {
        roxy.setPassword();
        if (roxy.authenticate()) {
            cout << "\n<==================================================================================================>\n\n";
            roxy.greet();
            roxy.processCommand();
        } else {
            cout << "\t<============================= W E L C O M E=============================>" << endl;
            cout << "\t<============================= I'M VIRTUAL ASSISTANT =============================>" << endl;
            cout << "\t<============================= MY NAME IS ROXY =============================>" << endl;
            cout << "\t<============================= I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =============================>" << endl
                 << endl;
            cout << "======================" << endl;
            cout << "X Incorrect Password X" << endl;
            cout << "======================" << endl
                 << endl;
        }
    } while (true);

    return 0;
}
