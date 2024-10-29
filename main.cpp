#include <QDir>
#include <QFile>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>

#include "stringids.h"

void listRecursively(const QString &srcDirPath)
{
    qInfo().noquote() << QString("listRecursively: %1").arg(srcDirPath);

    if (!QDir(srcDirPath).exists()) {
        return;
    }

    QStringList files = QDir(srcDirPath).entryList(QDir::Files | QDir::NoDotAndDotDot);

    foreach (QString file, files) {
        qInfo().noquote() << QString("listRecursively, file: %1").arg(srcDirPath + "/" + file);
    }

    QStringList dirs = QDir(srcDirPath).entryList(QDir::AllDirs | QDir::NoDotAndDotDot);

    foreach (QString dir, dirs) {
        listRecursively(srcDirPath + "/" + dir);
    }

    qInfo().noquote() << QString("listRecursively, dir: %1").arg(srcDirPath);
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    listRecursively(":/");

    // Load translations for the current locale
    auto m_translator = QTranslator();
    auto m_currentLocale = QLocale();
    if (m_translator.load(m_currentLocale, "app", "_", ":/i18n")) {
        qDebug() << m_translator.filePath();
        QCoreApplication::installTranslator(&m_translator);
    } else {
        qWarning() << "Could not load translation for" << m_currentLocale.name();
    }

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("DemoInternationalization", "Main");

    return app.exec();
}
