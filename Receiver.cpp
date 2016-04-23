#include "Receiver.h"

Receiver::Receiver(string ip, int port){
	_addr = new QHostAddress(QString::fromStdString(ip));
	_port = port;
}

void Receiver::receiveFromgrSim(){
    dgram.resize(packet.ByteSize());
    //packet.SerializeToArray(dgram.data(), dgram.size());
    //udpsocket.writeDatagram(dgram, *_addr, _port);
}

void Receiver::getPacket(){
}