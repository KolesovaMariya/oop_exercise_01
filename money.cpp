#include "money.h"
#include <iostream>
Money::Money() {
    rub = 0;
    kop = 0;
}
Money::Money(unsigned long long r, unsigned char k) {
    rub = r;
    kop = k;
}

unsigned long long Money::GetRub() const {
    return rub;
}
unsigned char Money::GetKop() const {
    return kop;
}

bool Money::More(const Money &b) const {
    if (rub == b.rub) {
        return kop > b.kop;
    }
    return rub > b.rub;
}
bool Money::Less(const Money &b) const {
    if (rub == b.rub) {
        return kop < b.kop;
    }
    return rub < b.rub;
}
bool Money::Equal(const Money &b) const {
    if (rub == b.rub) {
        return kop == b.kop;
    }
    return false;
}

Money Money::Sum(const Money &b) const {
    Money tmp = {rub, kop};
    tmp.rub = rub + b.rub;
    tmp.kop = kop + b.kop;
    if (tmp.kop > 99) {
        tmp.rub +=1;
        tmp.kop -= 100;
    }
    return tmp;
}
Money Money::Sub(const Money &b) const {
    unsigned char sub_kop = this->GetKop();
    unsigned long long sub_rub = this->GetRub();
    if(Less(b)) {
        return {0, 0};
    }
    Money tmp = {sub_rub, sub_kop};
    tmp.rub = sub_rub - b.rub;
    if (sub_kop < b.kop) {
        tmp.rub -= 1;
        sub_kop += 100;
    }
    tmp.kop = sub_kop - b.kop;
    return tmp;
}
Money Money::Mlt(const double &b) const {
    Money tmp_m;
    unsigned long long tmp = rub*100 + kop;
    double result = tmp*b;
//    std::cout << (int)kop << std::endl;
    tmp_m.rub = (unsigned long long)result/100;
    tmp_m.kop = (unsigned char)((unsigned long long )result%100);
    return tmp_m;
}
Money Money::DivFract(const double &b) const {
    Money tmp_money;
    unsigned long long tmp = rub*100 + kop;
    tmp /= b;
    tmp_money.kop = tmp%100;
    tmp_money.rub = tmp/100;
    return tmp_money;
}
Money Money::Div(const Money &b) const {
    Money tmp_money;
    unsigned long long tmp_1 = rub*10000 + (int)kop*100;
    unsigned long long tmp_2 = b.rub*100 + b.kop;
    unsigned long long result = tmp_1/tmp_2;
    tmp_money.rub = result/100;
    tmp_money.kop = result%100;
    return tmp_money;
}
void Money::Print() const {
    if (GetKop() > 9) {
        std::cout << GetRub() << "," << (int)GetKop() << std::endl;
    } else {
        std::cout << GetRub() << "," << "0" << (int)GetKop() << std::endl;
    }

}
void Money::Read() {
    rub = 0;
    kop = 0;
    int i = 0;
    char a[20];
    std::cin >> a;
    while ((a[i] != ',') && (a[i] != '.') && (a[i] != 0)) {
        rub = rub*10 + (int)(a[i] - '0');
        i++;
    }
    if (a[i] != 0) {
        i += 1;
        kop += (a[i]-'0')*10;
        i++;
        if (a[i] != 0) {
            kop += (a[i] -'0');
        }
    }
}






