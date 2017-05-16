#include "Table.h"

Table::Table(int id): number_id{id}, taken{false}{}

void Table::getTable(bool b){
    taken = b;
}

bool Table::isTaken() const{
    return taken;
}

int Table::getNumberId() const{
    return number_id;
}
