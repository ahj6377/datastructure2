
#include "MusicType.h"




// Á¤ÀÇºÎ
// Set student song Name from keyboard.
void MusicType::SetNameFromKB()
{

	cout << "\tsong Name : ";
	cin >> Name;

}


// Set Singer Name from keyboard.
void MusicType::SetSingerFromKB()
{

	cout << "\tSinger : ";
	cin >> Singer;

}


// Set Album Name from keyboard.
void MusicType::SetAlbumFromKB()
{

	cout << "\tAlbum : ";
	cin >> Album;

}
// Set Genre from keyboard
void MusicType::SetGenreFromKB()
{

	cout << "\tGenre : ";
	cin >> Genre;


}

// Set Lyrics from keyboard
void MusicType::SetLyricsFromKB()
{
	cin.ignore();
	cout << "\tLyrics : ";
	getline(cin, Lyrics);
}
void MusicType::SetNumFromKB()
{
	cout << "\tNumber : ";
	cin >> Num;
}


// Set student record from keyboard.
void MusicType::SetInfoFromKB()
{
	//SetNumFromKB();
	SetNameFromKB();
	SetSingerFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
	SetPkey();
}


// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> Name;
	fin >> Singer;
	fin >> Album;
	fin >> Genre;
	getline(fin, Lyrics);
	return 1;
};


// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << Name << " ";
	fout << Singer << " ";
	fout << Album << " ";
	fout << Lyrics << " ";

	return 1;
}