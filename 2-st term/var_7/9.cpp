/* 
Данные из файла в массивы структур
Создание бд, просмотр, добавление
Линейный поиск в файле
Сортировка массива методом прямого выбора и QuickSort
Двоичный поиск в отсортированном массиве
Данные из бд: 
- Код в бд - id - int
- Имя - name - string
- Фамилия - surname - string
- Отчество - middleName - string
- Игровой номер - gameNumber - int
- Возраст - age - int
- Рост (м) - height - double
- Вес (кг) - weight - double
- Страна - country - string
- Команда - team - string

Струтура БД: 
ID|NameOfPlayer|SurnameOfPlayer|MiddleNameOfPlayer|GameNumber|Age|Height|Weight|Country|Team;
*/
#include <iostream>
#include <fstream>

using namespace std;

struct player {
    int id;
    string name;
    string surname;
    string middleName;
    int gameNumber;
    int age;
    double height;
    double weight;
    string country;
    string team;
};

int sizeOfName, countOfPlayers;
char *fileName;
player *Players;

string input() {
    string line;
    while (true) {
        getline(cin, line);
        if (line != "")
            return line;
    }
}

void enterDatabaseName () {
    if (countOfPlayers > 0)
        delete [] Players;
    
    countOfPlayers = 0;
    cout << endl << "Введите название файла: ";
    string temp = input() + ".txt";
    
    fileName = new char[temp.length()];
    for (int i = 0; i < temp.length(); i++)
        fileName[i] = temp[i];

    sizeOfName = temp.length();
}

void checkIfDatabaseExist () {
    ifstream openFile(fileName);
    if (openFile.is_open())
        cout << endl << "Файл БД существует" << endl;
    else
        cout << endl << "Файл БД не существует" << endl;

    openFile.close();
}

void create_formatDatabase () {
    ifstream openFile(fileName);
    if (openFile.is_open()) {
        openFile.close();
        ofstream openFile(fileName);
        cout << endl << "Файл БД успешно отформатирован" << endl;
        openFile.close();
    } else {
        openFile.close();
        ofstream openFile(fileName);
        if (openFile.is_open())
            cout << endl << "Файл БД успешно создан" << endl;
        else
            cout << endl << "Файл БД не создан" << endl;

        openFile.close();
    }
}

player *addPlayer () {
    player *newArray = new player[countOfPlayers];
    for (int i = 0; i < countOfPlayers - 1; i++)
        newArray[i] = Players[i];

    return newArray;
}

int getCountOfCharInFiles () {
    int count;
    ifstream openFile(fileName);
    while (!openFile.eof()) {
        char ch;
        openFile >> ch;
        count++;
    }

    openFile.close();
    return count;
}

void cleanMemory () {
    countOfPlayers = 0;
    player *temp = Players;
    Players = new player[countOfPlayers];
    delete [] temp;
}

void readDataBase () {
    if (getCountOfCharInFiles() <= 3) {
        cout << endl << "Файл БД пустой" << endl;
        return;
    }
    
    if (countOfPlayers != 0)
        cleanMemory();
    
    ifstream openFile(fileName);
    char line[500];
    Players = new player[countOfPlayers];
    cout << endl << "Чтение БД в оперативную память ПК " << endl;
    while (!openFile.eof()) {
        openFile.getline(line, 500);
        int count = 0;
        countOfPlayers++;
        Players = addPlayer();
        string temp;
        for (int i = 0; i < 500 || line[i] != '\0'; i++) {
            if (line[i] == '|' || line[i] == ';') {
                switch (count++) {
                    case 0:
                        Players[countOfPlayers - 1].id = stoi(temp);
                        break;
                    case 1:
                        Players[countOfPlayers - 1].name = temp;
                        break;
                    case 2:
                        Players[countOfPlayers - 1].surname = temp;
                        break;
                    case 3:
                        Players[countOfPlayers - 1].middleName = temp;
                        break;
                    case 4:
                        if (temp != "-")
                            Players[countOfPlayers - 1].gameNumber = stoi(temp);
                        else
                            Players[countOfPlayers - 1].gameNumber = 0;
                        break;
                    case 5:
                        if (temp != "-")
                            Players[countOfPlayers - 1].age = stoi(temp);
                        else
                            Players[countOfPlayers - 1].age = 0;
                        break;
                    case 6:
                        if (temp != "-")
                            Players[countOfPlayers - 1].height = stod(temp);
                        else
                            Players[countOfPlayers - 1].height = 0;
                        break;
                    case 7:
                        if (temp != "-")
                            Players[countOfPlayers - 1].weight = stod(temp);
                        else
                            Players[countOfPlayers - 1].weight = 0;
                        break;
                    case 8:
                        Players[countOfPlayers - 1].country = temp;
                        break;
                    case 9:
                        Players[countOfPlayers - 1].team = temp;
                }

                temp.clear();
                continue;
            }

            temp += line[i];
        }
    }

    openFile.close();
    cout << endl << "БД успешно открыта в памяти компьютера" << endl;
}

