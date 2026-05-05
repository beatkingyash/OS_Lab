#!/bin/bash

THRESHOLD=1 # Alert threshold in %
PARTITION="/home" # Disk partition to monitor
HOSTNAME=$(hostname)
DATE=$(date)

USAGE=$(df -h "$PARTITION" | awk 'NR==2 {gsub("%",""); print $5}')

if [ "$USAGE" -ge "$THRESHOLD" ]; then
MESSAGE="WARNING: Disk usage on $HOSTNAME ($PARTITION) is at ${USAGE}% as
of $DATE"
# Send email alert
echo "$MESSAGE"
# Optional: log locally
echo "$DATE - $MESSAGE" >> "$HOME/disk_monitor.log"
fi