#pragma once

#include <DDBusInterface>

#include <QDebug>
#include <QObject>

using Dtk::Core::DDBusInterface;

class BackendObject final : public QObject
{
    Q_OBJECT

public:
    static BackendObject *instance();

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    inline QString name() const { return m_name; }

    inline void setName(QString name)
    {
        m_name = name;
        Q_EMIT nameChanged();
    }

    Q_PROPERTY(bool isGangdum READ isGangdum WRITE setIsGangdum NOTIFY isGangdumChanged)

    inline bool isGangdum() const { return m_isGangdum; }

    inline void setIsGangdum(bool isGangdum)
    {
        m_isGangdum = isGangdum;
        Q_EMIT isGangdumChanged();
    }

    Q_PROPERTY(QString StaticHostname READ staticHostname WRITE setStaticHostname NOTIFY staticHostnameChanged)

    inline QString staticHostname() { return m_staticHostName; }

    void setStaticHostname(const QString &value);

public:
    void active();

private:
    explicit BackendObject(QObject *parent = nullptr);

signals:
    void nameChanged();
    void isGangdumChanged();
    void StaticHostnameChanged(const QString &value) const;
    void staticHostnameChanged();
    void AuthorizationStateChanged(const int value) const;

private:
    QString m_name;
    bool m_isGangdum;

    QString m_staticHostName;

private:
    DDBusInterface *m_hostname1Inter;
};
