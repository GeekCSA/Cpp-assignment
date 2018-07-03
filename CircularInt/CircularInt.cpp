//
// Created by Nissan and Moshe on 4/18/18.
//

#include "CircularInt.hpp"

CircularInt::CircularInt(const int min,const int max): min(min),max(max),current(min),numOfElements(abs(max - min)+ 1){}

CircularInt::CircularInt(const int min,const int max,const int current): min(min),max(max),current(current),numOfElements(abs(max - min)+ 1){}

int CircularInt::Normalization(const int min,const int max, int current){

	while(current > max){
		current = current - numOfElements;
	}
	while(current < min){
		current = current + numOfElements;
	}
	return current;
}

int CircularInt::getCurrent() const{ return current; }

CircularInt& CircularInt::operator=(const int num){
	current = Normalization(min,max,num);
	return *this;
}

CircularInt& CircularInt::operator=(const CircularInt& circ2){
	current = Normalization(min,max,circ2.getCurrent());
	return *this;
}

CircularInt& CircularInt::operator+=(const int num) {
	if(num < 0)//+(-x) = -x
		current -= abs(num);
	else{
		current += num;
		current = Normalization(min,max,current);
	}
	return *this;
}
CircularInt& CircularInt::operator-=(const int num) {
	if(num < 0)//-(-x) = +x
		current += abs(num);
	else{
		current -= num;
		current = Normalization(min,max,current);
	}
	return *this;
}
CircularInt& CircularInt::operator*=(const int num) {

	current *= num;
	current = Normalization(min,max,current);
	return *this;
}
CircularInt& CircularInt::operator/=(const int num) {

	int temp;
	for(int i=min;i<=max;i++){
		temp = Normalization(min, max,i*num);
		if (temp == current){
			current = i;
			return *this;
		}
	}
	throw std::invalid_argument("There is no number x in this range such that x*i=current\n" );

}

