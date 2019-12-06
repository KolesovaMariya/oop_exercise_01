#ifndef LAB1_MONEY_H
#define LAB1_MONEY_H

class Money {
public:
    Money();
    Money(unsigned long long r, unsigned char k);

    unsigned long long GetRub();
    unsigned char GetKop();


    Money Sum(const Money &b);
    Money Sub(const Money &b);
    Money Mlt(const double &b);
    Money DivFract(const double &b); //деление на дробное число
    Money Div(const Money &b); //деление на Money

    bool More(const Money &b);
    bool Less(const Money &b);
    bool Equal(const Money &b);

    void Print();
    void Read();

private:
    unsigned long long rub;
    unsigned char kop;
};
#endif //LAB1_MONEY_H
