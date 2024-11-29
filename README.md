#Cub3D: Creating a Retro FPS

Introduction I had the opportunity to work on a really exciting project called Cub3D. It's about creating a retro first-person shooter (FPS) game, inspired by classics like Wolfenstein 3D. Working in a duo, we used raycasting to simulate a 3D view, while utilizing a very minimalistic graphics library, MinilibX, which only allows pixel display.

The Fundamentals Cub3D shares several core features with another project called "so_long", such as map flood filling, handling key press events, and rendering images on the screen. However, Cub3D introduces more advanced functionalities and different methods to accomplish these tasks.

Raycasting One of the most crucial aspects of this project is raycasting. This technique is used to determine which walls of our map are visible from the player's position and at what distance. Here's how we proceeded:

    Ray Emission: From the player's position, rays are projected in various directions.

    Wall Intersection: Each ray continues until it encounters a wall. We calculate the intersection point.

    Distance Calculation: The distance between the player and the intersection point is measured.

    Screen Projection: Based on the distance, the height of the walls is projected on the screen to create the illusion of depth.

Challenges and Solutions One of the main challenges was optimizing the code to ensure the game runs smoothly with MinilibX's limitations. We also worked hard to ensure accurate calculations for the raycasting so that walls are correctly displayed, and to handle player commands efficiently.

Useful Resources We found Lode Vandevenne's tutorial on raycasting extremely useful for this project. 
You can check it out 

https://lodev.org/cgtutor/raycasting.html

SCREEN SHOTS

![cub3](https://github.com/user-attachments/assets/cbe0e3a8-d6bc-4c9f-8f0a-49f644f1206f)
![FOREST](https://github.com/user-attachments/assets/3bad853a-47a1-4c51-99b0-6dae17dff0f6)
![JAIL](https://github.com/user-attachments/assets/d340195e-be17-4946-8526-fb7ebed54a27)
![MAIF](https://github.com/user-attachments/assets/4266a2d6-9e31-4f4b-b2a4-fd90f085de4f)
