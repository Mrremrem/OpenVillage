#include "EventManager.h"

void EventManager::subscribe(const std::string& name, EventCallback event) {
    eventList[name].push_back(event);
}

void EventManager::publish(const std::string& name) {
    for (const auto& callbackIndex : eventList[name]) {
        callbackIndex();
    }
}