void output () {
    cout << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;
    for (int i = 0; i < countOfPlayers; i++)
        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
}

bool checkMemory () {
    if (countOfPlayers < 1) {
        cout << endl << "Память пустая" << endl;
        return true;
    }

    return false;
}

void showDatabase () {
    if (checkMemory())
        return;
    
    cout << endl << "Содержимое БД: " << endl;
    output();
}

void writeDataToEnd () {
    if (countOfPlayers != 0)
        cleanMemory();
    
    string temp;
    cout << endl << "Добавление игрока в БД: " << endl;
    countOfPlayers++;
    Players = addPlayer();
    bool menu;
    cout << "Хотите ввести уникальный ID? (1 - да, 0 - нет): ";
    cin >> menu;
    if (menu) {
        cout << endl << "Введите ID: ";
        cin >> Players[countOfPlayers - 1].id;
    } else
        Players[countOfPlayers - 1].id = Players[countOfPlayers - 2].id + 1;

    cout << "Введите имя: ";
    Players[countOfPlayers - 1].name = input();
    cout << endl << "Введите фамилию: ";
    Players[countOfPlayers - 1].surname = input();
    cout << endl << "Введите отчество: ";
    Players[countOfPlayers - 1].middleName = input();
    cout << endl << "Введите игровой номер: ";
    cin >> Players[countOfPlayers - 1].gameNumber;
    cout << endl << "Введите возраст: ";
    cin >> Players[countOfPlayers - 1].age;
    cout << endl << "Введите рост (в метрах): ";
    cin >> Players[countOfPlayers - 1].height;
    cout << endl << "Введите вес (в килограммах): ";
    cin >> Players[countOfPlayers - 1].weight;
    cout << endl << "Введите страну: ";
    Players[countOfPlayers - 1].country = input();
    cout << endl << "Введите команду: ";
    Players[countOfPlayers - 1].team = input();

    cout << endl << "Информация добавлена" << endl;
}

player *removePlayer (int id) {
    player *newArray = new player[countOfPlayers - 1];
    int j;
    for (int i = 0; i < countOfPlayers; i++) {
        if (Players[i].id == id)
            continue;
        
        newArray[j++] = Players[i];
    }

    return newArray;
}

int getMaxID () {
    int max = INT_MIN;
    for (int i = 0; i < countOfPlayers; i++)
        max = max < Players[i].id ? Players[i].id : max;

    return max;
}

int getID () {
    int id;
    while (true) {
        cout << endl << "Выберите ID игрока: ";
        cin >> id;
        if (id >= 0 && id <= getMaxID())
            return id;
    }
}

void removePlayer () {
    if (checkMemory())
        return;
    
    cout << endl << "Удаление игрока из БД: " << endl;
    output();
    int id = getID();
    countOfPlayers--;
    player *newArray = new player[countOfPlayers];
    int j = 0;
    for (int i = 0; i <= countOfPlayers; i++) {
        if (Players[i].id == id)
            continue;

        newArray[j++] = Players[i];
    }

    swap(newArray, Players);
    delete [] newArray;

    cout << endl << "Удаление завершено" << endl;
}

int getIndex (int id) {
    for (int i = 0; i < countOfPlayers; i++)
        if (id == Players[i].id)
            return i;
}

