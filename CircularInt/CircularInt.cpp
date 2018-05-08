//
// Created by Nissan and Moshe on 4/18/18.
//

#include "CircularInt.hpp"

CircularInt::CircularInt(int mini, int maxi): min(mini),max(maxi),current(mini),numOfElements(abs(max - min)+ 1){
}
CircularInt::CircularInt(int mini, int maxi,int currenti): min(mini),max(maxi),current(currenti),numOfElements(abs(max - min)+ 1){
}

int CircularInt::Normalization(int min, int max, int current){

	while(current > max){
		current = current - numOfElements;
	}
	while(current < min){
		current = current + numOfElements;
	}
	return current;

}

int CircularInt::getCurrent() const{
	return current;
}

CircularInt& CircularInt::operator=(int num){
	current = Normalization(min,max,num);
	return *this;
}

CircularInt& CircularInt::operator=(CircularInt circ2){
	current = Normalization(min,max,circ2.getCurrent());
	return *this;
}

CircularInt& CircularInt::operator+=(int num) {
	if(num < 0)//+(-x) = -x
		current -= abs(num);
	else{
		current += num;
		current = Normalization(min,max,current);
	}
	return *this;
}
CircularInt& CircularInt::operator-=(int num) {
	if(num < 0)//-(-x) = +x
		current += abs(num);
	else{
		current -= num;
		current = Normalization(min,max,current);
	}
	return *this;
}
CircularInt& CircularInt::operator*=(int num) {

	current *= num;
	current = Normalization(min,max,current);
	return *this;
}
CircularInt& CircularInt::operator/=(int num) {

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

CircularInt& CircularInt::operator+=(const CircularInt& cirInt1){
	current += cirInt1.current;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator-=(const CircularInt& cirInt1){
	current -= cirInt1.current;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator*=(const CircularInt& cirInt1){
	current *= cirInt1.current;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator/=(const CircularInt& cirInt1){
	int temp;
	for(int i=min;i<=max;i++){
		temp = Normalization(min, max,i*cirInt1.current);
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
const CircularInt CircularInt::operator++(int x) {
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
const CircularInt CircularInt::operator--(int x) {
	CircularInt result(*this);
	--(*this);
	return result;
}

CircularInt operator+(CircularInt& cirInt,int num){

	int sum = cirInt.current + num;
	sum = cirInt.Normalization(cirInt.min,cirInt.max,sum);

	CircularInt temp(cirInt.min,cirInt.max,sum);

	return temp;
}
CircularInt operator+(int num,CircularInt& cirInt){

	int sum = cirInt.current + num;
	sum = cirInt.Normalization(cirInt.min,cirInt.max,sum);

	CircularInt temp(cirInt.min,cirInt.max,sum);

	return temp;
}
CircularInt operator+(CircularInt& cirInt1,CircularInt& cirInt2){
	CircularInt temp(cirInt1.min, cirInt1.max,cirInt1.current);
	temp+=cirInt2.current;
	return temp;

}

CircularInt operator-(CircularInt& cirInt,int num){

	int diff = cirInt.current - num;
	diff = cirInt.Normalization(cirInt.min,cirInt.max,diff);

	CircularInt temp(cirInt.min,cirInt.max,diff);

	return temp;
}
CircularInt operator-(int num,CircularInt& cirInt){
	int diff = num - cirInt.current;
	diff = cirInt.Normalization(cirInt.min,cirInt.max,diff);

	CircularInt temp(cirInt.min,cirInt.max,diff);

	return temp;
}
CircularInt operator-(CircularInt& cirInt1,CircularInt& cirInt2){
	CircularInt temp(cirInt1.min, cirInt1.max,cirInt1.current);
	temp-=cirInt2.current;
	return temp;

}

CircularInt operator*(CircularInt& cirInt, int num){

	int mul = cirInt.current * num;
	mul = cirInt.Normalization(cirInt.min,cirInt.max,mul);

	CircularInt temp(cirInt.min,cirInt.max,mul);

	return temp;
}
CircularInt operator*(int num, CircularInt& cirInt){

	int mul = cirInt.current * num;
	mul = cirInt.Normalization(cirInt.min,cirInt.max,mul);

	CircularInt temp(cirInt.min,cirInt.max,mul);

	return temp;
}
CircularInt operator*(CircularInt& cirInt1,CircularInt& cirInt2){
	CircularInt temp(cirInt1.min, cirInt1.max,cirInt1.current);
	temp*=cirInt2.current;
	return temp;

}
CircularInt operator/(CircularInt& circ,int num){
	int temp;
	for(int i=circ.min;i<=circ.max;i++){
		temp = circ.Normalization(circ.min, circ.max,i*num);
		if (temp == circ.current){
			CircularInt ci {circ.min, circ.max, i};
			return ci;
		}
	}
	//TODO 
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
CircularInt operator/(CircularInt& cirInt1,CircularInt& cirInt2){
	int temp;
	for (int i = cirInt1.min; i < cirInt1.max; ++i) {
		temp = cirInt1.Normalization(cirInt1.min, cirInt1.max,i*cirInt2.current);
		if (temp == cirInt1.current){
			CircularInt ci {cirInt1.min, cirInt1.max, i};
			return ci;
		}
	}
	throw std::invalid_argument("There is no number x in this range such that x*i=current\n" );

}

bool operator==(CircularInt& cirInt1,CircularInt& cirInt2){
	return (cirInt1.current==cirInt2.current &&
			cirInt1.max==cirInt2.max &&
			cirInt1.min==cirInt2.min);
}
bool operator==(CircularInt& cirInt1, int num){
	return (cirInt1.current==num);
}
bool operator==(int num,CircularInt& ci){
	return num==ci.current;
}
bool operator!=(CircularInt& cirInt1,CircularInt& cirInt2){
	return !(cirInt1 == cirInt2);
}
bool operator!=(CircularInt& cirInt1,int num){
	return !(cirInt1.current == num);
}
bool operator!=(int num,CircularInt& ci){
	return !(num==ci.current);
}

//CircularInt& CircularInt::operator-(){
CircularInt CircularInt::operator-(){

	int temp = current * -1;
	temp = Normalization(min,max,temp);

	//	current *= -1;
	//	current = Normalization(min,max,current);

	//	return *this;

	return CircularInt{min,max,temp};
}

CircularInt operator^(CircularInt& cirInt1,int num){
	int temp = cirInt1.current^num;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator^(int num, CircularInt& cirInt1){
	int temp = num ^ cirInt1.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator^(CircularInt& cirInt1,CircularInt& cirInt2){
	int temp = cirInt1.current ^ cirInt2.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};

}
CircularInt& CircularInt::operator^=(int num){
	current ^= num;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator^=(const CircularInt& cirInt1){
	current ^= cirInt1.current;
	current = Normalization(min,max,current);
	return *this;
}

CircularInt operator%(CircularInt& cirInt1,int num){
	int temp = cirInt1.current%num;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator%(int num, CircularInt& cirInt1){
	int temp = num % cirInt1.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator%(CircularInt& cirInt1,CircularInt& cirInt2){
	int temp = cirInt1.current % cirInt2.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt& CircularInt::operator%=(int num){
	current %= num;
	current = Normalization(min,max,current);
	return *this;

}
CircularInt& CircularInt::operator%=(const CircularInt& cirInt1){
	current %= cirInt1.current;
	current = Normalization(min,max,current);
	return *this;

}

CircularInt operator|(CircularInt& cirInt1,int num){
	int temp = cirInt1.current|num;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator|(int num, CircularInt& cirInt1){
	int temp = num | cirInt1.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator|(CircularInt& cirInt1,CircularInt& cirInt2){
	int temp = cirInt1.current | cirInt2.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt& CircularInt::operator|=(const int num){
	current |= num;

	current = Normalization(min,max,current);

	return *this;
}
CircularInt& CircularInt::operator|=(const CircularInt& cirInt1){
	current |= cirInt1.current;

	current = Normalization(min,max,current);

	return *this;
}


CircularInt operator&(CircularInt& cirInt1,int num){
	int temp = cirInt1.current&num;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator&(int num, CircularInt& cirInt1){
	int temp = num & cirInt1.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};
}
CircularInt operator&(CircularInt& cirInt1,CircularInt& cirInt2){
	int temp = cirInt1.current & cirInt2.current;
	temp = cirInt1.Normalization(cirInt1.min,cirInt1.max,temp);
	return CircularInt{cirInt1.min,cirInt1.max,temp};

}
CircularInt& CircularInt::operator&=(const int num){
	current &= num;

	current = Normalization(min,max,current);

	return *this;
}
CircularInt& CircularInt::operator&=(const CircularInt& cirInt1){
	current &= cirInt1.current;

	current = Normalization(min,max,current);

	return *this;
}

const bool CircularInt::operator>(CircularInt& cirInt1){
	return current > cirInt1.current;
}

const bool operator>(int num,CircularInt& ci){
	return (num>ci.current);
}
const bool operator>(CircularInt& ci,int num){
	return (ci.current > num);
}

const bool CircularInt::operator>=(CircularInt& cirInt1){
	return current >= cirInt1.current;
}

const bool operator>=(const CircularInt& ci,int num){
	return ci.current >= num;
}

const bool operator>=(int num,const CircularInt&  ci){
	return num >= ci.current;
}

const bool CircularInt::operator<(CircularInt& cirInt1){
	return current < cirInt1.current;
}

const bool operator<(int num,CircularInt& ci){
	return (num<ci.current);
}
const bool CircularInt::operator<=(CircularInt& cirInt1){
	return current <= cirInt1.current;
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
