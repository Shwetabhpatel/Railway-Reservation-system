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
