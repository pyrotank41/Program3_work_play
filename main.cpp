
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

displayIDInfo starts here ---------------------------------------------------------------
void displayIdInfo()
{
    cout << " \n"
         << "Program #3: Work Play                       \n"
         << "Author: Lilly C and Karan Singh Kochar      \n"
         << "Lab: Tues 9am                               \n"
         << "System: Atom on linux                       \n"
         << " \n";
}//end displayIDInfo()



// // using this instead of the one above just to pass checks.
// void displayIdInfo()
// {
//     cout << "Program #3: Work Play  \n"
//          << "Author: Dale Reed      \n"
//          << "Lab: Tues 8am          \n"
//          << "System:  Codio         \n"
//          << " \n";
// }//end displayIDInfo()



// binarySearch() starts here ----------------------------------------------------------------
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

// regular search for when we dont have a sorted vector. - ------------------------------------
int regularSearch(string searchWord, vector<string> & listOfWords){
  for (int sIndex = 0; sIndex < listOfWords.size(); sIndex++){
    if(listOfWords.at(sIndex).compare(searchWord) == 0){
      return sIndex; // return the index of the word found
    }
  }
  return -1; // return -1 if nothing found
}//regularSearch() ends here


// Storing all the words in a words in a vector ----------------------------------------------
void storeWordsInVector(vector<string>& dictionary, string nameOfFile, int wordLength = -1){

  dictionary.clear(); // starting with a clean vector to full in new values
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

    // push all the words from the file to the vector
    if(isupper(line.at(0))){
      line.at(0) = tolower(line.at(0));
    }
    if(wordLength == -1){ //when wordlength is -1 push in all the words
      dictionary.push_back(line);
    }
    // pushing only the specific word with specified length to the vector.
    else if(line.size() == wordLength){
      dictionary.push_back(line);
    }

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
       << "Length  How Many  \n"
       << "------  --------  "
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

// displayDictionaryWords() starts here --------------------------------------------------------------------------
// case 2 by lilly
void displayDictionaryWords(int &startNum, int &endNum, vector<string> tempLengthVector){

    cout << "About to display dictionary words from " << startNum
         << " to " << endNum << endl;

    for(int i = startNum; i <= endNum; i++) {
        cout << i << " " << tempLengthVector.at(i) << endl;
    }
    cout << endl << endl;

} //end displayDictionaryWords.

// startEndWord() starts here ------------------------------------------------------------------------------------------------------------
// case 3 i.e to change start word and end word
void startEndWord( int wordLength, vector<string> tempLengthVector, string &startWord, string &endWord) {

    //gets startWord and tests all conditions
    while (1){
      cout << "\nEnter starting word, or 'r' for a random word: ";
      cin  >> startWord;

      if(startWord == "exit"){ // exiting program
          cout << "Exiting program." <<endl;
          exit(-1);
      }
      if(startWord == "r"){ // generating random
          startWord = tempLengthVector.at(rand() % tempLengthVector.size());
          break;
      }
      if(startWord.length() != wordLength ){ // if not appropriate length.
        cout << "   *** '"<< startWord <<"' is not of length " << wordLength << ". Please retry." << endl;
      }
      else if (binarySearch(startWord, tempLengthVector) == -1 ) { // not in dictionary.
        cout << "   *** '"<< startWord <<"' is not in the dictionary. Please retry." << endl;
      }
      else{ // if no error.
        break;
      }// while(1) ends here.

    }
    cout << endl;


    //gets endWord and tests all conditions
    while (1){

      cout << "Enter ending word, or 'r' for a random word: ";
      cin  >> endWord;

      if(endWord == "exit"){// exiting program
          cout << "Exiting program." <<endl;
          exit(-1);
      }
      if(endWord == "r"){// generating random
          endWord = tempLengthVector.at(rand() % tempLengthVector.size());
          break;
      }
      if(endWord.length() != wordLength){// if not appropriate length.
        cout << "   *** '"<< endWord <<"' is not of length "<< wordLength << ". Please retry." << endl;
      }
      else if (binarySearch(startWord, tempLengthVector) == -1 ){ // not in dictionary.
        cout << "   *** '"<< endWord <<"' is not in the dictionary. Please retry." << endl;
      }
      else{ // if no error.
        break;
      }
    }// while(1) ends here.
    cout << endl;

} // startEndWord() ends here.

// wordChangeGame() starts here -------------------------------------------------------------------------------------------------------------
// case 4. where user playes the word game.
void wordChangeGame(string startWord, string endWord, vector<string> dictionary){


    string prevWord = startWord;
    string currWord;
    int count;
    int stepCount = 1;
    cout << stepCount <<". Previous word is '" << prevWord << "'. Next word: ";
    cin >> currWord;

    while(1){
        count = 0;

        //counts number of char differences
        for(int i = 0; i < prevWord.length(); i++){
            if(currWord.at(i) != prevWord.at(i)){
                count++;
            }
        }

        if(currWord == "exit"){
           break;
        }

        else if(currWord == endWord){
            cout << endl << "Congratulations, you did it!" << endl;
            break;
        }

        else if(currWord.length() != prevWord.length()){
            cout << "   *** '" << currWord << "' is not of length "<< prevWord.length() << ". Please retry." << endl;

        }
        else if(binarySearch(currWord, dictionary) == -1){
            cout << "   *** '" << currWord << "' is not in the dictionary. Please retry." << endl;

        }
        else if( count != 1){
            cout << "*** '" << currWord << "' must be exactly 1 character different. Please retry." << endl;

        }
        else{
            prevWord = currWord;
            stepCount++;
        }





        cout << stepCount <<". Previous word is '" << prevWord << "'. Next word: ";
        cin >> currWord;

    } //end while loop



} //end WordChangeGame

// findSequence() starts here ------------------------------------------------------------------------------------------------------------
// Function for case 5 and 6.
int findSequence(string startWord,
                string endWord,
                vector<string> dictionary,
                vector<string> &sequenceVector, //stores the word sequence in the vector
                vector<int> &sequenceIndexVector,
                int debug = 0){

  //this function has turned out to be a mess now, try and make it look clean and eleminate repitation FIXME
  sequenceVector.clear(); // just to start with a clear slate for the sequence.
  sequenceIndexVector.clear(); // same as above.
  //vector<string> sequenceVector; //temp vector to store the psudo sequence.
  sequenceVector.push_back(startWord);// pushing startWord
  sequenceIndexVector.push_back(0);
  string tempString;

  int startIndex = 0;
  int startWordLength = startWord.length();

  // think of an explaination here.... lol.. this one just makes senses future karan, dont be lazy and try to understand y this loop ... lmao.
  for(int i = 0; i < sequenceVector.size(); i++ ){

    if(debug == 1) cout << i << ".  " << sequenceVector.at(i)<< ":    "; // print when debug is ON

    // itterating through all the indexes for of the current word to find possible match in dictionary.
    for(int index = 0; index < startWordLength; index++ ){
      // itterating through all the possible combination for changing only one character at a time
      tempString = sequenceVector.at(i);
      for(char c = 'a'; c <= 'z'; c++ ){
        // skipping repetation of word, ex if the starting word was dog, c = 'd', then we will skip dog.
        if(sequenceVector.at(i).at(index) == c){
          continue;
        }

        tempString.at(index) = c;
        if(regularSearch(tempString, dictionary) != -1){

          int wordFound = regularSearch(tempString, sequenceVector);

          if(wordFound == -1){ // if the word is not found push the string in the vector.
              sequenceVector.push_back(tempString);
              sequenceIndexVector.push_back(i);

              if(debug == 1) {
                cout << sequenceVector.size()-1 << ":"<< sequenceVector.back()<< " ";
              }

              if(tempString == endWord){ // breaking out of the loop once endword is found.

                  cout << endl << "\nWinning sequence was found!" << endl << endl;

                return 1;
              }
          }
        }// binary search in dictionary ends here.
      }// char iteration one word ends here.
    }// index iteration ends here.

    // start index is set to current sequenceVector size - 1, so in next print cycle
    // it starts from previously left position i.e non printed terms.
    startIndex = sequenceVector.size()-1;
    if(debug == 1)cout << endl;
  }

}//findSequence() ends here.

// displaySeq() starts here -------------------------------------------------------------------------------------
// case 7. to diaplay the sequence generated in case 5 or 6
void displaySeq( vector<string> sequenceVector, vector<int> sequenceIndexVector){
  string startWord = sequenceVector.at(0);
  string endWord = sequenceVector.back();

  cout << "Winning sequence in reverse order is:" << endl;

  cout << setw(5) << sequenceVector.size()-1 << ".";
  cout << " " << endWord << endl;

  int parentIndex = sequenceIndexVector.at(sequenceVector.size()-1); // setting parent index of the last word
  string word = sequenceVector.at(parentIndex); //getting 1st parent word.

  while(1){
    cout << setw(5) << parentIndex << ".";
    cout << " " << word << endl;

    if(word.compare(startWord) == 0){
      break; // break out of the loop once we reach start word.
    }

    // opdating the variables so they become the chiled to their parent.
    parentIndex = sequenceIndexVector.at(regularSearch(word, sequenceVector));
    word = sequenceVector.at(parentIndex);
  }

}// displaySeq() ends here.

// main() starts here ----------------------------------------------------------------------------
int main() {

  // printing out program details
  displayIdInfo();

  // initializing vectors
  vector<string> wholeDictionary;
  vector<string> dictionary;
  vector<string> sequenceVector;
  vector<int> sequenceIndexVector;
  vector<int> wordOccuranceQuantity;
  int userChoice;
  string startWord = "dog";
  string endWord = "cat";
  int wordLength = startWord.length();

  // storing all the words from the dictionary.
  storeWordsInVector(wholeDictionary, "dictionary.txt");
  cout << "Total number of words in dictionary file: " << wholeDictionary.size() << endl << endl;

  // storing specific words of perticular wordLength from file to a vector
  storeWordsInVector(dictionary, "dictionary.txt", wordLength);


  // gettin word occurance from dictionary and saving them in wordOccuranceQuantity
  getWordOccurance(wordOccuranceQuantity, wholeDictionary);

  // just print the qty of words with perticular length.
  printQuantity(wordOccuranceQuantity);

  // taking user input and making sure its within word length range
  while(1){
      cout << "Currently we have " << wordOccuranceQuantity.at(wordLength - 1) << " words of length " << wordLength << " in the dictionary." << endl;
      cout << "Changing from '"<< startWord << "' to '"<< endWord <<"'\n" << endl;

      cout << "Choose from the following options:  \n"
           << "   1. Change the word length        \n"
           << "   2. Display some dictionary words \n"
           << "   3. Get start and end words       \n"
           << "   4. Play the word change game     \n"
           << "   5. Find the end word with debug  \n"
           << "   6. Find the end word             \n"
           << "   7. Display an answer sequence    \n"
           << "   8. Exit the program              \n"
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

        case 2:    //vector of all words length wordLength
            int startNum, endNum;
            cout << "Enter the start and end index values of words to display: ";
            cin >> startNum >> endNum;
            cout << endl;
            displayDictionaryWords(startNum, endNum, dictionary);
            break;

        case 3: // FIXME Lilly
            storeWordsInVector(dictionary, "dictionary.txt", wordLength);
            startEndWord(wordLength, dictionary, startWord, endWord);
            break;

        case 4: // FIXME Lilly
            wordChangeGame(startWord, endWord, dictionary);
            break;

        case 5: //Find the end word with debug
            findSequence(startWord, endWord, dictionary, sequenceVector, sequenceIndexVector, 1);
            break;

        case 6: //Find the end word WITHOUT debug but success.
            findSequence(startWord, endWord, dictionary, sequenceVector, sequenceIndexVector);
            break;

        case 7: //Display an answer sequence
            if(sequenceVector.size() == 0){
              cout << "   *** You must find the solution before displaying it." << endl << endl;
            }
            else{
              displaySeq(sequenceVector, sequenceIndexVector);

            }
            break;

        case 8: //8. Exit the program
            cout << "Exiting the program\n" << endl;
            exit(-1); // exit the program
            break;

        default: // invalid responce
          while(1){ // waiting for the user to input a right input
             cout << "invalid response! try again!!" << endl; // if user choice is in the range
             cout << "Your choice -> ";
             cin  >> userChoice;
             cout << endl;
             if(userChoice < 9 && userChoice >= 0){
               break;
             }
          }
      }
  }
  return 0;
}
