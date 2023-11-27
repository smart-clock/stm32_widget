/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ROBOTTHEMEVIEWBASE_HPP
#define ROBOTTHEMEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/robottheme_screen/robotThemePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/Gauge.hpp>
#include <touchgfx/mixins/ClickListener.hpp>
#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>
#include <gui/containers/alarmContainer.hpp>
#include <gui/containers/alarmCenterContainer.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>

class robotThemeViewBase : public touchgfx::View<robotThemePresenter>
{
public:
    robotThemeViewBase();
    virtual ~robotThemeViewBase();
    virtual void setupScreen();

    virtual void hourScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in robotTheme
    }

    virtual void hourScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in robotTheme
    }

    virtual void minuteScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in robotTheme
    }

    virtual void minuteScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
    {
        // Override and implement this function in robotTheme
    }

    /*
     * Virtual Action Handlers
     */
    virtual void buttonPlayClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void buttonStopClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void buttonResetClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void buttonTimerMaxClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void bottonTimerMinClicked()
    {
        // Override and implement this function in robotTheme
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image background;
    touchgfx::SwipeContainer swipeContainerWidget;
    touchgfx::Container home;
    touchgfx::TextAreaWithTwoWildcards textHomeClock;
    touchgfx::TextArea textDate_1;
    touchgfx::Container whether;
    touchgfx::Box boxBlurWhether;
    touchgfx::Image imageRaining;
    touchgfx::Box box1;
    touchgfx::TextArea textDegree;
    touchgfx::TextArea textWhether;
    touchgfx::Container StopWatch;
    touchgfx::Box boxBlurStop;
    touchgfx::DigitalClock digitalClock;
    touchgfx::Button buttonReset;
    touchgfx::Button buttonStop;
    touchgfx::Button buttonPlay;
    touchgfx::Container Timer;
    touchgfx::Box boxBlurTimer;
    touchgfx::Button buttonTimerMax;
    touchgfx::Button buttonTimerMin;
    touchgfx::Circle circleGaugeBackground;
    touchgfx::PainterRGB565 circleGaugeBackgroundPainter;
    touchgfx::ClickListener< touchgfx::Gauge > gaugeTimer;
    touchgfx::PainterRGB565 gaugeTimerPainter;
    touchgfx::TextAreaWithTwoWildcards textTimer;
    touchgfx::Container Alarm;
    touchgfx::Box boxBlurAlarm;
    touchgfx::ScrollWheelWithSelectionStyle hourScrollWheel;
    touchgfx::DrawableListItems<alarmContainer, 4> hourScrollWheelListItems;
    touchgfx::DrawableListItems<alarmCenterContainer, 2> hourScrollWheelSelectedListItems;
    touchgfx::ScrollWheelWithSelectionStyle minuteScrollWheel;
    touchgfx::DrawableListItems<alarmContainer, 4> minuteScrollWheelListItems;
    touchgfx::DrawableListItems<alarmCenterContainer, 2> minuteScrollWheelSelectedListItems;
    touchgfx::ToggleButton toggleButtonON;
    touchgfx::ToggleButton toggleButtonAM;
    touchgfx::TextArea textAreaON;
    touchgfx::TextArea textAreaAM;
    touchgfx::TextArea textAreaColon;
    touchgfx::Container calendar;
    touchgfx::Box boxBlurCal;
    touchgfx::ScrollList scrollList1;
    touchgfx::Box boxScheduleBack;
    touchgfx::TextArea textScheduleTime;
    touchgfx::TextArea textSchedule;
    touchgfx::Container Bus;
    touchgfx::Box boxBlurBus;
    touchgfx::TextArea busRoute;
    touchgfx::TextArea busStation;
    touchgfx::TextAreaWithTwoWildcards busTime1;
    touchgfx::TextAreaWithTwoWildcards busTime2;
    touchgfx::Image imageBus1;
    touchgfx::Image imageBus2;
    touchgfx::Container stock;
    touchgfx::Box boxBlurStock;
    touchgfx::GraphWrapAndClear<100> dynamicGraph1;
    touchgfx::GraphElementLine dynamicGraph1Line1;
    touchgfx::PainterRGB565 dynamicGraph1Line1Painter;
    touchgfx::GraphElementArea dynamicGraph1Area1;
    touchgfx::PainterRGB565 dynamicGraph1Area1Painter;
    touchgfx::TextArea textStock;
    touchgfx::TextArea textStockValue;
    touchgfx::Box boxInfoBG;
    touchgfx::TextAreaWithOneWildcard textBattery;
    touchgfx::TextAreaWithTwoWildcards textClock;
    touchgfx::TextAreaWithOneWildcard textDate;
    touchgfx::TextAreaWithTwoWildcards textAlarm;
    touchgfx::Image imageAlarm;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTHOMECLOCKBUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textHomeClockBuffer1[TEXTHOMECLOCKBUFFER1_SIZE];
    static const uint16_t TEXTHOMECLOCKBUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textHomeClockBuffer2[TEXTHOMECLOCKBUFFER2_SIZE];
    static const uint16_t TEXTTIMERBUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTimerBuffer1[TEXTTIMERBUFFER1_SIZE];
    static const uint16_t TEXTTIMERBUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTimerBuffer2[TEXTTIMERBUFFER2_SIZE];
    static const uint16_t BUSTIME1BUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar busTime1Buffer1[BUSTIME1BUFFER1_SIZE];
    static const uint16_t BUSTIME2BUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar busTime2Buffer1[BUSTIME2BUFFER1_SIZE];
    static const uint16_t TEXTCLOCKBUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textClockBuffer1[TEXTCLOCKBUFFER1_SIZE];
    static const uint16_t TEXTCLOCKBUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textClockBuffer2[TEXTCLOCKBUFFER2_SIZE];
    static const uint16_t TEXTDATE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textDateBuffer[TEXTDATE_SIZE];
    static const uint16_t TEXTALARMBUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAlarmBuffer1[TEXTALARMBUFFER1_SIZE];
    static const uint16_t TEXTALARMBUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAlarmBuffer2[TEXTALARMBUFFER2_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

    /*
     * Callback Declarations
     */
    touchgfx::Callback<robotThemeViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;
    touchgfx::Callback<robotThemeViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // ROBOTTHEMEVIEWBASE_HPP
