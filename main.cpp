#include "GameManager.h"

int main() {
    GameManager villageGame;

    while (!villageGame.getWindow()->isTerminated()){
        villageGame.handleInput();
        villageGame.update();
        villageGame.render();
        villageGame.restartClock();
    }
}
