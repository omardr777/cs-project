////Omar Hejazi 2230009001, Momen Rabah 2230009004, Abdullah Tumah 2230009012
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//const int LIMIT = 100;
//const int NUM_OF_STORGES = 50;
//const int NUM_OF_PRODUCTS = 50;
//const int MAX_PRODUCTS_IN_STORAGE = 5;
//const string STORAGE_PATH = "storage.txt";
//const string PRODUCT_PATH = "product.txt";
//int sSize = 0;
//int pSize = 0;
//
//struct Product {
//	string id;
//	string name;
//	string storageId;
//};
//
//struct Storage {
//	string id;
//	string rows;
//	string columns;
//	string productsIds[MAX_PRODUCTS_IN_STORAGE];
//};
//
//void printLn(string message){
//	cout << message << endl;
//}
//void printDivider(){
//	printLn("================================");
//}
//void displayProduct(Product p){
//	cout << "ID: " << p.id << ", Storage ID: "<<endl;
//}
//
//Products[] 
//
//void getProductsIdsFromFileLine(const string& s, int len, string ids[]) {
//    int index = 0;
//    string num = "";
//
//    for (int i = 0; i < len; ++i) {
//        if (s[i] != ' ') {
//            num += s[i];
//            if (i == len - 1 || s[i + 1] == ' ') {
//                ids[index++] = num;
//                num = "";
//            }
//        }
//    }
//}
//
//void loadStorages(Storage s[]){
//	ifstream inFile(STORAGE_PATH.c_str());
//	if(inFile.is_open()){
//		int counter = 0;
//		sSize=0;
//		while(!inFile.eof()){
//			string idsFromFile;
//			getline(inFile,s[counter].id);
//			getline(inFile,s[counter].rows);
//			getline(inFile,s[counter].columns);
//			getline(inFile,idsFromFile);
//			int idsLength = idsFromFile.length();
//			string ids[idsLength];
//			getProductsIdsFromFileLine(idsFromFile,idsLength,ids);
//			for (int i = 0; i < idsLength; ++i) {
//                s[counter].productsIds[i] = ids[i];
//            }
//        	counter++;
//        	sSize++;
//		}
//		sSize --;
//	}else{
//		printLn("Fail");
//	}
//}
//
//
//void loadData(Storage s[],Product p[]){
//	loadStorages(s);
////	loadProducts(p);
//}
//
//void addStorage(Storage s[]) {	
//    string id, rows, columns;
//    int choice;
//    do{
//    cout << "Enter the id: ";
//    cin >> id;
//    cout << "Enter the number of rows: ";
//    cin >> rows;
//    cout << "Enter the number of columns: ";
//    cin >> columns;
//
//    s[sSize].id = id;
//    s[sSize].rows = rows;
//    s[sSize].columns = columns;
//    for (int i = 0; i < MAX_PRODUCTS_IN_STORAGE; ++i) {
//        s[sSize].productsIds[i] = "";
//    }
//    sSize++;
//    
//    printLn("\nEnter -1 to quit: ");
//    cin >> choice;
//	}while(choice != -1);
//	printLn("Storages have been added successfully.");
//}
//
//void saveStorages(Storage s[]){
//	ofstream oFile(STORAGE_PATH.c_str());
//	if(oFile.is_open()){
//		for(int i =0; i < sSize; i++){
//			oFile << s[i].id << endl;
//			oFile << s[i].rows << endl;
//			oFile << s[i].columns << endl;
//			string products = "";
//			for(int j =0; j < MAX_PRODUCTS_IN_STORAGE; j++){
//				if(s[i].productsIds[j] != ""){
//					products += s[i].productsIds[j] + " ";
//				}
//			}
//			oFile << products << endl;
//		}
//	}else{
//		printLn("Fail");
//	}
//}
//
//void displayStorages(Storage s[]) {
//    if (sSize == 0) {
//        cout << "No storages available." << endl;
//        return;
//    }
//
//    for (int i = 0; i < sSize; ++i) {
//        cout << "Storage ID: " << s[i].id << ", ";
//        cout << "Number of Rows: " << s[i].rows << ", ";
//        cout << "Number of Columns: " << s[i].columns << ", ";
//
//        bool hasProducts = false;
//        cout << "Products in Storage: ";
//        for (int j = 0; j < MAX_PRODUCTS_IN_STORAGE; ++j) {
//            if (!s[i].productsIds[j].empty()) {
//                cout << "Product ID: " << s[i].productsIds[j];
//                hasProducts = true;
//                if (j < MAX_PRODUCTS_IN_STORAGE - 1 && !s[i].productsIds[j + 1].empty()) {
//                    cout << ", ";
//                }
//            }
//        }
//        if (!hasProducts) {
//            cout << "No products were added.";
//        }
//        cout << endl;
//    }
//}
//
//void runStorage(Storage s[]){
//	bool isRunning = true;
//	while(isRunning){
//		int userInput;
//		cout << "Select from the menu: \n1]Add Storage. \n2]Remove Storage. \n3]Review Storage. \n4]Return to main menu." << endl;
//		cin >> userInput;
//		switch (userInput){
//			case 1: {
//				printDivider();
//				printLn("Add Storage:");
//				addStorage(s);
//				saveStorages(s);
//				loadStorages(s);
//				printDivider();
//				break;
//			}
//			case 2: {
//				cout << "Remove Storage" << endl;
//				break;
//			}
//			case 3: {
//				printDivider();
//				printLn("Review Storage");
//				displayStorages(s);
//				printDivider();
//				break;
//			}
//			case 4:{
//				cout << "Return to main menu" << endl;
//				isRunning = false;
//				break;
//			}
//			default:{
//				cout << "Please select from 1 to 4 only!" << endl;
//				break;
//			}
//		}
//	}
//}
//
//void run(Storage s[], Product p[]){
//	bool isRunning = true;
//	while(isRunning){
//		int userInput;
//		printLn("Select from the menu: \n1]Storage management. \n2]Product management. \n3]Exit.");
//		cin >> userInput;
//		switch (userInput){
//			case 1: {
//				runStorage(s);
//				break;
//			}
//			case 2: {
//				printLn("Product management");
//				break;
//			}
//			case 3: {
//				printLn("Exit!");
//				isRunning = false;
//				break;
//			}
//			default:{
//				printLn("Please select from 1 to 3 only!");
//				break;
//			}
//		}
//	}
//}
//
//int main(int argc, char** argv) {
//	Storage storages[LIMIT];
//	Product products[LIMIT];
//	loadData(storages,products);
//	run(storages,products);
//	return 0;
//}


