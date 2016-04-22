#include "Sender.h"

Sender::Sender(string ip, int port){
	_addr = new QHostAddress(QString::fromStdString(ip));
	_port = port;
}

void Sender::send2grSim(){
    dgram.resize(packet.ByteSize());
    packet.SerializeToArray(dgram.data(), dgram.size());
    udpsocket.writeDatagram(dgram, *_addr, _port);
}

void Sender::setPacket(grSim_Packet packet){
	this->packet = packet;
}