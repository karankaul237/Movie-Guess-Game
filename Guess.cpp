#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

void PlayGame(const vector<string>& movieList){
  srand(time(0));
  int randomIdx = rand() % movieList.size();
  string randomMovie = movieList[randomIdx];

  cout << "Let's Start the Game!" << endl;

  transform(randomMovie.begin(), randomMovie.end(), randomMovie.begin(), ::tolower);

  string hiddenMovie(randomMovie.length(), '_');
  string guessedLetters = "";  

  for (int i = 0; i < randomMovie.length(); ++i) {
    if (randomMovie[i] == ' ') {
      hiddenMovie[i] = ' '; 
    }
    else {
      hiddenMovie[i] = '_'; 
    }
  }

  while (true) {
    bool correctGuess = false;
    char guess;

    cout << "\nMovie: " << hiddenMovie << endl;
    cout << "Guessed letters: " << guessedLetters << endl;
    cout << "Enter your guess (a single letter): ";
    cin >> guess;

    guess = tolower(guess);

    if (guessedLetters.find(guess) != string::npos) {
      cout << guess << " has already been guessed.\n";
      continue;
    }
    guessedLetters += guess; 

    for (int i = 0; i < randomMovie.length(); ++i) {
      if (randomMovie[i] == guess && hiddenMovie[i] == '_') {
        hiddenMovie[i] = randomMovie[i];
        correctGuess = true;
      }
    }

    if (!correctGuess) {
      cout << "Wrong guess! Try again.\n";
    }
    cout << endl;
    if (hiddenMovie == randomMovie) {
      cout << "Congratulations!! You won!\n";
      cout << "The movie was: " << randomMovie << endl;
      return;
    }
  }
}
void EnglishMovies(){
  vector<string> EnglishMovies = {"The Godfather","The Dark Knight","The Lion King","The Karate Kid","Oppenheimer","American Psycho","Inception","Interstellar","Life of Pi","The Shawshank Redemption","Stuart Little","John Wick","Mission Impossible","The Social Network", "King Kong", "Joker", "The Mummy","Jurassic World", "The Prestige", "The Matrix","Titanic"};

  PlayGame(EnglishMovies);
}  

void HindiMovies(){
  vector<string> HindiMovies = {"Pushpa","Sholay","Bahubali","Dangal","Animal","Bajrangi Bhaijaan","Kuch Kuch Hota Hai","Om Shanti Om","Dil","Singham","Veer Zara","Coolie","Gabbar is Back","Bhaag Milkha Bhaag","PK","Dhoom","Kabir Singh","Lagaan","Golmaal","The Legend of Bhagat Singh"};

  PlayGame(HindiMovies);
}

void PunjabiMovies(){
  vector<string> PunjabiMovies = {"Jatt and Juliet","Chal Mera Putt","Angrej","Teshan","Nikka Zaildar","Qismat","Shreek","Daana Pani","Warning","Ardaas","Daakuan Da Munda","Rupinder Gandhi","Vekh Baraatan Challiyan","Lahoriye","Rabb Da Radio"};

  PlayGame(PunjabiMovies);
}

int main(){
  cout << "Welcome to Movie Guessing Game!\n";
  cout << "There are three types of Movies in this Game\nSelect the number of the type of movie you want to guess\n(1)English Movies\n(2)Hindi Movies\n(3)Punjabi Movies" << endl;
  int choice;
  cin >> choice;
  switch(choice){
    case 1:
    EnglishMovies();
    break;
    case 2:
    HindiMovies();
    break;
    case 3:
    PunjabiMovies();
    break;
    default:
    cout << "Invalid Choice" << endl;
  }
  return 0;
}