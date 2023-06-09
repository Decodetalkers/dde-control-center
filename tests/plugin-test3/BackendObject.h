#pragma once

#include <DDBusInterface>

#include <QDebug>
#include <QObject>

#include <optional>

using Dtk::Core::DDBusInterface;

class BackendObject final : public QObject
{
    Q_OBJECT

public:
    static BackendObject *instance();

    Q_PROPERTY(QString StaticHostname READ staticHostname WRITE setStaticHostname NOTIFY staticHostnameChanged)

    inline QString staticHostname() { return m_staticHostName; }

    void setStaticHostname(const QString &value);

    Q_PROPERTY(QString edition READ edition NOTIFY baseInformationChanged)

    inline QString edition() { return m_edition.value_or(QString()); }

    Q_PROPERTY(QString cputype READ cputype NOTIFY baseInformationChanged)

    inline QString cputype() { return m_cputype.value_or(QString()); }

    Q_PROPERTY(QString processor READ processor NOTIFY baseInformationChanged)

    inline QString processor() { return m_processor.value_or(QString()); }

    Q_PROPERTY(QString memory READ memory NOTIFY baseInformationChanged)

    inline QString memory() { return m_memory.value_or(QString()); }

    Q_PROPERTY(QString graphicsPlatform READ graphicsPlatform NOTIFY graphicsPlatformChanged)

    inline QString graphicsPlatform() { return m_graphicsPlatform; }

    Q_PROPERTY(QString kernel READ kernel NOTIFY baseInformationChanged)

    inline QString kernel() { return m_kernel.value_or(QString()); }

public:
    void active();

private:
    explicit BackendObject(QObject *parent = nullptr);
    void connectToDBus();

signals:
    void StaticHostnameChanged(const QString &value) const;
    void staticHostnameChanged();
    void AuthorizationStateChanged(const int value) const;

    void graphicsPlatformChanged();
    void baseInformationChanged();

private:
    QString m_staticHostName;
    std::optional<QString> m_edition;
    std::optional<QString> m_cputype;
    std::optional<QString> m_processor;
    std::optional<QString> m_memory;
    QString m_graphicsPlatform;
    std::optional<QString> m_kernel;

private:
    DDBusInterface *m_hostname1Inter;
};
