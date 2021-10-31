# time-offset-calculator
## Using C++
The program calculates the time-difference on NTP-server and local machine over a time period and using these differences calculates the offset.

## Using system tools
The script connects to NTP server using `ntpd` and outputs time difference 
between server and system (offset). To use this script you must run it with `sudo`.

## Prerequisites
You must install `ntpd`, `boost`, `cmake`.
