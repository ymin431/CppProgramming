#include "Notification.h"

std::ostream& operator << (std::ostream& os, const Notification& n){
    os << n.icon << " " << n.appName << " " ;
    int diff = (int)std::difftime(std::time(nullptr), n.timestamp) / (60 * 60 * 24);
    os <<  ((diff==0) ? "now" : std::to_string(diff) );
    os << ((diff==0) ? "" : " days" ) << std::endl;
    os << n.title << std::endl;
    os << n.text << std::endl;
    return os;
}
NotificationBuilder Notification::create() {
    Notification ;
}

NotificationBuilder& NotificationBuilder::setSmallIcon(int icon) {
//    return notification.icon = icon ;
//    notification.icon = icon ;
}

NotificationBuilder& NotificationBuilder::setContentTitle(std::string title) {
//    notification.title = title ;
}


NotificationBuilder& NotificationBuilder::setContentText(std::string text) {
//    notification.text = text ;
}


NotificationBuilder& NotificationBuilder::setPriority(int priority) {
    notification.priority = priority ;
    return  ;
}