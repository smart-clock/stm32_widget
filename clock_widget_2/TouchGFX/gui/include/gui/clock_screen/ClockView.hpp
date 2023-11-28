#ifndef CLOCKVIEW_HPP
#define CLOCKVIEW_HPP

#include <gui_generated/clock_screen/ClockViewBase.hpp>
#include <gui/clock_screen/ClockPresenter.hpp>
#include <iostream>
#include <string>
using namespace std;

class ClockView : public ClockViewBase
{
public:
    ClockView();
    virtual ~ClockView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    
    virtual void buttonPlayClicked();
    virtual void buttonStopClicked();
    virtual void buttonResetClicked();

    virtual void buttonTimerMaxClicked();
    virtual void bottonTimerMinClicked();

    virtual void toggleButtonOn();
    virtual void toggleButtonAm();

    // virtual void handleDragEvent(const DragEvent& Event);

    virtual void hourScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex);
    virtual void hourScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex);
    virtual void minuteScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex);
    virtual void minuteScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex);

    virtual void uart_Data(char *data);
protected:
    string esp2stmPacket;

    char wifiID[20];
    char ipAddress[20];
    int background;

    // HOME WIDGET
    bool isTimeUpdated = false;
    int homeTimeCounter;
    int monthHome;
    int dateHome;
    char dayHome[4];
    int hourHome;
    int minuteHome;
    int secondHome;

	// WEATHER WIDGET
    char weatherRegion[10];
    char weather[20];
    int weatherTemp;

    // STOPWATCH WIDGET
    int tickCounter;
    int stopWatchHours;
    int stopWatchMinutes;
    int stopWatchSeconds;
    bool isStopWatchPlay = false;
    
    // TIMER WIDGET
    int timerCounter;
    bool timerWidgetDrag; // Issue #18
    int8_t timerMinute; // display value
    int8_t timerSecond; // display value
    int timerOfCurAng; // current angle
    int timerOfPreAng; // previous angle
    bool timerMax; // max drag limit
    bool timerMin; // min drag limit
    bool timerStart; // timer start flag

    // ALARM WIDGET
    bool isAlarmOn;
    bool isAlarmAm;
    bool alarmActive; // true면 알람 울림
    bool alarmCleared; // 알림 클리어
    int alarmHour;
    int alarmMinute;

    char stockName[10];
    char stockValue[10];

    Callback<ClockView, const Gauge&, const ClickEvent&> gaugeClickCallback;
    void gaugeClickHandler(const Gauge& g, const ClickEvent& e);
};

#endif // CLOCKVIEW_HPP