void editPlayer () {
    if (checkMemory())
        return;
    
    cout << endl << "Изменение данных игрока в БД: " << endl;
    output();

    int id = getID(), i = getIndex(id);

    while (true) {
        int menu;
        cout << endl << "Выбранный игрок: " << endl;
        cout << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;
        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
        cout << "Выберите данные для изменения:" << endl;
        cout << "1 - ID" << endl;
        cout << "2 - Имя" << endl;
        cout << "3 - Фамилия" << endl;
        cout << "4 - Отчество" << endl;
        cout << "5 - Игровой номер" << endl;
        cout << "6 - Возраст" << endl;
        cout << "7 - Рост" << endl;
        cout << "8 - Вес" << endl;
        cout << "9 - Страна" << endl;
        cout << "10 - Команда" << endl;
        cout << "11 - Выбрать другого игрока" << endl;
        cout << "0 - Выход из режима изменения данных" << endl;
        cout << "Ващ выбор: ";
        cin >> menu;

        switch (menu) {
            case 1: {
                cout << endl << "Введите ID: ";
                cin >> Players[i].id;
            }
            break;
            case 2: {
                cout << endl << "Введите имя: ";
                Players[i].name = input();
            }
            break;
            case 3: {
                cout << endl << "Введите фамилию: ";
                Players[i].surname = input();
            }
            break;
            case 4: {
                cout << endl << "Введите отчество: ";
                Players[i].middleName = input();
            }
            break;
            case 5: {
                cout << endl << "Введите игровой номер: ";
                cin >> Players[i].gameNumber;
            }
            break;
            case 6: {
                cout << endl << "Введите возраст: ";
                cin >> Players[i].age;
            }
            break;
            case 7: {
                cout << endl << "Введите рост (в метрах): ";
                cin >> Players[i].height;
            }
            break;
            case 8: {
                cout << endl << "Введите вес (в килограммах): ";
                cin >> Players[i].weight;
            }
            break;
            case 9: {
                cout << endl << "Введите страну: ";
                Players[i].country = input();
            }
            break;

            case 10: {
                cout << endl << "Введите команду: ";
               Players[i].team = input();
            }
            break;
            case 11: {
                id = getID();
                i = getIndex(id);
            }
            break;
            case 0:
                return;
        }

        if (menu > 0 && menu < 11)
            cout << endl << "Информация изменена успешно" << endl;
    }
}

void moveToFile () {
    if (checkMemory())
        return;
    
    ofstream openFile(fileName);
    for (int i = 0; i < countOfPlayers; i++) {
        openFile << Players[i].id << "|" << Players[i].name << "|" << Players[i].surname << "|" << Players[i].middleName << "|" << Players[i].gameNumber << "|" << Players[i].age << "|" << Players[i].height << "|" << Players[i].weight << "|" << Players[i].country << "|" << Players[i].team << ";";
        if (i != countOfPlayers - 1)
            openFile << endl;
    }

    openFile.close();
    cout << endl << "БД перемещена успешно" << endl;
}

