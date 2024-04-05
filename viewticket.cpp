void View_ticket() {                    // function to show booked ticket details to the user.
    ifstream myticket;
    myticket.open("Print_ticket.txt");  // the ticket details have been fetched from this text file.
    string track;
    while (getline(myticket, track)) {
        cout << track << endl;
    }
    myticket.close();
}