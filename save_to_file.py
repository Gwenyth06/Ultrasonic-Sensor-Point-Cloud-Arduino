import serial
import serial.tools.list_ports
import time
import math
import os

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portList = []

for onePort in ports:
    portList.append(str(onePort))
    print(str(onePort))

val = input("select Port: COM")

for x in range(0,len(portList)):
    if portList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portList[x])
    else:
        print("COM" + str(val) + " is not listed in port list.")

serialInst.baudrate = 115200
serialInst.port = portVar
time.sleep(2)
serialInst.open()


def polar_to_cartesian(x_ang, y_ang, distance):
    x_ang_rad = math.radians(x_ang)
    y_ang_rad = math.radians(y_ang)

    z = distance * math.cos(y_ang_rad)
    x = distance * math.sin(y_ang_rad) * math.cos(x_ang_rad)
    y = distance * math.sin(y_ang_rad) * math.sin(x_ang_rad)
    
    return x, y, z

# def start_scanning():
#     serialInst.write(b'START\n')  # Send start command to Arduino

file_path = os.path.abspath("points.txt")

try:
    with open(file_path,"w") as file:
        while True:
            if serialInst.in_waiting:
                    packet = serialInst.readline().decode('utf8').rstrip()
                    print(f"Received: {packet}")
                    try:
                        x_ang,y_ang,distance = map(int, packet.split(","))

                        x,y,z = polar_to_cartesian(x_ang, y_ang, distance)
    
                        file.write(f"{x},{y},{z}\n")
                        file.flush()
                        print(f"Point: {x},{y},{z}")
                    except ValueError:
                        print(f"Invalid data:{packet}")
except IOError as e:
    print(e)
        
        
 