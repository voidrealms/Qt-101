#include "tester.h"

Tester::Tester(QObject *parent) :
    QObject(parent)
{
}

void Tester::GetUrl()
{

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::DefaultProxy);
    proxy.setHostName("127.0.0.1");
    proxy.setPort(9051);
    //proxy.setUser("username");
    //proxy.setPassword("password");
    QNetworkProxy::setApplicationProxy(proxy);

    qDebug() << "Connecting";
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.whatsmyip.org/")));
}

void Tester::replyFinished(QNetworkReply *Reply)
{
    qDebug() << "Response...";
    if(Reply->isOpen())
    {
        qDebug() << Reply->read((5000));
        Reply->close();
    }
}
