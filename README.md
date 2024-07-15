# Ultrasonic Sensor Point Cloud | Arduino
 Scanning the environment with an ultrasonic sensor to gather points that form a cloud which can be visualized in 3D using Arduino.

https://gwenyth06.github.io/Ultrasonic-Sensor-Point-Cloud-Arduino/3d_plot.html

# Components
1x HC-SR04 Ultrasonic Sensor
2x 9g Servos
1x 3.3V / 5V Output Breadboard Power Module 
1x 9V / 1 Amp Adaptor
1x Big Breadboard

# Tools and Machines
Male/Female Jumper Wires
Craft Sticks (You can use any material to build it.)
Glue Gun (Or any sort of adhesive that won't damage the components.)

# IDEs
I used Arduino IDE and Visual Studio Code for this project. You can use anything as you please.

# Description
This project aims to visualize real-time data from an ultrasonic sensor mounted on servo motors using 3D point cloud visualization. The ultrasonic sensor scans its environment by rotating on two axes, capturing distance measurements at various angles. These measurements are then converted into Cartesian coordinates and visualized as a dynamic 3D point cloud, providing an intuitive representation of the surrounding objects' spatial distribution and distances.

# Circuit Diagram
2 Servos powered by breadboard power supply and 1 Ultrasonic sensor powered by Arduino UNO itself. Servos shouldn't be powered by Arduino for the reason of not enough Amps being supplied and there is a possiblity to burn the voltage regulator. 9g Servos draw 500 mA to 750 mA and operate at 4.8 to 6 Volts so it is a way safer approach to use an external power supply. HC-SR04 ultrasonic module consumes 15 mA and operates at 5V so I connected it directly to Arduino.  
![](diagram.png)

# Assembling the Components
In order to scan the environment in 3D, we need 2 servos: Servo 1 in the picture is going to move horizontally and Servo 2 is going to move vertically to scan between a defined range of angles. So inorder to accomplish this, we have to put one servo at the bottom to turn in a horizontal plane and the second servo on top to turn the sensor in a vertical plane.
![](picture_2.jpg)
After putting together these components, wiring the jumpers and connecting it to power is all is left. There is one important thing that shouldn't be overlooked: Do not forget to ground the servos! Otherwise they are all gonna go crazy.
![](picture_1.jpg)

# How It Works
I created a sketch in Arduino IDE and defined the functions of Servos and Sensor using specific libraries for each. Calculations and visualization is coded in python. The sketch has an open serial port which is sending the degrees and the distance values that come from the servos and the sensor at every single position a pulse is triggered to the "save_to_file.py".  
After powering every component, the sensor is going to start scanning but it won't save any points. To save the points you should run the "save_to_file.py" first and there is going to be a list of ports. Choose the port that is connected to Arduino inorder to open the serial communication. After you choose the port the servos are going to reset their position. The logic behind this file is to calculate the points and save them in "points.txt" file. You can see the coming data and the calculated points in the terminal. After the servos reset their position, stop the execution of "save_to_file.py" and run the "visualize.py" to view the 3D plot created in a point cloud format. 
