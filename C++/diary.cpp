#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;

// Base class
class Diary {
protected:
    char passwords[25] = "tanu"; // Default password
public:
    virtual void displayMenu() = 0; // Pure virtual function for abstraction
    int password(); // Method to check password
    void edit_password(); // Method to edit password
};

// Derived class
class Record : public Diary {
private:
    char time[10];
    char name[30];
    char place[25];
    char duration[10];
    char note[500];

public:
    void add_record();
    void view_record();
    void modify_record();
    void delete_record();
    void displayMenu() override; // Override base class method
};

// Password verification
int Diary::password() {
    fstream f;
    f.open("PASS", ios::in);
    f.read((char*)&passwords, sizeof(passwords));
    f.close();

    char pass[15] = {0}, ch;
    int i = 0, j;
    cout << "::FOR SECURITY PURPOSE::\n";
    cout << "::ONLY THREE TRIALS ARE ALLOWED::\n";

    for (j = 0; j < 3; j++) {
        i = 0;
        cout << "\n\n\tENTER THE PASSWORD:";
        pass[0] = getch();
        while (pass[i] != '\r') {
            if (pass[i] == '\b') {
                i--;
                cout << "\b \b";
                pass[i] = getch();
            } else {
                cout << "*";
                i++;
                pass[i] = getch();
            }
        }
        pass[i] = '\0';

        if (strcmp(pass, passwords) == 0) {
            cout << "\n\n\tACCESS GRANTED...\n";
            return 0;
        } else {
            cout << "\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n";
        }
    }
    cout << "\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...";
    getch();
    return 1;
}

void Diary::edit_password() {
    system("cls");
    char pass[15] = {0}, confirm[15] = {0}, ch;
    int choice, i, check;

    check = password();
    if (check == 1) return;

    do {
        i = 0;
        cout << "\n\n\tENTER THE NEW PASSWORD:";
        cin.ignore();
        pass[0] = getch();
        while (pass[i] != '\r') {
            if (pass[i] == '\b') {
                i--;
                cout << "\b \b";
                pass[i] = getch();
            } else {
                cout << "*";
                i++;
                pass[i] = getch();
            }
        }
        pass[i] = '\0';

        i = 0;
        cout << "\n\tCONFIRM PASSWORD:";
        confirm[0] = getch();
        while (confirm[i] != '\r') {
            if (confirm[i] == '\b') {
                i--;
                cout << "\b \b";
                confirm[i] = getch();
            } else {
                cout << "*";
                i++;
                confirm[i] = getch();
            }
        }
        confirm[i] = '\0';

        if (strcmp(pass, confirm) == 0) {
            strcpy(passwords, pass);
            fstream f;
            f.open("PASS", ios::out | ios::binary);
            f.write((char*)&passwords, sizeof(passwords));
            f.close();
            cout << "\n\n\tPASSWORD CHANGED SUCCESSFULLY.";
            cout << "\n\n\tPRESS ANY KEY TO CONTINUE...";
            getch();
            return;
        } else {
            cout << "\n\tTHE NEW PASSWORD DOES NOT MATCH.";
            choice = 1;
        }
    } while (choice == 1);
}

void Record::displayMenu() {
    cout << "\n\n\t***********************************\n";
    cout << "\t*PASSWORD PROTECTED PERSONAL DIARY*\n";
    cout << "\t***********************************";
}

// Add record
void Record::add_record() {
    system("cls");
    char another = 'Y', time[10];
    char filename[15];
    int choice, count = 0;

    cout << "\n\n\t\t***************************\n";
    cout << "\t\t* WELCOME TO THE ADD MENU *";
    cout << "\n\t\t***************************\n\n";
    cout << "\n\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]:";
    cin.ignore();
    cin.getline(filename, 15);

    fstream f(filename, ios::in | ios::binary | ios::app);
    if (!f.is_open()) {
        f.open(filename, ios::out | ios::binary);
        if (!f.is_open()) {
            cout << "\nSYSTEM ERROR...";
            cout << "\nPRESS ANY KEY TO EXIT";
            getch();
            return;
        }
    }

    while (another == 'Y' || another == 'y') {
        cout << "\n\tENTER TIME:[hh:mm]:";
        cin.getline(time, 10);

        f.seekg(0, ios::beg);
        bool recordExists = false;
        Record temp;
        while (f.read((char*)&temp, sizeof(Record))) {
            if (strcmp(temp.time, time) == 0) {
                recordExists = true;
                break;
            }
        }

        if (recordExists) {
            cout << "\n\tTHE RECORD ALREADY EXISTS.\n";
        } else {
            strcpy(this->time, time);
            cout << "\tENTER NAME:";
            cin.getline(this->name, 30);
            cout << "\tENTER PLACE:";
            cin.getline(this->place, 25);
            cout << "\tENTER DURATION:";
            cin.getline(this->duration, 10);
            cout << "\tNOTE:";
            cin.getline(this->note, 500);

            f.write((char*)this, sizeof(Record));
            cout << "\nYOUR RECORD IS ADDED...\n";
        }

        cout << "\n\tADD ANOTHER RECORD...(Y/N) ";
        another = getchar();
        cin.ignore();
    }

    f.close();
    cout << "\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
}

