// Created by Nissan and Moshe on 4/18/18.

#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class CircularInt {
    int min, max, current, numOfElements;

public:
    CircularInt();
    CircularInt(const int,const int);
    CircularInt(const int,const int,const int);

    int getCurrent() const;

    int Normalization(const int min,const int max, int current);

    CircularInt& operator=(const int);
    CircularInt& operator=(const CircularInt&);

    CircularInt& operator+=(const int);
    CircularInt& operator+=(const CircularInt&);
    CircularInt operator+(const int);
    friend CircularInt operator+(const int, CircularInt&);
    CircularInt operator+(const CircularInt&);


    CircularInt& operator-=(const int);
    CircularInt& operator-=(const CircularInt&);
    CircularInt operator-(const int);
    friend CircularInt operator-(const int, CircularInt&);
    CircularInt operator-(const CircularInt&);


    CircularInt& operator*=(const int num);
    CircularInt& operator*=(const CircularInt&);
    CircularInt operator*(const int);
    friend CircularInt operator*(int,CircularInt&);
    CircularInt operator*(const CircularInt&);


    CircularInt& operator/=(const int num);
    CircularInt& operator/=(const CircularInt&);
    CircularInt operator/(const int);
    friend CircularInt operator/(int,CircularInt&);
    CircularInt operator/(const CircularInt&);


    CircularInt operator^(const int);
    friend CircularInt operator^(int,CircularInt&);
    CircularInt operator^(const CircularInt&);
    CircularInt& operator^=(const CircularInt&);
    CircularInt& operator^=(const int);


    CircularInt operator%(const int);
    friend CircularInt operator%(int,CircularInt&);
    CircularInt operator%(const CircularInt&);
    CircularInt& operator%=(const CircularInt&);
    CircularInt& operator%=(const int);


    CircularInt operator&(const CircularInt&);
    CircularInt operator&(const int);
    friend CircularInt operator&(int,CircularInt&);
    CircularInt& operator&=(const CircularInt&);
    CircularInt& operator&=(const int);


    friend CircularInt operator|(CircularInt&,CircularInt&);
    friend CircularInt operator|(CircularInt&,int);
    friend CircularInt operator|(int,CircularInt&);
    CircularInt& operator|=(const CircularInt&);
    CircularInt& operator|=(const int);

    friend CircularInt operator<<(int,CircularInt&);
    friend CircularInt operator<<(CircularInt&,CircularInt&);
    friend CircularInt operator<<(CircularInt&,int);
    CircularInt& operator<<=(int);


    friend CircularInt operator>>(int,CircularInt&);
    friend CircularInt operator>>(CircularInt&,CircularInt&);
    friend CircularInt operator>>(CircularInt&,int);
    CircularInt& operator>>=(int);


    friend std::ostream & operator<<(std::ostream& os,const CircularInt& ci);
    friend std::istream & operator>>(std::istream& is, CircularInt& ci);

    CircularInt& operator++();
    const CircularInt operator++(const int);

    CircularInt& operator--();
    const CircularInt operator--(const int);

    friend bool operator==(CircularInt&,CircularInt&);
    friend bool operator==(CircularInt&, int);
    friend bool operator==(int,CircularInt&);
    friend bool operator!=(CircularInt&,CircularInt&);
    friend bool operator!=(CircularInt&, int);
    friend bool operator!=(int,CircularInt&);

    CircularInt operator-();

    CircularInt& operator~();

    friend const bool operator>(int,CircularInt&);
    const bool operator>(CircularInt&);
    friend const bool operator>(CircularInt&,int);
    const bool operator>=(CircularInt&);
    friend const bool operator>=(const CircularInt&,int num);
    friend const bool operator>=(int num,const CircularInt&);
    

    friend const bool operator<(int,CircularInt&);
    const bool operator<(CircularInt&);
    const bool operator<=(CircularInt&);
    friend const bool operator<=(const CircularInt&,int num);
    friend const bool operator<=(int num,const CircularInt&);
    friend const bool operator<(CircularInt&,int);
};