void linearSearch () {
    if (checkMemory())
        return;

    cout << endl << "Линейный поиск" << endl;
    while (true) {
        int menu;
        cout << "Выберите параметр для поиска: " << endl;
        cout << "1 - ID" << endl;
        cout << "2 - Имя" << endl;
        cout << "3 - Фамилия" << endl;
        cout << "4 - Отчество" << endl;
        cout << "5 - Игровой номер" << endl;
        cout << "6 - Возраст" << endl;
        cout << "7 - Рост" << endl;
        cout << "8 - Вес" << endl;
        cout << "9 - Страна" << endl;
        cout << "10 - Команда" << endl;
        cout << "0 - Выход в главное меню" << endl;
        cout << "Ващ выбор: ";
        cin >> menu;
        bool find = false;
        switch (menu) {
            case 1: {
                int id;
                cout << endl << "Введите ID игрока: ";
                cin >> id;
                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].id == id) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 2: {
                string name;
                cout << endl << "Введите имя игрока: ";
                while (true) {
                    getline(cin, name);
                    if (name != "")
                        break;
                }

                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].name == name) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 3: {
                string surname;
                cout << endl << "Введите фамилию игрока: ";
                while (true) {
                    getline(cin, surname);
                    if (surname != "")
                        break;
                }

                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].surname == surname) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 4: {
                string middleName;
                cout << endl << "Введите отчество игрока: ";
                while (true) {
                    getline(cin, middleName);
                    if (middleName != "")
                        break;
                }

                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].middleName == middleName) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 5: {
                int gameNumber;
                cout << endl << "Введите игровой номер игрока: ";
                cin >> gameNumber;
                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].gameNumber == gameNumber) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 6: {
                int age;
                cout << endl << "Введите возраст игрока: ";
                cin >> age;
                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].age == age) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 7: {
                double height;
                cout << endl << "Введите рост игрока: ";
                cin >> height;
                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].height == height) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 8: {
                double weight;
                cout << endl << "Введите вес игрока: ";
                cin >> weight;
                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].weight == weight) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 9: {
                string country;
                cout << endl << "Введите страну игрока: ";
                while (true) {
                    getline(cin, country);
                    if (country != "")
                        break;
                }

                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].country == country) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 10: {
                string team;
                cout << endl << "Введите команду игрока: ";
                while (true) {
                    getline(cin, team);
                    if (team != "")
                        break;
                }

                for (int i = 0; i < countOfPlayers; i++) {
                    if (Players[i].team == team) {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                    }
                }
            }
            break;
            case 0:
                return;
        }

        if (!find)
            cout << endl << "Совпадений не найдено" << endl;
    }
}

void exit () {
    if (countOfPlayers > 0)
        cleanMemory();

    exit();
}

int getParametr () {
    int parametr;
    while (!(parametr > 0 && parametr < 6)) {
        cout << endl << "Выберите параметр сортировки: " << endl;
        cout << "1 - ID" << endl;
        cout << "2 - Игровой номер" << endl;
        cout << "3 - Возраст" << endl;
        cout << "4 - Рост" << endl;
        cout << "5 - Вес" << endl;
        cout << "Ваш выбор: ";
        cin >> parametr;
    }
    
    return parametr;
}

void selectionSortID () {
    for (int i = 0; i < countOfPlayers - 1; i++) {
        int position = i;
        for (int j = i + 1; j < countOfPlayers; j++)
            position = Players[j].id < Players[position].id ? j : position;
        
        swap(Players[position], Players[i]);
    }
}

void selectionSortGameNumber () {
    for (int i = 0; i < countOfPlayers - 1; i++) {
        int position = i;
        for (int j = i + 1; j < countOfPlayers; j++)
            position = Players[j].gameNumber < Players[position].gameNumber ? j : position;
        
        swap(Players[position], Players[i]);
    }
}

void selectionSortAge () {
    for (int i = 0; i < countOfPlayers - 1; i++) {
        int position = i;
        for (int j = i + 1; j < countOfPlayers; j++)
            position = Players[j].age < Players[position].age ? j : position;
        
        swap(Players[position], Players[i]);
    }
}

void selectionSortHeight () {
    for (int i = 0; i < countOfPlayers - 1; i++) {
        int position = i;
        for (int j = i + 1; j < countOfPlayers; j++)
            position = Players[j].height < Players[position].height ? j : position;
        
        swap(Players[position], Players[i]);
    }
}

void selectionSortWeight () {
    for (int i = 0; i < countOfPlayers - 1; i++) {
        int position = i;
        for (int j = i + 1; j < countOfPlayers; j++)
            position = Players[j].weight < Players[position].weight ? j : position;
        
        swap(Players[position], Players[i]);
    }
}

void selectionSort () {
    switch (getParametr()) {
        case 1:
            selectionSortID();
            break;
        case 2:
            selectionSortGameNumber();
            break;
        case 3:
            selectionSortAge();
            break;
        case 4:
            selectionSortHeight();
            break;
        case 5:
            selectionSortWeight();
            break;
    }
}

int getMiddleIndexID (int leftIndex, int rightIndex) {
    int temp, middleIndex = rightIndex, i = leftIndex - 1;
    for (int j = leftIndex; j <= rightIndex - 1; j++)
        if (Players[j].id <= Players[middleIndex].id) {
            i++;
            swap(Players[j], Players[i]);
        }

    i++;
    swap(Players[i], Players[rightIndex]);
    return i;
}

