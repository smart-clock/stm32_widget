#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

     virtual void uart_Data(char *data) {}; // {} 있어야 uart_Date define 됨
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
