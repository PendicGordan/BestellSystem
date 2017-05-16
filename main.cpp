#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

#include "LessThanZero.h"
#include "Table.h"
#include "Restaurant.h"

using namespace std;

void printOptions();
vector<string> split(const string& input, char c = ' ');
int intOption(const vector<string>& vec);

int main()
{
    int num;
    cout << "How many tables are in restaurant? ";

    try{

    cin >> num;
    LessThanZeroException::check(num);

    }catch(LessThanZeroException ltz){
        cout << ltz.what();
        exit(1);
    }

    cin.ignore(INT_MAX, '\n');

    Restaurant restaurant{num};

    cout << "-------------------------------------------------" << endl;

    vector<string> orders;
    stringstream ss;
    ss << num;
    orders.push_back(ss.str());

    while(1){

        printOptions();

        bool flag = false; // variable for getting out from the while loop above

        int table;
        stringstream dish_name;
        string dish;

        string input; // input string
        getline(cin, input);

        vector<string> options = split(input);

        switch(intOption(options)){
            case 0:
                cout << restaurant.available_tables(restaurant.getTables()) << endl;
            break;
            case 1:

                istringstream(options.at(1)) >> table;
                restaurant.take_table(table, restaurant.getTables());
            break;
            case 2:
                istringstream(options.at(1)) >> table;

                for(int i=2; i < options.size(); i++){
                    dish_name << options.at(i);
                    if(options.size() > 3){
                        if(options.size()-1 != i){
                            dish_name << " ";
                        }
                    }
                }

                dish = dish_name.str();

                restaurant.take_order(table, dish, orders, restaurant.getTables());
            break;
            case 3:
                restaurant.process(orders);
                orders.push_back(ss.str());
            break;
            default:
                try{
                    throw runtime_error("Unknown option");
                }catch(runtime_error re){
                    re.what();
                    flag = true;
                }
            break;
        }

        if(flag)break;

    }

    return 0;
}

void printOptions(){
    cout << "\nChoose an option:\n";
    cout << "available_tables --> shows which tables are available\n";
    cout << "take number_of_table --> taking table with number number_of_tables\n";
    cout << "order number_of_table name_of_dish/drink --> ordering some dish or drink for table number_of_table\n";
    cout << "process --> process all orders to that moment\n\n";
}

vector<string> split(const string& input, char c){

    const char* str = input.c_str();

    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    }while (0 != *str++);

    return result;
}

int intOption(const vector<string>& vec){
    if(vec.at(0) == "available_tables"){
        return 0;
    }else if(vec.at(0) == "take"){
        return 1;
    }else if(vec.at(0) == "order"){
        return 2;
    }else if(vec.at(0) == "process"){
        return 3;
    }

    return 4;
}
