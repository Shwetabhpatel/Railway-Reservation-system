void firstPage()
{
    int choice;
    cout << "-------------------------------WELCOME TO IRCTC-------------------------------" << endl;
    cout << "\t\t|\t 1. Admin Mode    \t|" << endl;
    cout << "\t\t|\t 2. User Mode     \t|" << endl;
    cout << "\t\t|\t 3. Exit          \t|" << endl;
    cout << "Select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int pw = 0, counter = 0;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "                       Welcome to Admin Mode                       " << endl;
        cout << endl;
        string a_id, a_pass;
        cout << "Enter Admin Username : ";
        cin >> a_id;
        if (id == a_id)
        {
            cout << "\nEnter Admin Password : ";
            cin >> a_pass;
            if (a_pass == password)
            {
                cout << endl;
                cout << " Login Successful !" << endl;
                int i = 1;
                while (i)
                {
                    cout << endl;
                    cout << " Menu : " << endl;
                    cout << " \t1. View Train" << endl;
                    cout << " \t2. Modify Train" << endl;
                    cout << " \t3. Exit" << endl;
                    int choose;
                    cout << endl;
                    cout << "Select : ";
                    cin >> choose;
                    switch (choose)
                    {
                    case 1:
                    {
                        View_trains();
                    }
                    break;
                    case 2:
                    {
                        View_trains();
                        modi();
                    }
                    break;
                    case 3:
                    {
                        i = 0;
                        firstPage();
                    }
                    }
                }
            }
            else
            {
                cout << "Password is wrong, Please try again !" << endl;
                firstPage();
            }
        }
        else
        {
            cout << "Entered Admin ID is wrong, Please Try Again!" << endl;
            firstPage();
        }
        break;
    }
    case 2:
    {
        int i = 1;
        while (i)
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

            switch (choice)
            {
            case 1:
            {
                View_trains();
            }
            break;
            case 2:
            {

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
                View_ticket();
            }
            break;

            case 4:
            {
                cout << endl;
                cout << "Sorry Ticket cannot be cancelled, it is NON REFUNDABLE !!" << endl;
            }
            break;

            case 5:
            {
                i = 0;
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