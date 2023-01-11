#include <cstring>
#include "classes.h"

const char* DM::getTitle() {
	return title;
}

void DM::setTitle(const char* t) {
	strcpy(title, t);
}

unsigned int DM::getYear() {
	return year;
}

void DM::setYear(unsigned int y) {
	year = y;
}


// game ====================================

const char* game::getPub() {
	return publisher;
}

void game::setPub(const char* x) {
	strcpy(publisher, x);
}

unsigned int game::getRate() {
	return rating;
}

void game::setRate(unsigned int x) {
	rating = x;
}


// music ====================================

const char* music::getArt() {
	return artist;
}

void music::setArt(const char* x) {
	strcpy(artist, x);
}

unsigned int music::getDur() {
	return duration;
}

void music::setDur(unsigned int x) {
	duration = x;
}

const char* music::getPub() {
	return publisher;
}

void music::setPub(const char* x) {
	strcpy(publisher, x);
}



// movie ====================================

const char* movie::getDir() {
	return director;
}

void movie::setDir(const char* x) {
	strcpy(director, x);
}

unsigned int movie::getDur() {
	return duration;
}

void movie::setDur(unsigned int x) {
	duration = x;
}

unsigned int movie::getRate() {
	return rating;
}

void movie::setRate(unsigned int x) {
	rating = x;
}