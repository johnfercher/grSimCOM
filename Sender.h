#ifndef _SENDER_H_
#define _SENDER_H_

#include "iostream"
#include "grSim_Packet.pb.h"
#include "grSim_Commands.pb.h"
#include "grSim_Replacement.pb.h"
#include "Qts/Qts.h"

using namespace std;
 
class Sender{
private:
	// Socket info
	QUdpSocket udpsocket;
    quint16 _port;
    QHostAddress *_addr;
    QByteArray dgram;
    
    // Proto info
    grSim_Packet packet;

public:
	Sender(string ip = "127.0.0.1", int port = 20011);

	void send2grSim();
	void setPacket(grSim_Packet);
};

#endif