void quickSortID (int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex) {
        int middleIndex = getMiddleIndexID(leftIndex, rightIndex);
        quickSortID(leftIndex, middleIndex - 1);
        quickSortID(middleIndex + 1, rightIndex);
    }
}

int getMiddleIndexGameNumber (int leftIndex, int rightIndex) {
    int temp, middleIndex = rightIndex, i = leftIndex - 1;
    for (int j = leftIndex; j <= rightIndex - 1; j++)
        if (Players[j].gameNumber <= Players[middleIndex].gameNumber) {
            i++;
            swap(Players[j], Players[i]);
        }

    i++;
    swap(Players[i], Players[rightIndex]);
    return i;
}

void quickSortGameNumber (int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex) {
        int middleIndex = getMiddleIndexGameNumber(leftIndex, rightIndex);
        quickSortGameNumber(leftIndex, middleIndex - 1);
        quickSortGameNumber(middleIndex + 1, rightIndex);
    }
}

int getMiddleIndexAge (int leftIndex, int rightIndex) {
    int temp, middleIndex = rightIndex, i = leftIndex - 1;
    for (int j = leftIndex; j <= rightIndex - 1; j++)
        if (Players[j].age <= Players[middleIndex].age) {
            i++;
            swap(Players[j], Players[i]);
        }

    i++;
    swap(Players[i], Players[rightIndex]);
    return i;
}

void quickSortAge (int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex) {
        int middleIndex = getMiddleIndexAge(leftIndex, rightIndex);
        quickSortAge(leftIndex, middleIndex - 1);
        quickSortAge(middleIndex + 1, rightIndex);
    }
}

int getMiddleIndexHeight (int leftIndex, int rightIndex) {
    int temp, middleIndex = rightIndex, i = leftIndex - 1;
    for (int j = leftIndex; j <= rightIndex - 1; j++)
        if (Players[j].height <= Players[middleIndex].height) {
            i++;
            swap(Players[j], Players[i]);
        }

    i++;
    swap(Players[i], Players[rightIndex]);
    return i;
}

void quickSortHeight (int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex) {
        int middleIndex = getMiddleIndexHeight(leftIndex, rightIndex);
        quickSortHeight(leftIndex, middleIndex - 1);
        quickSortHeight(middleIndex + 1, rightIndex);
    }
}

int getMiddleIndexWeight (int leftIndex, int rightIndex) {
    int temp, middleIndex = rightIndex, i = leftIndex - 1;
    for (int j = leftIndex; j <= rightIndex - 1; j++)
        if (Players[j].weight <= Players[middleIndex].weight) {
            i++;
            swap(Players[j], Players[i]);
        }

    i++;
    swap(Players[i], Players[rightIndex]);
    return i;
}

void quickSortWeight (int leftIndex, int rightIndex) {
    if (rightIndex > leftIndex) {
        int middleIndex = getMiddleIndexWeight(leftIndex, rightIndex);
        quickSortWeight(leftIndex, middleIndex - 1);
        quickSortWeight(middleIndex + 1, rightIndex);
    }
}

void quickSort () {
    switch (getParametr()) {
        case 1:
            quickSortID(0, countOfPlayers - 1);
            break;
        case 2:
            quickSortGameNumber(0, countOfPlayers - 1);
            break;
        case 3:
            quickSortAge(0, countOfPlayers - 1);
            break;
        case 4:
            quickSortHeight(0, countOfPlayers - 1);
            break;
        case 5:
            quickSortWeight(0, countOfPlayers - 1);
            break;
    }
}

