#include <gui/clock_screen/ClockView.hpp>
#include <gui/clock_screen/ClockPresenter.hpp>

ClockPresenter::ClockPresenter(ClockView& v)
    : view(v)
{

}

void ClockPresenter::activate()
{

}

void ClockPresenter::deactivate()
{

}

void ClockPresenter::uart_Data(char *data)
{
	view.uart_Data (data);
}

void ClockPresenter::clockToggleBuzzer()
{
    model->hwToggleBuzzer();
}

void ClockPresenter::clockToggleBuzzerOff()
{
    model->hwToggleBuzzerOff();
}

void ClockPresenter::userButton()
{
	view.respondUserButton();
}
