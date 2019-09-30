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

//binarySearch() starts here ----------------------------------------------------------------
int binarySearch(string searchWord, vector< string> dictionary){

    int low, mid, high;     // array indices for binary search
    int searchResult = -1;  // Stores index of word if search succeeded, else -1

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


// Storing all the words in a words in a vector ----------------------------------------------
void storeWordsInVector(vector<string>& dictionary, string nameOfFile){
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

  string line;
  int count = 0;
  while(getline(inputFileStream, line)){
    // checking and changing word for capital case word to lowercase.
    if(isupper(line.at(0))){
      line.at(0) = tolower(line.at(0));
    }
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
      cout << " " << setw(4) << i+1 << "    ";
      cout << setw(6) << wordOccuranceQuantity.at(i) << endl;
    }
  }

  cout << endl;
} // printQuantity() ends here


int findSequence(string startWord,
                string endWord,
                vector<string> dictionary,
                vector<string> & tempVector,
                vector<int> & sequenceIndexVector,
                int debug = 0){

  tempVector.push_back(startWord);
  string tempString;

  int startIndex = 0;

  // think of an explaination here.... lol.. this one just makes senses future karan, dont be lazy and try to understand y this loop ... lmao.
  for(int i = 0; i < tempVector.size(); i++ ){
    // itterating through all the indexes for of the current word to find possible match in dictionary.
    for(int index = 0; index < startWord.length(); index++ ){
      // itterating through all the possible combination for changing only one character at a time
      for(char c = 'a'; c <= 'z'; c++ ){
        // skipping repetation of word, ex if the starting word was dog, c = 'd', then we will skip dog.
        if(tempVector.at(i).at(index) == c){
          continue;
        }

        tempString = tempVector.at(i);
        tempString.at(index) = c;

        if( binarySearch(tempString, dictionary) != -1){

          bool wordFound = false;
          // simple search algorithm to make sure if any
          for (int sIndex = 0; sIndex < tempVector.size(); sIndex++){
            if(tempString == tempVector.at(sIndex)){
              wordFound = true;
            }
          }// simple search algo ends here.

          if(!wordFound){ // if the word was not found push the string in the vector
              tempVector.push_back(tempString);
          }
        }// binary search in dictionary ends here.
      }// char iteration one word ends here.
    }// index iteration ends here.


    if(debug == 1){ // debug mode on

      cout << i << ".  " << tempVector.at(i)<< ":    ";

      for(int j = startIndex + 1; j < tempVector.size(); j++){
        cout << j << ":"<<tempVector.at(j)<< " ";

        // if endword is found then break out of this function
        if(tempVector.at(j) == endWord){
          cout << endl << "\nWinning sequence was found!" << endl << endl;
          return 1;
        }
      }

      cout << endl;
    }
    else if( debug == 2){
      for(int j = startIndex + 1; j < tempVector.size(); j++){
        // if endword is found then break out of this function
        if(tempVector.at(j) == endWord){
          cout << endl << "\nWinning sequence was found!" << endl << endl;
          return 1;
        }
      }
    }

    // start index is set to current tempVector size-1, so in next print cycle
    // it starts from previously left position i.e non printed terms.
    startIndex = tempVector.size()-1;
  }

}//findSequence() ends here.

//displayAnsSeq starts here ----------------------------------------------------------------------
void displayAnsSeq(vector<string> sequenceVector){

  for(int i = 0; i < sequenceVector.at(0).size(); i++){

  }


}//displayAnsSeq() ends here.

// main() starts here ----------------------------------------------------------------------------
int main() {

  // printing out program details
  displayIdInfo();

  // initializing vectors
  vector<string> dictionary;
  vector<string> sequenceVector;
  vector<int> sequenceIndexVector;
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

        case 4: // FIXME Lilly
            break;

        case 5: //Find the end word with debug
            findSequence(startWord, endWord, dictionary, sequenceVector, sequenceIndexVector, 1);
            break;

        case 6: //Find the end word WITHOUT debug but success.
            findSequence(startWord, endWord, dictionary, sequenceVector, sequenceIndexVector, 2);
            break;

        case 7: //Display an answer sequence
            findSequence(startWord, endWord, dictionary, sequenceVector, sequenceIndexVector);
            displayAnsSeq(sequenceVector);
            break;

        case 8: //8. Exit the program
            cout << "Exitting the prgram\n" << endl;
            exit(-1); // exit the program
            break;

        default: // invalid responce
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
