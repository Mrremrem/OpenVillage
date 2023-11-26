//
// Created by mrremrem on 12/19/22.
//

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

#ifndef OPENVILLAGE_EVENTMANAGER_H
#define OPENVILLAGE_EVENTMANAGER_H

/*
 * A Singleton, handles events
 */
class EventManager {
public:
    // Returns single EventManager instance
    static EventManager& getInstance() {
        static EventManager instance;

        return instance;
    }

    using EventCallback = std::function<void()>; // Event container

    void subscribe(const std::string& name, EventCallback event); // Stores event
    void publish(const std::string& name); // Calls event


private:
    EventManager() {} // No public default constructor

    // Disables both copy and assignment constructors
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete; 

    std::unordered_map<std::string, std::vector<EventCallback>> eventList;
};


#endif // OPENVILLAGE_EVENTMANAGER_H