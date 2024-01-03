    //
    //  main.cpp
    //  Test
    //
    //  Created by Kyo Mangold on 14.01.18.
    //   © 2018 Kyo Mangold. All rights reserved.
    //

    // UNCOMMENT THE FOLLOWING LINE (REMOVE THE TWO SLASHES AT THE BEGINNING) TO RUN AUTOMATIC TESTS
    //#include "tests.h"

    #include <iostream>
    #include <string>
    //#include "hangman.h"

    int main(){
        
        // TODO: Your Hangman implementation goes here
        const int max_wrong = 6;
        int wrong_guesses = 0;
        std::string word_to_guess ="APPLE"; //call random word to guess with chooseWord() function
        std::string unmasked;
        std::string underline ="_ ";
        unmasked = std::string(word_to_guess.length(), '_');
        
        while(wrong_guesses < max_wrong)
        {
            int attempts = max_wrong - wrong_guesses;// attempts left
            std::cout << "Attempts left: ";
            std::cout << attempts << std::endl;
            
            
            std::cout << "[ ";
            for(int i =0; i<unmasked.length();i++){
                std::cout << unmasked.at(i) << " ";
            }
            std::cout << "]";
            
            char guess;
            std::cout << "Your guess: \n" ;
            std::cin >> guess; // input: guessed letter
    
            if (word_to_guess.find(guess) != std::string::npos) // checks if guess is in the word to guess
                {
              // need to update the unmasked word, because the guess was correct
                    for (int i = 0; i < word_to_guess.length(); i++)
                    {
                        if (word_to_guess[i] == guess)
                        {
                           unmasked[i] = guess;
                        }
                    }
                }
                   
            else // wrong guess, unmasked doesn't need to be updated
                {
                    ++wrong_guesses; // increase wrong guesses
                }

                    
            if (unmasked == word_to_guess) // check if unmasked word is completely unmasked, if so, you win
            {
                std::cout << "[ ";
                for(int i =0; i<unmasked.length();i++){
                    std::cout << unmasked.at(i) << " ";
                }
                std::cout << "]";
                
                std::cout << "\nYou won!\n\n" << std::endl;
                return 0;
            }
        }

        if (wrong_guesses == max_wrong) // check the number of wrong guesses, too many wrong guesses means game over
        {
            std::cout << "\nThe word was: " << word_to_guess << std::endl;
            std::cout << "You lost! \n\n" << std::endl;
            return 0;
        }
        return 0;
    }



