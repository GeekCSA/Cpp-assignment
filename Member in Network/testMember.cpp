#include "Member.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing the creating and deleting member and count() function") {
	Member a;
    CHECK(Member::count() == 1);
    Member b;
    CHECK(Member::count() == 2);
    {
        Member c;
        CHECK(Member::count() == 3);
    }
    CHECK(Member::count() == 2);
}

TEST_CASE("testing the follow() function") {
	Member a;
    CHECK(a.numFollowing() == 0);
    CHECK(a.numFollowers() == 0);

    Member b;
    a.follow(b);
    CHECK(a.numFollowing() == 1);
    CHECK(b.numFollowers() == 1);

    {
        Member c;
        a.follow(c);
        CHECK(a.numFollowing() == 2);
        CHECK(b.numFollowers() == 1);
        CHECK(c.numFollowers() == 1);
        //The c member will be deleted after the scope.
    }
    CHECK(a.numFollowing() == 1);
    CHECK(b.numFollowers() == 1);

    a.unfollow(b);
    CHECK(a.numFollowing() == 0);
    CHECK(b.numFollowers() == 0);
}
