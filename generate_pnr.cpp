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