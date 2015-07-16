#include "systeminformation.h"
#include "ui_systeminformation.h"

#include "blinkytape.h"

#include <QSerialPortInfo>
#include <QSysInfo>
#include <QLibraryInfo>
#include <QtWidgetsDepends>

SystemInformation::SystemInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemInformation)
{
    ui->setupUi(this);
    QString report;

    QString osName;

    report.append("Pattern Paint ");
    report.append(QString("%1.%2.%3").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_BUILD));
    report.append("\r");
    report.append("  Build Date: ");
    report.append(__DATE__);
    report.append(" ");
    report.append(__TIME__);
    report.append("\r");

#if defined(Q_OS_WIN)
    switch(QSysInfo::windowsVersion()) {
    case QSysInfo::WV_2000:
        osName = "Windows 2000";
        break;
    case QSysInfo::WV_2003:
        osName = "Windows 2003";
        break;
    case QSysInfo::WV_VISTA:
        osName = "Windows Vista";
        break;
    case QSysInfo::WV_WINDOWS7:
        osName = "Windows 7";
        break;
    case QSysInfo::WV_WINDOWS8:
        osName = "Windows 8";
        break;
    case QSysInfo::WV_WINDOWS8_1:
        osName = "Windows 8.1";
        break;
//    case QSysInfo::WV_WINDOWS10:
//        osName = "Windows 10";
//        break;
    default:
        osName = "Windows (Unknown Version)";
        break;
    }
#elif defined(Q_OS_MAC)
    switch(QSysInfo::macVersion()) {
    case QSysInfo::MV_10_6:
        osName = "OS X 10.6 (Snow Leopard)";
        break;
    case QSysInfo::MV_10_7:
        osName = "OS X 10.7 (Lion)";
        break;
    case QSysInfo::MV_10_8:
        osName = "OS X 10.8 (Mountain Lion)";
        break;
    case QSysInfo::MV_10_9:
        osName = "OS X 10.9 (Mavericks)";
        break;
    case QSysInfo::MV_10_10:
        osName = "OS X 10.10 (Yosemite)";
        break;
//    case QSysInfo::MV_10_11:
//        osName = "OS X 10.11 (El Capitan)";
//        break;
    default:
        osName = "OS X (Unknown version)";
        break;
    }
#else
    osName = "Unknown";
#endif
    report.append("Operating system: " + osName + "\r");

    report.append("QT information:\r");
    report.append("  Build Date: " + QLibraryInfo::buildDate().toString() + "\r");
    report.append("  Path: " + QLibraryInfo::location(QLibraryInfo::LibrariesPath) + "\r");

    report.append("Detected devices: \r");
    foreach (const QSerialPortInfo &info, BlinkyTape::probe()) {
        report.append("  BlinkyTape:" + info.portName() + "\r");
    }
    foreach (const QSerialPortInfo &info, BlinkyTape::probeBootloaders()) {
        report.append("  BlinkyTape:" + info.portName() + " (bootloader)\r");
    }

    report.append("Detected Serial Ports: \r");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        report.append("  " + info.portName() + "\r");
        report.append("    Manufacturer: " + info.manufacturer() + "\r");
        report.append("    Description: " + info.description() + "\r");
        report.append("    VID: 0x" + QString::number(info.vendorIdentifier(),16) + "\r");
        report.append("    PID: 0x" + QString::number(info.productIdentifier(),16) + "\r");
    }

    ui->infoBrowser->setText(report);
}

SystemInformation::~SystemInformation()
{
    delete ui;
}

void SystemInformation::on_copyToClipboard_clicked()
{
    QClipboard *clip = QApplication::clipboard();
    QString input = ui->infoBrowser->toPlainText();
    clip->setText(input);
}

void SystemInformation::on_sendToSupport_clicked()
{
    QString body = "Thanks for helping make Pattern Paint a better program!\r"
                   "Please fill out this brief questionaire to help us better understand your issue.\r\r"
                   "1. Please describe the issue you are having:\r\r\r\r"
                   "2. How can we reproduce it? Be as detailed as possible. If there is a specific pattern that causes the problem, please attach it:\r\r\r\r"
                   "3. Has this worked for you before?\r\r\r\r"
                   "============ System Information generated by PatternPaint ============\r"
                   + ui->infoBrowser->toPlainText();

    QDesktopServices::openUrl(QUrl("mailto:support@blinkinlabs.com?subject=Pattern Paint issue&body=" + body,
                                   QUrl::TolerantMode));
}
