#!/usr/bin/python
from scapy.all import *

ip=IP(src="192.168.8.104", dst="192.168.8.104")
SYN=TCP(sport=4000, dport=1050, flags="S", seq=100)
SYNACK=sr1(ip/SYN)

my_ack = SYNACK.seq + 1
ACK=TCP(sport=4000, dport=1050, flags="A", seq=101, ack=my+ack)
send(ip/ACK)

payload="stuff"
PUSH=TCP(sport=4000, dport=1050, flags="PA", seq=11, ack=my_ack)
send(ip/PUSH/payload)
