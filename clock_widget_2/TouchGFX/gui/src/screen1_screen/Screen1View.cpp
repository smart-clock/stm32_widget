#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View() :
    boxClickedCallback(this, &Screen1View::boxClickHandler)
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    box.setClickAction(boxClickedCallback);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::boxClickHandler(const Box& b, const ClickEvent& e)
{
    if (&b == &box)
    {
        //Implement what should happen when 'box' is touched/clicked here.
        Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%03d", e.getX());
        textArea1.invalidate();
    }
}