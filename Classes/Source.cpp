#include <iostream>
#include <cstring>
using namespace std;

int const Max = 100;
class Song {
private:
	char title[Max];
	char artist[Max];
	int duration;
public:

	Song()
	{
		strcpy_s(title, "");
		strcpy_s(artist, "");
		duration = 0;
	}

	Song(char const * new_title, char const* new_artist, int new_duration)
	{
		strncpy_s(this->title, new_title, Max - 1);
		this->title[Max - 1] = '/0';
		strncpy_s(artist, new_artist, Max - 1);
		this->artist[Max - 1] = '/0';
		this->duration = new_duration;
	}

	char const* getTitle() const
	{
		return title;
	}

	char const* getArtist() const
	{
		return artist;
	}

	int getDuration()
	{
		return duration;
	}

	void printSong()
	{
		cout << getTitle() << " " << getArtist() << " " << getDuration() << endl;
 	}
};

class Playlist
{
private:
	Song* playlist;
	int capacity;
	int size;

	void copy(Playlist const &other)
	{
		size = other.size;
		capacity = other.capacity;
		playlist = new Song[other.capacity];
		for (int i = 0; i < other.size; i++)
		{
			playlist[i] = other.playlist[i];
		}
	}
public:
	Playlist(int num)
	{
		capacity = num;
		size = 0;
		playlist = new Song[capacity];
	}

	Playlist(Playlist const& other) {
		copy(other);
	}

	~Playlist() {
		delete[] playlist;
	}

	void addSong(Song const &song)
	{
		if (size < capacity)
		{
			playlist[++size] = song;
		}
		else cout << "Playlist is full! " << endl;
	}

	void printPlaylist()
	{
		for (int i = 1; i < size + 1; i++)
		{
			cout << playlist[i].getTitle() << " " << playlist[i].getArtist() << " " << playlist[i].getDuration() 
				<< endl;
		}
	}

	int totalDuration()
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += playlist[i].getDuration();
		}
		return sum;
	}

	void longestSong()
	{
		Song longest_song;
		for (int i = 0; i < size; i++)
		{
			if (longest_song.getDuration() < playlist[i].getDuration())
			{
				longest_song = playlist[i];
			}
		}
		longest_song.printSong();
	}
};

int main()
{
	Song a("MMA", "Azis", 323); 
	Song b("Otlichen 6", "Toni Storaro", 420);
	Song c("Poludei", "Djordan", 350);
	Song d("Nonstop", "Drake", 212);
	Song e("Bel djip", "BNR", 422);
	Song f("Dim4ou", "422", 320);
	Song g("Krisko", "Nezamenim", 293);
	Playlist ab(50);
	ab.addSong(a);
	ab.addSong(b);
	ab.addSong(c);
	ab.addSong(d);
	ab.addSong(e);
	ab.addSong(f);
	ab.addSong(g);
	cout << ab.totalDuration() << endl;
	ab.longestSong();
}