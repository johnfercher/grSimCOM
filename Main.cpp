#include "iostream"
#include <google/protobuf/text_format.h>
#include "grSim_Packet.pb.h"
#include "grSim_Commands.pb.h"
#include "grSim_Replacement.pb.h"

#include "Qts/Qts.h"

using namespace std;

int main(int argc, char** argv){
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    QUdpSocket udpsocket;
    quint16 _port = 20011;
    QHostAddress _addr("127.0.0.1");

	grSim_Packet packet;
    bool yellow = false;

    packet.mutable_commands()->set_isteamyellow(yellow);
    packet.mutable_commands()->set_timestamp(0.0);

    grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
    command->set_id(0);

    command->set_wheelsspeed(0);
    command->set_wheel1(0);
    command->set_wheel2(0);
    command->set_wheel3(0);
    command->set_wheel4(0);
    command->set_veltangent(0);
    command->set_velnormal(0);
    command->set_velangular(1);

    command->set_kickspeedx(0);
    command->set_kickspeedz(0);
    command->set_spinner(false);

    QByteArray dgram;
    dgram.resize(packet.ByteSize());
    packet.SerializeToArray(dgram.data(), dgram.size());
    udpsocket.writeDatagram(dgram, _addr, _port);
	
	return 0;
}