#ifndef TRANSPORT_USB_HID_HPP__
#define TRANSPORT_USB_HID_HPP__

#include "cpp-lib/Transport/TransportBase.hpp"

class TransportUsbHid
    : public xiohw::TransportBase
{
public:
    TransportUsbHid();
    virtual ~TransportUsbHid();

protected:
    virtual bool doStart(const xiohw::DeviceDescriptor&) override;
    virtual void doStop() override;
    virtual bool doSendMessage(const xiohw_proto_Message&) override;
    virtual bool doReceiveMessage(xiohw_proto_Message&) override;
};

#endif // TRANSPORT_USB_HID_HPP__
