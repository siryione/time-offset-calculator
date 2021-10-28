#!/bin/bash
echo "first sync in progress..."
ntpd -g -d -n -q -G | grep "offset"
sleep $1
echo -e "\nsecond sync in progress..."
ntpd -g -d -n -q -G | grep "offset"