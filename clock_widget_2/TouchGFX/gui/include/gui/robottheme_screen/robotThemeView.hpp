#ifndef ROBOTTHEMEVIEW_HPP
#define ROBOTTHEMEVIEW_HPP

#include <gui_generated/robottheme_screen/robotThemeViewBase.hpp>
#include <gui/robottheme_screen/robotThemePresenter.hpp>

class robotThemeView : public robotThemeViewBase
{
public:
    robotThemeView();
    virtual ~robotThemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    
    virtual void buttonPlayClicked();
    virtual void buttonStopClicked();
    virtual void buttonResetClicked();

    virtual void buttonTimerMaxClicked();
    virtual void bottonTimerMinClicked();

    virtual void handleDragEvent(const DragEvent& Event);
protected:
    int tickCounter;
    int stopWatchHours;
    int stopWatchMinutes;
    int stopWatchSeconds;

    bool isStopWatchPlay = false;
    
    static const uint32_t TICK_BLINK_INTERVAL = 180;
    uint32_t frameCountBlinkInterval;

    bool timerMinuteDrag;
    int8_t timerMinute;
    int8_t timerSecond;
    int curAngleOfTimer;
    int prevAngleOfTimer;
    bool timerMax;
    bool timerMin;
    bool timerStart;
    int timerCounter;

    Callback<robotThemeView, const Gauge&, const ClickEvent&> gaugeClickCallback;
    void gaugeClickHandler(const Gauge& g, const ClickEvent& e);
};

#endif // ROBOTTHEMEVIEW_HPP
