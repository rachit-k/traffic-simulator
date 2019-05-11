# ROAD TRAFFIC SIMULATOR:

- In this assignment we build a simple traffic simulator for one way and four different type vechiles having different sizes. Every vechile has it’s specific speed and acceleration. If a vechile is not able to move in front because of some restriction and if it has space in right then it will overtake from right. If signal is red then vechile will stop at signal and if it has more sped then stoppable speed then it will break signal. I have assumed a minimum separation for every type of vechile that they will try to maintain from vechile in front of it. From this purpose we enter vechiles according to instruction given in configuration file and if there is no space for vechile to enter then we avoid it. If there is a vechile which is about to hit vechile in front of it then to will suddenly stop.
- We have assumed magnitude accleration and retardation same except sudden stop. We have entered full vechile suddenly and removed it according to it’s speed ad space in front of it vechile will change it’s speed except drastic conditions.
- We have done overtaking if there is no space in front of it and has space in right of it and assuming only *right overtake*.
- There are two config files in the folder with their respective simulations.
- We have included a randomised traffic simulator code additionally with the main code.
- In opengl, signal is indicated by the red line on the road.
