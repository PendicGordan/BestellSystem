#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <string>

#include "Table.h"

using namespace std;

class Restaurant
{
    public:
        Restaurant(int numberOfTables);
        void take_table(unsigned int table_id, vector<Table>& tables);
        string available_tables(const vector<Table>& tables);
        void take_order(unsigned int table_id, string dish_name, vector<string>& orders, const vector<Table>& tables);
        void process(vector<string>& orders);

        vector<Table>& getTables();

    private:

    vector<Table> tables;
};

#endif // RESTAURANT_H
