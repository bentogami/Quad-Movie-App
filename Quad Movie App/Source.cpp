#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool again();
bool exists(vector<string> a, string m);
void addMovies(vector<string> a);
/* To do:
void removeMovies(vector<string> a);
void showMovies(vector<string> a);
void update();
*/

int main()
{
	//Initialize movie vector and open the list
	vector<string> movies;
	fstream write;
	write.open("Movie_List.txt");

	//Make sure the file opens properly
	if (!write.is_open()) {
		cout << "List failed to open\n";
		return 0;
	}

	/*
	Populates the vector with all of our movies,
	then closes the list.
	*/
	string movie;	
	while (getline(write, movie)) {
		movies.push_back(movie);
	}
	write.close();

	/* Need to move this to update().
	if (remove("Movie_List.txt") != 0)
		perror("Error removing file");
	*/

	//Main menu:
	bool cont;
	do {
		char ans;
		cout << "What do you want to do?\n"
			<< "1. Add movies\n" << "2. Remove movies\n" << "3. Check List\n" << "4. Exit\n"
			<< "Enter a number: ";
		cin >> ans;
		switch (ans) {
		case '1':
			addMovies(movies);
			cont = again();
			break;

		case '2':
			// To do: removeMovies(movies);
			cont = again();
			break;

		case '3':
			// To do: showMovies(movies);
			cont = again();
			break;

		case '4':
			cont = false;
			break;

		default:
			cout << "Invalid choice. Try again.";
			cont = true;
		}
	} while (cont);

	// To do: update();

	return 0;
}

//Checks if the movie vector contains a movie
bool exists(vector<string> a, string m) {
	bool e = false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == m)
			e = true;
	}
	return e;
}

//Adds as many movies as the user wants
void addMovies(vector<string> a) {
	string m;
	bool addMore;
	do {
		addMore = false;
		//Takes in a movie
		m.clear();
		cout << "Enter a movie: ";
		getline(cin, m);

		//Adds that movie if it isn't in the library
		if (exists(a, m))
			cout << "Movie already in library.\n";
		else {
			a.push_back(m);
			cout << "Movie added.\n";
		}

		//Checks if the user wants to keep adding movies.
		char ans;
		cout << "Want to add another? (y/n): ";
		cin >> ans;
		if (ans == 'y')
			addMore = true;
	} while (addMore);
}

//Checks whether the user wants to do something else
bool again() {
	char ans;
	cout << "Want to do something else? (y/n): ";
	cin >> ans;
	if (ans == 'y')
		return true;
	return false;
}