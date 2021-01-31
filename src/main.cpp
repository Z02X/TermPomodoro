#include <iostream>
#include <unistd.h>
#include <SFML/Audio.hpp>

//This takes time_wait then sleeps for that amount of time in <units> then plays sound
void play_sound_after(int time_wait, sf::Music& sound)
{
	std::cout << "Started timer" << std::endl;
	sleep(time_wait);
	std::cout << "Press enter" << std::endl;
	sound.play();
	//This only works if you run std::cin.ignore(); twice.. Sigh
	std::cin.ignore();
	std::cin.ignore();
	sound.stop();
}

int main()
{
	// NOTE(Z): Unnecessary optimization can put under the while, I do this because fo the type of code I work on.
	int input = 0;

	sf::Music sound;
	// Initialize
	if (!sound.openFromFile("./files/sound.wav"))
	{
		std::cout << "Couldn't load sound."; // NOTE(Z): May want to tell user to check that file exist.
		return -1; // NOTE(Z): Just something other than 0 since 0 is concidered pass.
	}

	while(1)
	{
		//Clears screen
		std::cout << "\x1B[2J\x1B[H";

		//Asks the user what to do
		std::cout << std::endl;
		std::cout << "How long would you want to take a break for or work for?" << std::endl << std::endl;

		std::cout << "1. Work for 25 mins"         << std::endl;
		std::cout << "2. Take a break for 5 mins"  << std::endl;
		std::cout << "3. Take a break for 10 mins" << std::endl << std::endl;

		":";

		// NOTE(Z): What happens when someone puts not a number :) this is a simple program so no need to fix it's just good to point out
		// these things.
		std::cin >> input;

		//Checks the Input starting with 3 since we all know you are lazy and will pick 3
		if(input == 3)
		{
			wait_for(600, sound);
		}
		else if (input == 2)
		{
			//wait_for(300); Try to not submit commented out code without explanation.
			wait_for(1, sound);
		}
		else if (input == 1)
		{
			wait_for(1500, sound);
		}
		else
		{
			std::cout << "Invalid input press enter";
		}
	}

	// Never ever ever ever ever, get into the habbit of forgetting to return a function. Learn about warning levels they force you to
	// learn good habits early on.
	return 0;
}
