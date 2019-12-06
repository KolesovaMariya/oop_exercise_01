#ifndef LAB1_MONEY_H
#define LAB1_MONEY_H

class Money {
public:
    Money();
    Money(unsigned long long r, unsigned char k);

    unsigned long long GetRub() const;
    unsigned char GetKop() const;


    Money Sum(const Money &b) const;
    Money Sub(const Money &b) const;
    Money Mlt(const double &b) const;
    Money DivFract(const double &b) const; //деление на дробное число
    Money Div(const Money &b) const; //деление на Money

    bool More(const Money &b) const;
    bool Less(const Money &b) const;
    bool Equal(const Money &b) const;

    void Print() const;
    void Read();

private:
    unsigned long long rub;
    unsigned char kop;
};
#endif //LAB1_MONEY_H
