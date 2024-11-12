#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;

string takeinput()
{
    bool valid = false;
    string letter;

    while(!valid){
        cout << "Please enter a letter"<< endl;
        cin >> letter;
        if(letter.size() == 1)
            valid = true;
        else
            cout << "Invalid" << endl; 
    }
    return letter;


}

string getword() {
    ifstream file("WORDS.txt");

    vector<string> words;
    string word;
    
    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    srand(time(0));


    int randNum = rand()%words.size();
    return words[randNum];
    abort;
}

int numberleft(string current)
{
    int count = 0;

    for (int i = 0; i < 5; i++){
        if(current.substr(i, 1) == "_")
            count++;
    }

    return count;
}

void print_hangman(int mistakes) 
{
    if (mistakes == 1) 
    {
        cout << "---------------" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "---------------" << endl;
    } else {
        cout << "---------------" << endl;
        cout << "|             |" << endl;
        cout << "|  -       -  |" << endl;
        cout << "|      ^      |" << endl;
        cout << "|   -------   |" << endl;
        cout << "|             |" << endl;
        cout << "---------------" << endl;
    }

    if (mistakes == 3) 
    {
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
    } else if (mistakes > 3) {
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "-------|-------" << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
    }

    if (mistakes >= 5) 
    {
        cout << "      /\\       " << endl;
        cout << "     /  \\       " << endl;
        cout << "    /    \\       " << endl;
    }
}

int main()
{
    string played;
    string target = getword();
    string current = "_____";
    int mistakes = 0;
    int temp;

    while(numberleft(current) != 0){
        cout << current << endl;
        played = takeinput();
        temp = numberleft(current);

        for(int i = 0; i < 5; i++){
            if(target.substr(i, 1) == played){
                current = current.substr(0, i) + played + current.substr(i+1);
            }   
        }

        if(temp == numberleft(current))
            mistakes++;
        
        print_hangman(mistakes);
    }

    cout << "You completed the hangman of the word " << target << " with " << mistakes << " mistake(s)";
}