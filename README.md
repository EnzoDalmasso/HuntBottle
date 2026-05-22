# HuntBottle

A classic 2D shooting gallery arcade game developed in **C++** using the **SFML** library. This project was created as a final practical assignment for university during the early stages of my video game development studies.

The objective of the game is to destroy as many bottles as possible within a 60-second time limit while avoiding penalty targets that drain your lives.

---

## Game Mechanics

* **Real-Time Aiming:** The standard mouse cursor is replaced by a custom crosshair to aim and shoot using the left mouse button.
* **Physics-Based Launching:** Bottles spawn randomly from different starting points on the screen and follow a realistic parabolic trajectory driven by simulated velocity and acceleration/gravity.
* **Dynamic Scoring System:** Each bottle type features unique sizes, speeds, and point values:
    * **Brown Bottle:** +100 points.
    * **Black Bottle:** +50 points.
    * **Green Bottle:** +200 points (smaller and faster).
    * **Molotov Cocktail ("Molo"):** Watch out! Shooting this will deduct 1 life.
* **Game Over Conditions:** The match ends when either the 60-second timer runs out or the player loses all 3 lives. Once the game is over, the player can restart the match instantly by pressing the `R` key.

---

## Technologies & Libraries Used

* **Language:** C++
* **Multimedia/Graphics Framework:** SFML (Simple and Fast Multimedia Library)
    * `SFML/Graphics`: For rendering sprites, textures, fonts, and on-screen text (UI elements).
    * `SFML/Window`: To manage the main window application and handle mouse/keyboard inputs.
    * `SFML/Audio`: For background music loop management and shooting sound effects.
* **IDE:** Visual Studio

---

## Project Architecture

The codebase follows Object-Oriented Programming (OOP) principles, neatly separating game entity responsibilities:

* **`Tp final mavi1.cpp`:** The main entry point of the application. It instantiates the central `Encargado` class and kicks off the core game loop.
* **`Encargado.h`:** The central controller or *Game Manager*. It handles window management, the main rendering loop (`Game Loop`), player life counts, scoring, timers, background music, mouse click collision detection, and game state transitions (Gameplay Screen / Game Over Screen).
* **`Jugador1.h`:** Represents the player entity. It tracks and updates the crosshair position based on mouse movement and triggers the gunshot sound effect (`disparo.wav`).
* **`Blancos.h`:** Manages the life cycle of the targets (bottles). It handles random spawning, constant rotation, position updates using movement vectors, and object destruction routines.

---

## ⚙️ Requirements & Installation

To run and compile this project locally, you need to configure **SFML** within your development environment.

### 1. Clone the repository
```bash
git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git)
