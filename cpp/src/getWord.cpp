#include "getWord.h"
#include <fstream>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;
vector<string> getWordList(){
    srand(time(NULL));
    ifstream wordDict;
    wordDict.open ("/usr/share/dict/words");

    vector<string> wordList;
    vector<string> fileWords;

    string word;

    while (getline(wordDict, word)){
        fileWords.push_back(word);
    }
    for (int i = 0; i < 40; i++){
        wordList.push_back(fileWords[rand()%fileWords.size()]);
        //cout << wordList[i] << endl;
    }
    
    
    
    
    

    wordDict.close();
    return wordList;
}
