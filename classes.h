#ifndef CLASSES_H
#define CLASSES_H

#include <vector>

class DM {
private:
	char* title;
	unsigned int year;
	unsigned int type = 0;

public:
	DM() {
		title = new char[128];
	};
	~DM() {
		delete title;
	};

	const char* getTitle();
	void setTitle(const char*);
	unsigned int getYear();
	void setYear(unsigned int);

	void setType(unsigned int x) { if (type == 0) { type = x; }  } // (1 = game, 2 = music, 3 = movie
	unsigned int getType() { return type;}
};


class game : public DM {
private:
	char* publisher;
	int rating;
public:
	game() {
		setType(1);
		publisher = new char[128];
	};
	~game() {
		delete publisher;
	};

	const char* getPub();
	void setPub(const char*);
	unsigned int getRate();
	void setRate(unsigned int);
};


class music : public DM {
private:
	char* artist;
	int duration;
	char* publisher;
public:
	music() {
		setType(2);
		artist = new char[128];
		publisher = new char[128];
	};
	~music() {
		delete artist;
		delete publisher;
	};

	const char* getArt();
	void setArt(const char*);
	unsigned int getDur();
	void setDur(unsigned int);
	const char* getPub();
	void setPub(const char*);
};


class movie : public DM {
private:
	char* director;
	int duration;
	int rating;
public:
	movie() {
		setType(3);
		director = new char[128];
	};
	~movie() {
		delete director;
	};

	const char* getDir();
	void setDir(const char*);
	unsigned int getDur();
	void setDur(unsigned int);
	unsigned int getRate();
	void setRate(unsigned int);
};


class db {
private:
	std::vector<DM*> media;
public:
	db() {};

	void add(const char*, unsigned int, const char*, unsigned int); // game pub/rate
	void add(const char*, unsigned int, const char*, const char*, unsigned int); // music art/pub/dur
	void add(const char*, unsigned int, const char*, unsigned int, unsigned int); // movie dir/dur/rate
	std::vector<DM*>* search(bool, const char*);
	void del(bool type, char* str);
};


#endif