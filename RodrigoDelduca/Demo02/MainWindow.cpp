#include "MainWindow.h"

MainWindow::MainWindow(QWindow *parent)
: QQuickView(parent)
, reply_(nullptr)
{
    setSource(QUrl("qrc:/Main.qml"));

    QObject *root = qobject_cast<QObject *>(rootObject());

    QObject *button = root->findChild<QObject *>("button");
    if (button)
        connect(button, SIGNAL(clicked()), SLOT(buttonClicked()));
}

void MainWindow::buttonClicked()
{
    rootContext()->setContextProperty(TAG_MODEL, QVariant());

    if (reply_) {
        if (reply_->isRunning()) {
            disconnect(reply_, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
            disconnect(reply_, SIGNAL(finished()), this, SLOT(finished()));

            reply_->abort();
        }

        reply_->deleteLater();
        reply_ = nullptr;
    }

    QUrl url(GITHUB_API);

    QNetworkRequest request(url);
    request.setRawHeader("Accept", "application/json");

    reply_ = manager_.get(request);
    connect(reply_, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(error(QNetworkReply::NetworkError)));
    connect(reply_, SIGNAL(finished()), SLOT(finished()));
}

void MainWindow::finished()
{
    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(reply_->readAll(), &parseError);
    if (parseError.error == QJsonParseError::NoError) {
        QList<QObject *> members;
        foreach (const QJsonValue& value, document.array()) {
            QJsonObject object = value.toObject();

            auto member = new Member(this);
            member->setName(object[TAG_NAME].toString());
            member->setAvatar(object[TAG_AVATAR].toString());
            members << member;
        }

        rootContext()->setContextProperty(TAG_MODEL, QVariant::fromValue(members));
    }
}

void MainWindow::error(QNetworkReply::NetworkError error)
{
    qWarning() << "Network error" << reply_->errorString();
}
