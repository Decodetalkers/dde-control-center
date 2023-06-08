#include "BackendObject.h"

const QString HostnameService = QStringLiteral("org.freedesktop.hostname1");
const QString HostnamePath = QStringLiteral("/org/freedesktop/hostname1");
const QString HostnameInterface = QStringLiteral("org.freedesktop.hostname1");

static BackendObject *BACKEND = nullptr;

BackendObject *BackendObject::instance()
{
    if (!BACKEND) {
        BACKEND = new BackendObject;
    }
    return BACKEND;
}

BackendObject::BackendObject(QObject *parent)
    : QObject(parent)
    , m_name("First")
    , m_isGangdum(true)
    , m_hostname1Inter(new DDBusInterface(
              HostnameService, HostnamePath, HostnameInterface, QDBusConnection::systemBus(), this))
{
    connect(this, &BackendObject::StaticHostnameChanged, this, [this](const QString &value) {
        m_staticHostName = value;
        Q_EMIT staticHostnameChanged();
    });
}

void BackendObject::setStaticHostname(const QString &value)
{
    QList<QVariant> argumentList;
    argumentList << QVariant::fromValue(value) << QVariant::fromValue(true);
    m_hostname1Inter->asyncCallWithArgumentList("SetStaticHostname", argumentList);
}

void BackendObject::active()
{
    qDebug() << "Active once";
    m_staticHostName = qvariant_cast<QString>(m_hostname1Inter->property("StaticHostname"));
    Q_EMIT staticHostnameChanged();
}
