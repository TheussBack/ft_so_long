# So Long

So Long is a simple 2D game where the player controls a character (such as a dolphin) attempting to collect items on a map and escape through a specific exit. The game is developed in C using the MiniLibX library and follows basic gameplay mechanics such as movement, collecting items, and navigating a map.

---

## Features

- **2D Gameplay**: The player moves through a grid-based map collecting items and finding the exit.
- **Basic Movement**: Uses W, A, S, D keys to move the character up, down, left, and right.
- **Interactive Map**: A map is provided in the `.ber` format, consisting of walls, collectibles, exit, and the player’s start position.
- **Graphics Management**: The game window is managed smoothly, and user interactions (like ESC key and window close) are handled correctly.
- **Items & Exit**: The player must collect all items (denoted by "C") and reach the exit ("E").
- **Error Handling**: Proper error messages are displayed for invalid maps, duplicate items, or missing elements.

---

## Requirements

- **Language**: C
- **Library**: MiniLibX (provided in the project)
- **Makefile**: The project includes a Makefile to compile the program.
- **External Functions**: `open`, `close`, `read`, `write`, `malloc`, `free`, etc.
- **Map Format**: The game takes a `.ber` file containing the map.

---

## Gameplay

- **Objective**: Collect all items and escape using the shortest path possible.
- **Movement**: Use `W`, `A`, `S`, `D` to move the character. You can’t move through walls.
- **Exit**: Reach the exit after collecting all items.
- **Map Layout**: The map is defined with these characters:
  - `0` - Empty space
  - `1` - Wall
  - `C` - Collectible item
  - `E` - Exit
  - `P` - Player’s starting position

Example of a map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

## Installation

1. Clone this repository:
    ```bash
    git clone <repository_url>
    ```

2. Navigate into the project directory:
    ```bash
    cd so_long
    ```

3. Compile the program using the Makefile:
    ```bash
    make
    ```

4. Run the game:
    ```bash
    ./so_long <map_file.ber>
    ```

---

## Bonus Features (Optional)

While not required, there are additional features that can be added for extra points:

- Enemy patrols that the player must avoid to not lose.
- Sprite animations for the character or environment.
- Displaying the total movement count on-screen (instead of in the shell).

---

![Game Screenshot](screenshots/BushesSoLong.jpg)
![Game Screenshot](screenshots/ChampisSoLong.jpg)
![Game Screenshot](screenshots/ChatSoLong.jpg)
![Game Screenshot](screenshots/GrenouilleSoLOng.jpg)
![Game Screenshot](screenshots/SolSoLong.jpg)

