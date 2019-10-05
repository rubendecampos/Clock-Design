#ifndef ISM_H
#define ISM_H

class XFEvent;
class ISM
{
public:
    virtual bool processEvent(XFEvent* ev) = 0;
};


#endif // ISM_H
