#ifndef PACKETVIEW_HPP
#define PACKETVIEW_HPP

#include <gui_generated/packet_screen/PacketViewBase.hpp>
#include <gui/packet_screen/PacketPresenter.hpp>

class PacketView : public PacketViewBase
{
public:
    PacketView();
    virtual ~PacketView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void uart_Data(char *data);
protected:
    int16_t hourCurrent;
    int16_t minuteCurrent;
};

#endif // PACKETVIEW_HPP
