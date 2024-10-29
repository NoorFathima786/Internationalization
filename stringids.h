#ifndef STRINGIDS_H
#define STRINGIDS_H

#include <QObject>
#include <QQmlEngine>

class StringIDs : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QString string_id_address READ string_id_address NOTIFY localeChanged)
    Q_PROPERTY(QString string_id_date_of_birth READ string_id_date_of_birth NOTIFY localeChanged)
    Q_PROPERTY(QString string_id_demo_title READ string_id_demo_title NOTIFY localeChanged)
    Q_PROPERTY(QString string_id_dialog_text_enrollment_form READ string_id_dialog_text_enrollment_form NOTIFY localeChanged)
    Q_PROPERTY(QString string_id_mobileno READ string_id_mobileno NOTIFY localeChanged)
    Q_PROPERTY(QString string_id_name READ string_id_name NOTIFY localeChanged)
    Q_PROPERTY(QString string_id_pincode READ string_id_pincode NOTIFY localeChanged)

    Q_DISABLE_COPY(StringIDs)
    explicit StringIDs(QObject *parent = nullptr)
        : QObject(parent)
    {}

public:
    static StringIDs &instance()
    {
        static StringIDs staticInstance;
        return staticInstance;
    }

    static StringIDs *create(QQmlEngine *, QJSEngine *)
    {
        StringIDs *instance = &(StringIDs::instance());
        QJSEngine::setObjectOwnership(instance, QJSEngine::CppOwnership);
        return instance;
    }

    QString string_id_address() const
    {
        //% "string_id_address"
        return qtTrId("string_id_address");
    }

    QString string_id_date_of_birth() const
    {
        //% "string_id_date_of_birth"
        return qtTrId("string_id_date_of_birth");
    }

    QString string_id_demo_title() const
    {
        //% "string_id_demo_title"
        return qtTrId("string_id_demo_title");
    }

    QString string_id_dialog_text_enrollment_form() const
    {
        //% "string_id_dialog_text_enrollment_form"
        return qtTrId("string_id_dialog_text_enrollment_form");
    }

    QString string_id_mobileno() const
    {
        //% "string_id_mobileno"
        return qtTrId("string_id_mobileno");
    }

    QString string_id_name() const
    {
        //% "string_id_name"
        return qtTrId("string_id_name");
    }

    QString string_id_pincode() const
    {
        //% "string_id_pincode"
        return qtTrId("string_id_pincode");
    }

signals:
    void localeChanged();
};

#endif // STRINGIDS_H
