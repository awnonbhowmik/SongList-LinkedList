#include "pch.h"
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

string inputs() {
	string input;
	getline(cin, input);
	return input;
}

int inputi() {
	string input;
	getline(cin, input);
	return atoi(input.c_str());
}

class Song
{
private:
	int SongID;
	string Title;
	string Artist;
	string Album;
	int year;

public:
	Song();	//default constructor, sets strings to "" and integer variables to 0
	Song(int aID, string aTitle, string anArtist, string anAlbum, int aYear);

	int getSongID() const;
	string getTitle() const;
	string getArtist() const;
	string getAlbum() const;
	int getYearReleased() const;

	void setSongID(int newSongID);
	void setTitle(string newTitle);
	void setArtist(string newArtist);
	void setAlbum(string newAlbum);
	void setYear(int newYear);
};

struct node
{
	Song song;
	node *next;
};

void displayList(node **head)
{
	node *temp = *head;
	if (temp == NULL)
		cout << "Empty"<<endl;
	else {
		while (temp != NULL)
		{
			cout << "Title: " << temp->song.getTitle() << endl;
			cout << "Artist: " << temp->song.getArtist() << endl;
			cout << "Album: " << temp->song.getAlbum() << endl;
			cout << "Year: " << temp->song.getYearReleased() << endl << endl;
			temp = temp->next;
		}
	}
}

void displaySong(node **head, int ID)
{
	node *temp = *head;
	if (temp == NULL)
		cout << "List is empty" << endl;
	else if (temp->song.getSongID() == ID)
	{
		cout << "Title: " << temp->song.getTitle() << endl;
		cout << "Artist: " << temp->song.getArtist() << endl;
		cout << "Album: " << temp->song.getAlbum() << endl;
		cout << "Year: " << temp->song.getYearReleased() << endl << endl;

		temp = temp->next;
	}
	else
	{
		cout << "Song ID not found in the list!" << endl;
	}
}

void insertNewSong(node** head, Song newSong)
{
	node *temp = new node();
	temp->song.setSongID(newSong.getSongID());
	temp->song.setTitle(newSong.getTitle());
	temp->song.setArtist(newSong.getArtist());
	temp->song.setAlbum(newSong.getAlbum());
	temp->song.setYear(newSong.getYearReleased());

	temp->next = *head;
	*head = temp;
}

Song::Song()
{
	SongID = 0;
	Title = "";
	Artist = "";
	Album = "";
	year = 0;
}

Song::Song(int aID, string aTitle, string anArtist, string anAlbum, int aYear)
{
	aID = SongID;
	aTitle = Title;
	anArtist = Artist;
	anAlbum = Album;
	aYear = year;
}

int Song::getSongID() const
{
	return SongID;
}

string Song::getTitle() const
{
	return Title;
}

string Song::getArtist() const
{
	return Artist;
}

string Song::getAlbum() const
{
	return Album;
}

int Song::getYearReleased() const
{
	return year;
}

void Song::setSongID(int newSongID)
{
	SongID = newSongID;
}

void Song::setTitle(string newTitle)
{
	Title = newTitle;
}

void Song::setArtist(string newArtist)
{
	Artist = newArtist;
}

void Song::setAlbum(string newAlbum)
{
	Album = newAlbum;
}

void Song::setYear(int newYear)
{
	year = newYear;
}

int main(int argc, const char *argv[])
{
	int choice = 0;
	node *list = NULL;

	int newSongID;
	string newTitle;
	string newArtist;
	string newAlbum;
	int newYear;
	int id;


	while (true)
	{
		cout << "**** My Song List ****" << endl;
		cout << "1 - Display List" << endl;
		cout << "2 - Display Song" << endl;
		cout << "3 - Insert New Song" << endl;
		cout << "4 - Exit"<<endl<<endl;

		cout << "Enter your choice and press return:";
		choice = inputi();
		switch (choice)
		{
		case 1:
		{
			displayList(&list);
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "Enter the ID of the song that you would like to display: ";
			id = inputi();
			cout << endl;
			displaySong(&list, id);
			break;
		}
		case 3:
		{
			Song newSong;
			cout << endl;
			cout << "Enter information for your new song!" << endl;
			cout << "Song ID: ";
			newSongID = inputi();
			newSong.setSongID(newSongID);

			cout << "Title: ";
			newTitle = inputs();
			newSong.setTitle(newTitle);

			cout << "Artist: ";
			newArtist = inputs();
			newSong.setArtist(newArtist);

			cout << "Album: ";
			newAlbum = inputs();
			newSong.setAlbum(newAlbum);

			cout << "Year: ";
			newYear = inputi();
			newSong.setYear(newYear);

			insertNewSong(&list, newSong);
			cout << endl << "New song is added!!!" << endl;
			break;
		}
		case 4:
		{
			cout << "End of program.\n";
			return 0;
			break;
		}
		default:
		{
			cout << "Not a Valid Choice.\n\n";
			break;
		}
		}
	}
	return 0;
}