#include <iostream>   // Input/output stream for standard input/output operations
#include <fstream>    // File stream for reading from and writing to files
#include <string>     // String class to manipulate strings
#include <ctime>      // Time functions for date and time manipulation
#include <cstdlib>    // General utilities library for functions such as srand() and rand()
#include <sstream>    // String stream to convert a string to create a string object

using namespace std;

struct TrainInfo {          // Structure is defined for train information.
    string trainno, trainname, source, destination, departime, arrivalt;
    double distance;
    string executiveCoach, economyCoach;
    double executiveFare, economyFare;
};

// Function prototypes
void firstPage();      //or main page
void View_trains();     //to show train details
void modi();         //to modify train details
void View_ticket();   //to show booked ticket details
void retrieve(string sourceStation, string destinationStation);  //retrive train information
void Details();  //to add passengers details
void pnr();       //to generate pnr

// Global variables
string id = "admin"; // Admin username
string password = "password"; // Admin password
string source, destination; 
int choice;                     // choices asked in switch statement.

void firstPage() {   //function for the welcome or main page
    int choice;
    cout << "-------------------------------WELCOME TO IRCTC-------------------------------" << endl;
    cout << "\t\t|\t 1. Admin Mode    \t|" << endl;
    cout << "\t\t|\t 2. User Mode     \t|" << endl;
    cout << "\t\t|\t 3. Exit          \t|" << endl;
    cout << "Select: ";
    cin >> choice;

    switch (choice) {  //to choose from Admin mode/ User mode / Exit
        case 1: {
            int pw = 0, counter = 0;
            cout << "-------------------------------------------------------------------------------------------" << endl;
            cout <<"                       Welcome to Admin Mode                       "<<endl;
            cout << endl;
            string a_id, a_pass;
            cout << "Enter Admin Username : ";
            cin >> a_id;                       // for taking admin id
            if (id == a_id) {
                cout << "\nEnter Admin Password : ";
                cin >> a_pass;                 // for taking admin password
                if (a_pass == password) {  // if password is correct then continue 
                    cout <<endl;
                    cout << " Login Successful !" << endl;
                    int i = 1;
                    while (i) {
                        cout <<endl;
                        cout << " Menu : " << endl;
                        cout << " \t1. View Train" << endl;
                        cout << " \t2. Modify Train" << endl;
                        cout << " \t3. Exit" << endl;
                        int choose;
                        cout <<endl;
                        cout << "Select : "; //to choose from menu :View train/ Modify train/ Exit
                        cin >> choose;
                        switch (choose) {
                            case 1: {
                                View_trains();  //calling function to view train information.
                            }
                            break;
                            case 2: {
                                View_trains();  
                                modi();   //calling function to modify train information.
                            }
                            break;
                            case 3: {
                                i = 0;
                                firstPage(); //go back to main or welcome page.
                            }
                        }
                    }
                } else {
                    cout << "Password is wrong, Please try again !" << endl;
                    firstPage();  // if password is wrong then go to welcome or main page.
                }
            } else {
                cout << "Entered Admin ID is wrong, Please Try Again!" << endl;
                firstPage();  //if admin id is wrong then go to main or welcome page.
            }
            break;
        }
        case 2: {
            int i=1;
            while(i)
            {
                cout << "\n------------------------------------------------------------------------------------------" << endl;
                cout << "                      WELCOME TO USER MODE                     " << endl;
                cout << "\n";
                cout << " Menu : " << endl;
                cout << "\n";
                cout << "\t1. View Trains" << endl;
                cout << "\t2. Book Ticket" << endl;
                cout << "\t3. View Ticket" << endl;
                cout << "\t4. Cancel Ticket" << endl;
                cout << "\t5. Exit" << endl;
                cout << "\n";
                cout << "Select: ";
                cin >> choice;

                switch (choice) //to choose from menu : View Trains/ Book Ticket/ View Ticket/cancel ticket /exit.
                 {
                    case 1:
                     {
                        View_trains();       // funtion is being called to view train information.
                     }
                    break;
                    case 2:      // This case is used to fetch information of source and destination from the text file given
                     {           // and will add personal details and it will also book and generate pnr for ticket.

                        cout << "Enter source station : ";
                        string source, destination;
                        cin.ignore();
                        getline(cin, source);
                        cout << "Enter destination station : ";
                        getline(cin, destination);
                        retrieve(source, destination);
                        Details();
                        pnr();
                    }

                    break;

                    case 3:
                    {
                            View_ticket();   // Function is been called to view booked ticket details given or printed in text file.
                    }
                    break;

                    case 4:
                     {
                         cout << endl;
                         cout << "Sorry Ticket cannot be cancelled, it is NON REFUNDABLE !!" << endl;


                    }
                    break;



                    case 5:                     // exit function.
                     {
                        i=0;
                        firstPage();
                    }
                    break;
                }
            }

        }
        case 3:
         {
            exit(0);
        }
        break;
    }
}