#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    int quantity;
};

struct Warehouse {
    string name;
    Product products[100];
    int productCount;
};

Warehouse warehouses[10];
int warehouseCount = 0;

void addProduct() {
    string productName;
    int productQuantity;
    int warehouseIndex;

    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter product quantity: ";
    cin >> productQuantity;
    cout << "Enter warehouse index to add the product to: ";
    cin >> warehouseIndex;

    if (warehouseIndex >= 0 && warehouseIndex < warehouseCount) {
        warehouses[warehouseIndex].products[warehouses[warehouseIndex].productCount].name = productName;
        warehouses[warehouseIndex].products[warehouses[warehouseIndex].productCount].quantity = productQuantity;
        warehouses[warehouseIndex].productCount++;
        cout << "Product added successfully!" << endl;
    } else {
        cout << "Invalid warehouse index!" << endl;
    }
}

void searchProduct() {
    string productName;

    cout << "Enter product name to search: ";
    cin >> productName;

    bool found = false;
    for (int i = 0; i < warehouseCount; i++) {
        for (int j = 0; j < warehouses[i].productCount; j++) {
            if (warehouses[i].products[j].name == productName) {
                cout << "Product found in warehouse: " << warehouses[i].name << endl;
                cout << "Quantity: " << warehouses[i].products[j].quantity << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Product not found!" << endl;
    }
}

void deleteProduct() {
    string productName;

    cout << "Enter product name to delete: ";
    cin >> productName;

    for (int i = 0; i < warehouseCount; i++) {
        for (int j = 0; j < warehouses[i].productCount; j++) {
            if (warehouses[i].products[j].name == productName) {
                for (int k = j; k < warehouses[i].productCount - 1; k++) {
                    warehouses[i].products[k] = warehouses[i].products[k + 1];
                }
                warehouses[i].productCount--;
                cout << "Product deleted successfully!" << endl;
                return;
            }
        }
    }

    cout << "Product not found!" << endl;
}

void transferProduct() {
    string productName;
    int sourceIndex, destinationIndex;

    cout << "Enter product name to transfer: ";
    cin >> productName;
    cout << "Enter source warehouse index: ";
    cin >> sourceIndex;
    cout << "Enter destination warehouse index: ";
    cin >> destinationIndex;

    if (sourceIndex >= 0 && sourceIndex < warehouseCount &&
        destinationIndex >= 0 && destinationIndex < warehouseCount) {
        int sourceProductIndex = -1;

        for (int i = 0; i < warehouses[sourceIndex].productCount; i++) {
            if (warehouses[sourceIndex].products[i].name == productName) {
                sourceProductIndex = i;
                break;
            }
        }

        if (sourceProductIndex != -1) {
            warehouses[destinationIndex].products[warehouses[destinationIndex].productCount] = warehouses[sourceIndex].products[sourceProductIndex];
            warehouses[destinationIndex].productCount++;
            for (int i = sourceProductIndex; i < warehouses[sourceIndex].productCount - 1; i++) {
                warehouses[sourceIndex].products[i] = warehouses[sourceIndex].products[i + 1];
            }
            warehouses[sourceIndex].productCount--;
            cout << "Product transferred successfully!" << endl;
        } else {
            cout << "Product not found in source warehouse!" << endl;
        }
    } else {
        cout << "Invalid warehouse indices!" << endl;
    }
}

void addWarehouse() {
    cout << "Enter warehouse name: ";
    cin >> warehouses[warehouseCount].name;
    warehouses[warehouseCount].productCount = 0;
    warehouseCount++;
    cout << "Warehouse added successfully!" << endl;
}

void previewWarehouse() {
    int warehouseIndex;

    cout << "Enter warehouse index to preview: ";
    cin >> warehouseIndex;

    if (warehouseIndex >= 0 && warehouseIndex < warehouseCount) {
        cout << "Warehouse name: " << warehouses[warehouseIndex].name << endl;
        cout << "Products: " << endl;
        for (int i = 0; i < warehouses[warehouseIndex].productCount; i++) {
            cout << "Name: " << warehouses[warehouseIndex].products[i].name << ", Quantity: " << warehouses[warehouseIndex].products[i].quantity << endl;
        }
    } else {
        cout << "Invalid warehouse index!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Menu page: " << endl;
        cout << "1. Products" << endl;
        cout << "2. Warehouses" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int productChoice;

                cout << "Products page: " << endl;
                cout << "1. Add product" << endl;
                cout << "2. Search for product" << endl;
                cout << "3. Delete product" << endl;
                cout << "4. Transfer product" << endl;
                cout << "Enter your choice: ";
                cin >> productChoice;

                switch (productChoice) {
                    case 1:
                        addProduct();
                        break;
                    case 2:
                        searchProduct();
                        break;
                    case 3:
                        deleteProduct();
                        break;
                    case 4:
                        transferProduct();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            case 2:
                int warehouseChoice;

                cout << "Warehouses page: " << endl;
                cout << "1. Add warehouse" << endl;
                cout << "2. Preview a warehouse" << endl;
                cout << "Enter your choice: ";
                cin >> warehouseChoice;

                switch (warehouseChoice) {
                    case 1:
                        addWarehouse();
                        break;
                    case 2:
                        previewWarehouse();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}
