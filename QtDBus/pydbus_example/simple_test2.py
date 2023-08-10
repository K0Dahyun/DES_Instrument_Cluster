from pydbus import SessionBus

bus = SessionBus()
notifications = bus.get('.Notifications')

help(notifications)