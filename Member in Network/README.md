## In this code I demonstrate a social network.

A social network is made up of connectors and connections. When friends have connections.
There are two approaches in forming relationships between friends in a social network.

1) If A is a member of B then immediately B is also a member of A.
2) If a member of B then not necessarily also a member of A.

I was referring to the first approach.

In the code shown, the Member class represents a member on the network

Each member has several functions that he can run:

1) Start tracking someone
2) Stop following someone
3) Check out how many network members are following him
4) Check after a few friends is following

It is also possible to see how many members are there on the net.

Each member is held in two groups, one representing the members he follows, the other representing the members who follow him.

### To see how the network works, I've included a main.cpp file that demonstrates
* Create friends
* Make friends between friends
* Terminating contact between friends

Also attached is a file called testMember.cpp (which uses the docttest.h file) which contains integrity checks of the class functions.

When running the code, there are two options
1) Run the main.cpp file with the Member.cpp and Member.h files by command
clang ++ - 5.0 -std = c ++ 17 main.cpp Member.cpp
2) Run the testMember.cpp file with the Member.cpp, Member.h and doctt.h files by command
clang ++ - 5.0 -std = c ++ 17 testMember.cpp Member.cpp