CircularInt& CircularInt::operator+=(const CircularInt& cirInt){
	current += cirInt.current;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator-=(const CircularInt& cirInt){
	current -= cirInt.current;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator*=(const CircularInt& cirInt){
	current *= cirInt.current;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator/=(const CircularInt& cirInt){
	int temp;
	for(int i=min;i<=max;i++){
		temp = Normalization(min, max,i*cirInt.current);
		if (temp == current){
			current = i;
			return *this;
		}
	}
	throw std::invalid_argument("There is no number x in this range such that x*i=current\n" );
}

//++a
CircularInt& CircularInt::operator++ (){
	if ((current+1)<=max)
		current+=1;
	else{
		current = min;
	}
	return *this;
}
//a++
const CircularInt CircularInt::operator++(const int x) {
	CircularInt result(*this);
	++(*this);
	return result;
}

//--a
CircularInt& CircularInt::operator--() {
	if ((current-1)>=min)
		current-=1;
	else{
		current = max;
	}
	return *this;
}
//a--
const CircularInt CircularInt::operator--(const int x) {
	CircularInt result(*this);
	--(*this);
	return result;
}

CircularInt CircularInt::operator+(const int num){

	int sum = current + num;
	sum = Normalization(min,max,sum);

	CircularInt temp(min,max,sum);

	return temp;
}
CircularInt operator+(const int num, CircularInt& cirInt){ return cirInt + num; }

CircularInt CircularInt::operator+(const CircularInt& cirInt2){
	CircularInt temp(min, max, current);
	temp+=cirInt2.current;
	return temp;
}

CircularInt CircularInt::operator-(const int num){

	int diff = current - num;
	diff = Normalization(min,max,diff);

	CircularInt temp(min,max,diff);

	return temp;
}
CircularInt operator-(const int num, CircularInt& cirInt){ return -(cirInt - num); }

CircularInt CircularInt::operator-(const CircularInt& cirInt2){
	CircularInt temp(min, max, current);
	temp-=cirInt2.current;
	return temp;

}

CircularInt CircularInt::operator*(const int num){

	int mul = current * num;
	mul = Normalization(min,max,mul);

	CircularInt temp(min,max,mul);

	return temp;
}
CircularInt operator*(int num, CircularInt& cirInt){ return cirInt *num; }

CircularInt CircularInt::operator*(const CircularInt& cirInt2){
	CircularInt temp(min, max, current);
	temp*=cirInt2.current;
	return temp;

}
CircularInt CircularInt::operator/(const int num){
	int temp;
	for(int i=min;i<=max;i++){
		temp = Normalization(min, max,i*num);
		if (temp == current){
			CircularInt ci {min, max, i};
			return ci;
		}
	}
	throw std::invalid_argument("There is no number x in this range such that x*i=current\n" );
}

CircularInt operator/(int num, CircularInt& cirInt){
	int temp;
	for (int i = cirInt.min; i < cirInt.max; ++i) {

		temp = cirInt.Normalization(cirInt.min, cirInt.max,i*cirInt.current);
		if (temp == num){
			CircularInt ci (cirInt.min, cirInt.max, i);
			return ci;
		}
	}
	throw std::invalid_argument("There is no number x in this range such that x*i=current\n" );

}
CircularInt CircularInt::operator/(const CircularInt& cirInt2){
	int temp;
	for (int i = min; i < max; ++i) {
		temp = Normalization(min, max,i*cirInt2.current);
		if (temp == current){
			CircularInt ci {min, max, i};
			return ci;
		}
	}
	throw std::invalid_argument("There is no number x in this range such that x*i=current\n" );

}

bool operator==(CircularInt& cirInt,CircularInt& cirInt2){
	return (cirInt.current==cirInt2.current &&
			cirInt.max==cirInt2.max &&
			cirInt.min==cirInt2.min);
}
bool operator==(CircularInt& cirInt, int num){
	return (cirInt.current==num);
}
bool operator==(int num,CircularInt& cirInt){
	return num==cirInt.current;
}
bool operator!=(CircularInt& cirInt,CircularInt& cirInt2){
	return !(cirInt == cirInt2);
}
bool operator!=(CircularInt& cirInt,int num){
	return !(cirInt.current == num);
}
bool operator!=(int num,CircularInt& ci){
	return !(num==ci.current);
}

CircularInt CircularInt::operator-(){

	int temp = current * -1;
	temp = Normalization(min,max,temp);

	return CircularInt{min,max,temp};
}

CircularInt CircularInt::operator^(const int num){
	int temp = current^num;
	temp = Normalization(min, max, temp);
	return CircularInt{min, max, temp};
}
CircularInt operator^(int num, CircularInt& cirInt){

	return cirInt ^ num;
}
CircularInt CircularInt::operator^(const CircularInt& cirInt2){
	int temp = current ^ cirInt2.current;
	temp = Normalization(min, max, temp);
	return CircularInt{min, max, temp};

}
CircularInt& CircularInt::operator^=(const int num){
	current ^= num;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator^=(const CircularInt& cirInt){
	current ^= cirInt.current;
	current = Normalization(min,max,current);
	return *this;
}

CircularInt CircularInt::operator%(const int num){
	int temp = current%num;
	temp = Normalization(min, max, temp);
	return CircularInt{min, max, temp};
}
CircularInt operator%(int num, CircularInt& cirInt){
	int temp = num % cirInt.current;
	temp = cirInt.Normalization(cirInt.min,cirInt.max,temp);
	return CircularInt{cirInt.min,cirInt.max,temp};
}
CircularInt CircularInt::operator%(const CircularInt& cirInt2){
	int temp = current % cirInt2.current;
	temp = Normalization(min, max, temp);
	return CircularInt{min, max, temp};
}
CircularInt& CircularInt::operator%=(const int num){
	current %= num;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator%=(const CircularInt& cirInt){
	current %= cirInt.current;
	current = Normalization(min,max,current);
	return *this;

}

CircularInt operator|(CircularInt& cirInt,int num){
	int temp = cirInt.current|num;
	temp = cirInt.Normalization(cirInt.min,cirInt.max,temp);
	return CircularInt{cirInt.min,cirInt.max,temp};
}
CircularInt operator|(int num, CircularInt& cirInt){

	return cirInt | num;
}
CircularInt operator|(CircularInt& cirInt,CircularInt& cirInt2){
	int temp = cirInt.current | cirInt2.current;
	temp = cirInt.Normalization(cirInt.min,cirInt.max,temp);
	return CircularInt{cirInt.min,cirInt.max,temp};
}
CircularInt& CircularInt::operator|=(const int num){

	current |= num;
	current = Normalization(min,max,current);

	return *this;
}
CircularInt& CircularInt::operator|=(const CircularInt& cirInt){

	current |= cirInt.current;
	current = Normalization(min,max,current);

	return *this;
}


CircularInt CircularInt::operator&(const int num){
	int temp = current&num;
	temp = Normalization(min, max, temp);
	return CircularInt{min, max, temp};
}
CircularInt operator&(int num, CircularInt& cirInt){ return cirInt & num; }

CircularInt CircularInt::operator&(const CircularInt& cirInt2){
	int temp = current & cirInt2.current;
	temp = Normalization(min, max, temp);
	return CircularInt{min, max, temp};

}
CircularInt& CircularInt::operator&=(const int num){

	current &= num;
	current = Normalization(min,max,current);

	return *this;
}
CircularInt& CircularInt::operator&=(const CircularInt& cirInt){
	current &= cirInt.current;

	current = Normalization(min,max,current);

	return *this;
}

const bool CircularInt::operator>(CircularInt& cirInt){
	return current > cirInt.current;
}

const bool operator>(int num,CircularInt& ci){
	return (num>ci.current);
}
const bool operator>(CircularInt& ci,int num){
	return (ci.current > num);
}

const bool CircularInt::operator>=(CircularInt& cirInt){
	return current >= cirInt.current;
}

const bool operator>=(const CircularInt& ci,int num){
	return ci.current >= num;
}

const bool operator>=(int num,const CircularInt&  ci){
	return num >= ci.current;
}

const bool CircularInt::operator<(CircularInt& cirInt){
	return current < cirInt.current;
}

const bool operator<(int num,CircularInt& ci){
	return (num<ci.current);
}
const bool CircularInt::operator<=(CircularInt& cirInt){
	return current <= cirInt.current;
}

const bool operator<=(const CircularInt& ci,int num){
	return ci.current <= num;
}
const bool operator<=(int num,const CircularInt&  ci){
	return num <= ci.current;
}

const bool operator<(CircularInt& ci,int num){
	return (ci.current < num);
}

std::ostream& operator<<(std::ostream & os,const CircularInt &ci){
	return os<<ci.current;
}


CircularInt operator<<(int num,CircularInt& circ){
	int temp = circ.Normalization(circ.min,circ.max,num<<circ.current);
	return CircularInt{circ.min,circ.max,temp };
}
CircularInt operator<<(CircularInt& ci1,CircularInt& ci2){
	int temp = ci1.Normalization(ci1.min,ci1.max,ci1.current<<ci2.current);
	return CircularInt{ci1.min,ci1.max,temp };
}

CircularInt operator<<(CircularInt& circ,int num){
	int temp = circ.current<<num;
	return CircularInt{circ.min,circ.max,temp };
}


CircularInt operator>>(int num,CircularInt& circ){
	int temp = circ.Normalization(circ.min,circ.max,num>>circ.current);
	return CircularInt{circ.min,circ.max,temp };
}
CircularInt operator>>(CircularInt& ci1,CircularInt& ci2){
	int temp = ci1.Normalization(ci1.min,ci1.max,ci1.current>>ci2.current);
	return CircularInt{ci1.min,ci1.max,temp };
}

CircularInt operator>>(CircularInt& circ,int num){
	int temp = circ.current>>num;
	return CircularInt{circ.min,circ.max,temp };
}

CircularInt& CircularInt::operator>>=(int num){
	current = Normalization(min,max,current>>num);
	return *this;
}

CircularInt& CircularInt::operator<<=(int num){
	current = Normalization(min,max,current<<num);
	return *this;
}

CircularInt& CircularInt::operator~(){
	current = Normalization(min,max,~current);
	return *this;
}

std::istream& operator>>(std::istream & is,CircularInt &ci) {
	//Todo check for valid input
	int temp;
	is>>temp;
	if(temp>ci.max || temp<ci.min)
		throw std::invalid_argument( "received value not in range\n" );
	ci.current = temp;
	return is;
}
