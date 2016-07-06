#!/usr/bin/perl -w

# initial script was stolen from:
# http://www.windmeadow.com/node/38

use strict;
use Device::SerialPort;

# Set up the serial port
# 9600, 81N
my $port = Device::SerialPort->new("/dev/ttyACM0");
$port->databits(8);
$port->baudrate(9600);
$port->parity("none");
$port->stopbits(1);

sleep(2);

my $alarmState = 0;
my $dataVar = $port->write("$alarmState");
print "$dataVar"."\n";

#EOF
