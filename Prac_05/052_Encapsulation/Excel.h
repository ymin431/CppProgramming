#include "Cell.cpp"

class Excel {
    public:
        Excel(std::vector<std::vector<Cell>> data);
        double average(int fromRow, int fromCol, int toRow, int toCol) const;
    private:
        std::vector<std::vector<Cell>> data;
};