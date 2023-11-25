#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::hourScrollWheel_1UpdateItem(alarmContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
}

void Screen1View::hourScrollWheel_1UpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
}