void binarySearch () {
    if (checkMemory())
        return;

    cout << endl << "Для бинарного поиска необходимо отсортировать массив" << endl;
    while (true) {
        int menu;
        cout << "Выберите параметр: " << endl;
        cout << "1 - ID" << endl;
        cout << "2 - Игровой номер" << endl;
        cout << "3 - Возраст" << endl;
        cout << "4 - Рост" << endl;
        cout << "5 - Вес" << endl;
        cout << "0 - Выход в главное меню" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
        bool find = false;
        bool leave = false;
        switch (menu) {
            case 1: {
                quickSortID(0, countOfPlayers - 1);
                int id;
                cout << endl << "Введите ID игрока: ";
                cin >> id;
                int leftBorder = 0, rightBorder = countOfPlayers - 1, middle;
                while (leftBorder <= rightBorder) {
                    middle = (leftBorder + rightBorder) / 2;
                    if (id < Players[middle].id)
                        rightBorder = middle - 1;
                    else if (id > Players[middle].id)
                        leftBorder = middle + 1;
                    else {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[middle].id << " | " << Players[middle].name << " | " << Players[middle].surname << " | " << Players[middle].middleName << " | " << Players[middle].gameNumber << " | " << Players[middle].age << " | " << Players[middle].height << " | " << Players[middle].weight << " | " << Players[middle].country << " | " << Players[middle].team << endl;
                        for (int i = middle - 1; i > -1; i--)
                            if (id == Players[i].id)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        for (int i = middle + 1; i < countOfPlayers; i++)
                            if (id == Players[i].id)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        break;
                    }
                }
            }
                break;
            case 2: {
                quickSortGameNumber(0, countOfPlayers - 1);
                int gameNumber;
                cout << endl << "Введите игровой номер игрока: ";
                cin >> gameNumber;
                int leftBorder = 0, rightBorder = countOfPlayers - 1, middle;
                while (leftBorder <= rightBorder) {
                    middle = (leftBorder + rightBorder) / 2;
                    if (gameNumber < Players[middle].gameNumber)
                        rightBorder = middle - 1;
                    else if (gameNumber > Players[middle].gameNumber)
                        leftBorder = middle + 1;
                    else {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[middle].id << " | " << Players[middle].name << " | " << Players[middle].surname << " | " << Players[middle].middleName << " | " << Players[middle].gameNumber << " | " << Players[middle].age << " | " << Players[middle].height << " | " << Players[middle].weight << " | " << Players[middle].country << " | " << Players[middle].team << endl;
                        for (int i = middle - 1; i > -1; i--)
                            if (gameNumber == Players[i].gameNumber)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        for (int i = middle + 1; i < countOfPlayers; i++)
                            if (gameNumber == Players[i].gameNumber)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        break;
                    }
                }
            }
                break;
            case 3: {
                quickSortAge(0, countOfPlayers - 1);
                int age;
                cout << endl << "Введите игровой номер игрока: ";
                cin >> age;
                int leftBorder = 0, rightBorder = countOfPlayers - 1, middle;
                while (leftBorder <= rightBorder) {
                    middle = (leftBorder + rightBorder) / 2;
                    if (age < Players[middle].age)
                        rightBorder = middle - 1;
                    else if (age > Players[middle].age)
                        leftBorder = middle + 1;
                    else {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[middle].id << " | " << Players[middle].name << " | " << Players[middle].surname << " | " << Players[middle].middleName << " | " << Players[middle].gameNumber << " | " << Players[middle].age << " | " << Players[middle].height << " | " << Players[middle].weight << " | " << Players[middle].country << " | " << Players[middle].team << endl;
                        for (int i = middle - 1; i > -1; i--)
                            if (age == Players[i].age)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        for (int i = middle + 1; i < countOfPlayers; i++)
                            if (age == Players[i].age)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        break;
                    }
                }
            }
                break;
            case 4: {
                quickSortHeight(0, countOfPlayers - 1);
                double height;
                cout << endl << "Введите игровой номер игрока: ";
                cin >> height;
                int leftBorder = 0, rightBorder = countOfPlayers - 1, middle;
                while (leftBorder <= rightBorder) {
                    middle = (leftBorder + rightBorder) / 2;
                    if (height < Players[middle].height)
                        rightBorder = middle - 1;
                    else if (height > Players[middle].height)
                        leftBorder = middle + 1;
                    else {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[middle].id << " | " << Players[middle].name << " | " << Players[middle].surname << " | " << Players[middle].middleName << " | " << Players[middle].gameNumber << " | " << Players[middle].age << " | " << Players[middle].height << " | " << Players[middle].weight << " | " << Players[middle].country << " | " << Players[middle].team << endl;
                        for (int i = middle - 1; i > -1; i--)
                            if (height == Players[i].height)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        for (int i = middle + 1; i < countOfPlayers; i++)
                            if (height == Players[i].height)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        break;
                    }
                }
            }
                break;
            case 5: {
                quickSortWeight(0, countOfPlayers - 1);
                double weight;
                cout << endl << "Введите игровой номер игрока: ";
                cin >> weight;
                int leftBorder = 0, rightBorder = countOfPlayers - 1, middle;
                while (leftBorder <= rightBorder) {
                    middle = (leftBorder + rightBorder) / 2;
                    if (weight < Players[middle].weight)
                        rightBorder = middle - 1;
                    else if (weight > Players[middle].weight)
                        leftBorder = middle + 1;
                    else {
                        if (!find)
                            cout << endl << "ID | Имя игрока | Фамилия игрока | Отчество игрока | Игровой номер | Возраст | Рост | Вес | Страна | Команда" << endl;

                        find = true;
                        cout << Players[middle].id << " | " << Players[middle].name << " | " << Players[middle].surname << " | " << Players[middle].middleName << " | " << Players[middle].gameNumber << " | " << Players[middle].age << " | " << Players[middle].height << " | " << Players[middle].weight << " | " << Players[middle].country << " | " << Players[middle].team << endl;
                        for (int i = middle - 1; i > -1; i--)
                            if (weight == Players[i].weight)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        for (int i = middle + 1; i < countOfPlayers; i++)
                            if (weight == Players[i].weight)
                                cout << Players[i].id << " | " << Players[i].name << " | " << Players[i].surname << " | " << Players[i].middleName << " | " << Players[i].gameNumber << " | " << Players[i].age << " | " << Players[i].height << " | " << Players[i].weight << " | " << Players[i].country << " | " << Players[i].team << endl;
                            else
                                break;

                        break;
                    }
                }
            }
                break;
            case 0:
                return;
        }

        if (!find)
            cout << endl << "Совпадений не найдено: " << endl;
    }
}

