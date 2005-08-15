#!/bin/bash

# sets up CP env var
. ./setupclasspath.sh

$JAVA_HOME/bin/java -cp $CP -Damqj.logging.level="INFO" org.openamq.requestreply1.ServiceRequestingClient localhost 7654 guest guest /test serviceQ "$@"