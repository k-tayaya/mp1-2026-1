#include <iostream>
#include <numeric>
class Rac {
    private:
        int a;
        int b;
        int c;
    public:
        Rac()
        {
            a = 0;
            b = 0;
            c = 1;
        }
        Rac(int a , int b , int c )
        {
            if (c == 0)
            {
                std::cout << "Ââåäåíî íåêîðåêòíîå çíà÷åíèå" << std::endl;
                a = 0;
                b = 0;
                c = 1;
            }
            else
            {
                int nod = std::gcd(b, c);
                this->b = b / nod;
                this->c = c / nod;
                this->a = a + this->b / this->c;
                this->b = (this->b % this->c);
            }
        }
        Rac operator+(const Rac& point1)
        {
            return Rac(0, (b + a * c) * (point1.c) + (point1.b + point1.a * point1.c) * c, point1.c * c);
        }
        Rac operator-(const Rac& point1)
        {
            return Rac(0, (b + a * c) * (point1.c) - (point1.b + point1.a * point1.c) * c, point1.c * c);
        }
        Rac operator*(const Rac& point1)
        {
            return Rac(0, (b + a * c) * (point1.b + point1.a * point1.c), point1.c * c);
        }
        Rac operator/(const Rac& point1)
        {
            return Rac(0, (b + a * c) * point1.c, (point1.b + point1.a * point1.c) * c);
        }
        friend std::ostream& operator<<(std::ostream& os, const Rac& racout) {
            os << racout.a << " " << racout.b << "/" << racout.c;
            return os;
        }
};
class LongLong {
    private:
        int high;  
        unsigned int low;      
    public:
        LongLong() {
            high = 0;
            low = 0;
        }
        LongLong(int h, unsigned int l) {
            high = h;
            low = l;
        }
        LongLong(long long value) {
            high = (int)(value >> 32);
            low = (unsigned int)(value & 0xFFFFFFFF);
        }
        LongLong operator+(const LongLong& other) const {
            LongLong result;
            result.low = low + other.low;
            int carry = 0;
            if (result.low < low) 
                carry = 1;
            result.high = high + other.high + carry;
            return result;
        }
        LongLong operator-(const LongLong& other) const {
            LongLong result;
            result.low = low - other.low;
            int borrow = 0;
            if (low < other.low)
                borrow = 1;
            result.high = high - other.high - borrow;
            return result;
        }
        LongLong operator*(const LongLong& other) const {
            return LongLong(toLongLong()*other.toLongLong());
        }
        LongLong operator/(const LongLong& other) const {
            if (other.toLongLong()==0) {
                std::cout << "Îøèáêà: äåëåíèå íà 0\n"<<std::endl;
                return LongLong();
            }
            return LongLong(toLongLong()/other.toLongLong());
        }
        LongLong operator%(const LongLong& other) const {
            if (other.toLongLong() == 0) {
                std::cout << "Îøèáêà: äåëåíèå íà 0\n"<<std::endl;
                return LongLong();
            }
            return LongLong(toLongLong() % other.toLongLong());
        }
        long long toLongLong() const {
            return ((long long)high << 32) | low;
        }
        friend std::ostream& operator<<(std::ostream& os, const LongLong& longnumber) {
            os << longnumber.toLongLong();
            return os;
        }
};
class Time {
    private:
        int hour;
        int minute;
        int sec;
    public:
        Time() {
            hour = 0;
            minute = 0;
            sec = 0;
        }
        Time(int h , int m , int s ) {
            s =s + m * 60 + h * 3600;
            s %= 86400;
            this->hour = s / 3600;
            this->minute = (s % 3600) / 60;
            this->sec = (s % 3600) % 60;
        }
        void set(int h = 0, int m = 0, int s = 0) {
            s = s + m * 60 + h * 3600;
            s %= 86400;
            this->hour = s / 3600;
            this->minute = (s % 3600) / 60;
            this->sec = (s % 3600) % 60;
        }
        void output() {
            std::cout << "hours: " << hour << " minute: " << minute << " sec: " << sec << std::endl;
        }
        Time time(const Time& t) {
            return Time(abs(hour - t.hour), abs(minute - t.minute), abs(sec - t.sec));
        }
        void shift(int h, int m, int s, bool up)
        {
           int s1 = hour * 3600 + minute * 60 + sec;
           int s2 = h * 3600 + m * 60 + s;
            if (up) this->set(0, 0, s1 + s2);
            else this->set(0, 0,s1 - s2+86400);
        }
};
class Length {
    private:
        double leng;
    public:
        Length()
        {
            leng = 0;
        }
        Length(double l)
        {
            leng = l;
        }
        void set(double l) {
            leng = l;
        }
        void output(int mode=0) {
            if (mode==0) std::cout << "Äëèíà â ìåòðàõ: " << leng << std::endl;
            else if (mode == 1) std::cout << "Äëèíà â cm: " << leng*100 << std::endl;
            else if (mode == 2) std::cout << "Äëèíà â mm: " << leng * 1000 << std::endl;
            else if (mode == 3) std::cout << "Äëèíà â ìèëÿõ: " << leng *0.000621 << std::endl;
            else if (mode == 4) std::cout << "Äëèíà â ÿðäàõ: " << leng *1.093613 << std::endl;
            else if (mode == 5) std::cout << "Äëèíà â äþéìàõ: " << leng*39.37 << std::endl;
            else if (mode == 6) std::cout << "Äëèíà â ôóòàõ: " << leng *3.28084 << std::endl;
            else if (mode == 7) std::cout << "Äëèíà â Km: " << leng / 1000.0f << std::endl;
        }
};
class Weight {
    private:
        double weg;
    public:
        Weight()
        {
            weg = 0;
        }
        Weight(double w)
        {
            weg = w;
        }
        void set(double w) {
            weg = w;
        }
        void output(int mode = 0) {
            if (mode == 0) std::cout << "Âåñ â êã: " << weg << std::endl;
            else if (mode == 1) std::cout << "Âåñ â ã: " << weg * 1000 << std::endl;
            else if (mode == 2) std::cout << "Âåñ â öåíòíåðàõ: " << weg / 100 << std::endl;
            else if (mode == 3) std::cout << "Âåñ â ôóíòàõ: " << weg * 2.2046 << std::endl;
            else if (mode == 4) std::cout << "Âåñ â óíöèÿõ: " << weg * 35.273962 << std::endl;
            else if (mode == 5) std::cout << "Âåñ â êàðàòàõ: " << weg * 5000 << std::endl;
            else if (mode == 6) std::cout << "Âåñ â ïóäàõ: " << weg * 0.061 << std::endl;
            else if (mode == 7) std::cout << "Âåñ â òîííàõ: " << weg / 1000.0f << std::endl;
        }
};
class Temperature {
private:
    double temp;
public:
    Temperature()
    {
        temp = 0;
    }
    Temperature(double t)
    {
        temp = t;
    }
    void set(double t) {
        temp= t;
    }
    void output(int mode = 0) {
        if (mode == 0) std::cout << "Òåìïåðàòóðà â Öåëüñèÿ: " << temp << std::endl;
        else if (mode == 1) std::cout << "Òåìïåðàòóðà â Ôàðåíãåéòà: " << temp * 9 / 5 + 33.8 << std::endl;
        else if (mode == 2) std::cout << "Òåìïåðàòóðà â Êåëüâèíà: " << temp + 273.15 << std::endl;
        else if (mode == 3) std::cout << "Òåìïåðàòóðà â Ðàíêèíà: " << (temp + 273.15)*9/5 << std::endl;
        else if (mode == 4) std::cout << "Òåìïåðàòóðà â Ðåîìþðà: " << temp * 0.8 << std::endl;    
    }
};
void main()
{
    setlocale(LC_ALL, "Russian");
    //1.1
    Rac rac1(1, 5, 3), rac2(2, 10, 7), rac3;
    rac3 = rac1 + rac2;
    std::cout << " ÏÅÐÂÛÉ ÊËÀÑÑ ÐÀÖÈÎÍÀËÜÍÛÅ ×ÈÑËÀ" << std::endl;
    std::cout << rac1 << " + " << rac2 << " = " << rac3 << std::endl;
    std::cout << rac1 << " - " << rac2 << " = " << rac1 - rac2 << std::endl;
    std::cout << rac1 << " * " << rac2 << " = " << rac1 * rac2 << std::endl;
    std::cout << rac1 << " / " << rac2 << " = " << rac1 / rac2 << std::endl;
    //1.2
    LongLong a(2148000000), b(11148000000);
    std::cout << "\n ÂÒÎÐÎÉ ÊËÀÑÑ ÁÎËÜØÈÅ ×ÈÑËÀ" << std::endl;
    std::cout << a << " + " << b << " = " << a+b << std::endl;
    std::cout << a << " - " << b << " = " << a-b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " % " << b << " = " << a % b << std::endl;
    //1.3
    Time t;
    std::cout << "\n ÒÐÅÒÈÉ ÊËÀÑÑ ÂÐÅÌß" << std::endl;
    t.output();
    t.set(12, 45, 32);
    t.output();
    Time res = Time(23, 1, 5).time(t);
    std::cout << "Ðàçíèöà ìåæäó: 23:1:5 è 12:45:32 = " << std::endl;
    res.output();
    std::cout << "Ñäâèã âíèç 12:45:32  íà 15:21:49 = " << std::endl;
    t.shift(15, 21, 49, false);
    t.output();
    std::cout << "Ñäâèã ââåðõ íà 8:50:49 = " << std::endl;
    t.shift(8, 50, 49, true);
    t.output();
    // 1.4
    std::cout << "\n ×ÅÒÂÅÐÒÛÉ ÊËÀÑÑ ÊÎÍÂÅÐÒÎÐ ÄËÈÍÛ" << std::endl;
    Length l;
    l.output();
    l.set(173);
    for (int i = 0; i <= 7; i++)
    {
        l.output(i);
    }
    // 1.5
    std::cout << "\n ÏßÒÛÉ ÊËÀÑÑ ÊÎÍÂÅÐÒÎÐ ÂÅÑÀ" << std::endl;
    Weight w;
    w.output();
    w.set(279.8);
    for (int i = 0; i <= 7; i++)
    {
        w.output(i);
    }
    // 1.6
    std::cout << "\n ØÅÑÒÎÉ ÊËÀÑÑ ÊÎÍÂÅÐÒÎÐ ÒÅÌÏÅÐÀÒÓÐÛ" << std::endl;
    Temperature tem;
    tem.output();
    tem.set(36.6);
    for (int i = 0; i <= 4; i++)
    {
        tem.output(i);
    }
}