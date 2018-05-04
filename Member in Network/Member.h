/*
 *  Member.h
 *
 *  Created on: Mar 25, 2018
 *  Author: Moshe
 */

#pragma once

#ifndef MEMBER_HPP_
#define MEMBER_HPP_

#include <set>

class Member{
	static int totalUsers;//Number of all members

	std::set<Member*> followers;//List of followers
	std::set<Member*> following;//List of following

	void addToFollowers(Member&);//Add to the list of following

	void removeFromFollowers(Member&);//Remove from the list of following

public:
	Member();

	~Member();

	void follow(Member&);//Add someone to follow

	void unfollow(Member&);//Unfollow member

	int numFollowers() const;//Return numbers of followers

	int numFollowing() const;//Return numbers of following

	static int count();//Return number of total user
};

#endif /* MEMBER_HPP_ */
