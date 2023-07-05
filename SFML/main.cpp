#include <SFML/Audio.hpp>
#include <cstdlib>
#include "game.h"
#include "mainMenu.h"

using namespace sf;

int main() {
    Music music;
    if (!music.openFromFile("audio/Interstellar_Arabic.ogg"))
        return -1; // error
    music.play();
    music.setLoop(true);
    mainMenu();  // Call the function from the game logic file

    return 0;
}
