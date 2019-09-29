/* ------------------------------------------------
 * sample.cpp
 *
 * Class: Program #3 for CS 141, Fall 2019
 * System: Atom on linix
 * Author: Lilly C and Karan Singh Kochar
 *
*/

/* play space her

*/

#include <iostream>     // for input out put to terminal
#include <cctype>       // For the letter checking functions
#include <fstream>      // For file input
#include <iomanip>      // For setw
#include <cstdlib>      // For exit and abs
#include <vector>       // For enabling vector here

using namespace std;

// displayIDInfo starts here ---------------------------------------------------------------
void displayIdInfo()
{
    cout << " \n"
         << "Program #3: Work Play                       \n"
         << "Author: Lilly C and Karan Singh Kochar      \n"
         << "Lab: Tues 9am                               \n"
         << "System: Atom on linux                       \n"
         << " \n";
}//end displayIDInfo()

// simple function to open a file and return the stream -------------------------------------
ifstream openTextFile( string nameOfFile = " " ){
  ifstream inputFileStream;  // Declare the input file stream

  // Open input file
  inputFileStream.open( nameOfFile.c_str() );

  //verify if the input to the function wasnt blank
  if(nameOfFile == " "){
      cout << "Please enter the file name in the function" << endl;
      cout << "Exiting the program ..."<< endl;
      exit( -1);
  }
  // verify that file was found
  else if( !inputFileStream.is_open()) {
      cout << "Could not find input file " << nameOfFile << "  Exiting..." << endl;
      exit( -1);
  }

  return inputFileStream;
}

// Storing all the words in a words in a vector ----------------------------------------------
void storeWordsInVector(vector<string>& dictionary, string nameOfFile){
  ifstream inputFileStream = openTextFile(nameOfFile);
  string line;
  int count = 0;
  while(getline(inputFileStream, line)){
    dictionary.push_back(line);
  }
  inputFileStream.close();

} // storeWordsInVector() ends here.

// getWordOccurance starts here ----------------------------------------------------------------------------
void getWordOccurance(vector<int>& wordOccuranceQuantity, vector<string> dictionary){
  int longestWordLength = 0;
  // Get the highest char length of word
  for(int i = 0; i < dictionary.size(); i++){
    string line = dictionary.at(i);
    if(line.size() > longestWordLength){
      longestWordLength = line.size();
    }
  }

  //Setting wordOccuranceQuantity vector's size to longestWordLength so we
  //could store the count of word in their respective char count.
  //For eg: lets say there are 69 words that has 2 character then at 1st (2-1 = 1)
  // index will store 69 as a value.
  wordOccuranceQuantity.resize(longestWordLength);

  for (int i = 0; i < dictionary.size(); i++) {
    string line = dictionary.at(i);
    wordOccuranceQuantity.at( line.length() -1) += 1;
  }

}// wordLengthCalc ends here.


// printing wordOccuranceQuantity starts here ----------------------------------------------------------------
void printQuantity(vector<int> wordOccuranceQuantity){

  // Printing details of the upcoming prints
  cout << "Word lengths where there are more than 1400 words:\n"
       << "Length  How Many\n"
       << "------  --------"
       << endl;

  // iterating through wordOccuranceQuantity vector to print words length occurance that is greater than 1400
  for (int i = 0; i < wordOccuranceQuantity.size() - 1; i++){
    if(wordOccuranceQuantity.at(i) > 1400){
      cout << " "
           << setw(4)
           << i+1
           << "    ";

      cout << setw(6)
           << wordOccuranceQuantity.at(i) << endl;
    }
  }

  cout << endl;
} // printQuantity() ends here

long binarySearch(string searchWord, vector< string> dictionary){

    long low, mid, high;     // array indices for binary search
    long searchResult = -1;  // Stores index of word if search succeeded, else -1

    // Binary search for word
    low = 0;
    high = dictionary.size() - 1;
    while ( low <= high)  {
        mid = (low + high) / 2;
        // SearchResult negative value means word is to the left, positive value means
        // word is to the right, value of 0 means word was found
        searchResult = searchWord.compare( dictionary[ mid] );
        if ( searchResult == 0)  {
            // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1; // word should be located before the mid location
        }
        else  {
            low = mid + 1; // word should be located after the mid location
        }
    }

    // Word was not found
    return -1;
}//end binarySearch()


// main() starts here ----------------------------------------------------------------------------
int main() {

  // printing out program details
  displayIdInfo();

  // initializing vectors
  vector<string> dictionary;
  vector<int> wordOccuranceQuantity;
  int wordLength = 3;
  int userChoice;
  string startWord = "dog";
  string endWord = "cat";

  // store words from file to a vector
  storeWordsInVector(dictionary, "dictionary.txt" );
  cout << "Total number of words in dictionary file: " << dictionary.size() << endl << endl;

  // gettin word occurance from dictionary and saving them in wordOccuranceQuantity
  getWordOccurance(wordOccuranceQuantity, dictionary);

  // just print the qty of words with perticular length.
  printQuantity(wordOccuranceQuantity);

  // taking user input and making sure its within word length range
  while(1){
      cout << "Currently we have " << wordOccuranceQuantity.at(wordLength - 1) << " words of length " << wordLength << " in the dictionary." << endl;
      cout << "Changing from '"<< startWord << "' to '"<< endWord <<"'\n" << endl;

      cout << "Choose from the following options: \n"
           << "  1. Change the word length \n"
           << "  2. Display some dictionary words \n"
           << "  3. Get start and end words \n"
           << "  4. Play the word change game \n"
           << "  5. Find the end word with debug \n"
           << "  6. Find the end word \n"
           << "  7. Display an answer sequence \n"
           << "  8. Exit the program\n"
           << "Your choice -> ";
      cin  >> userChoice;
      cout << endl;

      switch(userChoice){
        case 1: // 1. Change the word length
            cout << "What length words do you want to use? ";
            cin  >> wordLength; // updating user word length
            cout << endl;

            // resetting start and end words;
            startWord = "";
            endWord = "";
            break;

        case 2: // FIXME Lilly
            break;

        case 3: // FIXME Lilly
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8: //8. Exit the program
            cout << "Exitting the prgram\n" << endl;
            exit(-1); // exit the program
            break;

        default: // invalud responce
          while(1){ // waiting for the user to input a right input
             cout << "invalid response! try again!!" << endl; // if user choice is in the range

             cout << "Your choice -> ";
             cin  >> userChoice;
             cout << endl;
             if(userChoice < 9 && userChoice > 0){
               break;
             }
          }
      }
  }





  return 0;
}