void View_trains() {            // this function is used to show information about train fetched from  the text file.
    ifstream file;
    file.open("Train_schedule.txt");
    string matter;
    while (getline(file, matter)) {
        cout << matter << endl;
    }
    file.close();
}

void modi() {      // function to modify the train information by the admin.
    string searchStr, replaceStr;
    cout << "Enter the string to search for: ";     // string like search and replace has been used to search the given info and modify the same.
    cin.ignore();
    getline(cin, searchStr);
    cout << "Enter the string to replace with: ";
    getline(cin, replaceStr);
    ifstream file("Train_schedule.txt");        // ifstram is used to read from the file.
    string line, modifiedContent;
    if (!file.is_open()) {
        cout << "Unable to open file";
        return;
    }
    while (getline(file, line)) {
        size_t found = line.find(searchStr);
        if (found != string::npos) {
            line.replace(found, searchStr.length(), replaceStr); // Replace search string with replace string
        }
        modifiedContent += line + "\n";
    }
    file.close();
    ofstream outFile("Train_schedule.txt");     // ofstream is used to modify or write into the file.
    if (!outFile.is_open()) {
        cout << "Unable to open file";
        return;
    }
    outFile << modifiedContent;
    outFile.close();
    cout << "Operation done";
}

void View_ticket() {                    // function to show booked ticket details to the user.
    ifstream myticket;
    myticket.open("Print_ticket.txt");  // the ticket details have been fetched from this text file.
    string track;
    while (getline(myticket, track)) {
        cout << track << endl;
    }
    myticket.close();
}

void pnr() {                // function to generate pnr in to the ticket.
    ofstream print("Print_ticket.txt", ios::app);  // ::app is used to modify but not to over-write.
    if (print.is_open()) {
        srand(time(0));
        unsigned long long pnr_number = 0;
        for (int i = 0; i < 10; ++i) {
            pnr_number = pnr_number * 10 + (rand() % 10);   // rand function is used to generate random number.
        }
        cout << endl;
        cout << " Your PNR number is : " << pnr_number;
        cout << endl;
        print << " Your PNR number is : " << pnr_number;
        print.close();
    } else {
        cout << "Unable to open file";
    }
}

void Details() {                   // to get passenger details from the user.
    ofstream print("Print_ticket.txt", ios::app);
    if (print.is_open()) {      // is.open to open the file.
        string name, gender, date;
        int age;
        cout <<endl;
        cout << "\nPassenger's Name : ";
        cin.ignore();
        getline(cin, name);         // getline function is used to read string from the input stream.

        print <<endl;
        print << "Name : " << name;
        cout << endl;
        cout << "Passenger's Age : ";
        cin >> age;
        print << " Age : " << age;
        cout << endl;
        cout << "Passenger's Gender (M / F / U) : ";
        cin >> gender;
        print << " Gender : " << gender;
        cout << endl;
        cout << "Enter the Date of Journey -> (dd/mm/yy) : ";
        cin >> date;
        print << "\t \t   Date of journey : " << date;
        cout << endl;
        print.close();
    }
}

