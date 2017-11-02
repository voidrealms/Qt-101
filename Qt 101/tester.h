#ifndef TESTER_H
#define TESTER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

#include <QNetworkProxy>

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(QObject *parent = 0);

signals:

public slots:
    void GetUrl();
    void replyFinished(QNetworkReply* Reply);

};

#endif // TESTER_H
