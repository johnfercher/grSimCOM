#include "Receiver.h"

Receiver::Receiver(string ip, int port){
	cout << ip << ":" << port << endl;
	_addr = new QHostAddress(QString::fromStdString(ip));
	_port = port;
}

void Receiver::receiveFromgrSim(){
	udpsocket.bind(QHostAddress("0.0.0.0"), _port, QUdpSocket::ShareAddress);
    udpsocket.joinMulticastGroup(*_addr);

    usleep(1000000);

    while (udpsocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpsocket.pendingDatagramSize());
        udpsocket.readDatagram(datagram.data(), datagram.size());
        packet.ParseFromArray(datagram.data(), datagram.size());

        string text_str;
		google::protobuf::TextFormat::PrintToString(packet, &text_str);
		cout << text_str << endl;
    }
}

SSL_WrapperPacket Receiver::getFrame(){
	return packet;
}
