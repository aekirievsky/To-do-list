#include <iostream>
#include <string>

using namespace std;


struct ToDo {
    string name;
    int priority{};
    string description;
    string date;
};


void showNote(ToDo& notes) {
    cout << "Name: " << notes.name << endl;
    cout << "Priority: " << notes.priority << endl;
    cout << "Description: " << notes.description << endl;
    cout << "Date: " << notes.date << endl;
}

void showToDoList(ToDo*& notes, int& size) {
    for (int i = 0; i < size; i++) {
        cout << "Note " << i + 1 << endl;
        showNote(notes[i]);
    }
}


ToDo* addNote(ToDo*& notes, ToDo newNote, int& size) {
    ToDo* newNotes = new ToDo[size + 1];
    for (int i = 0; i < size; i++) {
        newNotes[i] = notes[i];
    }

    newNotes[size] = newNote;

    delete[] notes;
    size++;
    return newNotes;
}

ToDo* deleteNote(ToDo*& notes, int indexdeleteNote, int& size) {
    ToDo* newNotes = new ToDo[size - 1];
    int count{};
    for (int i = 0; i < size; i++) {
        if (i != indexdeleteNote) {
            newNotes[count] = notes[i];
            count++;
        }
    }

    delete[] notes;
    size--;
    return newNotes;
}

ToDo* searchNoteByName(ToDo* notes, int& size, int& newSize, string name) {
    int count{};
    for (int i = 0; i < size; i++) {
        if (notes[i].name == name) {
            count++;
            newSize++;
        }
    }

    ToDo* newNotes = new ToDo[count];
    int count1{};
    for (int i = 0; i < size; i++) {
        if (notes[i].name == name) {
            newNotes[count1] = notes[i];
            count1++;
        }
    }

    return newNotes;
}

ToDo* searchNoteByPriority(ToDo* notes, int& size, int& newSize, int priority) {
    int count{};
    for (int i = 0; i < size; i++) {
        if (notes[i].priority == priority) {
            count++;
            newSize++;
        }
    }

    ToDo* newNotes = new ToDo[count];
    int count1{};
    for (int i = 0; i < size; i++) {
        if (notes[i].priority == priority) {
            newNotes[count1] = notes[i];
            count1++;
        }
    }

    return newNotes;
}

ToDo* searchNoteByDescription(ToDo* notes, int& size, int& newSize, string description) {
    int count{};
    for (int i = 0; i < size; i++) {
        if (notes[i].description == description) {
            count++;
            newSize++;
        }
    }

    ToDo* newNotes = new ToDo[count];
    int count1{};
    for (int i = 0; i < size; i++) {
        if (notes[i].description == description) {
            newNotes[count1] = notes[i];
            count1++;
        }
    }

    return newNotes;
}

ToDo* searchNoteByDate(ToDo* notes, int& size, int& newSize, string date) {
    int count{};
    for (int i = 0; i < size; i++) {
        if (notes[i].date == date) {
            count++;
            newSize++;
        }
    }

    ToDo* newNotes = new ToDo[count];
    int count1{};
    for (int i = 0; i < size; i++) {
        if (notes[i].date == date) {
            newNotes[count1] = notes[i];
            count1++;
        }
    }

    return newNotes;
}

ToDo* searchNoteForWeekMonth(ToDo* notes, int& size, int& newSize, string firstDate, string secondDate) {
    for (int i = 0; i < size; i++) {
        if (notes[i].date >= firstDate && notes[i].date <= secondDate) {
            newSize++;
        }
    }

    ToDo* newNotes = new ToDo[newSize];
    int count{};
    for (int i = 0; i < size; i++) {
        if (notes[i].date >= firstDate && notes[i].date <= secondDate) {
            newNotes[count] = notes[i];
            count++;
        }
    }

    return newNotes;
}

void editNoteName(ToDo& notes, string name) {
    notes.name = name;
}

void editNotePriority(ToDo& notes, int priority) {
    notes.priority = priority;
}

void editNoteDescription(ToDo& notes, string description) {
    notes.description = description;
}

void editNoteTime(ToDo& notes, string date) {
    notes.date = date;
}

ToDo* sortNoteByPriority(ToDo*& notes, int& size) {
    ToDo* newNotes = new ToDo[size];
    for (int i = 0; i < size; i++) {
        newNotes[i] = notes[i];
    }

    for (int i = 0; i < size; i++) {
        ToDo temp;
        for (int j = 0; j < size; j++) {
            if (newNotes[i].priority < newNotes[j].priority) {
                temp = newNotes[i];
                newNotes[i] = newNotes[j];
                newNotes[j] = temp;
            }
        }
    }
    return newNotes;
}

ToDo* sortNoteByDate(ToDo*& notes, int& size) {
    ToDo* newNotes = new ToDo[size];
    for (int i = 0; i < size; i++) {
        newNotes[i] = notes[i];
    }

    for (int i = 0; i < size; i++) {
        ToDo temp;
        for (int j = 0; j < size; j++) {
            if (newNotes[i].date < newNotes[j].date) {
                temp = newNotes[i];
                newNotes[i] = newNotes[j];
                newNotes[j] = temp;
            }
        }
    }
    return newNotes;
}

