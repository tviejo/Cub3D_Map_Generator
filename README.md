#Map Generator for Cub3D

This project is a Map Generator for Cub3D, part of the curriculum at School 42. The tool automatically generates maps based on the parameters you provide, allowing you to create different styles of maps like rooms or mazes with custom configurations for width, height, density, monsters, and doors.
Features

    Two map generation modes:
        Room (mode: 0)
        Maze (mode: 1)
    Customizable map dimensions: Define the width and height of the generated map.
    Adjustable map density: Control the amount of walls or obstacles generated.
    Configurable monsters and doors: Set the number of monsters and doors in the map.

Usage

bash

./map_generator [mode] [width] [height] [density] [nb_monster] [nb_door]

Parameters

    mode:
        0 for room generation
        1 for maze generation
    width: The width of the map.
    height: The height of the map.
    density: Density of the obstacles in the map (e.g., walls).
    nb_monster: The number of monsters to place on the map.
    nb_door: The number of doors to place on the map.

Example

bash

./map_generator 0 50 50 40 5 5

This command will generate a room (mode 0) with the following parameters:

    Map size: 50x50
    40% density of walls/obstacles
    5 monsters
    5 doors

Defaults

If a parameter is not provided, the program will use its default value:

    Mode: 0 (Room)
    Width: 10
    Height: 10
    Density: 30 (30%)
    Number of Monsters: 0
    Number of Doors: 0

Compilation and Setup

    Clone the repository:

bash

git clone git@github.com:tviejo/Cub3D_Map_Generator.git

    Navigate to the project directory and compile the code:

bash

cd cub3d-map-generator
make

    Run the executable with the desired parameters:

bash

./map_generator [mode] [width] [height] [density] [nb_monster] [nb_door]

License

This project is licensed under the MIT License. Feel free to use and modify it.
Contributing

Feel free to open issues or submit pull requests to improve the project or add new features!