void retrieve(string sourceStation, string destinationStation) {            // this function is used to retrieve data from the files i:e, collect information from  the given text file.
    ofstream print("Print_ticket.txt", ios::app);
    if (print.is_open()) {
        ifstream readsd;
        readsd.open("Train_schedule.txt");
        string line;
        while (getline(readsd, line)) {
            stringstream ss(line);      // is used for flexible input and output operations with strings.
            TrainInfo train;
            ss >> train.trainno >> train.trainname >> train.source >> train.destination >> train.departime >> train.arrivalt >> train.distance >> train.executiveCoach >> train.executiveFare >> train.economyCoach >> train.economyFare;
            if (train.source == sourceStation && train.destination == destinationStation) {     // if the source and destination are correctly prompted then only the data will fetch from the file.
                cout << endl;
                print << endl;
                cout << "Train No : " << train.trainno << endl;
                print << "\n\n\nTrain No : " << train.trainno << endl;
                cout << "\n";
                print << "\n";
                cout << "Train Name : " << train.trainname << endl;
                print << "Train Name : " << train.trainname << endl;
                cout << "\n";
                print << "\n";
                cout << "Your Boarding Station is : " << train.source << endl;
                print << "Your Boarding Station is : " << train.source << endl;
                cout << "\n";
                print << "\n";
                cout << "Your Destination is : " << train.destination << endl;
                print << "Your Destination is : " << train.destination << endl;
                cout << "\n";
                print << "\n";
                cout << "Distance between stations: " << train.distance << " km" << endl;
                print << "Distance between stations: " << train.distance << " km" << endl;
                cout << "\n";
                print << "\n";
                cout << "Train Departure Time will be : " << train.departime << endl;
                print << "Train Departure Time will be : " << train.departime << endl;
                cout << "\n";
                print << "\n";
                cout << "Train Arrival Time will be : " << train.arrivalt << endl;
                print << "Train Arrival Time will be : " << train.arrivalt << endl;
                cout << "\n";
                print << "\n";
                cout << "Select Coach:\n\n1. Executive\n\n2. Economy\n\nSelect : ";
                int choice;
                cin >> choice;
                if (choice == 1 )             // for choosing executive coach.
                {
                    cout <<endl;
                    cout<<"Fare of Executive class is : "<<train.executiveFare;
                    Details();
                    pnr();
                    cout << "\n Your ticket has been booked. Thank you for using, Happy Journey !" << endl;
                    cout << "\n Visit again " << endl;
                    cout << endl;
                    // Ask if user wants to book another ticket
                    char bookAnotherTicket;
                    cout << "Do you want to book another ticket? (y/n): ";
                    cin >> bookAnotherTicket;
                    if (bookAnotherTicket == 'y' || bookAnotherTicket == 'Y') {
                        retrieve(sourceStation, destinationStation); // Call retrieve again for booking another ticket
                    }

                    else{
                        firstPage();
                    }

                }
                if (choice == 2)                // for choosing economy coach.
                {
                    cout <<endl;
                    cout<<"train.executiveFare : "<<train.economyFare;
                    Details();
                    pnr();
                    cout << "\n Your ticket has been booked. Thank you for using, Happy Journey !" << endl;
                    cout << "\n Visit again " << endl;
                    cout << endl;
                    // Ask if user wants to book another ticket
                    char bookAnotherTicket;
                    cout << "Do you want to book another ticket? (y/n): ";
                    cin >> bookAnotherTicket;
                    if (bookAnotherTicket == 'y' || bookAnotherTicket == 'Y') {
                        retrieve(sourceStation, destinationStation); // Call retrieve again for booking another ticket
                    }

                    else{
                        firstPage();
                    }
                }
                 else {
                    cout << "Invalid choice!" << endl;
                }
                cout << endl;
            }
        }
        readsd.close();
        print.close();
    }
}

int main() {            //This is the main function of the whole code where it will call the firstpage function.
    firstPage();        // to display the whole code.
    return 0;
}
