#ifndef Table_H
#define Table_H


class Table
{
    public:
        Table(int);

        void getTable(bool taken);
        bool isTaken() const;
        int getNumberId() const;

    private:
    int number_id;
    bool taken;
};
#endif // Table_H
