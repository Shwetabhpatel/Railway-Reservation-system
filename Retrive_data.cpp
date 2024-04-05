void retrieve(string sourceStation, string destinationStation)
{
    ofstream print("Print_ticket.txt", ios::app);
    if (print.is_open())
    {
        ifstream readsd;
        readsd.open("Train_schedule.txt");
        string line;
        while (getline(readsd, line))
        {
            stringstream ss(line);
            TrainInfo train;
            ss >> train.trainno >> train.trainname >> train.source >> train.destination >> train.departime >> train.arrivalt >> train.distance >> train.executiveCoach >> train.executiveFare >> train.economyCoach >> train.economyFare;
            if (train.source == sourceStation && train.destination == destinationStation)
            {
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
                if (choice == 1)
                {
                    cout << endl;
                    cout << "Fare of Executive class is : " << train.executiveFare;
                    Details();
                    pnr();
                    cout << "\n Your ticket has been booked. Thank you for using, Happy Journey !" << endl;
                    cout << "\n Visit again " << endl;
                    cout << endl;
                    // Ask if user wants to book another ticket
                    char bookAnotherTicket;
                    cout << "Do you want to book another ticket? (y/n): ";
                    cin >> bookAnotherTicket;
                    if (bookAnotherTicket == 'y' || bookAnotherTicket == 'Y')
                    {
                        retrieve(sourceStation, destinationStation); // Call retrieve again for booking another ticket
                    }

                    else
                    {
                        firstPage();
                    }
                }
                if (choice == 2)
                {
                    cout << endl;
                    cout << "train.executiveFare : " << train.economyFare;
                    Details();
                    pnr();
                    cout << "\n Your ticket has been booked. Thank you for using, Happy Journey !" << endl;
                    cout << "\n Visit again " << endl;
                    cout << endl;
                    // Ask if user wants to book another ticket
                    char bookAnotherTicket;
                    cout << "Do you want to book another ticket? (y/n): ";
                    cin >> bookAnotherTicket;
                    if (bookAnotherTicket == 'y' || bookAnotherTicket == 'Y')
                    {
                        retrieve(sourceStation, destinationStation); // Call retrieve again for booking another ticket
                    }

                    else
                    {
                        firstPage();
                    }
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
                cout << endl;
            }
        }
        readsd.close();
        print.close();
    }
}