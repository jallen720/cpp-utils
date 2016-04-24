#pragma once


namespace JCore {


struct ITestEventListener {
    virtual ~ITestEventListener() {}
    virtual void onEvent(int) {};
};


} // namespace JCore
