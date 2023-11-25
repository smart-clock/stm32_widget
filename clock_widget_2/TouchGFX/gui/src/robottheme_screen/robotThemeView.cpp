#include <gui/robottheme_screen/robotThemeView.hpp>

robotThemeView::robotThemeView() : 
    gaugeClickCallback(this, &robotThemeView::gaugeClickHandler)
{
    this->timerWidgetDrag = false;
    this->timerMinute = 0;
    this->timerOfCurAng = 0;
    this->timerOfPreAng = 0;
    this->timerMax = false;
    this->timerMin = false;
    this->timerStart = false;
    this->timerCounter = 0;

    this->alarmHour = 0;
    this->alarmMinute = 0;
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
        timerCounter++;
        if(timerCounter % 60 == 0)
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
            timerWidgetDrag = true;
        }
        else if(e.getType() == ClickEvent::RELEASED)
        {
            timerWidgetDrag = false;
            timerMax = false;
            timerMin = false;
            timerStart = true;
        }
    }
}

// handleDragEvent 오버라이딩 시에 Scroll Wheel 위젯 애니매이션 자연스럽지 않음 #20
// void robotThemeView::handleDragEvent(const DragEvent& Event)
// {

//     if(timerWidgetDrag)
//     {
//         int16_t timerDragX = Event.getNewX();
//         int16_t timerDragY = Event.getNewY();

//         timerOfCurAng = CWRUtil::angle<int>(timerDragX - 240, timerDragY - 124);

//         if(timerOfPreAng > 340 && timerOfCurAng < 20)
//         {
//             timerMax = true;
//         }
//         else if(timerOfPreAng < 20 && timerOfCurAng > 340)
//         {
//             timerMin = true;
//         }

//         if(timerMax)
//         {
//             gaugeTimer.setValue(360);
//             timerMinute = 60;
//         }
//         else if(timerMin)
//         {
//             gaugeTimer.setValue(0);
//             timerMinute = 0;
//         }
//         else
//         {
//             gaugeTimer.setValue(timerOfCurAng);
//             timerMinute = timerOfCurAng/6;
//         }

//         Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", timerMinute);
//         textTimer.invalidate();

//         timerSecond = 0;
//         Unicode::snprintf(textTimerBuffer2, TEXTTIMERBUFFER2_SIZE, "%02d", timerSecond);
//         textTimer.invalidate();

//         timerOfPreAng = timerOfCurAng;
//     }
// }

void robotThemeView::hourScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
    alarmHour = itemIndex - 1;

    // 상단 알람 표시 업데이트
    Unicode::snprintf(textAlarmBuffer1, TEXTALARMBUFFER1_SIZE, "%02d", alarmHour);
    textAlarm.invalidate();
}

void robotThemeView::hourScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
    alarmHour = itemIndex - 1;

    // 상단 알람 표시 업데이트
    Unicode::snprintf(textAlarmBuffer1, TEXTALARMBUFFER1_SIZE, "%02d", alarmHour);
    textAlarm.invalidate();
}

void robotThemeView::minuteScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
}

void robotThemeView::minuteScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
    alarmMinute = itemIndex;

    // 상단 알람 표시 업데이트
    Unicode::snprintf(textAlarmBuffer2, TEXTALARMBUFFER2_SIZE, "%02d", alarmMinute);
    textAlarm.invalidate();
}