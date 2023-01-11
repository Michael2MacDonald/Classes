#include "classes.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h> // atoi()

// void db::add() {
// 	char buf[128] = {};
// 	// Type
// 	std::cout << "Type (game, music, movie):\n";
// 	std::cin >> buf;
// 	memset(buf, 0, strlen(buf)); // clear
// 	// First name
// 	std::cout << "First Name:\n";
// 	//return;
// 	std::cin >> buf;
// 	char* firstName = (char*)malloc(strlen(buf)+1);
// 	strcpy(firstName, buf);
// 	student->firstName = firstName;
// 	// Last Name
// 	memset(buf, 0, strlen(buf)); // clear
// 	std::cout << "Last Name:\n";
// 	std::cin >> buf;
// 	char* lastName = (char*)malloc(strlen(buf)+1);
// 	strcpy(lastName, buf);
// 	student->lastName = lastName;
// 	// GPA
// 	std::cout << "GPA:\n";
// 	std::cin >> student->gpa;
	
// 	StudentNode* node = new StudentNode(student);
// 	Students->addNode(node);

// }

void db::add(const char* title, unsigned int year, const char* publisher, unsigned int rating) { // game pub/rate
	game* g = new game();
	g->setTitle(title);
	g->setYear(year);
	g->setPub(publisher);
	g->setRate(rating);
	media.push_back(g);
}
void db::add(const char* title, unsigned int year, const char* artist, const char* publisher, unsigned int duration) { // music art/pub/dur
	music* m = new music();
	m->setTitle(title);
	m->setYear(year);
	m->setArt(artist);
	m->setPub(publisher);
	m->setDur(duration);
	media.push_back(m);
}
void db::add(const char* title, unsigned int year, const char* director, unsigned int duration, unsigned int rating) { // movie dir/dur/rate
	movie* m = new movie();
	m->setTitle(title);
	m->setYear(year);
	m->setDir(director);
	m->setDur(duration);
	m->setRate(rating);
	media.push_back(m);
}


void db::del(bool type, char* str) {
	for (int i = 0; i < strlen(str); i++) {
		str[i] = std::tolower(str[i]);
	}
	if (type) {
		int year;
		year = atoi(str);
		for(int i=0; i < media.size(); i++) {
			if (media[i]->getYear() == year) {
				media.erase(media.begin() + i);
			}
		}
	} else {
		for(int i=0; i < media.size(); i++) {
			if (!strcmp(media[i]->getTitle(), str)) {
				media.erase(media.begin() + i);
			}
		}
	}
}


std::vector<DM*>* db::search(bool type, const char* s) {
	char str[strlen(s) + 1] = {0};
	strcpy(str,s);
	for (int i = 0; i < strlen(str); i++) {
		str[i] = std::tolower(str[i]);
	}
	std::vector<DM*> *results = new std::vector<DM*>;
	if (type) {
		int year;
		year = atoi(str);
		for(int i=0; i < media.size(); i++) {
			if (media[i]->getYear() == year) {
				results->push_back(media[i]);
			}
		}
	} else {
		for(int i=0; i < media.size(); i++) {
			if (!strcmp(media[i]->getTitle(), str)) {
				results->push_back(media[i]);
			}
		}
	}

	return results;
}

