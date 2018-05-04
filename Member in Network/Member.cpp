/*
 *  Member.cpp
 *
 *  Created on: Mar 25, 2018
 *  Author: Moshe
 */

#include "Member.h"

using namespace std;

int Member::totalUsers = 0;

Member::Member(){
	//Increase number of the user.
	totalUsers++;
}

/**
 * The destructor go through sets followers and following of the object that deleted
 * and deletes this member from the sets followers and following of the other members.
 */
Member::~Member(){
	totalUsers--;

	set<Member*>::iterator it;

	for ( it= following.begin() ; it != following.end(); it++ )
	{
		(*it)->followers.erase(this);
	}

	for ( it= followers.begin() ; it != followers.end(); it++ )
	{
		(*it)->following.erase(this);
	}
}

int Member::count(){
	return totalUsers;
}

int Member::numFollowers() const{
	int n = followers.size();
	return n;
}

int Member::numFollowing() const{
	int n = following.size();
	return n;
}

void Member::addToFollowers(Member& member){
	followers.insert(&member);
}

void Member::removeFromFollowers(Member& member){
	followers.erase(&member);
}

/*
 * The function check if the member doesn't appear in the list
 * and if it doesn't appear the function adds it to the list.
 */
void Member::follow(Member& member){

	if(&member == this)
		return;

	if(following.find(&member) == following.end()) {
		following.insert(&member);
		member.addToFollowers(*this);
	}
}

/*
 * The function checks if the member appears in the list
 * and if it appears the function removes it from the list
 */
void Member::unfollow(Member& member){

	if(&member == this)
		return;

	if (following.find(&member) != following.end())
	{
		following.erase(&member);
		member.removeFromFollowers(*this);
	}
}





