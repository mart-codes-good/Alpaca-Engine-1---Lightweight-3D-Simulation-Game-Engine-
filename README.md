## Alpaca Engine 1 (A 3D Simulation Engine)

**Technology Stack:** C, Render

**Libraries Used:**
OpenGL (Rendering), OpenAL  (Audio), GLFW (Window/Input), GLEW (OpenGL extensions), GLUT(Text/UI)

## Description

Alpaca Engine 1 is a lightweight 3D simulation engine designed to run quickly while still supporting core game engine systems such as rendering, collision, and audio.

This project was created as a personal passion project and self-study to better understand how 3D engines operate at a low level. Instead of relying heavily on large prebuilt engines, I focused on building core systems from scratch using only essential libraries.

The engine includes:

* First-person camera system
* Axis-Aligned Bounding Box (AABB) collision detection
* Spatial audio using OpenAL
* Basic entity system and world simulation
* Hitscan shooting mechanics

It’s always best to avoid “reinventing the wheel”, but I wanted to custom build something for my amusement and experience.


https://github.com/user-attachments/assets/f1417ba5-fae6-4072-8c50-260febb318ec

## Implmented Libraries (Short notes) 
### Collision.c (AABB)
Collision is checked by testing whether two boxes overlap on all three axes. 
If the X, Y, and Z ranges all overlap, the collision is true.

Overlap test (per axis):
```
a.minX ≤ b.maxX && a.maxX ≥ b.minX
a.minY ≤ b.maxY && a.maxY ≥ b.minY
a.minZ ≤ b.maxZ && a.maxZ ≥ b.minZ
```
A collision occurs if all three are true.

### Hitscan.c (Ray Casting)

Using this equation, the engine checks whether a ray cast from the camera intersects a collision box. 
This is done by finding where the ray enters and exits the box across all three axes to determine whether the shot hits its target.

Ray equation:
```
P(t) = O + tD
```
Intersection condition:
```
t_exit ≥ t_enter && t_exit > 0
```
### Camera.c

The camera direction is calculated from the current yaw and pitch angles, which are updated from player input. 
These direction values are then used to determine where the camera is facing and to apply the view transformation.

Direction from angles:
```
forwardX = cos(pitch) * sin(yaw)
forwardY = sin(pitch)
forwardZ = -cos(pitch) * cos(yaw)
```
View transformation:
```
lookAt = position + forward
```
### Geometry / Maps
Maps are currently built using an array of boxes that store the bounds of solid world geometry, such as floors and walls. 
These boxes are used both for collision detection and for rendering simple map structures.


## What we are currently working on
These are the next few features we are building. Due to a busy schedule, it may take some time before the work is completed.

* Model Loading
* Scene management and improved maps library
* Proper default maps for demos
* Basic Textures
* Debug Audio Issues
* Complete items implementation

## Attributions 
* Martin (mart-codes-good)
* Cathy (zcxu-4444)
