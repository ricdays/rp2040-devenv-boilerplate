#include "TransportUsbHid.hpp"

using namespace xiohw;

TransportUsbHid::TransportUsbHid()
{

}

TransportUsbHid::~TransportUsbHid()
{

}

bool TransportUsbHid::doStart(const DeviceDescriptor&)
{
    return true;
}

void TransportUsbHid::doStop()
{

}

bool TransportUsbHid::doSendMessage(const xiohw_proto_Message&)
{
    return false;
}

bool TransportUsbHid::doReceiveMessage(xiohw_proto_Message&)
{
    return false;
}