int main() {
    int size{}, resultSize{};
    ToDo* list = new ToDo[size];
    ToDo* resultSearch;
    ToDo* sortByPriority;
    ToDo* sortByDate;
    ToDo Note{};
    int indexEditNoteByName{}, indexEditNoteByPriority{}, indexEditNoteByDescription{}, indexEditNoteByTime{}, indexDeleteNote{}, searchPriority{}, newPriorityNote{};;
    string newNameNote;
    string newDescriptionNote;
    string newTimeNote;
    string searchName;
    string searchDescription;
    string searchDate;
    string searchDateFirst;
    string searchDateSecond;
    int key;
    while (true) {
        cout << "Select a menu item:" << endl << "1 - Add note" << endl << "2 - Drop note" << endl
            << "3 - Edit note by name" << endl << "4 - Edit note by priority" << endl << "5 - Edit note by description"
            << endl << "6 - Edit note by date"
            << endl << "7 - Search note by name" << endl
            << "8 - Search note by priority" << endl << "9 - Search note by description" << endl
            << "10 - Search note by date" << endl
            << "11 - Show to-do list for a day" << endl << "12 - Show to-do list output for a period"
            << endl
            << "13 - Sort to-do list by priority" << endl
            << "14 - Sort to-do list by date of execution" << endl << "15 - Show all notes"
            << endl << "0 - Menu exit" << endl
            << "Your choice: ";
        cin >> key;
        cout << endl;
        switch (key) {
        case 1:
            cout << "Enter name note: ";
            cin.ignore();
            getline(cin, Note.name);
            cout << endl << "Enter priority for note: ";
            cin >> Note.priority;
            cout << endl << "Enter description for note: ";
            cin.ignore();
            getline(cin, Note.description);
            cout << endl << "Enter date of execution: ";
            getline(cin, Note.date);
            list = addNote(list, Note, size);
            break;
        case 2:
            showToDoList(list, size);
            cout << endl << "Enter number note of the case that you plan to remove from the list: ";
            cin >> indexDeleteNote;
            list = deleteNote(list, indexDeleteNote - 1, size);
            break;
        case 3:
            showToDoList(list, size);
            cout << endl << "Choice note for edit: ";
            cin >> indexEditNoteByName;
            indexEditNoteByName--;
            cout << "Enter new name for note: ";
            cin.ignore();
            getline(cin, newNameNote);
            editNoteName(list[indexEditNoteByName], newNameNote);
            break;
        case 4:
            showToDoList(list, size);
            cout << endl << "Choice note for edit: ";
            cin >> indexEditNoteByPriority;
            indexEditNoteByPriority--;
            cout << "Enter new priority for note: ";
            cin >> newPriorityNote;
            editNotePriority(list[indexEditNoteByPriority], newPriorityNote);
            break;
        case 5:
            showToDoList(list, size);
            cout << endl << "Choice note for edit: ";
            cin >> indexEditNoteByDescription;
            indexEditNoteByDescription--;
            cout << "Enter new description: ";
            cin.ignore();
            getline(cin, newDescriptionNote);
            editNoteDescription(list[indexEditNoteByDescription], newDescriptionNote);
            break;
        case 6:
            showToDoList(list, size);
            cout << endl << "Choice note for edit: ";
            cin >> indexEditNoteByTime;
            indexEditNoteByTime--;
            cout << "Enter new date: ";
            cin.ignore();
            getline(cin, newTimeNote);
            editNoteTime(list[indexEditNoteByTime], newTimeNote);
            break;
        case 7:
            cout << "Enter name note: ";
            cin.ignore();
            getline(cin, searchName);
            resultSearch = searchNoteByName(list, size, resultSize, searchName);
            showToDoList(resultSearch, resultSize);
            delete[] resultSearch;
            break;
        case 8:
            cout << "Enter priority note: ";
            cin >> searchPriority;
            resultSearch = searchNoteByPriority(list, size, resultSize, searchPriority);
            showToDoList(resultSearch, resultSize);
            delete[] resultSearch;
            break;
        case 9:
            cout << "Enter description note: ";
            cin.ignore();
            getline(cin, searchDescription);
            resultSearch = searchNoteByDescription(list, size, resultSize, searchDescription);
            showToDoList(resultSearch, resultSize);
            delete[] resultSearch;
            break;
        case 10:
            cout << "Enter date note: ";
            cin.ignore();
            getline(cin, searchDate);
            resultSearch = searchNoteByDate(list, size, resultSize, searchDate);
            showToDoList(resultSearch, resultSize);
            delete[] resultSearch;
            break;
        case 11:
            cout << "Enter date in the format YYYY.MM.DD: ";
            cin.ignore();
            getline(cin, searchDate);
            resultSearch = searchNoteByDate(list, size, resultSize, searchDate);
            sortByDate = sortNoteByDate(resultSearch, resultSize);
            showToDoList(sortByDate, resultSize);
            delete[] resultSearch;
            delete[] sortByDate;
            break;
        case 12:
            cout << "Enter date in the format YYYY.MM.DD: ";
            cin.ignore();
            getline(cin, searchDateFirst);
            cout << "Enter date in the format YYYY.MM.DD: ";
            getline(cin, searchDateSecond);
            resultSearch = searchNoteForWeekMonth(list, size, resultSize, searchDateFirst, searchDateSecond);
            sortByDate = sortNoteByDate(resultSearch, resultSize);
            showToDoList(sortByDate, resultSize);
            delete[] resultSearch;
            delete[] sortByDate;
            break;
        case 13:
            sortByPriority = sortNoteByPriority(list, size);
            showToDoList(sortByPriority, size);
            delete[] sortByPriority;
            break;
        case 14:
            sortByDate = sortNoteByDate(list, size);
            showToDoList(sortByDate, size);
            delete[] sortByDate;
            break;
        case 15:
            showToDoList(list, size);
            break;
        case 0:
            cout << "See you soon";
            return 0;
        default:
            cout << "Wrong choice";
        }
        resultSize = 0;
        cout << endl;
    }
}