void sortDatabase () {
    if (checkMemory())
        return;

    if (countOfPlayers < 2) {
        cout << endl << "В памяти находится один игрок" << endl;
        return;
    }
    
    int menu = 0;
    cout << endl << "Сортировка БД" << endl;
    while (!(menu > 0 && menu < 3)) {
        cout << "1 - Метод прямого выбора" << endl;
        cout << "2 - Быстрая сортировка" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    switch (menu) {
        case 1:
            selectionSort();
            break;
        case 2:
            quickSort();
    }

    cout << endl << "Сортировка успешно завершена" << endl;
}

int main() {
    enterDatabaseName();
    
    while (true) {
        int menu;
        cout << endl << "Меню работы с БД \"" << fileName << "\": " << endl;
        cout << "1 - Проверка на существование БД" << endl;
        cout << "2 - Создание/форматирование БД" << endl;
        cout << "3 - Чтение БД в оперативную память ПК" << endl;
        cout << "4 - Показать БД из оперативной памяти" << endl;
        cout << "5 - Добавление информации в БД" << endl;
        cout << "6 - Удаление информации из БД" << endl;
        cout << "7 - Редактирование информации в БД" << endl;
        cout << "8 - Выбрать другую БД" << endl;
        cout << "9 - Перенос БД из оперативной памяти в файл (с форматированием файла)" << endl;
        cout << "10 - Очистка памяти" << endl;
        cout << "11 - Линейный поиск" << endl;
        cout << "12 - Сортировка" << endl;
        cout << "13 - Двоичный поиск" << endl;
        cout << "0 - Завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        switch (menu) {
            case 1:
                checkIfDatabaseExist();
                break;
            case 2:
                create_formatDatabase();
                break;
            case 3:
                readDataBase();
                break;
            case 4:
                showDatabase();
                break;
            case 5:
                writeDataToEnd();
                break;
            case 6:
                removePlayer();
                break;
            case 7:
                editPlayer();
                break;
            case 8:
                enterDatabaseName();
                break;
            case 9:
                moveToFile();
                break;
            case 10:
                cleanMemory();
                break;
            case 11:
                linearSearch();
                break;
            case 12:
                sortDatabase();
                break;
            case 13:
                binarySearch();
                break;
            case 0:
                exit();
        }
    }
}