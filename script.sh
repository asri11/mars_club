#!/bin/bash

#1
mkdir rover_mission
cd rover_mission

#2
touch log1.txt log2.txt log3.txt

#3
mv log1.txt mission_log.txt

#4
find . -type f -name "*.log"

#5
cat mission_log.txt

#6
grep "ERROR" mission_log.txt

#7
wc -l mission_log.txt

#8
date

#9
top

#10
sudo shutdowm +10
