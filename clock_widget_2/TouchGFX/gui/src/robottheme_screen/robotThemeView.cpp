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

    this->timerStart = false;
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

    if(timerStart)
    {
        tickCounter++;
        if(tickCounter % 60 == 0)
        {
            if(timerMinute > 0 && timerSecond == 0)
            {
                timerMinute--;
                timerSecond = 59;
            }
            else if(timerMinute == 0)
            {
                timerStart = false;
            }
            else
            {
                timerSecond--;
            }
        }
    }

    // Update the clock
    digitalClock.setTime24Hour(stopWatchHours, stopWatchMinutes, stopWatchSeconds);

    // Update timer
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", timerMinute);
    textTimer.invalidate();
    Unicode::snprintf(textTimerBuffer2, TEXTTIMERBUFFER2_SIZE, "%02d", timerSecond);
    textTimer.invalidate();
    gaugeTimer.setValue(timerMinute*6);
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
    gaugeTimer.setValue(360);
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 60);
    textTimer.invalidate();
    timerMinute = 60;
    timerSecond = 0;
}

void robotThemeView::bottonTimerMinClicked()
{
    gaugeTimer.setValue(0);
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 0);
    textTimer.invalidate();
    timerMinute = 0;
    timerSecond = 0;
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
            timerStart = true;
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
            gaugeTimer.setValue(360);
            timerMinute = 60;
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

        Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", timerMinute);
        textTimer.invalidate();

        timerSecond = 0;
        Unicode::snprintf(textTimerBuffer2, TEXTTIMERBUFFER2_SIZE, "%02d", timerSecond);
        textTimer.invalidate();

        prevAngleOfTimer = curAngleOfTimer;
    }
}