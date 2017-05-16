#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Restaurant.h"
#include "Table.h"

using namespace std;

Restaurant::Restaurant(int numberOfTables){
    for(int i=0; i < numberOfTables; i++){
        tables.push_back(Table(tables.size()+1));
    }
}

void Restaurant::take_table(unsigned int table_id, vector<Table>& tables){

        if(table_id-1 >= tables.size()){
            cout << "error: table " << table_id << " not available" << endl;
            return;
        }

        if(tables.at(table_id-1).isTaken()){
            cout << "Table is already taken." << endl;
        }else{
            tables.at(table_id-1).getTable(true);
            cout << "Taking table number " << table_id << "." << endl;
        }
}

string Restaurant::available_tables(const vector<Table>& tables){
    stringstream res;

    for(int i=0; i < tables.size(); i++){
        if(tables.at(i).isTaken() == false){
            res << tables.at(i).getNumberId();
            res << " ";
        }
    }

    return res.str();
}

void Restaurant::take_order(unsigned int table_id, string dish_name, vector<string>& orders, const vector<Table>& tables){

    if(table_id-1 >= tables.size() || table_id - 1 < 0){
            cout << "error: table " << table_id << " doesn't exist" << endl;
            return;
    }

    if(tables.at(table_id - 1).isTaken() == true){
        stringstream ss;
        ss << table_id;;

        orders.push_back(ss.str());
        orders.push_back(dish_name);

        for(int i=0; i < orders.size(); i++)cout << orders.at(i);

    }else{
        cout << "error: no customer at table " <<  table_id << "\n";
    }

}

void Restaurant::process(vector<string>& orders){

    if(orders.size() == 0){
        cout << "There is no orders\n";
        return;
    }

    cout << "Preparing ";
    for(int i=2; i < orders.size(); i=i+2){
        cout << "\"" << orders.at(i) << "\" ";
    }

    cout << endl;

    for(int i=0; i < atoi(orders.at(0).c_str()); i++){
        vector<string> temp;
        for(int j=2; j < orders.size(); j=j+2){
            if(atoi(orders.at(j-1).c_str()) == i+1){
                temp.push_back(orders.at(j));
            }
        }

        for(int k=0; k<temp.size(); k++){
            if(k == 0)cout << "Delivering ";
            cout << "\"" << temp.at(k) << "\" ";
            if(k+1 == temp.size())cout << "to Table " << i+1 << endl;
        }
    }

    orders.erase(orders.begin(), orders.end());

}

vector<Table>& Restaurant::getTables(){
    return tables;
}

