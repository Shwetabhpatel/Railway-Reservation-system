void Details()
{
    ofstream print("Print_ticket.txt", ios::app);
    if (print.is_open())
    {
        string name, gender, date;
        int age;
        cout << endl;
        cout << "\nPassenger's Name : ";
        cin.ignore();
        getline(cin, name);

        print << endl;
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