void print(std::vector<DM*> *dm) {
	for (int i=0; i<(dm->size()); i++) {
		std::cout << "-----------------------\n";
		//std::cout << "Title: " << dm[i]->getTitle() << '\n';
		std::cout << "Title: ";
		for (int j=0; j < strlen((*dm)[i]->getTitle()); j++) { std::cout << ((*dm)[i]->getTitle())[j]; }
		std::cout << '\n';
		std::cout << "Year: " << (*dm)[i]->getYear() << '\n';
		if ((*dm)[i]->getType() == 1) {
			std::cout << "Publisher: ";
			for (int j = 0; j < strlen(((game*)(*dm)[i])->getPub()); j++) { std::cout << (((game*)(*dm)[i])->getPub())[j]; }
			std::cout << '\n';
			std::cout << "Rating: " << ((game*)(*dm)[i])->getRate() << '\n';
		} else if ((*dm)[i]->getType() == 2) {
			std::cout << "Artist: ";
			for (int j = 0; j < strlen(((music*)(*dm)[i])->getArt()); j++) { std::cout << (((music*)(*dm)[i])->getArt())[j]; }
			std::cout << '\n';
			std::cout << "Publisher: ";
			for (int j = 0; j < strlen(((music*)(*dm)[i])->getPub()); j++) { std::cout << (((music*)(*dm)[i])->getPub())[j]; }
			std::cout << '\n';
			std::cout << "Duration: " << ((music*)(*dm)[i])->getDur() << '\n';
		} else if ((*dm)[i]->getType() == 3) {
			std::cout << "Director: ";
			for (int j = 0; j < strlen(((movie*)(*dm)[i])->getDir()); j++) { std::cout << (((movie*)(*dm)[i])->getDir())[j]; }
			std::cout << '\n';
			std::cout << "Duration: " << ((movie*)(*dm)[i])->getDur() << '\n';
			std::cout << "Rating: " << ((movie*)(*dm)[i])->getRate() << '\n';
		}
	}
}


int main() {
	db mydb;

	while(1) {
		// This will produce and error or unexpected behavior if the user enters more than 9 characters
		// To fix this we would have to implement some sort of "string" class with operator overloading or something
		// Because this is not a production, we can just ignore this
		char buf[128] = {}; // zero-init the entire array
		std::cout << "===============\nType A Command:\n";
		std::cin >> buf;
		
		// to lower case
		for (int i = 0; i < strlen(buf); i++) {
			buf[i] = std::tolower(buf[i]);
		}
		if (!strcmp(buf, "add")) {
			memset(buf, 0, strlen(buf)); // clear
			std::cout << "Title:\n";
			std::cin >> buf;
			char title[128]; strcpy(title,buf);
			memset(buf, 0, strlen(buf)); // clear
			std::cout << "Year:\n";
			std::cin >> buf;
			int year = atoi(buf);
			memset(buf, 0, strlen(buf)); // clear
			std::cout << "Type (Game, Music, Movie):\n";
			std::cin >> buf;
			if (!strcmp(buf, "game")) {
				char pub[128];
				std::cout << "Publisher:\n";
				std::cin >> pub;
				int rating;
				std::cout << "Rating:\n";
				std::cin >> rating;
				mydb.add(title, year, pub, rating);
			} else if (!strcmp(buf, "music")) {
				char art[128];
				std::cout << "Artist:\n";
				std::cin >> art;
				char pub[128];
				std::cout << "Publisher:\n";
				std::cin >> pub;
				int dur;
				//std::cout << "Duration:\n";
				//std::cin >> dur;
				mydb.add(title, year, art, pub, dur);
			} else if (!strcmp(buf, "movie")) {
				char dir[128];
				std::cout << "Director:\n";
				std::cin >> dir;
				int dur;
				std::cout << "Duration:\n";
				std::cin >> dur;
				int rating;
				std::cout << "Rating:\n";
				std::cin >> rating;
				mydb.add(title, year, dir, dur, rating);
			} //else { /* ERROR */ }
		} else if (!strcmp(buf, "delete")) {
			int type;
			std::cout << "Select:\n0 - Title\n1 - Year\n";
			std::cin >> type;
			char search[128];
			std::cout << "Delete:\n";
			std::cin >> search;
			mydb.del((bool)type, search);
		} else if (!strcmp(buf, "search")) {
			int type;
			std::cout << "Select:\n0 - Title\n1 - Year\n";
			std::cin >> type;
			char search[128];
			std::cout << "Search:\n";
			std::cin >> search;
			std::vector<DM*> *results = mydb.search((bool)type, search);
			print(results);
		} else if (!strcmp(buf, "quit")) {
			return 0;
		} else { std::cout << "ERROR: Incorrect Command\n"; }
		//} else { std::cout << "========================\nERROR: Incorrect Command\n========================\n"; }
	} // while
}