// View record
void Record::view_record() {
    system("cls");
    char filename[15], choice;
    int ch;

    cout << "\n\n\t\t*******************************\n";
    cout << "\t\t*   HERE IS THE VIEWING MENU  *";
    cout << "\n\t\t*******************************\n\n";

    if (password() != 0) return;

    do {
        cout << "\n\tENTER THE DATE OF RECORD TO BE VIEWED:[dd-mm-yyyy]:";
        cin.ignore();
        cin.getline(filename, 15);

        fstream f(filename, ios::in | ios::binary);
        if (!f) {
            cout << "\nTHE RECORD DOES NOT EXIST...\n";
            cout << "PRESS ANY KEY TO EXIT...";
            getch();
            return;
        }

        system("cls");
        cout << "\n\tHOW WOULD YOU LIKE TO VIEW:\n";
        cout << "\n\t1.WHOLE RECORD OF THE DAY.";
        cout << "\n\t2.RECORD OF FIX TIME.";
        cout << "\n\t\tENTER YOUR CHOICE:";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nTHE WHOLE RECORD FOR:" << filename;
                while (f.read((char*)this, sizeof(Record))) {
                    cout << "\n";
                    cout << "\nTIME:" << time;
                    cout << "\nMEETING WITH:" << name;
                    cout << "\nMEETING AT:" << place;
                    cout << "\nDURATION:" << duration;
                    cout << "\nNOTE:" << note;
                    cout << "\n";
                }
                break;
            case 2:
                cin.ignore();
                cout << "\nENTER TIME:[hh:mm]:";
                char viewTime[10];
                cin.getline(viewTime, 10);
                while (f.read((char*)this, sizeof(Record))) {
                    if (strcmp(time, viewTime) == 0) {
                        cout << "\nYOUR RECORD IS:";
                        cout << "\nTIME:" << time;
                        cout << "\nMEETING WITH:" << name;
                        cout << "\nMEETING AT:" << place;
                        cout << "\nDURATION:" << duration;
                        cout << "\nNOTE:" << note;
                    }
                }
                break;
            default:
                cout << "\nYOU TYPED SOMETHING ELSE...\n";
                break;
        }

        cout << "\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):";
        cin >> choice;
        f.close();
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
}

