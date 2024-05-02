//Omar Hejazi 2230009001, Momen Rabah 2230009004, Abdullah Tumah 2230009012
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int LIMIT = 100;
const int MAX_HISTORY_SIZE = 200;
const string STORAGE_PATH = "storage.txt";
const string PRODUCT_PATH = "product.txt";
const string HISTORY_PATH = "history.txt";
int sSize = 0;
int pSize = 0;
int hSize = 0;
string history[MAX_HISTORY_SIZE];

struct Product {
	int id;
	string name;
	int storageId;
	int row;
	int column;
};

struct Storage {
	int id;
	int rows;
	int columns;
};


void printLn(string message);
void printDivider();
void printThinDivider();
void recordAction(string action);
void loadHistory();
void saveHistory();
void displayHistory();
void performActionSaveAndLoad(string action);
string intToString(int num);
int stringToInt(const string& str);
void loadProducts(Product p[]);
void loadStorages(Storage s[]);
void loadData(Storage s[], Product p[]);
void addStorage(Storage s[]);
Storage searchStorage(Storage s[], int id);
void saveStorages(Storage s[]);
void removeStorage(Storage s[], int storageId);
bool isValidRowColumn(Storage& storage, int row, int column);
bool isRowColumnAvailable(Product p[], int sId, int row, int column);
void display(Storage s, Product p[]);
void displayStorages(Storage s[], Product p[]);
Product searchProduct(Product p[], int id);
void runStorage(Storage s[], Product p[]);
void saveProducts(Product p[]);
void display(Product& p);
void displayProducts(Product p[]);
void updateProduct(Product p[], Storage s[]);
void addProduct(Product p[], Storage s[]);
void removeProduct(Product p[], int productId);
void runProduct(Product p[], Storage s[]);
void run(Storage s[], Product p[]);
void bubbleSortProducts(Product p[], int size);

void printLn(string message){
	cout << message << endl;
}

void printDivider(){
	printLn("================================");
}

void printThinDivider(){
	printLn("-------------------------------------");
}

void recordAction(string action) {
    if (hSize < MAX_HISTORY_SIZE) {
        time_t now = time(0);
        char* dt = ctime(&now);
        string timestamp(dt);

        string record = "The user choose to " + action + " at " + timestamp;

        history[hSize] = record;
        hSize++;
    } else {
        cout << "History is full. Cannot record more actions." << endl;
    }
}

void loadHistory() {
    ifstream inFile(HISTORY_PATH.c_str());
    if (inFile.is_open()) {
        string line;
        hSize = 0;
        while (getline(inFile, line)) {
            history[hSize] = line;
            hSize++;
            if (hSize >= MAX_HISTORY_SIZE) {
                break;
            }
        }
        inFile.close();
    } else {
        cout << "Unable to open history file: " << endl;
    }
}

