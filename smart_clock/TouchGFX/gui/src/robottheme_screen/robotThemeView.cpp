#include <gui/robottheme_screen/robotThemeView.hpp>

robotThemeView::robotThemeView() : hour(0), minute(0)
{

}

void robotThemeView::setupScreen()
{
    robotThemeViewBase::setupScreen();
}

void robotThemeView::tearDownScreen()
{
    robotThemeViewBase::tearDownScreen();
}

void robotThemeView::handleTickEvent()
{
    if (tickCount == 10)
    {
        minute++;
        hour = (hour + (minute / 10)) % 24;
        minute %= 10;

        Unicode::snprintf(textClockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", hour);
        Unicode::snprintf(textClockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", minute);

        textClock.invalidate();

        tickCount = 0;
    }
}