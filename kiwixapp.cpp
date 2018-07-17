#include "kiwixapp.h"
#include "zim/error.h"

KiwixApp::KiwixApp(int& argc, char *argv[])
    : QApplication(argc, argv)
{
    auto icon = QIcon();
    icon.addFile(":/icons/kiwix/app_icon.svg");
    setWindowIcon(icon);

    setApplicationDisplayName("Kiwix");
    setApplicationName("Kiwix");
    setDesktopFileName("kiwix.desktop");

    mainWindow = new MainWindow;
    mainWindow->show();
}

KiwixApp::~KiwixApp()
{
    delete mainWindow;
}


void KiwixApp::openZimFile(const QString &zimfile)
{
    const std::string zimfile_ = zimfile.toLocal8Bit().constData();
    std::cout << "Opening " << zimfile_ << std::endl;
    try {
        auto zimId = library.openBook(zimfile);
        mainWindow->displayReader(library.getReader(zimId));
    } catch (const std::exception& e) {
        std::cout << "oup" << e.what() << std::endl;
    }
}
