#Automatically generated in Qt creator (right click on project and choose 'add library'
#Then modified to fit in a .pri file.

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libblinky/release/ -llibblinky
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libblinky/debug/ -llibblinky
else:unix: LIBS += -L$$OUT_PWD/../libblinky/ -llibblinky

# For some reason, building externally puts the lib in bin/ instead of debug/ or release/
# So just add that to the path.s
win32: LIBS += -L$$OUT_PWD/../libblinky/bin/

INCLUDEPATH += $$PWD/libblinky
DEPENDPATH += $$PWD/libblinky