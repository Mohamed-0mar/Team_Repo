#include "A1_P1_GroupB_20220504-20220505-20221251_header.h"
#include <regex>

BigDecimalInt:: BigDecimalInt(string decStr)
{
    regex entry_pattern("[+-]?[0-9][0-9]*");
    if(regex_match(decStr, entry_pattern))
    {
        if(decStr[0] == '+' || decStr[0] == '-'){
            sign = decStr[0];
            decStr.erase(0,1);
        }
        else{
            sign = '+';
        }
        int i = 0;
        while(decStr[i] == '0' && decStr[i] != '\0'){
            i++;
        }
        if(decStr[i] == '\0')
        {
            value = "0";
        }
        else
        {
            if(i != 0)
                decStr.erase(0, i); 
            value = decStr;
            cout << value << endl;
        }
    }
    else
    {
        cout << "Invalid Entry";
    }
}

BigDecimalInt :: BigDecimalInt(int decInt)
{
    if(decInt < 0)
    {
        sign = '-';
        decInt * -1;
    }
    else if (decInt >= 0)
    {
        sign = '+';
    }
    value = to_string(decInt);
    cout << value << endl;
}
BigDecimalInt BigDecimalInt :: operator+(BigDecimalInt anotherDec)
{
    string res = "0";
    BigDecimalInt result_obj(res);
    if(sign == anotherDec.sign)
    {
        result_obj.sign = sign;
        if(value.length() >= anotherDec.value.length())
        {
            int carry = 0;
            res = value;
            for(int i = value.length()-1, j = anotherDec.value.length()-1;j>=0;i--,j--)
            {
                int tmp_res = (value[i]-'0') + (anotherDec.value[j]-'0') + carry;
                carry = (tmp_res/10)%10;
                res[i] = (tmp_res%10)+'0';
            }
            for(int i = value.length() - anotherDec.value.length()-1;i>=0;i--)
            {
                int tmp_res = ((res[i]-'0') + carry);
                res[i] = ((res[i]-'0') + carry)%10+'0';
                carry = (tmp_res/10) %10;
            }
            if(carry != 0)
            {
                res.insert(0, 1, carry+'0');
            }
        }
        else
        {
            int carry = 0;
            res = anotherDec.value;
            for(int i = anotherDec.value.length()-1, j = value.length()-1;j>=0;i--,j--)
            {
                int tmp_res = (value[j]-'0') + (anotherDec.value[i]- '0') + carry;
                carry = (tmp_res/10)%10;
                res[i] = (tmp_res%10) + '0';
            }
            for(int i = anotherDec.value.length() - value.length()-1;i>=0;i--)
            {
                int tmp_res = ((res[i]-'0') + carry);
                res[i] = ((res[i]-'0') + carry)%10+'0';
                carry = (tmp_res/10) %10;
            }
            if(carry != 0)
            {
                res.insert(0, 1, carry+'0');
            }
        }
    }
    else
    {
        // mohammed omar implementation for the subtraction operator
    }
    result_obj.value = res;
    cout << res;
    return result_obj;
}
string BigDecimalInt :: get_value()
{
    return value;
}
void BigDecimalInt :: set_value(string res)
{
    value = res;
}