void Record::modify_record() {
    system("cls");
    char filename[15], time[10], choice;
    int num, cnt = 0;

    cout << "\n\n\t\t*******************************\n";
    cout << "\t\t* WELCOME TO THE EDITING MENU *";
    cout << "\n\t\t*******************************\n\n";

    if (password() != 0) return;

    do {
        cout << "\n\tENTER THE DATE OF RECORD TO BE EDITED:[dd-mm-yyyy]:";
        cin.ignore();
        cin.getline(filename, 15);
        cout << "\n\tENTER TIME:[hh:mm]:";
        cin.getline(time, 10);

        fstream f(filename, ios::in | ios::out | ios::binary);
        if (!f) {
            cout << "\nRECORD DOES NOT EXIST:";
            cout << "\nPRESS ANY KEY TO GO BACK";
            getch();
            return;
        }

        while (f.read((char*)this, sizeof(Record))) {
            cnt++;
            if (strcmp(this->time, time) == 0) {
                cout << "\nYOUR OLD RECORD WAS AS:";
                cout << "\nTIME:" << time;
                cout << "\nMEETING WITH:" << name;
                cout << "\nMEETING AT:" << place;
                cout << "\nDURATION:" << duration;
                cout << "\nNOTE:" << note;

                cout << "\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..";
                cout << "\n1.TIME.";
                cout << "\n2.MEETING PERSON.";
                cout << "\n3.MEETING PLACE.";
                cout << "\n4.DURATION.";
                cout << "\n5.NOTE.";
                cout << "\n6.WHOLE RECORD.";
                cout << "\n7.GO BACK TO MAIN MENU.";

                do {
                    cout << "\n\tENTER YOUR CHOICE:";
                    cin >> num;
                    cin.ignore();

                    switch (num) {
                        case 1:
                            cout << "\nENTER THE NEW DATA:";
                            cout << "\nNEW TIME:[hh:mm]:";
                            cin.getline(this->time, 10);
                            break;
                        case 2:
                            cout << "\nENTER THE NEW DATA:";
                            cout << "\nNEW MEETING PERSON:";
                            cin.getline(this->name, 30);
                            break;
                        case 3:
                            cout << "\nENTER THE NEW DATA:";
                            cout << "\nNEW MEETING PLACE:";
                            cin.getline(this->place, 25);
                            break;
                        case 4:
                            cout << "\nENTER THE NEW DATA:";
                            cout << "\nDURATION:";
                            cin.getline(this->duration, 10);
                            break;
                        case 5:
                            cout << "\nENTER THE NEW DATA:";
                            cout << "\nNOTE:";
                            cin.getline(this->note, 500);
                            break;
                        case 6:
                            cout << "\nENTER THE NEW DATA:";
                            cout << "\nNEW TIME:[hh:mm]:";
                            cin.getline(this->time, 10);
                            cout << "\nNEW MEETING PERSON:";
                            cin.getline(this->name, 30);
                            cout << "\nNEW MEETING PLACE:";
                            cin.getline(this->place, 25);
                            cout << "\nDURATION:";
                            cin.getline(this->duration, 10);
                            cout << "\nNOTE:";
                            cin.getline(this->note, 500);
                            break;
                        case 7:
                            cout << "\nPRESS ANY KEY TO GO BACK...\n";
                            getch();
                            return;
                        default:
                            cout << "\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n";
                            break;
                    }
                } while (num < 1 || num > 7);

                int location = (cnt - 1) * sizeof(Record);
                f.seekp(location);
                f.write((char*)this, sizeof(Record));
                f.close();

                cout << "\n\t\tEDITING COMPLETED...\n";
                cout << "--------------------\n";
                cout << "THE NEW RECORD IS:\n";
                cout << "--------------------\n";
                cout << "\nTIME:" << time;
                cout << "\nMEETING WITH:" << name;
                cout << "\nMEETING AT:" << place;
                cout << "\nDURATION:" << duration;
                cout << "\nNOTE:" << note;

                cout << "\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)";
                cin >> choice;
                break;
            }
        }

        if (strcmp(this->time, time) != 0) {
            cout << "\nTHE RECORD DOES NOT EXIST::\n";
            cout << "\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)";
            cin >> choice;
        }
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
}

// Delete record
void Record::delete_record() {
    system("cls");
    char filename[15], another = 'Y', time[10];
    int choice, check;

    cout << "\n\n\t\t*************************\n";
    cout << "\t\t* WELCOME TO DELETE MENU*";
    cout << "\n\t\t*************************\n\n";

    check = password();
    if (check == 1) return;

    while (another == 'Y' || another == 'y') {
        cout << "\n\n\tHOW WOULD YOU LIKE TO DELETE.";
        cout << "\n\n\t#DELETE WHOLE RECORD\t\t\t[1]";
        cout << "\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]";

        do {
            cout << "\n\t\tENTER YOUR CHOICE:";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\n\tENTER THE DATE OF RECORD TO BE DELETED:[dd-mm-yyyy]:";
                    cin.ignore();
                    cin.getline(filename, 15);
                    if (remove(filename) == 0)
                        cout << "\nDELETED SUCCESSFULLY...";
                    else
                        cout << "\nTHE FILE DOES NOT EXIST";
                    break;
                case 2:
                    cout << "\n\tENTER THE DATE OF RECORD:[dd-mm-yyyy]:";
                    cin.ignore();
                    cin.getline(filename, 15);

                    fstream f(filename, ios::in | ios::binary);
                    if (!f) {
                        cout << "\nTHE FILE DOES NOT EXIST";
                        cout << "\nPRESS ANY KEY TO GO BACK.";
                        getch();
                        return;
                    }

                    fstream temp("temp", ios::out | ios::binary);
                    cout << "\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:";
                    cin.getline(time, 10);

                    while (f.read((char*)this, sizeof(Record))) {
                        if (strcmp(this->time, time) != 0)
                            temp.write((char*)this, sizeof(Record));
                    }

                    f.close();
                    temp.close();
                    remove(filename);
                    rename("temp", filename);
                    cout << "\nDELETED SUCCESSFULLY...";
                    break;
                default:
                    cout << "\n\tYOU ENTERED WRONG CHOICE";
                    break;
            }
        } while (choice < 1 || choice > 2);

        cout << "\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):";
        cin >> another;
    }

    cout << "\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
}

// Main function
int main() {
    int ch;
    Record d;

    while (1) {
        d.displayMenu();
        cout << "\n\n\t\tMAIN MENU:";
        cout << "\n\t---------------------\n";
        cout << "\n\n\tADD RECORD\t[1]";
        cout << "\n\tVIEW RECORD\t[2]";
        cout << "\n\tMODIFY RECORD\t[3]";
        cout << "\n\tDELETE RECORD\t[4]";
        cout << "\n\tEDIT PASSWORD\t[5]";
        cout << "\n\tEXIT\t\t[6]";
        cout << "\n\n\tENTER YOUR CHOICE:";
        cin >> ch;

        switch (ch) {
            case 1:
                d.add_record();
                break;
            case 2:
                d.view_record();
                break;
            case 3:
                d.modify_record();
                break;
            case 4:
                d.delete_record();
                break;
            case 5:
                d.edit_password();
                break;
            case 6:
                cout << "\n\n\t\tTHANK YOU!!!";
                getch();
                exit(0);
            default:
                cout << "\nYOU ENTERED WRONG CHOICE..";
                cout << "\nPRESS ANY KEY TO TRY AGAIN";
                getch();
                break;
        }
        system("cls");
    }
    return 0;
}
