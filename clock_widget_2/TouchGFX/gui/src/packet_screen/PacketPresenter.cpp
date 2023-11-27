#include <gui/packet_screen/PacketView.hpp>
#include <gui/packet_screen/PacketPresenter.hpp>

PacketPresenter::PacketPresenter(PacketView& v)
    : view(v)
{

}

void PacketPresenter::activate()
{

}

void PacketPresenter::deactivate()
{

}

void PacketPresenter::uart_Data(char *data)
{
	view.uart_Data (data);
}