void saveHistory() {
    ofstream outFile(HISTORY_PATH.c_str());
    if (outFile.is_open()) {
        for (int i = 0; i < hSize; ++i) {
            outFile << history[i] << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open history file for writing." << endl;
    }
}

void displayHistory() {
    if (hSize == 0) {
        cout << "No history available." << endl;
        return;
    }
    cout << "Action History:" << endl;
    printThinDivider();
    for (int i = 0; i < hSize; ++i) {
        cout << history[i] << endl;
    }
}

void performActionSaveAndLoad(string action){
	recordAction(action);
	saveHistory();
	loadHistory();
}

string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

int stringToInt(const string& str) {
    stringstream ss(str);
    int num = 0;
    ss >> num;
    return num;
}

void loadProducts(Product p[]) {
    ifstream inFile(PRODUCT_PATH.c_str());
    if (inFile.is_open()) {
        int counter = 0;
        pSize = 0;
        while (!inFile.eof()) {
            string idFromFile, nameFromFile, storageIdFromFile,rowFromFile,columnFromFile;
            getline(inFile, idFromFile);
            p[counter].id = stringToInt(idFromFile);
            getline(inFile, nameFromFile);
            p[counter].name = nameFromFile;
            getline(inFile, storageIdFromFile);
            p[counter].storageId = stringToInt(storageIdFromFile);
            getline(inFile, rowFromFile);
            p[counter].row = stringToInt(rowFromFile);
            getline(inFile, columnFromFile);
            p[counter].column = stringToInt(columnFromFile);
            counter++;
            pSize++;
        }
        pSize--;
    } else {
        printLn("Failed to open product file.");
    }
}

void loadStorages(Storage s[]){
	ifstream inFile(STORAGE_PATH.c_str());
	if(inFile.is_open()){
		sSize=0;
		while(!inFile.eof()){
			string idFromFile,rowFromFile,columnFromFile;
			getline(inFile,idFromFile);
			s[sSize].id = stringToInt(idFromFile);
			getline(inFile,rowFromFile);
			s[sSize].rows = stringToInt(rowFromFile);
			getline(inFile,columnFromFile);
			s[sSize].columns = stringToInt(columnFromFile);
        	sSize++;
		}
		sSize --;
	}else{
		printLn("Fail");
	}
}

void loadData(Storage s[],Product p[]){
	loadStorages(s);
	loadProducts(p);
}

void addStorage(Storage s[]) {	
    int rows, columns;
    int choice;
    do{
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    s[sSize].id = sSize+1;
    s[sSize].rows = rows;
    s[sSize].columns = columns;
    sSize++;
    
    printLn("\nEnter -1 to quit: ");
    cin >> choice;
	}while(choice != -1);
	printLn("Storages have been added successfully.");
	
}

Storage searchStorage(Storage s[], int id) {
    for (int i = 0; i < sSize; ++i) {
        if (s[i].id == id) {
            return s[i];
        }
    }
    return {-1,-1,-1};
}

void saveStorages(Storage s[]){
	ofstream oFile(STORAGE_PATH.c_str());
	if(oFile.is_open()){
		for(int i =0; i < sSize; i++){
			oFile << s[i].id << endl;
			oFile << s[i].rows << endl;
			oFile << s[i].columns << endl;
		}
	}else{
		printLn("Fail");
	}
}

void removeStorage(Storage s[], int storageId) {
    int index = -1;
    for (int i = 0; i < sSize; ++i) {
        if (s[i].id == storageId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < sSize - 1; ++i) {
            s[i] = s[i + 1];
        }
        sSize--;
        printLn("Storage removed successfully.");
    } else {
        printLn("Storage not found.");
    }
}

bool isValidRowColumn(Storage& storage, int row, int column) {
    return (row >= 1 && row <= storage.rows && column >= 1 && column <= storage.columns);
}

bool isRowColumnAvailable(Product p[], int sId, int row, int column,int id) {
    for (int i = 0; i < pSize; ++i) {
        if (p[i].storageId == sId && p[i].row == row && p[i].column == column && p[i].id != id) {
            return false;
        }
    }
    return true;
}

void display(Storage s,Product p[]) {
    cout << "Storage ID: " << s.id << ", Number of Rows: " << s.rows << ", Number of Columns: " << s.columns << endl;

    bool hasProducts = false;
    for (int i = 0; i < pSize; ++i) {
        if (p[i].storageId == s.id) {
            cout << "Product ID: " << p[i].id << ", Name: " << p[i].name << ", Row: " << p[i].row << ", Column: " << p[i].column << endl;
            hasProducts = true;
        }
    }
    if (!hasProducts) {
        printLn("No products in this storage.");
    }
	printThinDivider();
}

void displayStorages(Storage s[],Product p[]) {
    if (sSize == 0) {
        cout << "No storages available." << endl;
        return;
    }

    for (int i = 0; i < sSize; ++i) {
        display(s[i],p);
    }
}

Product searchProduct(Product p[], int id) {
    for (int i = 0; i < pSize; ++i) {
        if (p[i].id == id) {
            return p[i];
        }
    }
    return {-1,"",-1,-1,-1};
}

void runStorage(Storage s[],Product p[]){
	bool isRunning = true;
	while(isRunning){
		int userInput;
		cout << "Select from the menu: \n1]Add Storage. \n2]Remove Storage. \n3]Review Storage. \n4]Search for Storage. \n5]Return to main menu." << endl;
		cin >> userInput;
		switch (userInput){
			case 1: {
				printDivider();
				printLn("Add Storage:");
				addStorage(s);
				saveStorages(s);
				loadStorages(s);
				printDivider();
				performActionSaveAndLoad("Add a storage");
				break;
			}
			case 2: {
				int id;
				printDivider();
				cout << "Remove Storage" << endl;
				printLn("Enter Storage Id: ");
				cin >> id;
				removeStorage(s,id);
				saveStorages(s);
				loadStorages(s);
				printDivider();
				performActionSaveAndLoad("Remove a storage");
				break;
			}
			case 3: {
				printDivider();
				printLn("Review Storage");
				displayStorages(s,p);
				printDivider();
				performActionSaveAndLoad("Review a storage");
				break;
			}
			case 4:{
				int id;
				printDivider();
				printLn("Search by Id: ");
				cin >> id;
				Storage searchedStorage = searchStorage(s,id);
				display(searchedStorage,p);
				printDivider();
				performActionSaveAndLoad("Search for a storage");
				break;
			}
			case 5:{
				cout << "Return to main menu" << endl;
				isRunning = false;
				break;
			}
			default:{
				cout << "Please select from 1 to 5 only!" << endl;
				break;
			}
		}
	}
}

void saveProducts(Product p[]) {
    ofstream oFile(PRODUCT_PATH.c_str());
    if (oFile.is_open()) {
        for (int i = 0; i < pSize; i++) {
            oFile << p[i].id << endl;
            oFile << p[i].name << endl;
            oFile << p[i].storageId << endl;
            oFile << p[i].row << endl;
            oFile << p[i].column << endl;
        }
    } else {
        printLn("Failed to open product file for saving.");
    }
}

void display(Product& p) {
    cout << "ID: " << p.id << ", Name: " << p.name << ", Storage ID: " << p.storageId << ", Row: " << p.row << ", Column: " << p.column << endl;
}

void displayProducts(Product p[]) {
    if (pSize == 0) {
        cout << "No products available." << endl;
        return;
    }

    for (int i = 0; i < pSize; ++i) {
        cout << "Product " << (i + 1) << ": ";
        display(p[i]);
    }
}

void updateProduct(Product p[], Storage s[]) {
    int id;
    cout << "Enter the ID of the product you want to update: ";
    cin >> id;

	int index = -1;
    for (int i = 0; i < pSize; ++i) {
        if (p[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
    	
        int sId, row, column;
        cout << "Enter the new storage ID for the product: ";
        cin >> sId;

        Storage storage = searchStorage(s, sId);
        if (storage.id == -1) {
            cout << "Storage with ID " << sId << " does not exist." << endl;
            return;
        }

        cout << "Enter the new row for the product: ";
        cin >> row;
        cout << "Enter the new column for the product: ";
        cin >> column;

        if (!isValidRowColumn(storage, row, column)) {
            cout << "Invalid row or column for the specified storage, out of range." << endl;
            return;
        }

        if (!isRowColumnAvailable(p, sId, row, column,p[index].id)) {
            cout << "Row " << row << " and column " << column << " are already used by another product." << endl;
            return;
        }

        string newName;
        cout << "Enter the new name for the product: ";
        cin.ignore();
        getline(cin, newName);

        p[index].name = newName;
        p[index].storageId = sId;
        p[index].row = row;
        p[index].column = column;

        cout << "Product with ID " << id << " has been updated successfully." << endl;
        performActionSaveAndLoad("Updated the product with id: " + intToString(p[index].id));
    } else {
        cout << "Product with ID " << id << " not found." << endl;
    }
}

void addProduct(Product p[],Storage s[]) {
    int sId, row, column;
    string name;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter storage ID: ";
    cin >> sId;

    Storage storage = searchStorage(s,sId);
    if (storage.id == -1) {
        cout << "Storage with ID " << sId << " does not exist." << endl;
        return;
    }

    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> column;
	
    if (!isValidRowColumn(storage,row,column)) {
        cout << "Invalid row or column for the specified storage, out of range." << endl;
        return;
    }
    
    
    if (!isRowColumnAvailable(p,sId,row,column,pSize)) {
        cout << "Row " << row << " and column " << column << " are already used by another product." << endl;
        return;
    }

    p[pSize] = {pSize + 1, name, sId, row, column};
    pSize++;
    printLn("Product added successfully.");
}

void bubbleSortProducts(Product p[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (p[j].name > p[j + 1].name) {
                Product temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void removeProduct(Product p[], int productId) {
    int index = -1;
    for (int i = 0; i < pSize; ++i) {
        if (p[i].id == productId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < pSize - 1; ++i) {
            p[i] = p[i + 1];
        }
        pSize--;
        printLn("Product removed successfully.");
    } else {
        printLn("Product not found.");
    }
}

void runProduct(Product p[],Storage s[]){
	bool isRunning = true;
	while(isRunning){
		int userInput;
		cout << "Select from the menu: \n1]Add Product. \n2]Remove Product. \n3]Review Products. \n4]Search for Product. \n5]Update Product. \n6]Sort Products by name. \n7]Return to main menu." << endl;
		cin >> userInput;
		switch (userInput){
			case 1: {
				printDivider();
				printLn("Add Product:");
				addProduct(p,s);
				saveProducts(p);
				loadProducts(p);
				printDivider();
				performActionSaveAndLoad("Add a product");
				break;
			}
			case 2: {
				int id;
				printDivider();
				printLn("Remove Product");
				printLn("Enter Storage Id: ");
				cin >> id;
				removeProduct(p,id);
				saveProducts(p);
				loadProducts(p);
				printDivider();
				performActionSaveAndLoad("Remove a prodcut");
				break;
			}
			case 3: {
				printDivider();
				printLn("Review Products");
				displayProducts(p);
				printDivider();
				performActionSaveAndLoad("Review the products");
				break;
			}
			case 4:{
				int id;
				printDivider();
				printLn("Search by Id: ");
				cin >> id;
				Product searchedProduct = searchProduct(p,id);
				if(searchedProduct.id == -1){
					printLn("No product with this id");
				}
				display(searchedProduct);
				printDivider();
				performActionSaveAndLoad("Search for a product");
				break;
			}
			case 5:{
				printDivider();
                printLn("Update Product");
                updateProduct(p, s);
                saveProducts(p);
                loadProducts(p);
                printDivider();
                performActionSaveAndLoad("Update a product");
				break;
			}
			case 6:{
				Product sortedProducts[LIMIT]; 
                printDivider();
                printLn("Review Sorted Products");
                for (int i = 0; i < pSize; ++i) {
                    sortedProducts[i] = p[i];
                }
                bubbleSortProducts(sortedProducts, pSize);
                displayProducts(sortedProducts);
                printDivider();
                performActionSaveAndLoad("Review sorted products");
				break;
			}
			case 7:{
				cout << "Return to main menu" << endl;
				isRunning = false;
				break;
			}
			default:{
				cout << "Please select from 1 to 6 only!" << endl;
				break;
			}
		}
	}
}

void run(Storage s[], Product p[]){
	bool isRunning = true;
	while(isRunning){
		int userInput;
		printLn("Select from the menu: \n1]Storage management. \n2]Product management. \n3]Show History. \n4]Exit.");
		cin >> userInput;
		switch (userInput){
			case 1: {
				printDivider();
				printLn("Storage management");
				printThinDivider();
				runStorage(s,p);
				printDivider();
				break;
			}
			case 2: {
				printDivider();
				printLn("Product management");
				printThinDivider();
				runProduct(p,s);
				printDivider();
				break;
			}
			case 3:{
				printDivider();
				displayHistory();
				printDivider();
				break;
			}
			case 4: {
				printLn("Exit!");
				isRunning = false;
				break;
			}
			default:{
				printLn("Please select from 1 to 4 only!");
				break;
			}
		}
	}
}

int main(int argc, char** argv) {
	Storage storages[LIMIT];
	Product products[LIMIT];
	loadData(storages,products);
	loadHistory();
	run(storages,products);
	return 0;
}
