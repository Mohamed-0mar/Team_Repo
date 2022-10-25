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
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
    if(value=="0"){
        if(anotherDec.sign=='-')anotherDec.sign='+';
        else anotherDec.sign='-';
        return anotherDec;
    }
    else if(anotherDec.value=="0"){
        BigDecimalInt temp("");
        temp.sign=sign;
        temp.value=value;
        return temp;
    }
    else if(sign==anotherDec.sign){
        long long com_length=max(value.size(),anotherDec.value.size());
         BigDecimalInt sum2("0");
        string to_10scom;
        if(sign=='-'){
            to_10scom=value;
           sum2.value=anotherDec.value;
           sum2.sign='+';
            }
        else{
            to_10scom=anotherDec.value;
           sum2.value=value;
           sum2.sign=sign;
            }
        long long to_10scom_length=to_10scom.length();
        string _10scom="";
        for(long long i=to_10scom_length-1;i>=0;i--){
            _10scom=char('9'-to_10scom[i]+'0')+_10scom;
        }
        for(long long i=0;i<(com_length-to_10scom_length);i++){
            _10scom='9'+_10scom;
        }
        int carry=0;
        bool first=true;
        for(long long i=_10scom.length()-1;i>=0;i--){
            if(_10scom[i]+carry>='9'){
                   
                    _10scom[i]='0';
                     carry=1;
                     first=false;
            }
            else {
                _10scom[i]=_10scom[i]+carry;
                if(first)_10scom[i]+=1;
                break ;
            }
        }
        BigDecimalInt bid_10scom(_10scom);
        BigDecimalInt sub=bid_10scom+sum2;
        if(sub.value.length()>_10scom.length()){
            sub.value.erase(0,1);
            return sub;
        }
        else {
            sub.sign='-';
            string temp_value="";
            for(long long i=sub.value.length()-1;i>=0;i--){
                temp_value=char('9'-sub.value[i]+'0')+temp_value;
            }
            cout<<endl<<temp_value;
            int carry =0;
            bool first=true;
            for(long long i=temp_value.length()-1;i>=0;i--){
            if(temp_value[i]+carry>='9'){
                 temp_value[i]='0';
                    carry=1;
                    first=false;
                   
            }
            else {
                temp_value[i]=temp_value[i]+carry;
                if(first)temp_value[i]+=1;
                break ;
                 }
            }
            sub.value=temp_value;
            return sub;
        }


    }
    else {
        BigDecimalInt _temp(value);
        if(anotherDec.sign=='-')anotherDec.sign='+';
        else anotherDec.sign='-';
        BigDecimalInt sub=_temp+anotherDec;
        return sub;
    }
    
}
bool BigDecimalInt :: operator< (BigDecimalInt anotherDec){
    if(anotherDec.sign==sign){
        long long anotherDec_lenght=anotherDec.value.length();
        long long this_length=value.length();

        if(this_length==anotherDec_lenght){
            for(long long i=0;i<this_length;i++){
                if(value[i]!=anotherDec.value[i]){
                    if(value[i]<anotherDec.value[i]){
                        if(sign=='+')return true;
                        else return false;
                    }
                    else {
                        if(sign=='-')return true;
                        else return false;
                    }
                }
            }
            return false;
        }
        else if(sign=='+'){
            if(this_length<anotherDec_lenght)return true;
            else return false;
        }
        else {
             if(this_length>anotherDec_lenght)return true;
            else return false;
        }
    }
    else{
        if(anotherDec.sign=='+')return true;
        else return false;
    }
}
