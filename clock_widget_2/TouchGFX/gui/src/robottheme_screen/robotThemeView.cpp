#include <gui/robottheme_screen/robotThemeView.hpp>

robotThemeView::robotThemeView() : 
    gaugeClickCallback(this, &robotThemeView::gaugeClickHandler)
{
    this->timerMinuteDrag = false;
    this->timerMinute = 0;

    this->curAngleOfTimer = 0;
    this->prevAngleOfTimer = 0;

    this->timerMax = false;
    this->timerMin = false;
}

void robotThemeView::setupScreen()
{
    robotThemeViewBase::setupScreen();

    stopWatchHours = digitalClock.getCurrentHour();
    stopWatchMinutes = digitalClock.getCurrentMinute();
    stopWatchSeconds = digitalClock.getCurrentSecond();

    gaugeTimer.setClickAction(gaugeClickCallback);
}

void robotThemeView::tearDownScreen()
{
    robotThemeViewBase::tearDownScreen();
}

void robotThemeView::handleTickEvent()
{
    frameCountBlinkInterval++;
    if(frameCountBlinkInterval == TICK_BLINK_INTERVAL)
    {
        //blink
        //When every N tick play video videoBlink
        //Play video on videoBlink
        videoBlink.play();
        frameCountBlinkInterval = 0;
    }

    if(isStopWatchPlay)
    {
        tickCounter++;

        if(tickCounter % 60 == 0)
        {
            if(++stopWatchSeconds >= 60)
            {
                stopWatchSeconds = 0;
                if(++stopWatchMinutes >= 60)
                {
                    stopWatchMinutes = 0;
                    if(++stopWatchHours >= 24)
                    {
                        stopWatchHours = 0;
                    }
                }
            }
        }
    }
    else
    {

    }

    // Update the clock
    digitalClock.setTime24Hour(stopWatchHours, stopWatchMinutes, stopWatchSeconds);
}

void robotThemeView::buttonPlayClicked()
{
    isStopWatchPlay = true;
}

void robotThemeView::buttonStopClicked()
{
    isStopWatchPlay = false;
}

void robotThemeView::buttonResetClicked()
{
    isStopWatchPlay = false;
    stopWatchHours = 0;
    stopWatchMinutes = 0;
    stopWatchSeconds = 0;
}

void robotThemeView::buttonTimerMaxClicked()
{
    if(timerMinute != 60)
    {
        gaugeTimer.setValue(360);
        Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 60);
        textTimer.invalidate();
        timerMinute = 60;
    }
}

void robotThemeView::bottonTimerMinClicked()
{
    gaugeTimer.setValue(0);
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 0);
    textTimer.invalidate();
}

void robotThemeView::gaugeClickHandler(const Gauge& g, const ClickEvent& e)
{
    if(&g == &gaugeTimer)
    {
        if(e.getType() == ClickEvent::PRESSED)
        {
            timerMinuteDrag = true;
        }
        else if(e.getType() == ClickEvent::RELEASED)
        {
            timerMinuteDrag = false;
            timerMax = false;
            timerMin = false;
        }
    }
}

void robotThemeView::handleDragEvent(const DragEvent& Event)
{
    int16_t timerDragX = Event.getNewX();
    int16_t timerDragY = Event.getNewY();

    if(timerMinuteDrag)
    {
        curAngleOfTimer = CWRUtil::angle<int>(timerDragX - 240, timerDragY - 124);

        if(prevAngleOfTimer > 340 && curAngleOfTimer < 20)
        {
            timerMax = true;
        }
        else if(prevAngleOfTimer < 20 && curAngleOfTimer > 340)
        {
            timerMin = true;
        }

        if(timerMax)
        {
            if(timerMinute != 60)
            {
                Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 60);
                textTimer.invalidate();
                gaugeTimer.setValue(360);
                timerMinute = 60;
            }
        }
        else if(timerMin)
        {
            gaugeTimer.setValue(0);
            timerMinute = 0;
        }
        else
        {
            gaugeTimer.setValue(curAngleOfTimer);
            timerMinute = curAngleOfTimer/6;
        }

        if(timerMinute != 60)
        {
            Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", timerMinute);
            textTimer.invalidate();
        }

        prevAngleOfTimer = curAngleOfTimer;
    }
}