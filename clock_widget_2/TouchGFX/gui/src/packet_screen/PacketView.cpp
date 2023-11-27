#include <gui/packet_screen/PacketView.hpp>

PacketView::PacketView()
{

}

void PacketView::setupScreen()
{
    PacketViewBase::setupScreen();
}

void PacketView::tearDownScreen()
{
    PacketViewBase::tearDownScreen();
}

void PacketView::uart_Data(char *data)
{
	textArea1.setWideTextAction(touchgfx::WIDE_TEXT_WORDWRAP);
	Unicode::strncpy(textArea1Buffer, data, TEXTAREA1_SIZE);
	textArea1.invalidate();

	hourCurrent = 5;
	minuteCurrent = 4;

	presenter->saveHour(hourCurrent);
	presenter->saveMinute(minuteCurrent);
}
