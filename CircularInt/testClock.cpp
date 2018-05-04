//
// Created by Nnissan and Moshe on 4/18/18.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "CircularInt.hpp"
#include "doctest.h"

CircularInt circularInt(1,10);

TEST_CASE("===== Adding += num ====") {


    CHECK(circularInt.getCurrent() == 1);

    circularInt+=5;
    CHECK(circularInt.getCurrent() == 6);

    circularInt+=6;
    CHECK(circularInt.getCurrent() == 2);

    circularInt+=20;
    CHECK(circularInt.getCurrent() == 2);
    {
        CircularInt circularInt5(2,7,4);
        circularInt5+=14;
        CHECK(circularInt5.getCurrent() == 6);
    }

}

TEST_CASE("===== Subtracting -= num ====="){
    circularInt-=1;
    CHECK(circularInt.getCurrent()==1);

    circularInt-=3;
    CHECK(circularInt.getCurrent()==8);

    circularInt-=20;
    CHECK(circularInt.getCurrent()==8);
}

TEST_CASE("===== Multiplication *= num ====="){
    circularInt*=2;
    CHECK(circularInt.getCurrent()==6);

    circularInt*=3;
    CHECK(circularInt.getCurrent()==8);
}

//TEST_CASE("===== Divide /= num ====="){
//    circularInt/=2;
//    CHECK(circularInt.getCurrent()==4);
//
//    circularInt/=6;
//    CHECK(circularInt.getCurrent()==4);
//
//    circularInt/=3;
//    CHECK(circularInt.getCurrent()==8);
//
//}

TEST_CASE("===== Adding += obj ====") {

	CircularInt circularInt1(1,10);

    CHECK((circularInt1 += circularInt).getCurrent() == 9);
}

TEST_CASE("===== Adding -= obj ====") {

	CircularInt circularInt1(1,10);

    CHECK((circularInt1 -= circularInt).getCurrent() == 3);
}

TEST_CASE("===== Adding *= obj ====") {

	CircularInt circularInt1(1,10);
	circularInt1 += 2;

    CHECK((circularInt1 *= circularInt).getCurrent() == 4);
}

TEST_CASE("===== a++ ====="){
    circularInt++;
    CHECK(circularInt.getCurrent()==9);
    (circularInt+=6)++;
    CHECK(circularInt.getCurrent()==6);

}

TEST_CASE("===== ++a ====="){
    ++circularInt;
    CHECK(circularInt.getCurrent()==7);

    CHECK( (++circularInt).getCurrent()==8 );

    ++(circularInt+=6);
    CHECK(circularInt.getCurrent()==5);

}

TEST_CASE("===== a-- ====="){
    circularInt--;
    CHECK(circularInt.getCurrent()==4);

    (circularInt+=6)--;
    CHECK( circularInt.getCurrent()==9);

}

TEST_CASE("===== --a ====="){
    CHECK((--circularInt).getCurrent()==8);

    CHECK((--circularInt).getCurrent()==7);

    --(circularInt+=6);
    CHECK(circularInt.getCurrent()==2);

}

TEST_CASE("===== obj+num ====="){
    CHECK((circularInt + 3).getCurrent()==5);

    CHECK((circularInt + 6).getCurrent()==8);

    CHECK((circularInt + (-3)).getCurrent()==9);

}

TEST_CASE("===== num+obj ====="){
    CHECK((2 + circularInt).getCurrent()==4);

    CHECK((9 + circularInt).getCurrent()==1);

    CHECK(((-7) + circularInt).getCurrent()==5);

}

TEST_CASE("===== obj+obj ====="){
    CHECK((circularInt + circularInt).getCurrent()==4);
}

TEST_CASE("===== obj-num ====="){
    CHECK((circularInt - 2).getCurrent()==10);

    CHECK((circularInt - 10).getCurrent()==2);

    CHECK((circularInt - (-3)).getCurrent()==5);

}

TEST_CASE("===== num-obj ====="){
    CHECK((2 - circularInt).getCurrent()==10);

    CHECK((6 - circularInt).getCurrent()==4);

    CHECK(((-7) - circularInt ).getCurrent()==1);

}

TEST_CASE("===== obj-obj ====="){
    CHECK((circularInt - circularInt).getCurrent()==10);
}

TEST_CASE("===== obj*num ====="){
    CHECK((circularInt * 2).getCurrent()==4);

    CHECK((circularInt * 9).getCurrent()==8);

    CHECK((circularInt * (-3)).getCurrent()==4);

}

TEST_CASE("===== num*obj ====="){
    CHECK((4 * circularInt).getCurrent()==8);

    CHECK((6 * circularInt).getCurrent()==2);

    CHECK(((-7) * circularInt ).getCurrent()==6);
}

TEST_CASE("===== obj*obj ====="){
    CHECK((circularInt * circularInt).getCurrent()==4);
}

TEST_CASE("===== equals / not equals == / != ====="){
    CircularInt circularInt2(1,10);
    CircularInt circularInt3(1,10);

    CHECK((circularInt2==circularInt3) == true);

    circularInt3 -= 4;
    CHECK((circularInt2!=circularInt3) == true);

    circularInt += 5;
    CHECK((circularInt2==circularInt3) == false);
}

TEST_CASE("===== negative - ====="){
    CHECK((-circularInt).getCurrent()==3);
}

TEST_CASE("===== |= num ====="){

    circularInt |= 8;
    CHECK(circularInt.getCurrent()==5);
}//1

TEST_CASE("===== |= obj ====="){

    CircularInt circularInt1(1,10);
    circularInt1 += 8;

    CHECK((circularInt1 |= circularInt).getCurrent()==3);
}

