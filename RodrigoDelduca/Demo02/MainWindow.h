#ifndef _MainWindow_h
#define _MainWindow_h

#include <QApplication>
#include <QMessageBox>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlContext>
#include <QList>

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "Member.h"

namespace {
    const QString GITHUB_API("https://api.github.com/orgs/ccppbrasil/members");
    const QString TAG_NAME("login");
    const QString TAG_AVATAR("avatar_url");
    const QString TAG_MODEL("membersModel");
}

class MainWindow : public QQuickView
{
    Q_OBJECT

    public:
        explicit MainWindow(QWindow *parent = 0);

    protected slots:
        void buttonClicked();

        void finished();
        void error(QNetworkReply::NetworkError error);

    private:
        QNetworkAccessManager manager_;
        QNetworkReply *reply_;
};

#endif
