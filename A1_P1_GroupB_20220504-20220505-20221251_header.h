#include <iostream>
using namespace std;
class BigDecimalInt{
    private:
        char sign;
        string value;
        int decimal_value;
    public:
    string get_value();
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    void set_value(string res);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
};