TEST_CASE("===== &= num ====="){

    circularInt &= 8;
    CHECK(circularInt.getCurrent()==10);
}//10

TEST_CASE("===== &= obj ====="){

    CircularInt circularInt1(1,10);
    circularInt1 += 8;

    CHECK((circularInt1 &= circularInt).getCurrent()==8);
}

TEST_CASE("===== xor ^ ====="){

    CircularInt circularInt2(1,10);

    CHECK((circularInt ^ 3).getCurrent()==9);
    CHECK((5 ^ circularInt).getCurrent()==5);
    CHECK((circularInt2 ^ circularInt).getCurrent()==1);

    circularInt2 ^= 15;
    CHECK((circularInt2).getCurrent()==4);

    circularInt +=3;
    CHECK((circularInt).getCurrent()==3);

    circularInt2 ^= circularInt;
    CHECK((circularInt2).getCurrent()==7);
}//3

TEST_CASE("===== mod % ====="){

    CircularInt circularInt2(1,10);

    circularInt2 +=1;

    CHECK((circularInt % 3).getCurrent()==10);
    CHECK((5 % circularInt).getCurrent()==2);
    CHECK((circularInt2 % circularInt).getCurrent()==2);

    circularInt2 %= 2;
    CHECK((circularInt2).getCurrent()==10);

    circularInt2 %= circularInt;
    CHECK((circularInt2).getCurrent()==1);
}

TEST_CASE("===== and & ====="){

    CircularInt circularInt2(1,10);

    circularInt2 +=1;//2

    CHECK((circularInt & 4).getCurrent()==10);
    CHECK((5 & circularInt).getCurrent()==1);
    CHECK((circularInt2 & circularInt).getCurrent()==2);

    circularInt2 &= 10;
    CHECK((circularInt2).getCurrent()==2);

    circularInt2 &= circularInt;
    CHECK((circularInt2).getCurrent()==2);
}

TEST_CASE("===== or | ====="){

    CircularInt circularInt2(1,10);

    circularInt2 +=1;//2

    CHECK((circularInt | 4).getCurrent()==7);
    CHECK((17 | circularInt).getCurrent()==9);
    CHECK((circularInt2 | circularInt).getCurrent()==3);

    circularInt2 |= 32;
    CHECK((circularInt2).getCurrent()==4);

    circularInt2 |= circularInt;
    CHECK((circularInt2).getCurrent()==7);
}//3

TEST_CASE("===== greater >  ====="){

    CircularInt circularInt2(1,10);
    CHECK((circularInt > circularInt2) == true);

}//3

TEST_CASE("===== greater and equal >=  ====="){

    CircularInt circularInt2(1,10);

    circularInt2*=3;

    CHECK((circularInt >= circularInt2) == true);

}//3

TEST_CASE("===== division obj/num  ====="){

    CircularInt circularInt2{1,12,11};
    circularInt2 *= 2;
    CHECK ( circularInt2.getCurrent()  == 10);
    CHECK ( (circularInt2/2).getCurrent() == 5);

}//3

TEST_CASE("===== bitwise obj<<num  ====="){

    CircularInt circularInt2{1,12,3};
    CHECK ( (circularInt2<<2).getCurrent()  == 12); //
    CHECK ( (circularInt2).getCurrent()  == 3); //3

}//3

TEST_CASE("===== bitwise num<<obj  ====="){

    CircularInt circularInt2{1,12,3};
    CHECK ( (3<<circularInt2).getCurrent()  == 12);
    CHECK ( (circularInt2).getCurrent()  == 3); //3

}//3

TEST_CASE("===== bitwise obj<<obj  ====="){

    CircularInt circularInt2{1,12,3};
    CircularInt circularInt3{1,12,2};
    CHECK ( (circularInt2<<circularInt3).getCurrent()  == 12);
    CHECK ( (circularInt2).getCurrent()  == 3); //3

}//3


TEST_CASE("===== bitwise obj>>num  ====="){

    CircularInt circularInt2{1,12,12};
    CHECK ( (circularInt2>>2).getCurrent()  == 3); //3
    CHECK ( (circularInt2).getCurrent()  == 12); //3

}//3

TEST_CASE("===== bitwise num>>obj  ====="){

    CircularInt circularInt2{1,12,2};
    CHECK ( (12>>circularInt2).getCurrent()  == 3);
    CHECK ( (circularInt2).getCurrent()  == 2); //3

}//3

TEST_CASE("===== bitwise obj>>obj  ====="){

    CircularInt circularInt2{1,12,12};
    CircularInt circularInt3{1,12,2};
    CHECK ( (circularInt2>>circularInt3).getCurrent()  == 3);

}//3

TEST_CASE("===== bitwise obj<<=num  ====="){

    CircularInt circularInt2{1,12,3};
    circularInt2<<=2;
    CHECK ( (circularInt2).getCurrent()  == 12);

}//3
TEST_CASE("===== bitwise obj>>=num  ====="){

    CircularInt circularInt2{1,12,12};
    circularInt2>>=2;
    CHECK ( (circularInt2).getCurrent()  == 3);

}//3

TEST_CASE("===== bitwise ~obj  ====="){

    CircularInt circularInt2{1,12,1};
    ~circularInt2;
    CHECK ( (circularInt2).getCurrent()  == 10);

}

TEST_CASE("===== division obj/=2 ====="){

    CircularInt circularInt2{1,12,10};
    circularInt2/=2;
    CHECK ( (circularInt2).getCurrent() == 5);

}

TEST_CASE("===== division obj/=obj ====="){

    CircularInt circularInt2{1,12,10};
    CircularInt circularInt3{1,12,2};
    circularInt2/=circularInt3;
    CHECK ( (circularInt2).getCurrent() == 5);

}