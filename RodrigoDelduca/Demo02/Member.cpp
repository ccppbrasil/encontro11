#include "Member.h"

Member::Member(QObject *parent)
: QObject(parent)
{
}

void Member::setName(QString name)
{
    name_ = name;
    emit nameChanged();
}

QString Member::name() const
{
    return name_;
}

void Member::setAvatar(QUrl avatar)
{
    avatar_ = avatar;
    emit avatarChanged();
}

QUrl Member::avatar() const
{
    return avatar_;
}

