### In this code we demonstrate a class that represents circular numbers.

Circular numbers mean, range of numbers is blocked on both sides. When a number is given, one of the following two cases occurs:

1) The number is within the range.
2) The number is out of range.

In the first case, everything is fine, but if the number is out of range, we want to find the "appropriate" number within the range.

To illustrate, if the range of numbers is [5-10] then for the number 8 everything is fine but for the number 12 out of range we would like to find a number within the range [510] that would be equal to number 19.
For this purpose, the number of organs in the range [5-10], ie, 10-5 + 1 = 6, is subtracted from 12 until the result is within the range. In our case 19-6 = 13 we will again lose 6 of 13 and get 7 and indeed 7 is within the range and therefore we reached the desired number.

Instead of subtracting until we reach the desired number we will use the formula

currentNumber + (ceil(b - currentNumber) / (b - a + 1)) * (b - a + 1)

Credit to [SamuelBismuth](https://github.com/SamuelBismuth/Operator_Overloading_CPP/blob/master/CircularInt.cpp)

Where a is the "small" end of the range and b is the large end of the range.

As with any standard account, all existing transactions are considered in the account

 * The usual account: +, -, *, /,%
 * Actions increase and decrease: ++, -
 * Actions on bits: &, |, ^, ~, >>, <<,
 * Deactivation: -
 * Comparison operations between two numbers: ==, = =, <,>, <=,> =

 Each of the actions also has an assignment function accordingly.

We can actually simulate these actions and the above account into a modular account

In the simple modular account the limits are 0 and a but for us the border does not have to be 0 but any other number.
