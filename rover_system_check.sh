#!/bin/bash

# Generate a random battery percentage between 0 and 100
battery=$(( RANDOM % 101 ))
echo "Battery Level: $battery%"

# Check if battery is below 20%
if [ "$battery" -lt 20 ]; then
    echo "Battery low! Return to base!"
    exit 1
fi

# Check network connectivity by pinging google.com
ping -c 1 google.com > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Communication failure!"
    exit 1
fi

# If both checks pass
echo "All systems operational!"
