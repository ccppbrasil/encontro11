#ifndef _Member_h
#define _Member_h

#include <QObject>
#include <QString>
#include <QUrl>

class Member : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl avatar READ avatar WRITE setAvatar NOTIFY avatarChanged)

    public:
        Member(QObject *parent = 0);

        void setName(QString name);

        QString name() const;

        void setAvatar(QUrl avatar);

        QUrl avatar() const;

    signals:
        void nameChanged();

        void avatarChanged();

    private:
        QString name_;
        QUrl avatar_;
};

#endif
