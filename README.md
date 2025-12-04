# Snake Game (Console Version)

A classic **Snake game** implemented in **C** for the Windows console.  
The player controls the snake using keyboard inputs, eats fruits to grow longer, and avoids collisions with walls and itself. Difficulty levels adjust the game speed, and you can restart without closing the program.

---

## 🎮 Gameplay
- Control the snake using **W/A/S/D** keys:
  - **W** → Up
  - **S** → Down
  - **A** → Left
  - **D** → Right
- Eat fruits (`F`) to increase your score and grow the snake’s tail.
- Avoid hitting the walls or your own tail.
- The game ends when a collision occurs.
- After **Game Over**, you can choose to **play again** without restarting the program.

---

## ✨ Features
- **Difficulty Selection**: Choose Easy, Medium, or Hard at the start.
- **Scoreboard**: Displays your current score during gameplay.
- **Pause/Resume**: Press `P` to pause and `R` to resume.
- **Restart Option**: Play multiple rounds without restarting the program.
- **Simple Console Graphics**: Borders, snake head (`O`), tail (`o`), and fruit (`F`).

---

## 🛠 Requirements
- Windows OS (uses `<conio.h>` and `<windows.h>`).
- A C compiler (e.g., GCC/MinGW, Turbo C, MSVC).
- Console/terminal to run the program.

---

## ▶️ How to Run
1. Save the code as `snake_game.c`.
2. Compile using:
   ```bash
   gcc snake_game.c -o snake_game
