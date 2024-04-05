void View_trains() {            // this function is used to show information about train fetched from  the text file.
    ifstream file;
    file.open("Train_schedule.txt");
    string matter;
    while (getline(file, matter)) {
        cout << matter << endl;
    }
    file.close();
}